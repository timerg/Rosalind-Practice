#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"


int complement(int input)
{
    if(input == 'T') {
        return 'A';
    }  else if (input == 'C'){
        return 'G';
    }  else if (input == 'G'){
        return 'C';
    }  else if (input == 'A'){
        return 'T';
    }   else {
        return '\0';
    }

}
//

int main(){
    FILE *read_file;
    read_file = fopen("data", "r");
    FILE *write_file;
    write_file = fopen("data_new", "w");        // Clear the File
    // write_file = fopen("data_new", "a");

    if (!read_file) {
        printf("nothing exists\n");
        fclose(read_file);
        return 1;
    };

    Node* list = new();
    int base;
    while((base = fgetc(read_file)) != EOF){

        list = cons (complement(base), list);

    };

    while (list->type != NIL){
        fputc(list->val, write_file);
        list = list->next;
    };

    free_list(list);
    fclose(read_file);
    fclose(write_file);

}
