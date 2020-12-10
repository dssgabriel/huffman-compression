CC = g++
DFLAGS = -std=c++17 -Wall -Wextra -g
RFLAGS = -std=c++17 -O2

MAIN = src/bin/
LIB = src/lib/
TEST = src/test/
DEBUG = target/debug/
RELEASE = target/release/

ARCHIVE = dos-santos_marouani

run1: build1
	$(DEBUG)main1

run2: build2
	$(DEBUG)main2 textfiles/test.txt

run_release1: build_release1
	$(RELEASE)main1

run_release2: build_release2
	$(RELEASE)main2 textfiles/test.txt

build1: debug_dir
	$(CC) $(MAIN)main1.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(TEST)PartOneTests.cpp $(DFLAGS) -o $(DEBUG)main1

build2: debug_dir
	$(CC) $(MAIN)main2.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(DFLAGS) -o $(DEBUG)main2

build_release1: release_dir
	$(CC) $(MAIN)main1.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(TEST)PartOneTests.cpp $(RFLAGS) -o $(RELEASE)main1

build_release2: release_dir
	$(CC) $(MAIN)main2.cpp $(LIB)Sommet.cpp $(LIB)ArbreB.cpp $(RFLAGS) -o $(RELEASE)main2

# Debugging
gdb1: build1
	gdb $(DEBUG)main1

gdb2: build2
	gdb $(DEBUG)main2

vg1: build1
	valgrind --leak-check=full -v $(DEBUG)main1

vg2: build2
	valgrind --leak-check=full -v $(DEBUG)main2 textfiles/test.txt

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
