INCLUDE+=-I. -Iutils -Isource-sdk -Iinterfaces -Ihooks -Ifeatures -I/usr/include/SDL2

CXX_FLAGS+=--std=c++20
CXX_FLAGS+=-fPIC
CXX_FLAGS+=-m32
CXX_FLAGS+=-ggdb3

LDLIBS+=-shared
LDLIBS+=-ldl
LDLIBS+=-lSDL2
LDLIBS+=-lGL

name := hajime
dest := ../bin
source := $(shell find -name "*.cc" | cut -b 3-)
objects := $(addprefix $(dest)/, $(patsubst %.cc, %.o, $(source)))
target := hl2_linux

# Default target
all: $(dest)/$(name).so

# Rule to build the final executable/library
$(dest)/$(name).so: $(objects)
	g++ $(CXX_FLAGS) $(objects) $(LDLIBS) -o $@

# Pattern rule to build object files
$(dest)/%.o: %.cc
	mkdir -p $(dir $@)
	g++ $(CXX_FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(dest)/*
