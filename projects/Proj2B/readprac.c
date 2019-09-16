/* Luke Donnelly
 * CIS 330 
 */ 


// Practicing and reading binary file
// Prints all numbers in file to check if answer is correct

#include <stdio.h>
#include <printf.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *f_in;
    int buff_size; 
    int *buffer;
    int i;  

    if(argc != 2 ){
        printf("Usage: %s <binaryfile>\n", argv[0]);
        exit(EXIT_FAILURE); 
    }

    f_in = fopen(argv[1], "rb"); 
    fseek(f_in, 0 , SEEK_END);
    buff_size = ftell(f_in);
    fseek(f_in, 0, SEEK_SET); 
    
    printf("Buff size is %d\n", buff_size); 

    buffer = (int *) malloc(buff_size); 
    
    fread(buffer, sizeof(int), buff_size, f_in); 
    
    printf("Contents are:"); 
    for(i = 0; i < (buff_size/ sizeof(int)); i++){
        if((i % 10) == 0){
            printf("\n"); 
        } 
        printf("%d ", buffer[i]); 
    }
    printf("\n");

    free(buffer); 
    fclose(f_in); 
}
