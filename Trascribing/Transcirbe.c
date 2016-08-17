#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int transcribe(int input)
{
    if(input == 'T') {
        return 'U';
    } else {
        return input;
    }

}
//

int main(){
    FILE *read_file;
    read_file = fopen("data", "r");
    FILE *write_file;
    write_file = fopen("data_new", "w");        // Clear the File
    write_file = fopen("data_new", "a");


    if (!read_file) {
        printf("nothing exists\n");
        fclose(read_file);
        return 1;
    };



    int base = 0;
    while((base = fgetc(read_file)) != EOF){
        base = transcribe(base);
        fputc(base, write_file);
    };
    fclose(read_file);
    fclose(write_file);

}


