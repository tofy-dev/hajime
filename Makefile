INCLUDE+=-I. -Iutils -Isource-sdk -Iinterfaces

CXX_FLAGS+=-O3
CXX_FLAGS+=-pipe
CXX_FLAGS+=-m32
CXX_FLAGS+=-fPIC
CXX_FLAGS+=--std=c++20

LDLIBS+=-lm
LDLIBS+=-lstdc++
LDLIBS+=-ldl
LDLIBS+=-shared

OUT:=hjm
SDK:=$(basename $(wildcard source-sdk/*.cc))
INT:=$(basename $(wildcard interfaces/*.cc))
UTL:=$(basename $(wildcard utils/netvars/*.cc))

SDK_objs:=$(addprefix ../bin/, $(addsuffix .o, $(SDK)))
INT_objs:=$(addprefix ../bin/, $(addsuffix .o, $(INT)))
UTL_objs:=$(addprefix ../bin/, $(addsuffix .o, $(UTL)))
OBJS:=$(SDK_objs) $(INT_objs) $(UTL_objs)


.PHONY: init all

# resetting
all: $(init) $(OUT)

$(OUT): $(OBJS)
	g++ $(CXX_FLAGS) $(OBJS) $(INCLUDE) main.cc \
		$(LDLIBS) -o ../bin/hajime.so
	# g++ $(SDK_objs) -m32 --std=c++20 -O3 -pipe -o ../bin/hajime.elf

../bin/source-sdk/%.o: source-sdk/%.cc
	g++ $(CXX_FLAGS) $(INCLUDE) -o $@ -c $<

../bin/interfaces/%.o: interfaces/%.cc
	g++ $(CXX_FLAGS) $(INCLUDE) -o $@ -c $<

../bin/utils/netvars/%.o: utils/netvars/%.cc
	g++ $(CXX_FLAGS) $(INCLUDE) -o $@ -c $<


# create dirs
init:
	mkdir ../bin/source-sdk/
	mkdir ../bin/interfaces/
	mkdir ../bin/utils/
	mkdir ../bin/utils/netvars/


# soft resetting
clean:
	find ../bin -name '*.*' -delete
# hard resetting
CLEAN:
	rm -rf ../bin/*
