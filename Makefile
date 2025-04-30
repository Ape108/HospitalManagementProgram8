
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./CS201R-Pgm8Hospital/include
SRCDIR = CS201R-Pgm8Hospital/src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
