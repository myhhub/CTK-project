CTK完整教程(OSGI for C++ 实现 C++ Qt 模块化)

CTK框架实际应用比较可靠，但网上资料很少。本教程围绕 CTK Plugin Framework，探索 C++ 中的模块化技术，并能够基于 CTK 快速搭建 C++ 组件化框架，避免后来的人走弯路。本教程的源码下载地址：[项目源代码](https://github.com/myhhub/CTK-project)。

# CTK介绍

[CTK](http://www.commontk.org/) 为支持生物医学图像计算的公共开发包，其全称为 Common Toolkit。CTK插件框架的设计有很大的灵感来自OSGi并且使得应用程序由许多不同的组件组合成一个可扩展模型。这个模型允许通过那些组件间共享对象的服务通信。

当前，CTK 工作的主要范围包括：

- [DICOM](http://www.commontk.org/index.php/Documentation/Dicom_Overview)：提供了从 PACS 和本地数据库中查询和检索的高级类。包含 Qt 部件，可以轻松地设置服务器连接，并发送查询和查看结果。

- [DICOM Application Hosting](http://www.commontk.org/index.php/Documentation/DicomApplicationHosting)：目标是创建 DICOM Part 19 Application Hosting specifications 的 C++ 参考实现。它提供了用于创建主机和托管应用程序的基础设。

- [Widgets](http://www.commontk.org/index.php/Documentation/Widgets)：用于生物医学成像应用的 Qt Widgets 集合。

- [Plugin Framework](http://www.commontk.org/index.php/Documentation/Plugin_Framework)：用于 C++ 的动态组件系统，以 OSGi 规范为模型。它支持一个开发模型，在这个模型中，应用程序（动态地）由许多不同（可重用的）组件组成，遵循面向服务的方法。

- [Command Line Interfaces](http://www.commontk.org/index.php/Documentation/Command_Line_Interface)：一种允许将算法编写为自包含可执行程序的技术，可以在多个终端用户应用程序环境中使用，而无需修改。

  ## 使用 CTK Plugin Framework 的好处

  由于 CTK Plugin Framework 基于 OSGi，因此它继承了一种非常成熟且完全设计的组件系统，这在 Java 中用于构建高度复杂的应用程序，它将这些好处带给了本地（基于 Qt 的）C++ 应用程序。以下内容摘自 [Benefits of Using OSGi](https://www.osgi.org/developer/benefits-of-using-osgi/)，并适应于 CTK Plugin Framework：

- 降低复杂性

  使用 CTK Plugin Framework 开发意味着开发插件，它们隐藏了内部实现，并通过定义良好的服务来和其它插件通信。隐藏内部机制意味着以后可以自由地更改实现，这不仅有助于 Bug 数量的减少，还使得插件的开发变得更加简单，因为只需要实现已经定义好的一定数量的功能接口即可。

- 复用

  标准化的组件模型，使得在应用程序中使用第三方组件变得非常容易。

- 现实情况

  CTK Plugin Framework 是一个动态框架，它可以动态地更新插件和服务。在现实世界中，有很多场景都和动态服务模型相匹配。因此，应用程序可以在其所属的领域中重用 Service Registry 的强大基元（注册、获取、用富有表现力的过滤语言列表、等待服务的出现和消失）。这不仅节省了编写代码，还提供了全局可见性、调试工具以及比为专用解决方案实现的更多的功能。在这样的动态环境下编写代码听起来似乎是个噩梦，但幸运的是，有支持类和框架可以消除大部分（如果不是全部的话）痛苦。

- 开发简单

  CTK Plugin Framework 不仅仅是组件的标准，它还指定了如何安装和管理组件。这个 API 可以被插件用来提供一个管理代理，这个管理代理可以非常简单，如命令 shell、图形桌面应用程序、Amazon EC2 的云计算接口、或 IBM Tivoli 管理系统。标准化的管理 API 使得在现有和未来的系统中集成 CTK Plugin Framework 变得非常容易。

- 动态更新

  OSGi 组件模型是一个动态模型，插件可以在不关闭整个系统的情况下被安装、启动、停止、更新和卸载。

- 自适应

  OSGi 组件模型是从头设计的，以允许组件的混合和匹配。这就要求必须指定组件的依赖关系，并且需要组件在其可选依赖性并不总是可用的环境中生存。Service Registry 是一个动态注册表，其中插件可以注册、获取和监听服务。这种动态服务模型允许插件找出系统中可用的功能，并调整它们所能提供的功能。这使得代码更加灵活，并且能够更好地适应变化。

- 透明性

  插件和服务是 CTK 插件环境中的一等公民。管理 API 提供了对插件的内部状态的访问，以及插件之间的连接方式。可以停止部分应用程序来调试某个问题，或者可以引入诊断插件。

- 版本控制

  在 CTK Plugin Framework 中，所有的插件都经过严格的版本控制，只有能够协作的插件才会被连接在一起。

- 简单

  CTK 插件相关的 API 非常简单，核心 API 不到 25 个类。这个核心 API 足以编写插件、安装、启动、停止、更新和卸载它们，并且还包含了所有的监听类。

- 懒加载

  懒加载是软件中一个很好的点，OSGi 技术有很多的机制来保证只有当类真正需要的时候才开始加载它们。例如，插件可以用饿汉式启动，但是也可以被配置为仅当其它插件使用它们时才启动。服务可以被注册，但只有在使用时才创建。这些懒加载场景，可以节省大量的运行时成本。

- 非独占性

  CTK Plugin Framework 不会接管整个应用程序，你可以选择性地将所提供的功能暴露给应用程序的某些部分，或者甚至可以在同一个进程中运行该框架的多个实例。

- 非侵入

  在一个 CTK 插件环境中，不同插件均有自己的环境。它们可以使用任何设施，框架对此并无限制。CTK 服务没有特殊的接口需求，每个 QObject 都可以作为一个服务，每个类（也包括非 QObject）都可以作为一个接口。

# CTK编译

使用cmake编译出与系统版本相应的动态库。参见[CTK编译教程(64位环境 Windows + Qt + MinGW或MSVC + CMake)](https://www.ljjyy.com/archives/2021/02/100643.html)。

# [使用 CTKWidgets](https://www.ljjyy.com/archives/2021/02/100643.html)。
# [使用 CTK Plugin Framework](https://www.ljjyy.com/archives/2021/02/100645.html)。
