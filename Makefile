# Makefile

CXX = clang++
CXXFLAGS = -O2 -g -Werror -Wall -std=c++17
TARGET = #myprog

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean:
	$(RM) $(TARGET)
