#
# Makefile for RoomSolver
# Author: Josie Barth
#
CXX      = clang++
CXXFLAGS = -O0 -Wall -Wextra -g

all: RoomSolver.h RoomSolver.cpp main.cpp
	${CXX} ${CXXFLAGS} -o roomsolver RoomSolver.cpp main.cpp

rmsolver: RoomSolver.h RoomSolver.cpp main.cpp
	${CXX} ${CXXFLAGS} -o roomsolver RoomSolver.cpp main.cpp
               
clean:
	rm -f roomsolver