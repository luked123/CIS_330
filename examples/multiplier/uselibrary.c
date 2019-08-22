#include <multiplier.h>
#include <stdio.h>

/* Short demonstration using libraries and headers to compile a program 
 *
 * Terminal command is gcc -o mult_example uselibrary.c -I/Users/luke/CIS_330/multiplier/include -L/Users/luke/CIS_330/lib -libmultiplier
 
 */

int main(){
    printf("Twice 6 is %d, tripple 6 is %d\n", doubler(6), tripler(6)); 
}
