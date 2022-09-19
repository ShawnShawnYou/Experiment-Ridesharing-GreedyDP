cmake_minimum_required(VERSION 3.20)
project(PRUNEGDP)


set(CMAKE_CXX_STANDARD 14)

add_executable(PRUNEGDP pruneGDP.cpp metric.h metric.cpp global.h global.cpp monitor.h monitor.cpp util.h util.cpp lrucache.h)