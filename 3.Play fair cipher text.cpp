#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void prepareMatrix(char key[], char matrix[SIZE][SIZE]);
void prepareText(char text[], char preparedText[]);
void encrypt(char matrix[SIZE][SIZE], char preparedText[], char encryptedText[]);
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col);
int main() {
    char key[25], plaintext[100], preparedText[100], encryptedText[100];
    char matrix[SIZE][SIZE];
    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    prepareMatrix(key, matrix);
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    prepareText(plaintext, preparedText);
    encrypt(matrix, preparedText, encryptedText);
    printf("Encrypted Text: %s\n", encryptedText);
    return 0;
}
void prepareMatrix(char key[], char matrix[SIZE][SIZE]) {
    int alpha[26] = {0};
    int k = 0, len = strlen(key);
    for (int i = 0; i < len; i++) {
        if (key[i] == 'j') key[i] = 'i'; 
        if (alpha[key[i] - 'a'] == 0) {
            matrix[k / SIZE][k % SIZE] = key[i];
            alpha[key[i] - 'a'] = 1;
            k++;
        }
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == 'j') continue; 
        if (alpha[ch - 'a'] == 0) {
            matrix[k / SIZE][k % SIZE] = ch;
            alpha[ch - 'a'] = 1;
            k++;
        }
    }
}
void prepareText(char text[], char preparedText[]) {
    int len = strlen(text);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (!isalpha(text[i])) continue; 
        preparedText[k++] = tolower(text[i]);
        if (k % 2 == 1 && i + 1 < len && tolower(text[i]) == tolower(text[i + 1])) {
            preparedText[k++] = 'x';
        }
    }
    if (k % 2 == 1) preparedText[k++] = 'x'; 
    preparedText[k] = '\0';
}
void encrypt(char matrix[SIZE][SIZE], char preparedText[], char encryptedText[]) {
    int len = strlen(preparedText);
    int row1, col1, row2, col2;
    for (int i = 0; i < len; i += 2) {
        findPosition(matrix, preparedText[i], &row1, &col1);
        findPosition(matrix, preparedText[i + 1], &row2, &col2);
        if (row1 == row2) {
            encryptedText[i] = matrix[row1][(col1 + 1) % SIZE];
            encryptedText[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encryptedText[i] = matrix[(row1 + 1) % SIZE][col1];
            encryptedText[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            encryptedText[i] = matrix[row1][col2];
            encryptedText[i + 1] = matrix[row2][col1];
        }
    }
    encryptedText[len] = '\0';
}
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
