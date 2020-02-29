#sudo dnf groupinstall "Development Tools"
#
#sudo dnf install gcc-c++ cmake qt5

cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" .

cmake --build ./cmake-build-minsizerel --target lilDevil -- -j 2