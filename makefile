# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Source files
SRCS = main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp
TEST_EVAL_SRCS = test_evaluator.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp
TEST_SORT_SRCS = test_sorting.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp

# Executables
MAIN = main
TEST_EVAL = test_evaluator
TEST_SORT = test_sorting

all: compile run clean

compile: $(MAIN) $(TEST_EVAL) $(TEST_SORT)

$(MAIN): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(MAIN)

$(TEST_EVAL): $(TEST_EVAL_SRCS)
	@$(CXX) $(CXXFLAGS) $(TEST_EVAL_SRCS) -o $(TEST_EVAL)

$(TEST_SORT): $(TEST_SORT_SRCS)
	@$(CXX) $(CXXFLAGS) $(TEST_SORT_SRCS) -o $(TEST_SORT)

run:
	@./$(MAIN)

clean:
	@rm -rf $(MAIN) $(TEST_EVAL) $(TEST_SORT) main.dSYM test_sorting.dSYM test_evaluator.dSYM

test: test_compile test_run test_clean

test_compile: $(TEST_EVAL) $(TEST_SORT)

test_run:
	@./$(TEST_EVAL)
	@./$(TEST_SORT)

test_clean:
	@rm -f $(TEST_EVAL) (TEST_SORT)

.PHONY: all compile run clean test test_compile test_run test_clean
