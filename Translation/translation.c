#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dbg.h"

int main(){

    FILE *file;
    file = fopen("data_input", "r");
    FILE *output_file;
    output_file = fopen("data_output", "w");
    output_file = fopen("data_output", "a");
    char *bases = malloc(sizeof(char) * 4);
    if(file == NULL){
        printf("No File exist\n");
        exit(1);
    }
    while(fgets(bases, 4, file)){
        // printf("%c\n", bases[0]);
        if (bases[0] == 'U'){
            if (bases[1] == 'U'){
                if (bases[2] == 'U'){
                    fputs("F", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("L", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("F", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("L", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'A'){
                if (bases[2] == 'U'){
                    fputs("Y", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("\n", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("Y", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("\n", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'C'){
                if (bases[2] == 'U'){
                    fputs("S", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("S", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("S", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("S", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'G'){
                if (bases[2] == 'U'){
                    fputs("C", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("\n", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("C", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("W", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else {
                printf("Wrong Input\n");
            }

        }   else if(bases[0] == 'A'){
            if (bases[1] == 'U'){
                if (bases[2] == 'U'){
                    fputs("I", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("I", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("I", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("M", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'A'){
                if (bases[2] == 'U'){
                    fputs("N", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("K", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("N", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("K", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'C'){
                if (bases[2] == 'U'){
                    fputs("T", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("T", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("T", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("T", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'G'){
                if (bases[2] == 'U'){
                    fputs("S", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("R", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("S", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("R", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else {
                printf("Wrong Input\n");
            }

        }   else if(bases[0] == 'C'){
            if (bases[1] == 'U'){
                if (bases[2] == 'U'){
                    fputs("L", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("L", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("L", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("L", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'A'){
                if (bases[2] == 'U'){
                    fputs("H", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("Q", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("H", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("Q", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'C'){
                if (bases[2] == 'U'){
                    fputs("P", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("P", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("P", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("P", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'G'){
                if (bases[2] == 'U'){
                    fputs("R", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("R", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("R", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("R", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else {
                printf("Wrong Input\n");
            }

        }   else if(bases[0] == 'G'){
            if (bases[1] == 'U'){
                if (bases[2] == 'U'){
                    fputs("V", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("V", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("V", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("V", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'A'){
                if (bases[2] == 'U'){
                    fputs("D", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("E", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("D", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("E", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'C'){
                if (bases[2] == 'U'){
                    fputs("A", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("A", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("A", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("A", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else if(bases[1] == 'G'){
                if (bases[2] == 'U'){
                    fputs("G", output_file);
                }   else if(bases[2] == 'A'){
                    fputs("G", output_file);
                }   else if(bases[2] == 'C'){
                    fputs("G", output_file);
                }   else if(bases[2] == 'G'){
                    fputs("G", output_file);
                }   else {
                    printf("Wrong Input\n");
                }

            }   else {
                printf("Wrong Input\n");
            }

        }   else {
            // printf("Wrong Input\n");
        }
    }

    free(bases);
    fclose(file);
    fclose(output_file);
    return 0;
}