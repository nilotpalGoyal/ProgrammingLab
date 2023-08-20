# Makefile example for a C++ program

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Source files
SRCS = helper.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Include path
INCLUDES = -I$(MAIN_DIR)

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
