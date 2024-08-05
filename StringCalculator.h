#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>

int isStringEmpty(const char* str) {
    return (str == NULL || str[0] == '\0');
}

void extractDelimiter(const char* str, char* delimiter) {
    int i = 2;  // Start after the initial delimiter //
    int j = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        delimiter[j++] = str[i++];
    }
    delimiter[j] = '\0';  // Null-terminate the delimiter string
}

void findDelimiter(const char* str, char* delimiter) {
    if (str[0] == '/' && str[1] == '/') {
        extractDelimiter(str, delimiter);
    } else {
        strcpy(delimiter, ",\n");
    }
}

int processValue(int value) {
    return (value < 1000) ? value : 0;
}

void checkForNegatives(int value) {
    if (value < 0) {
        throw std::runtime_error("negatives not allowed");
    }
}

int calculateSum(const char* str, const char* delimiter) {
    char* duplicateStr = strdup(str);
    int sum = 0;
    char* segment = strtok(duplicateStr, delimiter);
    while (segment != NULL) {
        int value = atoi(segment);
        checkForNegatives(value);
        sum += processValue(value);
        segment = strtok(NULL, delimiter);
    }
    free(duplicateStr);
    return sum;
}

int sumString(const char* str) {
    char delimiter[20];
    if (isStringEmpty(str)) {
        return 0;
    }
    findDelimiter(str, delimiter);
    int sum = calculateSum(str, delimiter);
    return sum;
}
