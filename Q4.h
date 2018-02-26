#include <iostream>
#include <string.h>

void replaceBlank(char *str) {
    if (str == nullptr) return;
    int s_len = strlen(str) + 1;  // without NULL
    char *s = new char[s_len];
    strcpy(s, str);
    int cursor = 0;
    while(s[cursor] != '\0') {
        if (s[cursor] == ' ') {
            int s_len_old = s_len-1;
            s_len += 2; // including NULL
            char *tmp = new char[s_len];
            strncpy(tmp, s, cursor * sizeof(char));
            tmp[cursor] = '%'; tmp[cursor+1] = '2'; tmp[cursor+2] = '0';
            strncpy(tmp+cursor+3, s+cursor+1, (s_len_old-cursor-1)*sizeof(char));
            tmp[s_len-1] = '\0';

            delete[] s;
            s = tmp;
            cursor += 3;
        }
        else {
            cursor ++;
        }
    }
    memcpy(str, s, s_len);
    //strcpy(str, s);   /// cannot use strcpy to assign the new block of mem!
}