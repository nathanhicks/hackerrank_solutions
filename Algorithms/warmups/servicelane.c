#include <stdlib.h>
#include <stdio.h>

/*
 *  * Constraints
 *   * 2 <= N <= 100000
 *    * 1 <= T <= 1000
 *     * 0 <= i < j < N
 *      * 2 <= j-i+1 <= min(N,1000)
 *       * 1 <= width[k] <= 3, where 0 <= k < N
 *        */

int main()
{
    int n,t,i,j,narrow;
    t = i = j = 0;
    narrow = 3;

    // Reads N and T separated by a single whitespace
    // where N is length of freeway, and T is # of test cases
    scanf("%i %i",&n,&t);
   
    int width[n]; // all elements to 0 
   
    // Read width of each segment
    for(int k = 0; k < n; k++) {
        scanf("%i ",&width[k]);
    }   
   
    // For each test case, T
    for(int m = 0; m < t; m++) {
        // Read the entry and exit points
        scanf("%i %i",&i,&j);
        narrow = 3;
        for(int k = i; k<= j; k++) {
            if(width[k] < narrow) {
                narrow = width[k];
            }
        }
        printf("%i\n",narrow);
    }   

    return 0;
}
