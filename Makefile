CXX = clang++

SRCS = $(wildcard src/*.cpp impl/*.cpp impl/*.hpp)

CXXFLAGS = -std=c++17 

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o target/out
