CC=clang
CFLAGS=-MMD -Wall -Wextra -pedantic -std=c11
EXE=tutorial
LIBS=$(addprefix -l,)

SRC=$(wildcard src/*.c)
OBJ=$(SRC:%.c=%.o)
DEP=$(OBJ:%.o=%.d)

all: debug

debug: CFLAGS += -g
debug: $(EXE)

remake: clean debug
.NOTPARALLEL: remake

release: CFLAGS += -O3 -DNDEBUG
release: clean $(EXE)
.NOTPARALLEL: release

clean: 
	rm -f $(OBJ) $(DEP) $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

-include $(DEP)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
