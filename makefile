# Compiler and flags
CXX		 = g++
CXXFLAGS = -Wall -std=c++17 -g

# Main program
MAIN_SRCS = main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)

# Test executables
TEST_EVAL_SRCS = test_evaluator.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp
TEST_EVAL_OBJS = $(TEST_EVAL_SRCS:.cpp=.o)

TEST_SORT_SRCS = test_sorting.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp
TEST_SORT_OBJS = $(TEST_SORT_SRCS:.cpp=.o)

# Default target builds everything
all: main test_evaluator test_sorting

# Build main executable
main: $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o main $(MAIN_OBJS)

# Build test executables
test_evaluator: $(TEST_EVAL_OBJS)
	$(CXX) $(CXXFLAGS) -o test_evaluator $(TEST_EVAL_OBJS)

test_sorting: $(TEST_SORT_OBJS)
	$(CXX) $(CXXFLAGS) -o test_sorting $(TEST_SORT_OBJS)

# Run the main executable
run: main
	./main

# Run tests
test: test_evaluator test_sorting
	./test_evaluator
	./test_sorting

# Pattern rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	rm -f *.o main test_evaluator test_sorting

.PHONY: all run test clean