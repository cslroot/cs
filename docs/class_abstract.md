```mermaid
classDiagram
 App ..> Render
 App ..> Modeler
 App ..> Drawing
 Render ..> Core
 Drawing ..> Core
 Modeler ..> Core
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