/* Luke Donnelly
 * CIS 330
 * Project 2B
 */ 

#include <stdio.h>
#include <printf.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE *f_in, *f_out; 
    int buffer_size; 
    int *buffer;
    int i, j;  

    if(argc != 3){
        printf("Usage: %s <file 1> <file 2>\n", argv[0]);
        exit(EXIT_FAILURE); 
    }

    // Opening the binary file and getting correct buffer size
    f_in = fopen(argv[1], "rb");
    fseek(f_in, 0, SEEK_END); 
    buffer_size = ftell(f_in) / 4; //Size of 1/4th the data
    fseek(f_in, 0, SEEK_SET);
    
    buffer = (int *) malloc(buffer_size); 
    
    // Reading the 5x5 bottom left corner of the array
    for(i = 0; i < 5; i++){
        for( j = 0; j < 5; j++){
            fseek(f_in,  (i*10 + j)* sizeof(int), SEEK_SET);
            fread(buffer + (i*5) + j, sizeof(int), 1, f_in);
        }
    }    
    
    // Writing to file one integer per line
    f_out = fopen(argv[2], "w"); 
    for(i = 0; i < 25; i++){
        fprintf(f_out, "%d\n", *(buffer + i)); 
    }

    fclose(f_in);
    fclose(f_out); 
    free(buffer);

    return 0; 
}

