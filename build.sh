dnf groupinstall "Development Tools" -y

dnf install gcc-c++ cmake qt5 -y

source ~/.bashrc

export CMAKE_PREFIX_PATH=/usr/lib64/cmake

mkdir cmake-build-minsizerel

cmake -DCMAKE_BUILD_TYPE=MinSizeRel -G "CodeBlocks - Unix Makefiles" .

cmake --build ./cmake-build-minsizerel --target lilDevil -- -j 2