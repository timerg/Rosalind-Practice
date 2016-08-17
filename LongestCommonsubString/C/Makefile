CFLAGS=-Wall -g
# ~/GitHub/DataStructure/linkedList -I~/GitHub/DataStructure/SufixTree -g
 # -g option adds the necessary debug information to your file for lldb.




all: longCSFind

longCSFind:	sufixTree.o linked.o parseFASTA.o testFile.o

parseFASTA: linked.o

clean:
	rm -f sufixTree.o linked.o parseFASTA.o testFile.o
	rm -r sufixTree linked parseFASTA testFile

  # make can't see anything in the file for object.o,
  # but it does see an object.c file,
  # and it knows how to turn a .c into a .o, so it does that.
