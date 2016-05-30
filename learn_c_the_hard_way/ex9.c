#include <stdio.h>

int
main(int argc, char *argv[]) {
  int numbers[4] = {1};
  char name[4] = {'a'};

  //first, print then out raw
  printf("numbers: %d %d %d %d\n",
          numbers[0], numbers[1],
          numbers[2], numbers[3]);

  printf("name each: %c %c %c %c\n",
          name[0], name[1],
          name[2], name[3]);

  printf("name: %s\n", name);

  //setup the numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  //setup the name
  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = '\0';

/*
http://stackoverflow.com/questions/671703/array-index-out-of-bound-in-c
The problem is that C/C++ doesn't actually do any boundary checking with regards to arrays. 
It depends on the OS to ensure that you are accessing valid memory.

In this particular case, you are declaring a stack based array. 
Depending upon the particular implementation, accessing outside the bounds of the array 
will simply access another part of the already allocated stack space (most OS's and threads reserve 
a certain portion of memory for stack). As long as you just happen to be playing
around in the pre-allocated stack space, everything will not crash (note i did not say work).

What's happening on the last line is that you have now accessed beyond the part of memory 
that is allocated for the stack. As a result you are indexing into a part of memory that 
is not allocated to your process or is allocated in a read only fashion. 
The OS sees this and sends a seg fault to the process.

This is one of the reasons that C/C++ is so dangerous when it comes to boundary checking.
*/

  // then print them out initialized
  printf("numbers: %d %d %d %d\n",
          numbers[0], numbers[1],
          numbers[2], numbers[3]);
        
  printf("name each: %c %c %c %c\n",
          name[0], name[1],
          name[2], name[3]);

  //print the name like a string
  printf("name: %s\n", name);

  // another way to use name
  char *another = "Zed";

  printf("another: %s\n", another);

  printf("another each: %c %c %c %c\n",
          another[0], another[1],
          another[2], another[3]);

  return 0;
}






