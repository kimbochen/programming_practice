CXX = clang++
CXXFLAGS = -std=c++17 -O0 -Wall -Werror
TARGET = 

# target filename: dependency list
# $@: target filename variable (prog)
# $^: dependency list variable (TARGET)
prog: $(TARGET)
	$(CXX) $^ $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf prog
