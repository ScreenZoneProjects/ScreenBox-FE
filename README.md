ScreenFlow
==========

Open-Source Emulators Frontend, with full HyperSpin configuration support.

Chat Support [![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/ScreenZoneProjects/ScreenFlow?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

| [Windows][win-link] | [Linux][lin-link] | [OSX][osx-link] |
| :-----------------: | :---------------: | :-------------: |
| ![win-badge]        | ![lin-badge]      | ![osx-badge]    |

[lin-link]: https://travis-ci.org/ScreenZoneProjects/ScreenFlow
[win-link]: https://ci.appveyor.com/project/jbltx/screenflow
[osx-link]: https://travis-ci.org/ScreenZoneProjects/ScreenFlow
[lin-badge]: https://travis-ci.org/ScreenZoneProjects/ScreenFlow.svg "Travis build status"
[win-badge]: https://ci.appveyor.com/api/projects/status/rp48rjajn5svtpoj?svg=true "AppVeyor build status"
[osx-badge]: https://travis-ci.org/ScreenZoneProjects/ScreenFlow.svg "Travis build status"

## DESCRIPTION

ScreenFlow is a simple open-source games emulators frontend.

ScreenFlow is written in C++, using the famous Qt framework.
It contains frontend standard and extra features :

* Navigate through several systems and games with animated menus.
* Each system and game can have their own animation theme.
* Themes, settings and databases are fully compatible with [HyperSpin](http://www.hyperspin-fe.com/) ones.
* Use [FFmpeg](https://github.com/FFmpeg/FFmpeg) for video and audio playback.
* Launch games in emulators with predefined configurations.
* User can remotely control the frontend using JSON-RPC protocol.

ScreenFlow uses [Doxygen](https://github.com/doxygen/doxygen) for online development documentation.

For more informations, please see the [Wiki](https://github.com/ScreenZoneProjects/ScreenFlow/wiki), or you can go to [Official ScreenZone forum](http://www.screenzone.fr/forum).

## SYSTEM REQUIREMENTS

| Windows | Linux | OSX | Android |
| :-----: | :---: | :-: | :-----: |
| 32/64bits | 32/64bits | 64bits | ARMv7 |

## RELEASE INSTALLATION

If you want to install from releases, go to [Releases page](https://github.com/ScreenZoneProjects/ScreenFlow/releases).

## SOURCES INSTALLATION

You may first need to install some additional [development packages](https://github.com/ScreenZoneProjects/ScreenFlow/wiki/Installation) for your OS.

### Get the source code

```bash
git clone https://github.com/ScreenZoneProjects/ScreenFlow.git
cd ScreenFlow
#Use the command below to work on last stable version commit
git checkout tags/latest
git submodule update --init --recursive
```

### Build ScreenFlow

- Using qmake

```bash
qmake <options> -o Makefile ScreenFlow.pro
```

- Using cmake

```bash
cmake <options> -o Makefile ScreenFlow.pro
```

#### Build options

By default, the Makefile generated will be available to build ScreenFlow for your **current system** as **release** environment. The default destination directory is `build/<YOUR_SYSTEM>/release`. Here are the options to customize your Makefile generation:

- `BUILD_DIR` = (*String*) The build destination directory (default: `build`)
- `WIN_DIR` = (*String*) The Windows build directory (default: `Windows`)
- `OSX_DIR` = (*String*) The OSX build directory (default: `MacOSX`)
- `LINUX_DIR` = (*String*) The Linux build directory (default: `Linux`)
- `DEBUG` = (*Boolean*) Set debug environment (default: `false`)
- `ARCH` = (*String x86_64 | x64*) Set build archithecture. Works only with Windows/Linux builds, OSX is by default only in x64 and android only in armv7 (default: `x86_64`)
- `INSTALL_DIR` = (*String*) The installation directory (defaut: `/usr/local` for Linux, `/Applications` for OSX and `C:\Program Files` for Windows)


## RUNNING

Just launch the ScreenFlow executable file, that's all !

OpenSpin has GUI, but also a Command-Line Interface :

#### Show help
```bash
$ ScreenFlow -h
```

#### Show application current version
```bash
$ ScreenFlow -v
```

#### JSON-RPC Configuration

*WIP...*

#### Launch a game using CLI

*WIP...*

# DOCUMENTATION

If you're looking for some documentation about ScreenFlow, you can use :

* [The wiki project section](https://github.com/ScreenZoneProjects/ScreenFlow/wiki)
* [The auto-generated documentation from sources](https://github.com/ScreenZoneProjects/ScreenFlow/doc)


## CONTRIBUTE

If you'd like to contribute to ScreenFlow, start by forking the repo on GitHub:

http://github.com/ScreenZoneProjects/ScreenFlow

ScreenFlow uses the Git-flow as Git workflow model, so to add new features, follow theses steps:

1. Fork this repo from develop branch
1. Clone down your fork
1. Create a new personal feature branch "feature/your-branch"
1. Code !
1. Test your code using gmake
1. If the feature is really awesome, don't forget to add it in the README.md file
1. Don't change any version number, it will be made later by repo owners
1. Push the branch up to GitHub
1. Send a pull request to the ScreenZoneProjects/ScreenFlow project on develop branch
