#include <iostream>

void PrintToFlag(char *arr, int flag) {
    if (arr == nullptr) return;
    for (int i = 0; i <= flag; i++) std::cout << arr[i] << std::endl;
}

// just mimic decimal addition
bool Increment(char *number) {
    bool isOverflow = false;
    int nTakeover = 0;
    int nLength = strlen(number);

    for (int i = nLength-1; i >= 0; i--) {
        int nSum = number[i] - '0' + nTakeover;
        if (i == nLength - 1) nSum++;

        if (nSum >= 10) {
            if (i == 0) isOverflow = true;
            else {
                nSum -= 10;
                nTakeover = 1;
                number[i] = '0' + nSum;
            }
        }
        else {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverflow;
}

void PrintNumber(char *number) {
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i) {
        if (isBeginning0 && number[i] != '0') isBeginning0 = false;
        if(!isBeginning0) printf("%c", number[i]);
    }
    printf("\t");
}

void Print1ToMaxOfNDigits(int n) {
    if (n <= 0) return;

    char *number = new char[n+1];
    // memset(number, '0', n);
    number[0] = '2'; number[1] = '9'; number[2] = '9';
    number[n] = '\0';

    while (!Increment(number)) {
        PrintNumber(number);
    }
    delete[] number;
}