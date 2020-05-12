# Babylon Polymorph

This is the official open source offering for Babylon Polymorph (Updated and Maintained by the Babylon Native team). See [this article](https://medium.com/@babylonjs/introducing-polymorph-a55588df6cee) for more details.

*This repo is under heavy development. Don't use this in production.*

## Getting Started

This section will outline the simple steps needed to get started with the Babylon Polymorph repo.
To begin development, you will need:
- [Visual Studio 2017 or higher](https://visualstudio.microsoft.com/vs/) (Visual Studio 2019 is recommended)
- [git](https://git-scm.com/)
- [CMake](https://cmake.org/)
- [Windows SDK](https://developer.microsoft.com/en-US/windows/downloads/windows-10-sdk/) (Version 10.0.17134.12 or later)

### Step 1

Using git, navigate to the folder that will hold your repo and clone the repo:
```
git clone https://github.com/BabylonJS/BabylonPolymorph.git
```

### Step 2

Once your repo is cloned, in git, use the following commands to go into the repo folder and download all required submodules:
```
cd BabylonPolymorph

git submodule update --init --recursive
```

### Step 3

#### Use CMake to generate the build files

Open up the Command Prompt and navigate to *<location of repo>\BabylonPolymorph\Morphs\Importers*.
In this folder, enter the following commands:
```
mkdir Build
cd Build
```

If you're fine with using the latest versions of Visual Studio, Windows SDK, and building against x64, the following command will take care of the rest:
```
cmake ..
```

If you want to build against a specific architecture, you can use the **-A** flag to change it (eg. *cmake -A Win32 ..*).  You can also change the generator that you want to use with the **-G** flag (eg. *cmake -G "Visual Studio 16 2019" ..).

### Step 4

Open *BabylonPolymorph\Morphs\Importers\Build\BabylonImporters.sln* in Visual Studio 2019.

## Contributing

Please read [CONTRIBUTING.md](./CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests.

## Reporting Security Issues

Security issues and bugs should be reported privately, via email, to the Microsoft Security
Response Center (MSRC) at [secure@microsoft.com](mailto:secure@microsoft.com). You should
receive a response within 24 hours. If for some reason you do not, please follow up via
email to ensure we received your original message. Further information, including the
[MSRC PGP](https://technet.microsoft.com/en-us/security/dn606155) key, can be found in
the [Security TechCenter](https://technet.microsoft.com/en-us/security/default).

## Development Notes

The importers in this repo make use of the following libraries:

- [**DirectXTex**](https://github.com/microsoft/DirectXTex): Used for handling reading and writing of textures. (MIT License)
- [**glTF-SDK**](https://github.com/microsoft/glTF-SDK): Used for handling reading and writing of glTF files. (MIT License)
- [**RapidJSON**](https://github.com/Tencent/rapidjson/): Used with glTF-SDK for validation/serialization purposes. (MIT License)
