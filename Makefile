CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall

code: solution.cpp
	$(CXX) $(CXXFLAGS) -o code solution.cpp

clean:
	rm -f code *.o
