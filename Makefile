CXX = clang++

SRCS = $(wildcard src/*.cpp impl/*.cpp impl/*.hpp)

CXXFLAGS = -std=c++17 -I/usr/local/include -L/usr/local/lib -lyaml-cpp

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o target/out
