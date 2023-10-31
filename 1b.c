#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void countWords(const char *text) {
    int count[MAX_WORDS] = {0};
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;

    char buffer[strlen(text) + 1];
    strcpy(buffer, text);
    char *token = strtok(buffer, " ,.");
    while (token != NULL) {
        int i;
        for (i = 0; token[i]; i++)
            token[i] = tolower(token[i]);
        int wordIndex = -1;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                wordIndex = i;
                break;
            }
        }
        if (wordIndex == -1) {
            if (wordCount == MAX_WORDS) {
                printf("Maximum word count reached.\n");
                return;
            }
            strcpy(words[wordCount], token);
            count[wordCount]++;
            wordCount++;
        }
        else {
            count[wordIndex]++;
        }
        token = strtok(NULL, " ,.");
    }
    int i;
    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }
}

int main() {
    const char *text = "This is a sample text. It contains multiple words, including repeated words.";
    countWords(text);
    return 0;
}