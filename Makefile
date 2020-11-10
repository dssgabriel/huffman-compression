CC = g++
DFLAGS = -Wall -Wextra -g
RFLAGS = -O2

MAIN = src/bin/
LIB = src/lib/
DEBUG = target/debug/
RELEASE = target/release/

# Create directories for binaries (if needed)
debug_dir:
	mkdir -p $(DEBUG)

release_dir:
	mkdir -p $(RELEASE) 

# Part 1
build: debug_dir
	$(CC) $(MAIN)part1_tests.cpp $(DFLAGS) -o $(DEBUG)part1_tests

run: build
	./$(DEBUG)part1_tests

gdb: build
	gdb ./$(DEBUG)part1_tests

vg: build
	valgrind --leak-check=full -v ./$(DEBUG)part1_tests

# Clean target directories
clean_debug:
	rm -Rf $(DEBUG)

clean_release:
	rm -Rf $(RELEASE)

clean:
	rm -Rf target/
