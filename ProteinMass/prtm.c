#include <stdlib.h>
#include <stdio.h>
#include "massTable.h"



int main() {

    double* table = readMassTable();

    FILE* data;
    data = fopen("data", "r");
    int base;
    double sum = 0;
    while((base = fgetc(data)) != EOF){
        sum = sum + table[base - 65];
    }
    printf("%lf\n", sum);
    fclose(data);
    return 0;
}