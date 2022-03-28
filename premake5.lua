workspace "Cosmos"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir= "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cosmos"
	location "Cosmos"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"COS_PLATFORM_WINDOWS",
			"COS_BUILD_DLL"
		}
	
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Antares")
		}


	filter "configurations:Debug"
		defines "COS_DEBUG"
		symbols "On"

	
	filter "configurations:Release"
		defines "COS_RELEASE"
		optimize "On"

	
	filter "configurations:Dist"
		defines "COS_DIST"
		optimize "On"

project "Antares"
	location "Antares"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Cosmos/vendor/spdlog/include",
		"Cosmos/src"
	}

	links 
	{
		"Cosmos"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
		"COS_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "COS_DEBUG"
		symbols "On"

	
	filter "configurations:Release"
		defines "COS_RELEASE"
		optimize "On"

	
	filter "configurations:Dist"
		defines "COS_DIST"
		optimize "On"

