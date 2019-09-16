/* Luke Donnelly
 * CIS 330
 * Making a copy program with read and write
 */

#include <stdio.h>
#include <printf.h>
#include <stdlib.h> 

int main(int argc, char *argv[]){
    FILE *f_in, *f_out;
    int buff_size;
    char *buffer; 

    if(argc != 3){
        printf("Usage: %s <file1> <file2>\n",argv[0]); 
        exit(EXIT_FAILURE);
    }

    f_in = fopen(argv[1], "r");
    fseek(f_in, 0, SEEK_END);
    buff_size = ftell(f_in);
    fseek(f_in, 0, SEEK_SET);
    
    buffer = (char *)  malloc(buff_size); 
    if(!fread(buffer, sizeof(char), buff_size, f_in)){
        printf("Failed to read file %s, exiting\n", argv[1]);
        free(buffer);  
        fclose(f_in);
        exit(EXIT_FAILURE);  
    }
    fclose(f_in);  

    printf("Copying %d bytes from %s to %s\n", buff_size, argv[1], argv[2]);

    f_out = fopen(argv[2], "w");
    if(!fwrite(buffer, sizeof(char), buff_size, f_out)){
        printf("Failed to write to %s, exiting\n", argv[2]);
        free(buffer);  
        fclose(f_out);
        exit(EXIT_FAILURE);  
    }
    fclose(f_out); 

    printf("Copy successful, cleaning up and exiting program\n");
    free(buffer); 

    return 0; 
}
