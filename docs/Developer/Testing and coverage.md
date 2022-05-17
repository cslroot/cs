# Testing



## Coverage

### github actions

using [Codecov](https://about.codecov.io/)

ref: https://about.codecov.io/blog/how-to-set-up-codecov-with-c-plus-plus-and-github-actions/

### local

Collect coverage using OpenCppCoverage

#### setup

```
choco install opencppcoverage
```

#### execute

```
OpenCppCoverage --sources src -- "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" .\build\windows-cl-x64-ninja\bin\Debug\cs.test.exe
```

```
OpenCppCoverage --sources src --modules=build\windows-cl-x64-ninja\bin\Debug\cs.* --export_type cobertura:cs.xml -- .\build\windows-cl-x64-ninja\bin\Debug\cs.test.exe
```
