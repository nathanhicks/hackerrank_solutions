/* Problem Statement
 *
 * You are given an integer, N.  Write a program to determine if N is an element of the Fibonacci Sequence.
 *
 * The first few elements of fibonacci sequence are 0,1,1,2,3,5,8,13, ... A fibonacci sequence is one where
 * every element is a sum of the previous two elements in the sequence.  The first two elements are 0 and 1.
 *
 * Formally:
 *
 *      fib0 = 0
 *      fib1 = 1
 *          .
 *          .
 *          .
 *      fibn = fibn-1 + fibn-2An > 1
 *
 * Input Format
 * 
 * The first line contains T, number of test cases.
 * T lines follows.  Each line contains an integer N.
 *
 * Output Format
 * 
 * Display IsFibo if N is a fibonacci number and IsNotFibo if it is not a fibonacci number.  The
 * output for each test case should be displayed in a new line.
 *
 * Constraints
 * 1 <= T <= 10^5
 * 1 <= N <= 10^10
 *
 * Sample Input
 * 3
 * 5
 * 7
 * 8
 *
 * Sample Output
 * IsFibo
 * IsNotFibo
 * IsFibo
 *
 * Explanation
 * 5 is a Fibonacci number given by fib5 = 3+2
 * 7 is not a Fibonacci number
 * 8 is a Fibonacci number given by fib6 = 5 + 3
 *
 * TimeLimit
 * Time limit for this challenge in C or C++ is 2 seconds (10 seconds for Python).
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isFibonacci(unsigned long long n);

int main()
{
    int t = 0;
    unsigned long long n = 0;
    int i = 0;

    scanf("%d",&t);
    
    // Assert Constraint: 1 <= T <= 10^5
    if( (t < 1) || (t > pow(10,5) ) ) {
        printf("Input Constraint Violation: T == %d does not satisfy constraint (1 <= T <= 10^5).\n",t);
        return 0;
    }

    for(i = 0; i < t; i++) {
        scanf("%llu",&n);
        // Assert Constraint: 1 <= N <= 10^10
        if( (n < 1) || (n > pow(10,10) ) ) {
            printf("Input Constraint Violation: N == %llu does not satisfy contraint (1 <= N <= 10^10).\n",n);
            return 0;
        }

        if( isFibonacci(n) ) {
            printf("IsFibo\n");
        } else {
            printf("IsNotFibo\n");
        }

    }

    return 0;
}

int isFibonacci(unsigned long long n)
{
    unsigned long long x = 0, y = 1;
    unsigned long long next = x + y;
    while(next <= n) {
        if( next == n) {
            return 1;
        }
        x = y;
        y = next;
        next = x + y;
    }
    return 0;
}
