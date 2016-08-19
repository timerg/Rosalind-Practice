#include <stdlib.h>
#include <stdio.h>
#include "rnaSplice.h"

// Because the string need to be splice is ar the bottom of the FastaList, we need to pull it out.
FastaList* pullOutLast(FastaList* input){
    if(input -> next -> next -> type == NIL){
        FastaList* out = input -> next;
        input -> next = out -> next;
        out -> next = newFastal();
        return out;
    } else {
        return pullOutLast(input -> next);
    }
}

Node* findIntron(Node* string, Node* intron){
    Node* output = doKmp(string, intron);
    return output;
}

// prevent overlapped intro position.
// Ex:  string: UAGAGAC; word: AGA. The first word is at position 2 while the 2nd is at 4.
// Only the 1st is valid
// These actually should combine into Kmp searching
Node* checkIntroPos(Node* intronPos, int l_i){
    if(intronPos -> next -> type == NIL){
        return intronPos;
    } else{
        if(intronPos -> next -> val < intronPos -> val + l_i){
            intronPos = delete_at(1, intronPos);
        }
        return (checkIntroPos(intronPos -> next, l_i));
    }
}

Node* spliceIntron(Node* string, Node* intronPos, int l_i){
    print_list(intronPos);
    if(intronPos -> type == NIL){
        return string;
    } else {
        int count = l_i;
        while(count > 0){
            string = delete_at(intronPos -> val, string);
            count = count - 1;
        }
        return spliceIntron(string, intronPos -> next, l_i);
    }
}

Node* doSplice(Node* string, FastaList* input){
    if(input -> type == NIL) {
        return string;
    } else {
        int l_w = length(input -> content);
        Node* pos = findIntron(string, input -> content);
        pos = checkIntroPos(pos, l_w);
        string = spliceIntron(string, pos, l_w);
        free_list(pos);
        return doSplice(string, input -> next);
    }
}



int main() {
    FILE* data;
    data = fopen("data", "r");
    FastaList* input = parseFile(data);

    // Take out the string
    FastaList* theLast = pullOutLast(input);
    Node* dnaString = theLast -> content;
    freeFastal(theLast -> next);
    free(theLast);

    dnaString = doSplice(dnaString, input);
    dnaString = reverse(dnaString);


    FILE* outData;
    outData = fopen("data_out", "w");
    outData = fopen("data_out", "a");

    Node* base = dnaString;
    while (base -> type != NIL) {
        fputc(base -> val, outData);
        base = base -> next;
    }


    fclose(data);
    free_list(dnaString);
    freeFastal(input);
    return 0;
}