#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    // The number of test cases
    int t;

    // Loop variables
    int i,j;

    // buffer size of string
    int buffer_size = 10001;

    // input string
    char input[buffer_size];

    // Minimum operations
    int ops_count;

    // length of input string
    int len;

    // Read # test cases
    scanf("%d",&t);

    // Assert constraint that 1 <= T <= 10
    if( (t < 0) || (t > 10) ) {
        printf("error: T does not satisfy problem constraint (1 <= T <= 10).  You entered %d\n", t);
        return 0;
    }

    // Iterate for # of test cases
    for(i = 0; i < t; i++) {

        memset(input, '\0', sizeof(input));

        // Read the string from stdin
        scanf("%s",input);

        // Get length of actual input string
        len = strlen(input);

        ops_count = 0;
        // Iterate over each character in the string
        for(j = 0; input[j] != '\0'; j++) {

            if(input[j] != input[len - j - 1])
            {
                if(input[j] > input[len - j - 1]) {
                    ops_count += input[j] - input[len - i - 1]; 
                } else {
                    ops_count += input[len - i - 1] - input[j];
                }
            }

        }
        printf("%d\n",ops_count);
    }

    return 0;
}
