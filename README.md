## lilDevil
### Developer productivity tools


#### Prerequisites
 - Qt 5.13+ (set appropriate paths in CMakeLists.txt)
 - OSX/Linux: clang compiler and cmake
 - Windows: Visual Studio 12+
 
#### Build
`cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" <PROJECT_PATH>`

`cmake --build <PROJECT_PATH>/cmake-build-minsizerel --target lilDevil -- -j 2`
