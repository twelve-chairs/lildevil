# lilDevil
### Cross-platform productivity workstation for developers' tools 
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=twelvechairssoftware_lildevil&metric=alert_status)](https://sonarcloud.io/dashboard?id=twelvechairssoftware_lildevil)

#### Prerequisites
 - MacOS: [`brew`](https://brew.sh), Xcode (`xcode-select --install`)
 - Windows: [`choco`](https://chocolatey.org/install), [Visual Studio 12+ (VS2017)](https://visualstudio.microsoft.com/vs/community/)
 - Optionally, [`Qt 5.13+`](https://www.qt.io/download-qt-installer)


#### Pre-built Binaries

- MacOS

  `brew tap twelvechairssoftware/lildevil https://gitlab.com/twelvechairssoftware/lildevil`
  
  `brew cask install lildevil`


#### Build your own
Clone this repository

  `git clone https://github.com/twelvechairssoftware/lildevil.git`
  
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
