# Sorting-Complexity-Project

Class: CPSC 223  

Authors: Cooper Braun, Abby Fewel, Ayden Humphries, Navin Kunakornvanich

## Testing Sorting

To test both data type sorting implementations in test_sorting.cpp:

```C++
// Compile
g++ -std=c++17 test_sorting.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o test_sorting

// Run
./test_sorting
```

You can also use our makefile:

```C++
// Compile and run
make test_compile
./test_sorting
```

## Testing the Evaluator

To test the evaluator implementation in test_evaluator.cpp:

```C++
// Compile
g++ -std=c++17 test_evaluator.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o test_evaluator

// Run
./test_evaluator
```

You can also use our makefile:

```C++
// Compile and run
make test_compile
./test_evaluator
```

## Running the Evaluation

To run the full evaluation using main.cpp:

```C++
// Compile
g++ -std=c++17 main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o main

// Run
./main
```

You can also use our makefile:

```C++
// Compile and run
make compile
./main
```

## Running All Tests

To compile and run all tests and the main program with the makefile:

```C++
// Run everything
make all

// Run the tests only
make test
```