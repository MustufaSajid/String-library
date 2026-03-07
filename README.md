# C String Library

A simple C library implementing common string functions with safe behavior and extensive unit tests.

---

## Features

This library provides custom implementations of:

- `my_strcmp`, `my_strncmp` — Compare strings
- `my_strcpy`, `my_strncpy` — Copy strings safely
- `my_strcat` — Concatenate strings with buffer checks
- `reverse` — Reverse a string in-place
- `my_split` — Split a string by a delimiter into a dynamically allocated array of strings

All functions handle edge cases, such as `NULL` pointers, empty strings, buffer size limits, and more.

---

## Project Structure

```
.
├── include/
│   ├── my_string.h      # Main library header
│   ├── common.h         # Common test utilities
│   └── acutest.h        # Testing framework
├── src/
│   └── main.c           # Library implementations
├── tests/
│   ├── test_strcmp.c
│   ├── test_strcat.c
│   ├── test_strcpy.c
│   ├── test_strncmp.c
│   ├── test_strncpy.c
│   ├── test_reverse.c
│   └── test_split.c
├── Makefile
└── README.md
```

---

## Requirements

- **GCC** or compatible C compiler (tested on MinGW)
- **Make** or compatible build tool

---

## Building

Compile the library and build all tests:

```bash
make
```

Or build just the tests:

```bash
make tests
```

---

## Testing

Run all tests:

```bash
make run-tests
```

Run a specific test:

```bash
make run-test TEST=test_strcmp
```

Available tests: `test_strcmp`, `test_strcpy`, `test_strcat`, `test_strncmp`, `test_strncpy`, `test_reverse`, `test_split`

---

## Cleaning

Remove build artifacts:

```bash
make clean
```

---

## License

[Add license information if applicable]


