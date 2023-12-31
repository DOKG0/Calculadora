################################################################

program   := Calculadora
compiler  := g++
flags     := -std=c++2a -fconcepts

Include_dir   := Calculadora
obj_dir   := Obj

src_files := $(shell find $(src_dir) -name "*.cpp" )
obj_files := $(patsubst $(src_dir)/%.cpp, $(obj_dir)/%.o, $(src_files) )

################################################################

$(obj_dir)/%.o: $(src_dir)/%.cpp
	@ mkdir -p $(@D)
	@ $(compiler) $(flags) -o $@ -c $<

################################################################

$(program): $(obj_files)
	@ $(compiler) $(flags) -o $(program) $^

################################################################

all: build

################################################################

build: $(program)

################################################################

run: $(program)
	@ ./$(program)

################################################################

clean:
	rm -f *.o

################################################################

rebuild: clean build clean

################################################################

.PHONY: all build clean rebuild run

################################################################
