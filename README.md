# Deling

[![Build Status Linux/OSX](https://travis-ci.org/myst6re/deling.svg?branch=develop)](https://travis-ci.org/myst6re/deling)
[![Build status Win32](https://ci.appveyor.com/api/projects/status/74gm0u6ya9nqxw9u/branch/develop?svg=true)](https://ci.appveyor.com/project/myst6re/deling/branch/develop)

![Deling](images/deling.png)

Final Fantasy VIII field archive editor.

## Building

If you are a developer and you want to build this software, follow the
instructions below.

### Requirements

 - CMake
 - Qt 5.5+

### Windows

#### Qt

0) Download the online installer from https://www.qt.io/download-qt-installer ( remember to click the Download button )
1) Install Qt with these items checked:
   - **Packages categories:** `Latest release`
   - **Components:** Uncheck everything and pick only `MSVC 2019 32-bit`

#### Visual Studio

> **Please note:**
>
> By default Visual Studio will pick the **x86-Release** build configuration, but you can choose any other profile available.

0) **REQUIRED!** Follow the steps to install Qt, if you didn't already
0) Download the the latest [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/) installer
1) Run the installer and import this [.vsconfig](.vsconfig) file in the installer to pick the required components to build this project
2) Once installed, open this repository **as a folder** in Visual Studio 2019 and click the build button.

#### Optional: Visual Studio Code

0) **REQUIRED!** Follow the steps to install Qt, if you didn't already
0) **REQUIRED!** Follow the steps to install Visual Studio, if you didn't already
1) Download and install the latest [Visual Studio Code](https://code.visualstudio.com/) release
2) Install the following extensions:
   - https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
   - https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
3) Open this repository as a folder in Visual Studio code
4) Choose as build profile in the status bar `CMake: [Release]` ( or one of the aforementioned profiles )
5) Click the button on the status bar `Build`

### macOS

In order to continue please make sure you have `brew` installed. See https://brew.sh/ for instructions.

#### Install dependencies
```sh
$ brew install cmake
$ brew install qt5
```
Close and reopen your terminal.

#### Build

> **Please note**: You can choose other build profiles if you want. See https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html for more information.

```sh
$ mkdir -p .dist/build .dist/install
$ cmake -S . -B .dist/build -DCMAKE_INSTALL_PREFIX=.dist/install -DCMAKE_BUILD_TYPE=Debug
$ cmake --build .dist/build --config Debug
```

### Linux

#### Install dependencies

##### Debian/Ubuntu
```sh
$ apt-get install build-essential cmake qt5-default qttools5-dev
```

##### Arch Linux
```sh
$ pacman -S --needed base-devel cmake qt5
```

#### Build

> **Please note**: You can choose other build profiles if you want. See https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html for more information.

```sh
$ mkdir -p .dist/build .dist/install
$ cmake -S . -B .dist/build -DCMAKE_INSTALL_PREFIX=.dist/install -DCMAKE_BUILD_TYPE=Debug
$ cmake --build .dist/build --config Debug
```

## How to contribute

Pull requests are welcome on [GitHub](https://github.com/myst6re/deling).
Ensure that you have commited in `develop` branch, otherwise I will not accept your
request.
