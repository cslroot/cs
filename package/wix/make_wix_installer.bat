setlocal
set PWD=%~dp0
cd %PWD%
candle cs.wxs -ext WixUIExtension
light cs.wixobj -ext WixUIExtension

endlocal
