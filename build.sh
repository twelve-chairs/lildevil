dnf groupinstall "Development Tools"

dnf install gcc-c++ cmake qt5

source ~/.bashrc

mkdir cmake-build-minsizerel

cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" .

cmake --build ./cmake-build-minsizerel --target lilDevil -- -j 2