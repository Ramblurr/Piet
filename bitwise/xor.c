#include <stdint.h>

/* implementations from
http://stackoverflow.com/questions/2982729/is-it-possible-to-implement-bitwise-operators-using-integer-arithmetic/2982963#2982963
*/
int32_t xor(int32_t a, int32_t b)
{
    int32_t x,c;
    c = 0;
    x = 32;
//     for (x = 0; x <= 31; ++x) {
    // must run exactly 32 times
    while(x>0) {
        // loop
        c += c;
        // a_check
        // a < 0 == 0 > a
        if (0 > a) {
            // a_sub
            // b >= 0 == b+1 > 0
            if ( (b+1) > 0) {
                // a_sub_b
                c += 1;
            }
        // b < 0 == 0 > b
        // b_check
        } else if (0 > b) {
            // b_sub
            c += 1;
        }
        // body
        a += a;
        b += b;
        --x;
    }
    return c;
}
int32_t and(int32_t a, int32_t b) {
    int32_t x,c;
    c = 0;
    for (x = 0; x <= 31; ++x) {
        c += c;
        if (a < 0) {
            if (b < 0) {
                c += 1;
            }
        }
        a += a;
        b += b;
    }
    return c;
}

int32_t or(int32_t a, int32_t b) {
    int32_t x,c;
    c = 0;
    for (x = 0; x <= 31; ++x) {
        c += c;
        if (a < 0) {
            c += 1;
        } else if (b < 0) {
            c += 1;
        }
        a += a;
        b += b;
    }
    return c;
}

int main() {
    int32_t i,j;
    printf("XOR\n");
    for(j=0,i=100; i>0; --i,++j )
    {
        printf("%d, %d\n", xor(j,i), i^j);
    }
//     printf("AND\n");
//     for(j=0,i=100; i>0; --i,++j )
//     {
//         printf("(%d,%d): %d, %d\n", j,i,and(j,i), i&j);
//     }
//     printf("OR\n");
//     for(j=0,i=100; i>0; --i,++j )
//     {
//         printf("(%d,%d): %d, %d\n", j,i,or(i,j), i|j);
//     }
    return 0;
}
