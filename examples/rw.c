/* Luke Donnelly
 * CIS 330
 * Read and Write example
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    char *hello = "hello world: file edition\n";
    FILE *f = fopen("writeExample", "w");

    
    //fwrite(const void *restrict ptr, size_t size, size_t nitems,
    // FILE *restrict stream); 
    fwrite(hello, sizeof(char), strlen(hello), f);
    fclose(f);  
}
