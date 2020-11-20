CC = g++
DFLAGS = -std=c++17 -Wall -Wextra -g
RFLAGS = -std=c++17 -O2

MAIN = src/bin/
LIB = src/lib/
TEST = src/test/
DEBUG = target/debug/
RELEASE = target/release/

ARCHIVE = dos-santos_marouani

run: build
	./$(DEBUG)main1

run_release: build_release
	./$(RELEASE)main1

# Part 1
build: debug_dir
	$(CC) $(MAIN)main1.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(TEST)PartOneTests.cpp $(DFLAGS) -o $(DEBUG)main1

build_release: release_dir
	$(CC) $(MAIN)main1.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(TEST)PartOneTests.cpp $(RFLAGS) -o $(RELEASE)main1

# Debugging
gdb: build
	gdb ./$(DEBUG)main1

vg: build
	valgrind --leak-check=full -v ./$(DEBUG)main1

# Create directories for binaries (if needed)
debug_dir:
	mkdir -p $(DEBUG)

release_dir:
	mkdir -p $(RELEASE) 

# Clean target directories
clean_debug:
	rm -Rf $(DEBUG)

clean_release:
	rm -Rf $(RELEASE)

clean:
	rm -Rf target/

# Create an archive of the project
archive: clean
	mkdir -p $(ARCHIVE)
	cp -R src/ $(ARCHIVE)
	cp Makefile $(ARCHIVE)
	cp README.org $(ARCHIVE)
	cp listing.pdf $(ARCHIVE)
	cp compte-rendu.pdf $(ARCHIVE)
	tar -czvf $(ARCHIVE).tar.gz $(ARCHIVE)
	rm -Rf $(ARCHIVE)
