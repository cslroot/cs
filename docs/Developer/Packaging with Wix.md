# Packaging with Wix


1. CS Developer
  1. -> build

-> packaging: put the include and libraries(.dll, .lib, .so) files into the framework installer

DevUser:
install cs via cs installer  
develop application-base using the modules
create some class 

EndUser: use the application installer.

------------

# dev log
Env.
* windows 11 x64


## consider which installer tool is suitable for me

CPack supported generators:

* NSIS: Null Soft Installer
* NSIS64: Null Soft Installer (64-bit)
* STGZ: Self extracting Tar GZip compression
* TBZ2: Tar BZip2 compression
* TGZ: Tar GZip compression
* TZ: Tar Compress compression
* WIX: MSI file format via WiX tools
* ZIP: ZIP file format

that means, 
* WiX
* NSIS


others:
* Inno Setup
* NSIS (Nullsoft Scriptable Install System)
* ~~InstallShield~~ Proprietary product


## trial WiX toolset

create the package manually.

## install 
* WiX Toolset https://wixtoolset.org/
  - add the directory of wix `bin` into PATH
    - `C:\Program Files (x86)\WiX Toolset v3.11\bin`
* WiX Edit https://wixedit.github.io/
  - Only the first time, I had to run as an administrator only once

## setup

https://qiita.com/Yanase-Takuma/items/bf0a360c9d37ca03a272


## gen

```
cd ./package/wix
candle cs.wxs -ext WixUIExtension
light cs.wixobj -ext WixUIExtension
```
