CXX =g++

CXXFLAGS = -Wall  -std=c++11

TARGET = myprogram

SOURCES =  circle.cpp square.cpp cutfigure.cpp main.cpp


$(TARGET): $(SOURCES)
		$(CXX) $(CXXFLAGS) $^ -o $@

clean:
		rm -f $(TARGET)
