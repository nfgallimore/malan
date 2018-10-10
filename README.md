# Malan programming language
## Description
Malan is a simple C like programming language. It was designed in the Compiler Design course at the [University of Akron](uakron.edu) during the fall semester of 2018. The professor teaching the course is [Dr. Andrew Sutton](http://asutton.github.io/). The name of the language was inspired by Harvard University's Intro to Computer Science [CS50](cs50.net) instructor Dr. David Malan.

## Documentation
For language specifications please view [**this**](https://github.com/nfgallimore/malan/edit/master/README.md) document that was last updated on October 10th, 2018.  


## Compilation
To compile using cmake from the project directory execute the following command:

`mkdir build && cd build && cmake .. && make`

## Execution of sample programs constructed in the AST
To run the sample main file containing the AST examples make sure you are in the build directory and execute the following command:

Run `./main`

## Unit test suite
In order to run the unit tests please execute from the build directory:

`ctest`

Or find the appropriate file postfixed with `_t` for a more verbose run. For example to run unit tests for *expr.cpp* execute the binary file
`./expr_t` 
