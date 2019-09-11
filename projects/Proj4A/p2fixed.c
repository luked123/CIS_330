// The author believes it has <5> memory errors

#include <stdio.h>
#include <stdlib.h>

int main(){

	int var;
	int arr[3];
	arr[0] = 12;
	arr[1] = 15;
	arr[2] = 18;
	// var = arr[3]; Original statement
    var = arr[2]; // added statement


	char *ptr;

	ptr =  (char *)malloc(sizeof(char)*11);

	free (ptr); 
	// free (ptr); Original statement

	int array[3];
	array[0] = 12;
	array[1] = 5;
	array[2] = 6;

	// free (array); Original statement

	// char *ptr1 = NULL; Original statement
    char *ptr1 = (char *) malloc(16 * sizeof(char)); 
    ptr1[0] = 'C';
    ptr1[1] = 'O';
    ptr1[2] = '\0';
	printf("%s\n", ptr1);
	ptr1[1] = 'Q'; // Original statment but can remain now

    free(ptr1); 

	int *ptr3 = malloc(3*sizeof(int));
	//  int var1 = ptr[3];  Original statment
    int i; 
    for(i = 0; i < 3; i++){
        ptr3[i] = 0; 
    }

    int var1 = ptr3[2]; 
    free(ptr3); 

};
