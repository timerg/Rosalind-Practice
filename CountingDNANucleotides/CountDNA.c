#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int *x;      // you declare a pointer x   (but it hasn't point to anywhere. These should only happen in function's parameter declare)
// Error:
    // int *x = 3;  // Since the pointer is ambiguous, you can't do so
// int x = 2;       // you declare a memory x(you need to give it value)


typedef void (*countDNA)(int input, int *num);

int DNANum(int *num, int input, countDNA aFunc){

// by declare *num: you telling the fun that a memory that is pointed is given to you.
// num is the name of "position"
    aFunc(input, num);
    return *num;
}

// countA : int -> Pointer int -> ()
// *_ : \forall {A} -> Pointer A -> A
// &_ : \forall {A} -> A -> Pointer A
// num : Pointer int
// *num : int
void countA(int input, int *num)
{
    if(input == 'A') {
        *num = *num + 1;
    }
}

void countT(int input, int *num)
{
    if(input == 'T') {
        *num = *num + 1;
    }
}

void countC(int input, int *num)
{
    if(input == 'C') {
        *num = *num + 1;
    }
}

void countG(int input, int *num)
{
    if(input == 'G') {
        *num = *num + 1;
    }
}


int main(){
    FILE *read_file;
    read_file = fopen("data", "r");
    FILE *write_file;
    write_file = fopen("data_new", "w");


    int a = 0;
    int t = 0;
    int c = 0;
    int g = 0;
    if (!read_file) {
        printf("nothing exists\n");
        fclose(read_file);
        return 1;
    };

    int fileC = 0;
    while((fileC = fgetc(read_file)) != EOF){
        DNANum(&a, fileC, countA);
        DNANum(&c, fileC, countC);
        DNANum(&t, fileC, countT);
        DNANum(&g, fileC, countG);

        // countA(fileC, &a);
    };
    fclose(read_file);
    fclose(write_file);
    printf("%d\n", a);
    printf("%d\n", c);
    printf("%d\n", g);
    printf("%d\n", t);

}


// Mutiple line acquire:
    // the function fget will return 0 if encounter EOF(end of file) message.
    // By man: fgets stops when 1. a newline character is found, 2. at end-of-file or
    //  3. error.
    // When the function stop, the pointer also stop also stop "at the position where the pointer itself is".
    // This is important. That means, if one calls the function again, the function start at the place it stopped last time
    // as long as one didn't use fclose to reboot the file.
    // So we can use while loop to read and write the whole file

    // char line[1000];
    // while(fgets(line, 1000, file)){
    //     // printf("%s\n", line);
    //     fputs(line, file_new);
    // };
    // printf("%d\n", 'a');




// Thing about feof: "the last line of the file will be handled twice"
// http://stackoverflow.com/questions/21180248/fgets-to-read-line-by-line-in-files
// http://www.programmer-club.com.tw/showsametitlen/c/39966.html
