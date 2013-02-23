CC = g++
LIBS = -lncurses
CFLAGS = -Wall $(LIBS)
EXE = main
OBJS = *.o
SRCS = *.cpp

all: compile
	$(CC) $(LIBS) -o $(EXE) $(OBJS)
	
compile: 
	$(CC) $(CLFAGS) -c $(SRCS)

clean:
	rm -f $(EXE) $(OBJS)
