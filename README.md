# lilDevil

![Build](https://github.com/twelvechairssoftware/lildevil/workflows/Build/badge.svg)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=twelvechairssoftware_lildevil&metric=alert_status&token=52a788a89ceba2c5c9520f211197652e716811cd)](https://sonarcloud.io/dashboard?id=twelvechairssoftware_lildevil)
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

## License

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The code is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2021 Twelve Chairs Software, LLC

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
