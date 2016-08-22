#include <stdlib.h>
#include <stdio.h>


double* readMassTable(){
    FILE* table;
    table = fopen("table", "r");

    static double massTable[26] = {0};
    char base;
    double mass;
    while (fscanf(table, "%c %lf ", &base, &mass) != EOF){

        *(massTable + (base - 65)) = mass;
    }
    double* tablePointer = &massTable[0];
    fclose(table);
    return tablePointer;

}



// int main() {
//
//     double* table = readMassTable();
//     // for (int i  = 0; i < 26;){
//     //     printf("%d\n", i);
//         printf(" %lf\n", table[24]);
//     //     i = i + 1;
//     // }
//     return 0;
// }