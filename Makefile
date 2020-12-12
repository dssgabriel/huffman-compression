CC = g++
DFLAGS = -std=c++17 -Wall -Wextra -g
RFLAGS = -std=c++17 -O2

MAIN = src/bin/
LIB = src/lib/
TEST = src/test/
DEBUG = target/debug/
RELEASE = target/release/

ARCHIVE = dos-santos_marouani

# Run everything
run: build debug_1 debug_2
run_release: build_release release_1 release_2
# Build everything
build: build_1 build_2
build_release: build_release_1 build_release_2


### PART 1 ###
# Running
debug_1: build_1
	$(DEBUG)main1

release_1: build_release_1
	$(RELEASE)main1

# Compiling
build_1: debug_dir
	$(CC) $(MAIN)main1.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(TEST)PartOneTests.cpp $(DFLAGS) -o $(DEBUG)main1

build_release_1: release_dir
	$(CC) $(MAIN)main1.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(TEST)PartOneTests.cpp $(RFLAGS) -o $(RELEASE)main1

# Debugging
gdb_1: build_1
	gdb $(DEBUG)main1

vg_1: build_1
	valgrind --leak-check=full -v $(DEBUG)main1


### PART 2 ###
# Running
debug_2: build_2
	$(DEBUG)main2 .textfiles/test.txt

release_2: build_release_2
	$(RELEASE)main2 .textfiles/test.txt

# Compiling
build_2: debug_dir
	$(CC) $(MAIN)main2.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(LIB)PartTwo.cpp $(DFLAGS) -o $(DEBUG)main2

build_release_2: release_dir
	$(CC) $(MAIN)main2.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(LIB)PartTwo.cpp $(RFLAGS) -o $(RELEASE)main2

# Debugging
gdb_2: build_2
	gdb $(DEBUG)main2

vg_2: build_2
	valgrind --leak-check=full -v $(DEBUG)main2 .textfiles/test.txt


### MISC ###
# Create directories for binaries (if needed)
debug_dir:
	mkdir -p $(DEBUG)

release_dir:
	mkdir -p $(RELEASE)

# Clean target sub-directories
clean_debug:
	rm -Rf $(DEBUG)

clean_release:
	rm -Rf $(RELEASE)

# Clean all
clean:
	rm -Rf target/

# Create an archive of the project
archive: clean
	rm -Rf $(ARCHIVE).tar.gz
	mkdir -p $(ARCHIVE)
	cp -R src/ $(ARCHIVE)
	cp Makefile $(ARCHIVE)
	cp README.org $(ARCHIVE)
	cp listing.pdf $(ARCHIVE)
	cp compte-rendu.pdf $(ARCHIVE)
	cp -R graphics/ $(ARCHIVE)
	tar -czvf $(ARCHIVE).tar.gz $(ARCHIVE)
	rm -Rf $(ARCHIVE)
