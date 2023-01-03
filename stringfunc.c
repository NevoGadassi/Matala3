#include <stdio.h>
#include <string.h>
#define WORD 30
#define LINE 256
#define TEXT 250

char word[WORD] = {'\0'};
char str[TEXT][LINE] = {'\0'};

int getWord() {
    int len = 0;
    int c=getchar();
    while ((c != '\n') && (c != '\t') && (c != '\r') && (c != ' ') && (c != EOF)) {
        word[len++] = (char) c;
        c=getchar();
    }
    word[len] = '\0';
    return len;
}

int getLine(int line) {
    int len = 0;
    int c=getchar();
    while ((c!= '\n') && (c != EOF) && (len < LINE - 1)) {
        str[line][len++] = (char) c;
        c=getchar();
    }
        str[line][len] = '\0';
    return len;
}
int isEqualStringN(char s1[], char s2[]) {
    int len2 = strlen(s2);
    for (int i=0; i<len2; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
        return 1;
}

int substring (char * str1,char * str2){
    int len1 = strlen(str1), len2 = strlen(str2);

    for (int i = 0; i <= len1-len2; i++) {
        if (isEqualStringN(str1+i, str2)) {
            return 1;
        }
    }
    return 0;
}

int similar (char s[], char t[], int n) {
if (strcmp(s, t) == 0) {
        return 1;
    }
    if(strlen(s) - n != strlen(t)) {
        return 0;
    }
    for (int i = 0, j = 0; i < strlen(s); i++) {
        if (s[i] != t[j]) {
            n--;
            if (n < 0) {
                return 0;
            }
        }
        else {
            j++;
        }
    }
    return 1;
}

void print_similar_words() {
    char thisline[WORD] = {0};
    for (int i = 0; i < TEXT; i++) {
        for (int j = 0; j < strlen(str[i]); j++) {
            int k = 0;
            while ((str[i][j] != '\0') && (str[i][j] != ' ')) {
                thisline[k++] = str[i][j++];
            }
            thisline[k] = '\0';
            if(similar(thisline, word, 1)) {
                printf("%s\n", thisline);
            }
        }
    }
}
int main() {
    getWord();

    char func = (char) getchar();
    getchar();
    getchar();
    for (int i = 0; i < TEXT; i++) {
        getLine(i);
    }

    if(func=='b')
    {
        print_similar_words();
    }
    else if(func=='a'){
           
         for (int i = 0; i < TEXT; i++) {
            if (substring(str[i],word)) {
                printf("%s\n", str[i]);
        }
        }
    }

    return 0;
}
