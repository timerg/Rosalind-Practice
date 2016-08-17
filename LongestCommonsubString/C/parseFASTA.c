#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseFasta.h"





FastaList* newFastal(){
    FastaList* list = malloc(sizeof(FastaList));
    list -> type = NIL;
    return list;
}

void freeFastal (FastaList* list){
    if(list -> type == NIL){
        free(list);
    } else {
        freeFastal(list -> next);
        free_list(list -> content);
        free(list);
    }
}

FastaList* consFastal(int number, Node* content, FastaList* list){
    FastaList* new = newFastal();
    new -> type = CONS;
    new -> number = number;
    new -> content = content;
    new -> next = list;
    return new;
}


void fgetc_size(char* str, int size, FILE* stream){
    int i = 0;
    int n = size;
    while(n != 0){
        *(str + i) = fgetc(stream);
        n--;
    }
}


int parseFasta(FILE* input){
    char string[8];
    int number;
    fgetc_size(string, 8, input);
    if(strcmp(string, "Rosalind_")){
        fscanf(input, "%d", &number);
        return number;
    } else{
        printf("[PARSE]: Name ParseError\n");
        exit(4);
    }
}


Node* parseDNA (FILE* input){
    int length = 0;
    int base;
    Node* inputList = newNode();
    while((base = fgetc(input)) != EOF && base != '>'){
        if (base != '\n'){
            inputList = cons(base, inputList);
            length = length + 1;
        }
    }
    inputList = cons('$', cons(length, inputList));
    return inputList;

}


FastaList* parseFile(FILE* input){
    FastaList* fastaList = newFastal();
    int number;
    int base;
    base = fgetc(input);
    if(base != '>'){
        printf("[PARSE] Not a Correct Parsing Start.\n");
    }
    base = fgetc(input);

    loop:
        number = parseFasta(input);
        Node* content = parseDNA(input);
        fastaList = consFastal(number, content, fastaList);
        if((base = getc(input)) != EOF){
            goto loop;
        } else {
            goto stop;
        }
    stop:
        return fastaList;
}

void print_list_number(FastaList* list){
    if(list -> type == NIL){
        printf("[]\n");
    } else {
        printf("%d ", list -> number);
        print_list_number(list -> next);
    }
}


// int main(){
//     FILE* input;
//     input = fopen("data", "r");
//     FastaList* fastaList = parseFile(input);
//
//     printf("%d\n", fastaList -> next -> next -> number);
//     print_listc(fastaList -> next -> next -> content);
//
//     // int base;
//     // base = fgetc(input);
//     // if(base != '>'){
//     //     printf("[PARSE] Not a Correct Parsing Start.\n");
//     // }
//     // printf("%d\n", parseFasta(input));
//     // print_listc(parseDNA(input));
//     // printf("%d\n", parseFasta(input));
//     // print_listc(parseDNA(input));
//
//     freeFastal(fastaList);
//     fclose(input);
// }
