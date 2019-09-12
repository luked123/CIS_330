// The author believes it has <1> memory errors
#include <stdio.h>
#include <stdlib.h>

int
add(char *operand1, char *operand2, char **answer)
{
    int length1 = 0;
    int length2 = 0;
    while(*(operand1 + length1) != '\0') {
        length1++;
    }
    while(*(operand2 + length2) != '\0') {
        length2++;
    }

    int larger = length1 < length2 ? length2 : length1;
    int i;
    int tempInt1 = 0; 
    int tempInt2 = 0;
    int value = 0;
    int total = 0; 
    int remainder = 0;
    char solution[1024]; // do not need to allocate on heap as it is temporary

    for(i = 0; i < 1024; i++){
        solution[i] = '\0';
    }

    for (i = 0; i < larger; i++) {
        if(i < length1){
            tempInt1 = *(operand1 + (length1 - (i + 1))) - 48; // Second error causes an out of bounds memory read because of larger statement
        }
        if( i < length2){
            tempInt2 = *(operand2 + (length2 - (i + 1))) - 48;
        }

        total = tempInt1 + tempInt2 + remainder;
        tempInt1 = 0; // resest temp values 
        tempInt2 = 0; 
        // remainder = remainder + (total / 10); // Calculates remainder wrong
        remainder = (total / 10); 
        value = (total % 10) + 48; 
       //  *(solution + i) = (total % 10) + 48; Original statement, unnecessary repitition
        solution[i] = value; 
    }

    int answerLength = 0;
    while (solution[answerLength] != '\0') {
        answerLength++;
    } 
    char *answerTemp = malloc(sizeof(char)*(answerLength + 1));

    for(i = 0; i < answerLength + 1; i++){         // Initializing memory
        *(answerTemp + i) = '\0'; 
    }
    
    for (i = 0; i < answerLength; i++) {
        *(answerTemp + (answerLength - (i+1))) = solution[i];
    }
    *answer = answerTemp;
    // free(answerTemp); // Cause of first error causes a free memory read.

    return 0;
}

int
main(int argc, char *argv[])
{
    char *operand1 = "12345";
    char *operand2 = "46832798";
    char *answer;

    add(operand1, operand2, &answer);
    printf("This answer is incorrect, your task is to figure out why.\n");
    printf("%s + %s = %s\n", operand1, operand2, answer);
    free(answer); // Third error, freeing unallocated memory. 
    return 0;
}
