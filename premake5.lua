workspace "IBF"
	configurations {"Debug","Release"}

project "IBF"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"

	files {"src/*"}

filter "system:windows"
	systemversion "latest"

filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"