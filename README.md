# GetHub

A lightweight, GitHub-inspired repository management simulator built in C++. GetHub demonstrates object-oriented programming, linked list data structures, dynamic memory management, and client-side repository cloning.

Originally developed as a university project at Carleton University and subsequently enhanced to improve reliability, usability, portability, and automated testing.

## Features

- Browse and manage repositories
- View repository files and their contents
- Remove repositories and individual files
- Clone repositories into an independent local client
- Maintain client copies after server-side repository deletion
- Validate user input and handle invalid operations

## Technologies

- C++
- Object-oriented programming
- Linked lists
- Dynamic memory management
- Makefile
- Docker
- GitHub Actions
- AddressSanitizer

## Getting Started

### Run Locally

Requirements: a C++ compiler and Make.

```bash
make
./a3
```

### Run with Docker

```bash
docker build -t gethub .
docker run --rm -it gethub
```

Docker provides a consistent Linux environment without requiring a local C++ compiler.

## Testing

Run the test suite locally:

```bash
./a3test
```

Or inside Docker:

```bash
printf '6\n0\n' | docker run --rm -i gethub ./a3test
```

The application passed all five existing automated tests with a weighted score of 25/25, both locally and inside Docker.

## Continuous Integration

A GitHub Actions workflow is configured to:

- Build the application inside Docker
- Execute automated tests
- Verify the expected test results
- Report build and test failures

## Project Improvements

Following the original academic implementation, the project was enhanced with:

- Memory management fixes
- Completed client-side functionality
- Improved input validation and error handling
- AddressSanitizer testing
- Docker containerization
- Automated continuous integration configuration

## Project Scope

GetHub is an educational repository management simulator. It operates on local sample data and does not connect to the GitHub API or modify real GitHub repositories.