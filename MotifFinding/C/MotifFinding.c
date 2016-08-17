#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// For practicing, I redundantly use Queue. A linked list is actually enough

// readc_and_compare(File* f, Que* q){
//     if((base = fgetc(target_file)) != EOF){
//         if(base == pop(q_source)){
//
//         }
//
//     } else {
//
//     }
//
// }

int* indices_list(int* inx, Node *n){
    if(n -> type != NIL){
        *inx = n -> val;
        return (indices_list(inx + 1, n -> next));
    } else return inx;
}

int* indices(Que *q, int l){
    int* indexQueue = malloc(l * sizeof(int));
    indices_list(indexQueue, q -> list);

    return indexQueue;
}

int* kmp_table(int* ss, int size){
    int* table = malloc(size * sizeof(int));
    table[0] = -1;
    table[1] = 0;
    int i = 0;
    int j = 2;
    while(j < size){
        if(ss[j - 1] == ss[i]){
            table[j] = i + 1;
            i = i + 1;
            j = j + 1;
        } else if(i > 0) {
            i = table[i];
        } else {
            table[j] = 0;
            j = j + 1;
        }
    }
    return table;
}
//
//  a|a|b|c|a|a|a|b|c
// -1 0 1 0 0 1 2 2 3
//  the j should go back to 1, this infomation is given at [3]

int kmp_search(int* ts, int* ss, int *table, int l_tag, int l_s, int start){
    int t = start;
    int s = 0;
    while(t + s < l_tag){
        if (ss[s] == ts[t + s]){
            if( s == l_s - 1) {
                return t;
            };
            s++;
        } else {
            if(table[s] > (-1)) {
                t = t + s - table[s];
                s = table[s];
            }
            else
            t = t + 1;
            s = 0;
        }
    }
    return l_tag;
}

Que* kmp_result(int* ts, int* ss, int *table, int l_tag, int l_s){
    Que* qout = new_Queue();
    int p = 0;
    while( p != l_tag){
        enque(p + 1, qout);  // The "1-based numbering" rule is used in here
        p = kmp_search(ts, ss, table, l_tag, l_s, p + 1);
    }
    return deque(qout);
}



int main(){
    FILE *target_file;
    target_file = fopen("data_target", "r");
    FILE *source_file;
    source_file = fopen("data_source", "r");

    if (!target_file) {
        printf("nothing exists in target\n");
        fclose(target_file);
        return 1;
    };
    if (!source_file) {
        printf("nothing exists in source\n");
        fclose(source_file);
        return 1;
    };

    Que *q_target = new_Queue();
    Que *q_source = new_Queue();
    int base;
    // int result;


    while((base = fgetc(source_file)) != EOF){
        q_source = enque(base, q_source);
    };

    int l_s = length_node(q_source -> list);
    int* q_source_index = indices(q_source, l_s);


    while((base = fgetc(target_file)) != EOF){
        q_target = enque(base, q_target);
    };
    int l_tag = length_node(q_target -> list);
    int* q_target_index = indices(q_target, l_tag);


    int* table = kmp_table(q_source_index, l_s);
    Que* result = kmp_result(q_target_index, q_source_index, table, l_tag, l_s);

    // for(int i = 0; i < l_s; i++){
    //     printf("%d ", table[i]);
    // }
    print_Queue(result);


    free(q_source_index);
    free(q_target_index);
    free(table);
    free_list(q_target);
    free_list(q_source);
    free_list(result);
    fclose(target_file);
    fclose(source_file);
    return 0;
}