# Babylon Polymorph

This is the official open source offering for Babylon Polymorph (Updated and Maintained by the Babylon Native team). See [this article](https://medium.com/@babylonjs/introducing-polymorph-a55588df6cee) for more details.

*This repo is under heavy development. Don't use this in production.*

## Contributing

Please read [CONTRIBUTING.md](./CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests.

## Reporting Security Issues

Security issues and bugs should be reported privately, via email, to the Microsoft Security
Response Center (MSRC) at [secure@microsoft.com](mailto:secure@microsoft.com). You should
receive a response within 24 hours. If for some reason you do not, please follow up via
email to ensure we received your original message. Further information, including the
[MSRC PGP](https://technet.microsoft.com/en-us/security/dn606155) key, can be found in
the [Security TechCenter](https://technet.microsoft.com/en-us/security/default).

## Getting Started

This section will outline the simple steps needed to get started with the Babylon Polymorph repo.  To begin development, you will need [Visual Studio 2019](https://visualstudio.microsoft.com/vs/) and [git](https://git-scm.com/).

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

Open *BabylonPolymorph\Morphs\Importers\Build\babylon.native.transcoders.sln* in Visual Studio 2019.
