INCLUDE+=-I. -Iutils -Isource-sdk -Iinterfaces -Ihooks -Ifeatures -I/usr/include/SDL2

CXX_FLAGS+=-O3
CXX_FLAGS+=-pipe
CXX_FLAGS+=-m32
CXX_FLAGS+=-fPIC
CXX_FLAGS+=--std=c++20

LDLIBS+=-lm
LDLIBS+=-lstdc++
LDLIBS+=-ldl
LDLIBS+=-shared
LDLIBS+=-static-libstdc++
LDLIBS+=-lGL
LDLIBS+=-lSDL2


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
