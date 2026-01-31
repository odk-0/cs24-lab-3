CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

all: testbst

testbst: testbst.o intbst.o
	$(CXX) $(CXXFLAGS) -o testbst testbst.o intbst.o

intbst.o: intbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c intbst.cpp

testbst.o: testbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c testbst.cpp

test_intbst: test_intbst.o intbst.o
	$(CXX) $(CXXFLAGS) -o test_intbst test_intbst.o intbst.o

test_intbst.o: test_intbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c test_intbst.cpp

clean:
	rm -f *.o testbst
