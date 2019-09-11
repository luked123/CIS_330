// Luke Donnelly
// CIS_330
// Character string examples with pointers

#include <stdio.h>


int main(){
    
    char str[12] = "hello world"; //make sure to create enough room for the null char
    char *str2 = str +6;

    printf("str is \"%s\" and str2 is \"%s\"\n", str, str2);

    str[5] = '\0'; // end of line char

    printf("Now str is \"%s\" and str2 is \"%s\"\n", str, str2);
    printf("First char of str is %c\n", str[0]); 

}
