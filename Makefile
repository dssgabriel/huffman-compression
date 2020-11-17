CC = g++
DFLAGS = -Wall -Wextra -g
RFLAGS = -O2

MAIN = src/bin/
LIB = src/lib/
TEST = src/test/
DEBUG = target/debug/
RELEASE = target/release/

ARCHIVE = dos-santos_marouani

# Create directories for binaries (if needed)
debug_dir:
	mkdir -p $(DEBUG)

release_dir:
	mkdir -p $(RELEASE) 

# Part 1
build: debug_dir
	$(CC) $(MAIN)main1.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(TEST)PartOneTests.cpp $(DFLAGS) -o $(DEBUG)main1

run: build
	./$(DEBUG)main1

gdb: build
	gdb ./$(DEBUG)main1

vg: build
	valgrind --leak-check=full -v ./$(DEBUG)main1

# Clean target directories
clean_debug:
	rm -Rf $(DEBUG)

clean_release:
	rm -Rf $(RELEASE)

clean:
	rm -Rf target/

archive: clean
	mkdir -p $(ARCHIVE)
	cp -R src/ $(ARCHIVE)
	cp Makefile $(ARCHIVE)
	cp README.org $(ARCHIVE)
	tar -zcvf $(ARCHIVE).tar $(ARCHIVE)
	rm -Rf $(ARCHIVE)
