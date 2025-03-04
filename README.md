# Number Parser

A simple C++ application that reads a sequence of numbers from standard input, parses them, and outputs the parsed numbers.

## Project Description

Number Parser is designed to read numeric input from stdin where numbers are separated by whitespace, commas, or newlines. The program stores these numbers in a vector and then displays them.

## Building the Project

This project uses CMake as its build system. Follow these steps to build the project:

### Prerequisites

- CMake (version 3.10 or higher)
- C++ compiler with C++11 support (GCC, Clang, MSVC, etc.)

### Build Instructions

1. Clone or download this repository
2. Create a build directory (optional but recommended)
3. Run CMake to configure the project
4. Build the project

```bash
# Create a build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# On Windows with Visual Studio, you may use:
# cmake --build .
```

After successful compilation, you'll have an executable named `number_parser`.

## Usage

Run the program and input numbers via standard input. The numbers can be separated by:
- Whitespace (spaces, tabs)
- Commas
- Newlines

The program will parse these numbers and output them.

### Example Usage

```bash
# Run the program
./number_parser
```

Then enter your numbers:
```
1 2 3
4,5,6
7
8
```

Press Ctrl+D (Unix) or Ctrl+Z (Windows) to signal the end of input.

The program will output:
```
Parsed numbers: 1 2 3 4 5 6 7 8
```

### Piping Input

You can also pipe data into the program:

```bash
echo "1 2 3,4,5 6" | ./number_parser
```

Or read from a file:

```bash
./number_parser < input_file.txt
```

## License

[Specify your license here, if applicable]

