#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define MAX_VAL 1000000001

int cmpfunc (const void *a, const void *b)
{
    long long fa = *(long*)a;
    long long fb = *(long*)b;
    return ( (fa > fb) - (fa < fb));
}

int main()
{

    long long i,z,N,K;
    long long unfairness = MAX_VAL,cur_unfairness;
    long long min,max;
    long long candies[MAX];

    // Read first two lines (N and K) from stdin
    scanf("%lld %lld",&N,&K);

    // Assert Constraint 1 <= N <= 10^5
    if( (N < 1) || (N > MAX) ) {
        printf("constraint error: N = %lld does not match constraint (1 <= N <= 10^5)",N);
        return 0;
    }

    // Assert Constraint 1 <= K <= N
    if( (K < 1) || (K > N) ) {
        printf("constraint error: K = %lld does not match constraint (1 <= K <= N)",K);
        return 0;
    }

    // Read N lines that follow from stdin
    for(i = 0; i < N; i++)
        scanf("%lld",candies + i);

    // Sort the array from smallest to largest
    qsort(candies,N,sizeof(long),cmpfunc);

    //for(i = 0; i < N; i++)
    //    printf("%lld\t",candies[i]);

    for(i = 0; i < N - K; i++) {
        z = K + i -1;
        if(z > (N-1)) {
            break;
        }
        min = candies[i];
        max = candies[z];
        cur_unfairness = max - min;
        if(cur_unfairness < unfairness) {
            unfairness = cur_unfairness;
        }
    }

    printf("%lld",unfairness);

    return 0;
}
