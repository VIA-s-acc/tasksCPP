CXX =g++

CXXFLAGS = -Wall  -std=c++11

TARGET = myprogram

SOURCES =  string_stack.cpp main.cpp


$(TARGET): $(SOURCES)
		$(CXX) $(CXXFLAGS) $^ -o $@

clean:
		rm -f $(TARGET)
