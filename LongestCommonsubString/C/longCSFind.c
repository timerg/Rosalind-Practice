// #define DEBUG
// #define DEBUGTIME

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "longCSFind.h"
#include "testFile.h"
#include "dbg.h"
// #include <time.h>




#define FAIL 0
#define PASS 1

int labelmatch(SNode* tree, Node* labelList){
    if(tree -> type == (NODE | KNOT)){
        if(length(labelList) == length(tree -> label)){
            return PASS;
        } else {
            return FAIL;
        }
    } else {
        printf("[CODEBUG]: This shold be NODE or KNOT but it's not.\n");
        exit(3);
    }
}




Node* longestCommon(SNode* tree, Node* labelList, Node* nowResult, Node* bestResult){
    debug("[longestCommon]: ___ \n");
    switch (tree -> type) {
        case ROOT:
            debug("A Root.\n");
            return longestCommonInChildrens(tree -> childrens, labelList, nowResult, bestResult);
        case NODE:
            debug("A Node.\n");
                debug("label match\n");
                nowResult -> val = nowResult -> val + 1;
                nowResult = insert_at(tree -> edge, 1, nowResult);
                if(nowResult -> val > bestResult -> val){
                    debug("The Best changes from %d to %d\n", bestResult -> val, nowResult -> val);
                    Node* hold = bestResult;
                    bestResult = copylist(nowResult);
                    free_list(hold);
                };
                debug("insert %c\n", tree -> edge);
                return longestCommonInChildrens(tree -> childrens, labelList, nowResult, bestResult);
            break;
        case KNOT:
            debug("A Knot.\n");
            nowResult -> val = nowResult -> val + 1;
            debug("insert %c\n", tree -> edge);
            nowResult = insert_at(tree -> edge, 1, nowResult);
            if(nowResult -> val > bestResult -> val){
                debug("The Best changes from %d to %d\n", bestResult -> val, nowResult -> val);
                Node* hold = bestResult;
                bestResult = copylist(nowResult);
                free_list(hold);
            };
            return longestCommon(tree -> childrens -> node, labelList, nowResult, bestResult);
            break;
        case LEAF:
            debug("A Leaf.\n");
            if(nowResult -> val < bestResult -> val){
                debug("Best is still Best.\n");
                free_list(nowResult);
                return bestResult;
            } else if(nowResult -> val == bestResult -> val){
                printf("Two String with same length. There might have multiple result. Keep the first one for now\n");
                free_list(nowResult);
                return bestResult;
            } else {
                printf("[CODEERROE]: Best Result is not best During Searcging.\n");
                exit(3);
            }
            break;
        default:
            printf("[CODEBUG]Some SNode don't have type\n");
            exit(3);
            break;
    }
}

Node* longestCommonInChildrens(ListOfSNode* childrens, Node* labelList, Node* nowResult, Node* bestResult){
    debug("[longestCommonInChildrens]: ___ \n");
    if(childrens -> type == NIL){
        free_list(nowResult);
        return bestResult;
    } else {
        switch (childrens -> node -> type) {
            case NODE:
            case KNOT:
                if(length(labelList) == length(childrens -> node -> label)){
                    Node* nowResultHolder = copylist(nowResult);
                    Node* nextBest = longestCommon(childrens -> node, labelList, nowResult, bestResult);
                    return longestCommonInChildrens(childrens -> next, labelList, nowResultHolder, nextBest);
                } else {
                    return longestCommonInChildrens(childrens -> next, labelList, nowResult, bestResult);
                }
                break;
            case LEAF:
                return longestCommonInChildrens(childrens -> next, labelList, nowResult, bestResult);
                break;
            default:
                printf("[CODEBUG]Some SNode don't have type\n");
                exit(3);
                break;
        }
    }
}


Node* findCommon(SNode* tree, Node* labelList){
    Node* initail = newNode();
    initail = cons(0, initail);
    Node* initailBest = newNode();
    initailBest = cons(0, initailBest);
    return longestCommon(tree, labelList, initail, initailBest);
}

SNode* constructTree(SNode* tree, FastaList* list){
    if(list -> type == NIL){
        return tree;
    } else {
        debug(" The input now is: %d\n", list -> number);
        int inputList_length = list -> content -> next -> val;

        // rmove the length information which is embedded in the cotent;
        Node* inputList = delete_at(1, list -> content);

        /* The index is needed
        to make comparison(new sufix compare with existed branches' prefix).
        Because the head of the new sufix is burried at the bottom of linked list(stack).
        This should be optimized by double Queue.
        */
        Node* index[(inputList_length)];
        indexNode(index, inputList, 0);

        int i = 1;
        while (i <= inputList_length) {
            createNode(tree, index, inputList, i, (list -> number));
            i = i + 1;
        }
        return constructTree(tree, list -> next);
    }
}

Node* constructLabel_(FastaList* list, Node* label){
    if(list -> type == NIL){
        label = reverse(label);
        return label;
    } else {
        label = cons(list -> number,  label);
        return constructLabel_(list -> next, label);
    }
}

Node* constructLabel(FastaList* list){
    Node* label = newNode();
    label = constructLabel_(list, label);
    label = reverse(label);   // To make the oreder same as content;
    return label;
}







int main() {
    FILE* file;
    file = fopen("sampleData", "r");
    // error happens after 1267
    // Build FASTA List
    FastaList* input = parseFile_withHead(file);
    // print_list_number(input);
    Node* labelList = constructLabel(input);

    // Build an empty tree
    SNode* tree = createRoot();

    test();
    tree = constructTree(tree, input);
    Node* output = findCommon(tree, labelList);


    int length = output -> val;
    output = pop(output);
    output = reverse(output);
    printf("The Result Length is %d\n", length);
    printf("With Result: ");
    print_listc(output);



    free_list(output);
    freeFastal(input);
    free_list(labelList);
    freeSNode(tree);

    fclose(file);
    return(0);
}