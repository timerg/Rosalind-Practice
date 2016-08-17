#include <stdlib.h>
#include <stdio.h>
// #include "linked.h"






int main() {
    FILE *source_file;
    source_file = fopen("data_source", "r");
    FILE *target_file;
    target_file = fopen("data_target", "r");

    int base_s;
    int base_tag;
    int count = 0;
    // Node *source = new();
        // Node *source = new();
    while((base_s = fgetc(source_file)) != EOF &&
        (base_tag = fgetc(target_file)) != EOF){
            if(base_s != base_tag) count = count + 1;
    }
    printf("%d\n", count);



    // free_list(source);
    fclose(source_file);
    fclose(target_file);
    return 0;
}