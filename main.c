#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

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

int equation(int a, int b, int c, int t, int k){
    int result = 0;
    result += (a + t) % k;
    result += (b + t) % k;
    result += (c + t) % k;
    return result;
}


void createSampleData() {
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
}

void printArray(int array[]) {
    for (int i = 0; i < 8; ++i) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void convertStrtoArr(char str[])
{
    // get length of string str
    size_t str_length = strlen(str);

//    printf("%lli\n", str_length);

    // create an array with size as string
    // length and initialize with 0
    int arr[str_length];


    int j = 0, i, mult = 1;

    // Traverse the string
    for (i = 0; str[i] != '\0'; i++) {

        printf("%c", str[i]);

        // if str[i] is ' ' then split
        if (str[i] == ' ') {

            // Increment j to point to next
            // array location
            j++;
            mult = 1;
        }
        else {

            // subtract str[i] by 48 to convert it to int
            // Generate number by multiplying 10 and adding
            // (int)(str[i])
            arr[j] = arr[j] + ((int)str[i] - 48)* mult;
            mult = mult * 10;
        }
    }

    printf("arr[] = ");
    for (i = 0; i <= j; i++) {
        printf("%d, ", arr[i]) ;
//        sum += arr[i]; // sum of array
    }
    printf("\n");

    // print sum of array

}

void readFromFile() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("..\\data.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
//        printf("%s", line);
        convertStrtoArr(line);
    }

}


int main() {

    readFromFile();

//    int a[] = {15, 21, 32, 15, 25, 45, 14, 36};
//    int b[] = {16, 13, 12, 11, 17, 18, 25, 22};
//    int c[] = {23, 34, 18, 17, 22, 29, 34, 25};
//    int k = 5;
//    int proccess[ARRAY_SIZE(a)];
//    int max_numbers[10];
//    int min_number;
//
//    int t = 0;
//
//    printf("Please enter the addition number\n", ARRAY_SIZE(a));
//    scanf("%d", &t);
//
//    while (t <= 0) {
//        printf("Addition number must be greater then 0\n");
//        scanf("%d", &t);
//    }
//
//    for (int i = 0; i < ARRAY_SIZE(a); ++i) {
//        proccess[i] = equation(a[i], b[i], c[i], t, k);
//    }
//
//    max_numbers[0] = max(proccess, ARRAY_SIZE(proccess));
//
//    printf("\n");
//    printArray(a);
//    printArray(b);
//    printArray(c);
//    printf("T = %d and K = %d and MAX Number = %d\n", t, k, max_numbers[0]);
//
//    int d[] = {11, 12, 36, 15, 22, 48, 17, 25};
//    int e[] = {15, 22, 36, 48, 25, 14, 12, 37};
//    int f[] = {85, 58, 97, 23, 24, 55, 43, 48};
//
//    printf("Please enter the addition number\n");
//    scanf("%d", &t);
//
//    while (t <= 0) {
//        printf("Addition number must be greater then 0\n");
//        scanf("%d", &t);
//    }
//
//    k = 4;
//
//    for (int i = 0; i < ARRAY_SIZE(d); ++i) {
//        proccess[i] = equation(d[i], e[i], f[i], t, k);
//    }
//
//    max_numbers[1] = max(proccess, ARRAY_SIZE(proccess));
//
//    printf("\n");
//    printArray(d);
//    printArray(e);
//    printArray(f);
//    printf("T = %d and K = %d and MAX Number = %d\n", t, k, max_numbers[1]);
//
//    int g[] = {47, 48, 65, 3, 10000, 1245, 4, 75};
//    int h[] = {45, 54, 16, 22, 65441, 1879, 2781, 23};
//    int j[] = {54, 555, 7584, 16, 58, 2541, 65, 3};
//
//    printf("Please enter the addition number\n");
//    scanf("%d", &t);
//
//    while (t <= 0) {
//        printf("Addition number must be greater then 0\n");
//        scanf("%d", &t);
//    }
//
//    k = 7;
//
//    for (int i = 0; i < ARRAY_SIZE(g); ++i) {
//        proccess[i] = equation(g[i], h[i], j[i], t, k);
//    }
//
//    max_numbers[2] = max(proccess, ARRAY_SIZE(proccess));
//
//    printf("\n");
//    printArray(g);
//    printArray(h);
//    printArray(j);
//    printf("T = %d and K = %d and MAX Number = %d\n", t, k, max_numbers[2]);
//
//    min_number = min(max_numbers, 2);
//
//    printf("\nMIN Number%d\n", min_number);

    return 0;
}