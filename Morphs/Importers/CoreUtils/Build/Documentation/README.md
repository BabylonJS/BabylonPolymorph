# Microsoft.Lift.Core

Microsoft.Lift.Core is a Nuget package built by Lift London and contains a collection of C++ core libraries.

1. [Summary](#summary)
2. [How to use it](#howto)
3. [Overview](#viewer)
	1. [Framework](#framework)
	2. [CoreUtils](#coreutils)
		1. [Tweening](#tweening)
		2. [Math](#math)
		3. [Lexical cast](#lexicalcast)
		4. [Trace](#trace)
		5. [Assert](#assert)
		6. [Json](#json)
	3. [ImagingComponent](#imagingcomponent)


<div id="summary"></div>   
## Summary

Microsoft.Lift.Core is made of C++ header files and static libraries built in VS2015.  

<div id="howto"></div>  
## How to use it
1. Set Nuget package source in Visual Studio:
	1. Open Visual Studio 2015
	2. Open Package Manager Settings (Tools > NuGet Package Manager)
	3. Add this feed as an available package source
		1. Name : SpectreNugetFeed
		2. Source : https://microsoft.pkgs.visualstudio.com/_packaging/BigPark/nuget/v3/index.json
2. Right click on the project that you want to add Microsoft.Lift.Core dependency
3. Select Manage Nuget Packages...
4. Browse to find Microsoft.Lift.Core.CPP nuget package and install it
5. Unload you project (right click, unload)
6. Add this snippet somewhere inside `<`Project`>` `<`/Project`>` tags:

~~~~~~~~~~~~~~~{.c}
  <PropertyGroup Condition="'$(Configuration)'=='Debug'">
    <RuntimeLibrary>MultiThreadedDebugDLL</RuntimeLibrary>
    <Linkage-Microsoft_Lift_Core_CPP>static</Linkage-Microsoft_Lift_Core_CPP>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)'=='Release'">
    <RuntimeLibrary>MultiThreadedDLL</RuntimeLibrary>
    <Linkage-Microsoft_Lift_Core_CPP>static</Linkage-Microsoft_Lift_Core_CPP>
  </PropertyGroup>
~~~~~~~~~~~~~~~

Library will be statically linked to your project. All the header files can be found under CoreUtils folder f.e.

~~~~~~~~~~~~~~~{.c}
#import <CoreUtils/Lexicalcast.h>
#import <CoreUtils/Maths/SimpleMath.h>
#import <CoreUtils/Tweening/TweeningManager.h>
~~~~~~~~~~~~~~~

## Overview

Microsoft.Lift.Core is made of 3 major components:

1. [Framework](#framework)
2. [CoreUtils](#coreutils)
3. [ImagingComponent](#imagincomponent)

<div id="Framework"></div> 
### Framework
Collection of BXF (Beihai exchange format) classes for reading and writing BXF streams.

<div id="CoreUtils"></div> 
### CoreUtils
Collection of useful utilities for writing C++ code including: 
- lexical cast for converting between various types
- a custom compile time trace utility for logging custom messages to the output
- a simple assert  which is supported by unit tests
- a custom exception handling classes
- utilities to read and write from files including various implementations of ISpectreStream
- a simple math library including handling 3D types
- simple thread pool implementation
- json handling
- support for simple animation based time and type remapping (tween)

<div id="ImagingComponent"></div> 
Helper project for reading and writing textures of various formats. It is based on DirectXTex project.

