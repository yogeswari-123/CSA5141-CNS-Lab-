#include <stdio.h>
#include <math.h>

int main() {
    // Number of possible keys ignoring identical encryptions
    double possible_keys = tgamma(26); // tgamma(n) returns (n-1)!
    double log2_possible_keys = log2(possible_keys);
    printf("Total possible keys (approx): 2^%.2f\n", log2_possible_keys);

    // Number of effectively unique keys
    double unique_keys = possible_keys / 8;
    double log2_unique_keys = log2(unique_keys);
    printf("Effectively unique keys (approx): 2^%.2f\n", log2_unique_keys);

    return 0;
}

