# lilDevil

[![Build](https://github.com/twelvechairssoftware/lildevil/actions/workflows/build.yml/badge.svg)](https://github.com/twelvechairssoftware/lildevil/actions/workflows/build.yml)
[![CodeQL](https://github.com/twelve-chairs/lildevil/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/twelve-chairs/lildevil/actions/workflows/github-code-scanning/codeql)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=twelve-chairs_lildevil&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=twelve-chairs_lildevil)
## Intro
Cross-platform productivity workstation for developers' tools 

## Roadmap

✅ - done; 🚧 - in-progress; 🌤️ -  some day, maybe;

## Open source libraries used:
 - QT (https://www.qt.io)
 - spdlog (https://github.com/gabime/spdlog)


## Pre-built Binaries

- MacOS
    
  Prerequisite: [homebrew](https://brew.sh)

  `brew tap twelvechairssoftware/lildevil`
  
  `brew cask install lildevil`

- Linux

  Prerequisite: [homebrew](https://docs.brew.sh/Homebrew-on-Linux)
  
  `brew tap twelvechairssoftware/lildevil`
    
  `brew cask install lildevil`

- Windows

  Prerequisite: [choco](https://chocolatey.org/install)
  
  `choco install lildevil`

## Build your own
Prerequisites
 - MacOS: Xcode (`xcode-select --install`)
 - Windows: [Visual Studio 12+ (VS2017)](https://visualstudio.microsoft.com/vs/community/)
 - Rarely needed: [Qt 5.13+](https://www.qt.io/download-qt-installer)


Clone this repository

  `git clone https://gitlab.com/twelvechairssoftware/lildevil.git`
  
  `cd lildevil`

Set appropriate Qt paths in CMakeLists.txt, then:

 - MacOS
       
      `brew install cmake qt`
      
      `cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" .`
 
      `cmake --build ./cmake-build-minsizerel --target lilDevil -- -j 2`
      
      `./bin/lilDevil`
 
 - Windows (very architecture-specific)
 
      `choco install cmake qtcreator`
      
      `cmake.exe -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - NMake Makefiles" <PROJECT_PATH>`

      `cmake.exe --build <PROJECT_PATH>/cmake-build-minsizerel --target lilDevil --`
      
      `bin\lilDevil.exe`

 - Linux (RHEL)
       
      `dnf groupinstall "Development Tools"`
      
      `dnf install gcc-c++ cmake qt5`
      
      `cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" .`
 
      `cmake --build ./cmake-build-minsizerel --target lilDevil -- -j 2`
      
      `./bin/lilDevil`

 - Linux (Debian)
             
      `apt-get install build-essential git cmake qt5-default`
      
      `cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" .`
 
      `cmake --build . --target lilDevil -- -j 2`
      
      `./bin/lilDevil`
