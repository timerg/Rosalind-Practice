CFLAGS=-Wall -g
# ~/GitHub/DataStructure/linkedList -I~/GitHub/DataStructure/SufixTree -g
 # -g option adds the necessary debug information to your file for lldb.




all: rnaSplice

rnaSplice: linked.o parseFASTA.o

clean:
	rm -f linked.o parseFASTA.o
	rm -r linked parseFASTA

  # make can't see anything in the file for object.o,
  # but it does see an object.c file,
  # and it knows how to turn a .c into a .o, so it does that.
