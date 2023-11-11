#include <stdlib.h>
#include <stdio.h>
#include "../headers/list.h"

void generateBinaryFile (List *data){

    FILE *file = fopen("files/binary/data.bin", "wb");
    Product *product = data->head;

    if(file == NULL){
        printf("ERROR: Could not open file.\n");
        return;
    }

    while(product != NULL){
        fwrite(product, sizeof(Product), 1, file);
        product = product->next;
    }

    fclose(file);
}

void generateTextFile (char* file_name){

    FILE *binary_file = fopen(file_name, "rb");
    FILE *text_file = fopen("files/text/data.txt", "w");
    Product *product = (Product*) malloc(sizeof(Product));

    if(binary_file == NULL){
        printf("ERROR: Could not open file.\n");
        return;
    }

    while(fread(product, sizeof(Product), 1, binary_file)){
        fprintf(text_file, "%d %d %.2f\n", product->id, product->amount, product->price);
    }

    fclose(binary_file);
    fclose(text_file);
    free(product);

}