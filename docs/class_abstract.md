```mermaid
classDiagram
 App ..> Render
 App ..> Modeler
 App ..> Drawing
 App ..> PluginFeatures
 PluginFeatures ..> Core
 Render ..> Core
 Render ..> Kernel
 Drawing ..> Kernel
 Modeler ..> Kernel
 Core ..> Base
 Kernel ..> Core
```

Package dependency

```mermaid
classDiagram
 Render ..> GLFW
 Core ..> Poco
 Core ..> fmt
 App ..> sqlite
```
