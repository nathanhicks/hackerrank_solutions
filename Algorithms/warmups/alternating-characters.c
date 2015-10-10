/* Problem Statement
 *
 * Shashank likes strings in which consecutive characters are different.  For example, he likes
 * ABABA, while he doesn't like ABAA.  Given a string containing characters A and B only, he
 * wants to change it into a string he likes.  To do this, he is allowed to delete the characters
 * in the string.
 *
 * Your task is to find the minimum number of required deletions.
 *
 * Input Format
 *
 * The first line contains an integer T i.e. the number of test cases.
 * Next T lines contain a string each.
 *
 * Output Format
 * Print minimum number of required steps for each test case.
 *
 * Constraints
 * 1 <= T <= 10
 * 1 <= length of String <= 10^5
 *
 * Sample Input
 * 5
 * AAAA
 * BBBBB
 * ABABABAB
 * BABABA
 * AAABBB
 *
 * Sample Output
 * 3
 * 4
 * 0
 * 0
 * 4
 *
 * Explanation
 * AAAA ==> A, 3 deletions
 * BBBBB ==> B, 4 deletions
 * ABABABAB ==> ABABABAB, 0 deletions
 * BABABA ==> BABABA, 0 deletions
 * AAABBB ==> AB, 4 deletions
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // # of test cases
    int t;
    // loop variables
    int i,j;
    int count;

    char str[100001];
    scanf("%d",&t);

    // Assert constraint that 1 <= T <= 10
    if( (t < 1) || (t > 10) ) {
        printf("error: T does not satisfy problem constraint (1 <= T <= 10). You entered %d\n", t);
        return 0;
    }

    // Iterate for # of test cases
    for(i = 0; i < t; i++) {
        // Set each value in array to '\0'
        memset(str,'\0',sizeof(str));

        // Read the string from stdin
        scanf("%s",str);
        count = 0;
        // Iterate for each character in a test case string
        for(j = 1; str[j] != '\0'; j++) { 
            if(str[j] == str[j-1]) {
                count++;
            }
        }
        printf("%d\n",count);
    }

    return 0;
}

