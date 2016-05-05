ScreenFlow
===========

Open-Source Emulators Frontend

Chat Support [![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/ScreenZoneProjects/ScreenFlow?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

| [Windows][win-link] | [Linux][lin-link] | [OSX][osx-link] |
| :-----------------: | :---------------: | :-------------: |
| ![win-badge]        | ![lin-badge]      | ![osx-badge]    |

[lin-link]: https://travis-ci.org/ScreenZoneProjects/ScreenFlow
[win-link]: https://ci.appveyor.com/project/jbltx/openspin-7jlje
[osx-link]: https://travis-ci.org/ScreenZoneProjects/ScreenFlow
[lin-badge]: https://travis-ci.org/ScreenZoneProjects/ScreenFlow.svg "Travis build status"
[win-badge]: https://ci.appveyor.com/api/projects/status/rp48rjajn5svtpoj?svg=true "AppVeyor build status"
[osx-badge]: https://travis-ci.org/ScreenZoneProjects/ScreenFlow.svg "Travis build status"

## DESCRIPTION

ScreenFlow is a simple open-source games emulators frontend.

ScreenFlow is written in C++, using the famous Qt libs.
It contains frontend standard and extra features :

* Navigate through several systems and games with animated menus.
* Each system and game can have their own animation theme.
* Themes, settings and databases are fully compatible with [HyperSpin](http://www.hyperspin-fe.com/) ones.
* Launch games in emulators with predefined configurations.
* User can remotely control the frontend using JSON-RPC protocol.

ScreenFlow uses [ClDoc](https://jessevdk.github.io/cldoc/) for online documentation.

For more informations, please see the [Wiki](https://github.com/ScreenZoneProjects/ScreenFlow/wiki).

## SYSTEM REQUIREMENTS

- Windows / Linux / OSX Operating Systems
- 32bits / 64bits / ARM CPU Architectures

## RELEASE INSTALLATION

If you want to install from releases, go to [Releases page](https://github.com/ScreenZoneProjects/ScreenFlow/releases).

## SOURCES INSTALLATION

You may first need to install some additional [development packages](https://github.com/ScreenZoneProjects/ScreenFlow/wiki/Installation) for your OS.

Then simply use the **[QMake](http://doc.qt.io/qt-5/qmake-overview.html#building-a-project)** and make command :

```bash
git clone https://github.com/ScreenZoneProjects/ScreenFlow.git
cd ScreenFlow
qmake -qt=qt5
make
sudo make install
```

If you prefer to use **[CMake](http://www.cmake.org/)**, you can also use it :

```bash
git clone https://github.com/ScreenZoneProjects/ScreenFlow.git
cd ScreenFlow && mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH="PATH_TO_Qt5<Module>_DIR" ../
make
sudo make install
```
**NB: You need to change `"PATH_TO_Qt5<Module>_DIR"` by your personal path.**


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
```bash
$ ScreenFlow -u NAME       # Define a server user name NAME
$ ScreenFlow -pwd PASSWORD # Define a server user password PASSWORD
$ ScreenFlow -p            # Define a server port
$ ScreenFlow --noserver    # Disable JSON-RPC server
```

#### Launch a game using CLI
```bash
$ ScreenFlow -s SYSTEM  # Define the system name SYSTEM
$ ScreenFlow -r ROM     # Define the ROM name ROM
$ ScreenFlow -a ARGS    # Optionnal: Additionnal arguments for the emulator executable ARGS
```

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
