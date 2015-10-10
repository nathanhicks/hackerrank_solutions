/* Problem Statement
 *
 * You are given an integer N.  Find the digits in this number that exactly divide N and display
 * their count.  For N = 24, there are 2 digits - 2 & 4.  Both these digits exactly divide 24.
 * So our answer is 2.
 *
 * Note
 *
 *  * If the same number is repeated twice at different positions, it should be counted twice,
 *    e.g., For N=122, 2 divides 122 exactly and occurs at ones' and tens' position.  So it should
 *    be counted twice.  So for this case, our answer is 3.
 *
 *  * Division by 0 is undefined.
 *
 * Input Format
 * 
 * The first line contains T (number of test cases) followed by T lines (each containing an
 * integer N).
 *
 * Constraints
 *
 * 1 <= T <= 15
 * 0 < N < 10^10
 *
 * Output Format
 *
 * For each test case, display the count of digits in N that exactly divide N in separate line.
 *
 * Sample Input
 *
 *  2
 *  12
 *  1012
 *
 * Sample Output
 *
 *  2
 *  3
 *
 * Explanation
 *
 *  1. 2 digits in the number 12 divide the number exactly.  Digits at tens' place,
 *     1, divides 12 exactly in 12 parts, and digit at ones' place, 2 divides 12
 *     equally in 6 parts.
 *
 *  2. 1 divides 1012 at two places and 2 divides it at one place.  Divide by 0 is
 *     an undefined behaviour and it will not be counted.
 *
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_digits(signed long long value);

int main()
{
    
    signed long long value = 0;
    int t = 0;
    int i;
    int count_arr[12];

    // t = # of test cases
    scanf("%d",&t);

    // Assert Constraint: 1 <= T <= 15
    if( (t < 1) || (t > 15) ) {
        printf("error: T does not satisfy problem constraint (1 <= T <= 15). You entered %d\n", t);
        return 0;
    }

    // Since N can be 0, so can the count. Thus, we set all values to a default of -1.
    memset(count_arr, -1, sizeof(count_arr));

    for(i = 0; i < t; i++) {
        scanf("%lld",&value);
        
        // Assert Constraint: 0 <= N <= 10^10
        if( (value < 0) || (value > pow(10,10)) )
        {
            printf("error: N,%lld, does not satisfy problem constraint (0 <= N <= 10^10).\n",value);
            return 0;
        }
        count_arr[i] = find_digits(value);
    }

    // Sizeof returns the size of the array in bytes,
    // so we must divide that number by the # of bytes in an integer type
    // to get the length of the array.
    for(i = 0; i < (sizeof(count_arr)/sizeof(int)); i++) {
        if(count_arr[i] == -1) {
            return 0;
        }
        printf("%d\n",count_arr[i]);
    }

    return 0;
}

int find_digits(signed long long value)
{
    int count = 0;
    long digit = 0;
    signed long long temp = value;

    while ( (temp > 0) ) {
        // Extract multi digit numbers into separate variables
        digit = temp % 10;

        // Dividing by zero is undefined and will not be counted
        if(digit != 0) {
            // Determine if the value can be divided into the digit evenly
            if((value % digit) == 0) {
                count++;
            }
        }
        // Remove ones' place digit from value
        temp /= 10;
    }
    return count;
}
