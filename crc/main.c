#include <stdio.h>
#include <string.h>

void performCRC(char *dataword, char *polynomial, char *sentCodeword) {
    printf("\nEntered data word = %s", dataword);
    int polyLength = strlen(polynomial);
    int n = polyLength + strlen(dataword);
    char tempdata[n];

    strcpy(tempdata, dataword);

    for (int i = 0; i < polyLength - 1; i++) {
        strcat(tempdata, "0");
    }
    printf("\nZero padded data word = %s", tempdata);
    char remainder[polyLength];


    for (size_t i = 0; i < strlen(dataword); i++) {
        if (tempdata[i] == '1') {
            for (int j = 0; j < polyLength; j++) {
                tempdata[i + j] = (tempdata[i + j] == polynomial[j]) ? '0' : '1';
            }
        }
    }
    printf("\nTemp data word = %s", tempdata);
    int k = 0;
    for (int i= strlen(dataword); i<n ; i++)
    {
        remainder[k++] = tempdata[i];
    }
    printf("\nRemainder = %s", remainder);
    strcpy(sentCodeword, dataword);
    strcat(sentCodeword, remainder);
    printf("\nSent code word = %s", sentCodeword);
}

void checkCRC(char *receivedCodeword, char *polynomial, char *extractedDataword) {
    strcpy(extractedDataword, receivedCodeword);

    for (size_t i = 0; i < strlen(receivedCodeword); i++) {
        if (extractedDataword[i] == '1') {
            for (size_t j = 0; j < strlen(polynomial); j++) {
                extractedDataword[i + j] = (extractedDataword[i + j] == polynomial[j]) ? '0' : '1';
            }
        }
    }

    if (strchr(extractedDataword, '1') == NULL) {
        // No '1' found in the remainder, CRC check succeeded
        //extractedDataword[strlen(receivedCodeword) - strlen(polynomial) + 1] = '\0';
        printf("\nMessage received without any error. ");
    } else {
        //strcpy(extractedDataword, "Error: CRC check failed!");
        printf("\nCorrupted message received. CRC check gives non zero remainder. ");
    }
}

int main() {
    int choice;
    char dataword[100] = {0};  // Initialize to zero
    char polynomial[100] = {0};  // Initialize to zero
    char sentCodeword[200] = {0};  // Initialize to zero
    char receivedCodeword[200] = {0};  // Initialize to zero
    char extractedDataword[100] = {0};  // Initialize to zero

    do {
    printf("\nMenu:\n");
        printf("1. Sender - Generate and send codeword - CRC\n");
        printf("2. Receiver - Receive and check codeword - CRC\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("-----Sender Mode-----\n");
                printf("Enter the dataword: ");
                scanf("%s", dataword);
                printf("Enter the CRC polynomial: ");
                scanf("%s", polynomial);
                performCRC(dataword, polynomial, sentCodeword);
                printf("\n\nSent Codeword with CRC: %s\n", sentCodeword);
                break;

            case 2:
                printf("-----Receiver Mode-----\n");
                printf("Enter the received codeword: ");
                scanf("%s", receivedCodeword);
                printf("Enter the CRC polynomial: ");
                scanf("%s", polynomial);
                checkCRC(receivedCodeword, polynomial, extractedDataword);
                printf("Received Codeword: %s\n", receivedCodeword);
                break;

            case 3:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);


    return 0;
}
