cmake_minimum_required(VERSION 3.17)
project(ITCR_DatosII_ProyectoI_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(ITCR_DatosII_ProyectoI_Server src/C++/main.cpp src/C++/mServer.cpp src/C++/mServer.h src/DataStructures/Node.cpp src/DataStructures/Node.h src/DataStructures/LinkedList.cpp src/DataStructures/LinkedList.h src/C++/MemoryMap.cpp src/C++/MemoryMap.h src/C++/Request.cpp src/C++/Request.h src/C++/blockTest.cpp src/C++/blockTest.h)