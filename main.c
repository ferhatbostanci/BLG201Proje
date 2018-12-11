#include <stdio.h>
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

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

int main() {
    int array[] = {8, 9, 55, 999, 4, 2};

    printf("Min: %d", min(array, ARRAY_SIZE(array)));
    printf("\nMax: %d", max(array, ARRAY_SIZE(array)));
    printf("\nFormul ciktisi: %d", equation(15, 11, 5, 2, 5));

    return 0;
}