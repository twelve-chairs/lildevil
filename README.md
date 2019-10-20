# lilDevil
### Cross-platform productivity workstation for developers' tools 


#### Prerequisites
 - Qt 5.13+ (https://www.qt.io/download-qt-installer)
 - OSX: cmake and clang compiler
 - Windows: Visual Studio 12+ (VS2017)
 - Linux: cmake and Qt-compatible C++ compiler
 
#### Build
Clone this repository

      `git clone https://github.com/twelvechairssoftware/lildevil.git`

Set appropriate Qt paths in CMakeLists.txt, then:

 - OSX
 
      `cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" <PROJECT_PATH>`
 
      `cmake --build <PROJECT_PATH>/cmake-build-minsizerel --target lilDevil -- -j 2`
 
 - Windows
 
      `cmake.exe -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - NMake Makefiles" <PROJECT_PATH>`

      `cmake.exe --build <PROJECT_PATH>/cmake-build-minsizerel --target lilDevil --`

 - Linux (Fedora)
 
      `dnf -y groupinstall "Development Tools"`
      
      `dnf -y install gcc-c++ cmake qt5`
      
      `cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" <PROJECT_PATH>`
 
      `cmake --build <PROJECT_PATH>/cmake-build-minsizerel --target lilDevil -- -j 2`

