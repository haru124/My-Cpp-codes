#include <stdio.h>
#include <math.h>

// Function to calculate the number of parity bits required
int calcParityBits(int m) {
    int r = 0;
    while (pow(2, r) < (m + r + 1)) {
        r++;
    }
    return r;
}

// Function to generate the Hamming Code
void generateHammingCode(int data[], int m) {
    int r = calcParityBits(m);
    int n = m + r;
    int hammingCode[n];

    // Initialize all positions as 0
    for (int i = 0; i < n; i++) {
        hammingCode[i] = 0;
    }

    // Copy data bits to hamming code positions
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) != 0) { // Skip positions which are powers of 2
            hammingCode[i - 1] = data[j++];
        }
    }

    // Calculate parity bits
    for (int i = 0; i < r; i++) {
        int parity = 0;
        int bitPosition = (int)pow(2, i);
        for (int j = bitPosition - 1; j < n; j += 2 * bitPosition) {
            for (int k = j; k < j + bitPosition && k < n; k++) {
                parity ^= hammingCode[k];
            }
        }
        hammingCode[bitPosition - 1] = parity;
    }

    // Print the Hamming Code
    printf("Hamming Code: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", hammingCode[i]);
    }
    printf("\n");
}

// Function to decode the Hamming Code
void decodeHammingCode(int codeword[], int codewordLength) {
    int r = calcParityBits(codewordLength);
    int n = codewordLength;
    int errorBit = 0;

    // Calculate Syndrome Bits
    for (int i = 0; i < r; i++) {
        int parity = 0;
        int bitPosition = (int)pow(2, i);
        for (int j = bitPosition - 1; j < n; j += 2 * bitPosition) {
            for (int k = j; k < j + bitPosition && k < n; k++) {
                parity ^= codeword[k];
            }
        }
        errorBit += parity << i; // Accumulate syndrome bits
    }

    if (errorBit == 0) {
        printf("No error detected.\n");

        // Extract the data bits
        int m = n - r;
        int data[m];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (((i + 1) & i) != 0) {
                data[j++] = codeword[i];
            }
        }
        printf("Decoded Data: ");
        for (int i = 0; i < m; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    } else {
        printf("Error detected at position: %d\n", errorBit);

        // Correct the error
        codeword[errorBit - 1] ^= 1;

        printf("Corrected Codeword: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", codeword[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("1. Sender\n2. Receiver\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int m;
        printf("Enter the number of bits in the dataword: ");
        scanf("%d", &m);
        int data[m];
        printf("Enter the actual bits in the dataword: ");
        for (int i = 0; i < m; i++) {
            scanf("%d", &data[i]);
        }
        generateHammingCode(data, m);
    } else if (choice == 2) {
        int n;
        printf("Enter the number of bits in the codeword: ");
        scanf("%d", &n);
        int codeword[n];
        printf("Enter the codeword: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &codeword[i]);
        }
        decodeHammingCode(codeword, n);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
