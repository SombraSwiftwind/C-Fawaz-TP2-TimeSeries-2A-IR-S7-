# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Include directory
INCLUDES = -Iheaders

# Source files
SRCS = main.cpp knn.cpp time_series_generator.cpp sin_wave_generator.cpp gaussian_generator.cpp step_generator.cpp time_series_dataset.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main

# Default target
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Compile the source files into object files (make)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up the build files (make clean)
clean:
	rm -f $(OBJS) $(EXEC)

# Run the executable (make run)
run: $(EXEC)
	./$(EXEC)