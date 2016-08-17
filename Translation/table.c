#include <stdlib.h>
#include <stdio.h>
// #include "dbg.h"


const int NIL = 0;
const int NODE = 1;

typedef struct Node {
    int nodeType;
    char AA;
    struct Node *branch_A;
    struct Node *branch_U;
    struct Node *branch_C;
    struct Node *branch_G;
} Node;

Node* new(){
    Node* node = malloc(sizeof(Node));
    node -> nodeType = NIL;
    return node;
}

void free_tree(Node* xs) {
    if (xs -> nodeType == NIL) {
        // Nil
        free(xs);
    } else {
        // Cons
        free_tree(xs -> branch_A);
        free_tree(xs -> branch_U);
        free_tree(xs -> branch_C);
        free_tree(xs -> branch_G);
        free(xs);
    }
}

Node* createBranch(char base, Node* xs) {
    Node* node = malloc(sizeof(Node));
    xs -> nodeType = NODE;
    node -> nodeType = NIL;
    switch (base) {
        case 'A':
            xs -> branch_A = node;
            break;
        case 'U':
            xs -> branch_U = node;
            break;
        case 'C':
            xs -> branch_C = node;
            break;
        case 'G':
            xs -> branch_G = node;
            break;
        default:
            printf("Wrong input\n");
            break;
    }
    return xs;
}

Node* createLeaf(char aa, Node* xs) {
    xs -> nodeType = NIL;
    xs -> AA = aa;
    return xs;
}

Node* buildTree(FILE* file ){
    int x = 0;
    Node* tree = new();

    char *bases = malloc(sizeof(char) * 10);
    while(fgets(bases, 10, file)){

        // for (int i = 0; i < 3; i++){
        //     createBranch(bases[i], tree);
        // };

        for(int j = 0; j < 6; j++){
            printf("%c", bases[j]);
        };
        printf("\n");



        x++;
    }
    free(bases);
    return tree;
}


int main(){
    FILE *file;
    file = fopen("transTable", "r");

    Node* tree = buildTree(file);
    free_tree(tree);
    // printf("%d\n", out);

    fclose(file);
    return 0;
}

//