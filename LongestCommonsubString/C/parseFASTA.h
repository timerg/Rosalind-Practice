#ifndef _FASTA_
#define _FASTA_

// For function "parseDNA"; 1st elemnt is '$', 2nd elemnt is the length. the rest are the contents;


#include "linked.h"



typedef struct FastaList {
    int type;
    int number;
    Node* content;
    struct FastaList* next;
} FastaList;

FastaList* newFastal();
void freeFastal (FastaList* list);
FastaList* consFastal(int number, Node* content, FastaList* list);

void fgetc_size(char* str, int size, FILE* stream);
int parseFasta(FILE* input);
Node* parseDNA (FILE* input);
FastaList* parseFile(FILE* input);
void print_list_number(FastaList* list);

#endif