

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "testFile.h"




int runTest(FILE* file){


    FastaList* input = parseFile_withHead(file);
    Node* labelList = constructLabel(input);
    SNode* tree = createRoot();
    tree = constructTree(tree, input);
    Node* output = findCommon(tree, labelList);

    fclose(file);
    freeFastal(input);
    free_list(labelList);
    // print_list(tree -> label);
    freeSNode(tree);
    int outputVal = output -> next -> next -> val;
    free_list(output);
    return (outputVal);

}

void test(){


    char* filename[3] = {"./data_test/data0", "./data_test/data1", "./data_test/data2"};
    int result[3] = {67, 65, 155};
    for(int i = 0; i < 3; i++){

    printf("%s\n", filename[i]);
    FILE* file;
    file = fopen(filename[i], "r");

    int val = runTest(file);

    assert(val == result[i]);
    printf("Result: %d\n", val);
    }
}