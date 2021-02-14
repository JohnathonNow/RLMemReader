all: rlreader.exe

.PHONY: all clean

rlreader.exe: main.o proc.o rlproc.o
	g++ -o $@ $^

proc.o: Proc/Proc.cpp Proc/Proc.h
	g++ -c -o $@ $<

rlproc.o: Proc/RLProc.cpp Proc/RLProc.h
	g++ -c -o $@ $<

main.o: main.cpp
	g++ -c -o $@ $^

clean: 
	rm rlproc.o proc.o main.o rlreader.exe
