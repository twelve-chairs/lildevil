# lilDevil
#### Cross-platform productivity workstation for developers' tools 
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=twelvechairssoftware_lildevil&metric=alert_status&token=4329843c47a53da188d303a7358d7d97f9d58e94)](https://sonarcloud.io/dashboard?id=twelvechairssoftware_lildevil)
[![Lines of Code](https://sonarcloud.io/api/project_badges/measure?project=twelvechairssoftware_lildevil&metric=ncloc&token=4329843c47a53da188d303a7358d7d97f9d58e94)](https://sonarcloud.io/dashboard?id=twelvechairssoftware_lildevil)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=twelvechairssoftware_lildevil&metric=security_rating&token=4329843c47a53da188d303a7358d7d97f9d58e94)](https://sonarcloud.io/dashboard?id=twelvechairssoftware_lildevil)
[![Vulnerabilities](https://sonarcloud.io/api/project_badges/measure?project=twelvechairssoftware_lildevil&metric=vulnerabilities&token=4329843c47a53da188d303a7358d7d97f9d58e94)](https://sonarcloud.io/dashboard?id=twelvechairssoftware_lildevil)
### Pre-built Binaries

- MacOS

  `brew tap twelvechairssoftware/lildevil`
  
  `brew cask install lildevil`

- Linux

  `snapd install lildevil`

### Build your own
Prerequisites
 - MacOS: [`brew`](https://brew.sh), Xcode (`xcode-select --install`)
 - Windows: [`choco`](https://chocolatey.org/install), [Visual Studio 12+ (VS2017)](https://visualstudio.microsoft.com/vs/community/)
 - Linux: [`snapd`](https://snapcraft.io/docs/installing-snapd)
 - Rarely needed: [`Qt 5.13+`](https://www.qt.io/download-qt-installer)


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
