FILES.c = main.c chorus.c pre_chorus.c verse.c bridge.c intro.c ui_tools.c
FILES.o = $(FILES.c:.c=.o)
CLEAN_SPECIFICATION = *.o *.exe *.stackdump

DEBUG_FLAG = -g
OPTIMIZATION = -O0
CFLAGS = -c -Wall -std=c17
EXE_NAME = program

default: build
	./$(EXE_NAME).exe

build: $(FILES.o)
	gcc $(FILES.o) -o $(EXE_NAME).exe

all: clean build
	echo
	./$(EXE_NAME).exe

debug: clean build

main.o: main.c
	gcc $(DEBUG_FLAG) $(CFLAGS) $(OPTIMIZATION) main.c

ui_tools.o: UI_tools.c
	gcc $(DEBUG_FLAG) $(CFLAGS) $(OPTIMIZATION) ui_tools.c

chorus.o: chorus.c
	gcc $(DEBUG_FLAG) $(CFLAGS) $(OPTIMIZATION) chorus.c

pre_chorus.o: pre_chorus.c
	gcc $(DEBUG_FLAG) $(CFLAGS) $(OPTIMIZATION) pre_chorus.c

bridge.o: bridge.c
	gcc $(DEBUG_FLAG) $(CFLAGS) $(OPTIMIZATION) bridge.c

intro.o: intro.c
	gcc $(DEBUG_FLAG) $(CFLAGS) $(OPTIMIZATION) intro.c

verse.o: verse.c
	gcc $(DEBUG_FLAG) $(CFLAGS) $(OPTIMIZATION) verse.c



clean:
	$(RM) *.exe *.o *.stackdump