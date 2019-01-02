#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

int maxValues[1000];
int n, k;

size_t getline(char **lineptr, size_t *n, FILE *stream) {
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL) {
        return -1;
    }
    if (stream == NULL) {
        return -1;
    }
    if (n == NULL) {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF) {
        return -1;
    }
    if (bufptr == NULL) {
        bufptr = malloc(128);
        if (bufptr == NULL) {
            return -1;
        }
        size = 128;
    }
    p = bufptr;
    while(c != EOF) {
        if ((p - bufptr) > (size - 1)) {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n') {
            break;
        }
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}

int min(const int values[], int length){
    int i, minimum;
    minimum = values[0];
    for (i = 0; i < length; i++) {
        if(values[i] < minimum) minimum = values[i];
    }
    return minimum;
}

int max(const int values[], int length){
    int i, maximum;
    maximum = values[0];
    for (i = 0; i < length; i++) {
        if(values[i] > maximum) maximum = values[i];
    }
    return maximum;
}

int equation(int a, int b, int c, int t){
    int result = 0;
    result += (a + t) % k;
    result += (b + t) % k;
    result += (c + t) % k;
    return result;
}


/*void createSampleData() {
    FILE *fptr = fopen(".\\data.txt", "wb");
    if (fptr == NULL) {
        printf("Can't Create A File!\n");
        exit(1);
    }

    fprintf(fptr, "15,25,35,45,55,65,75,85,95\n");
    fprintf(fptr, "12,22,32,42,52,62,72,82,92\n");
    fprintf(fptr, "17,27,37,47,57,67,77,87,97\n");
    fprintf(fptr, "5\n");
    fprintf(fptr, "10,20,30,40,50,60,70,80,90\n");
    fprintf(fptr, "36,46,56,66,76,86,96,106,116\n");
    fprintf(fptr, "33,43,53,63,73,83,93,103,113\n");
    fprintf(fptr, "3\n");
    fprintf(fptr, "10,20,30,40,50,60,70,80,90\n");
    fprintf(fptr, "17,27,37,47,57,67,77,87,97\n");
    fprintf(fptr, "33,43,53,63,73,83,93,103,113\n");
    fprintf(fptr, "7\n");
    fclose(fptr);
}*/

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int getIntCount(char str[]){
    char *temp = malloc(strlen(str) + 1);
    strcpy(temp, str);
    char seps[] = " ";
    char* token;
    int var;
    int i = 0;

    token = strtok(temp, seps);
    while(token != NULL){
        sscanf(token, "%d", &var);
        token = strtok(NULL, seps);
        i++;
    }

    return i;
}

int * convertStrtoArr(char str[], int size){
    char seps[] = " ";
    char* token;
    int var;
    int i = 0;
    int *input = malloc(sizeof(int) * size);

    token = strtok(str, seps);
    while (token != NULL){
        sscanf(token, "%d", &var);
        input[i++] = var;
        token = strtok(NULL, seps);
    }

    /*for (int j = 0; j < size ; ++j) {
        printf("%d ", input[j]);
    }*/

    return input;
}

void readFromFile() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 2;
    int index_max = 0, index_process = 0;
    int a, b, c;
    int t, i=0;
    int process[1000];
    int *temp;

    int arr_count = 0;

    fp = fopen("..\\data.txt", "r");

    if (fp == NULL) exit(EXIT_FAILURE);

    printf("Please enter the %d. data's addition(t) number: ", index_max+1);
    scanf("%d", &t);

    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("%s", line);
        int linesize = getIntCount(line);
        if(linesize == 2) {
            temp = convertStrtoArr(line, 2);
            n = temp[0];
            k = temp[1];
            //printf("%d\n", temp[0]);
        }else{
            temp = convertStrtoArr(line, 3);
            int tempA = temp[0];
            int tempB = temp[1];
            int tempC = temp[2];

            process[index_process] = equation(tempA, tempB, tempC, t);
            printf("Equ: %d\n", process[index_process]);
            index_process = index_process +1;
        }

        if(index_process == 3){
            maxValues[index_max] = max(process, index_process);
            index_max = index_max + 1;
            index_process = 0;

            printf("Please enter the %d. data's addition(t) number: ", index_max+1);
            scanf("%d", &t);
        }
    }

    printf("\n\nMax Values are : \n");
    printArray(maxValues, index_max);

    printf("\n\nMinimum Number of Equation is : %d", min(maxValues, index_max));

}


int main() {

    printf("Welcome to Our Equation Cli Application\n");
    printf("This Application takes data from a file.\n");
    printf("You just need to input addition number.\n\n");

    readFromFile();

    return 0;
}