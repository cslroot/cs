
project(cs.examples.wpf VERSION 0.1.0)
enable_language(CSharp)

include(CSharpUtilities)

add_executable(cs.examples.wpf
	App.config
	App.xaml
	App.xaml.cs
	MainWindow.xaml
	MainWindow.xaml.cs

	Properties/AssemblyInfo.cs
	Properties/Resources.Designer.cs
	Properties/Resources.resx
	Properties/Settings.Designer.cs
	Properties/Settings.settings)

csharp_set_designer_cs_properties(
	Properties/AssemblyInfo.cs
	Properties/Resources.Designer.cs
	Properties/Resources.resx
	Properties/Settings.Designer.cs
	Properties/Settings.settings)

csharp_set_xaml_cs_properties(
	App.xaml
	App.xaml.cs
	MainWindow.xaml
	MainWindow.xaml.cs)


set_target_properties(cs.examples.wpf PROPERTIES FOLDER examples)

set_property(SOURCE App.xaml PROPERTY VS_XAML_TYPE "ApplicationDefinition")

# install NuGet packages
# CMake 3.15-
# https://cmake.org/cmake/help/latest/prop_tgt/VS_PACKAGE_REFERENCES.html
set_property(TARGET cs.examples.wpf PROPERTY VS_PACKAGE_REFERENCES "Fluent.Ribbon_9.0.4")

set_property(TARGET cs.examples.wpf PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.2")
set_property(TARGET cs.examples.wpf PROPERTY WIN32_EXECUTABLE TRUE)

set_property(TARGET cs.examples.wpf PROPERTY VS_DOTNET_REFERENCES
	"Microsoft.CSharp"
	"PresentationCore"
	"PresentationFramework"
	"System"
	"System.Core"
	"System.Data"
	"System.Data.DataSetExtensions"
	"System.Net.Http"
	"System.Xaml"
	"System.Xml"
	"System.Xml.Linq"
	"WindowsBase")
