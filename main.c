#include <stdio.h>
#include <stdlib.h>

/*
Escreva funções em C que calculem para um array de inteiros,juntamente com o número de
elementos, as seguintes medidas estatísticas:
    * a moda dos elementos no array (elemento mais freqüente)
    * a mediana dos elementos no array (elemento central)
    * a média
*/


//Declaration
int array_mode(int *array, int size);
void array_sort(int *array, int size);
float array_median(int *array, int size);
float array_mean(int *array, float size);

int main() {

    //Defining array size and input inside main function
    int size;

    printf("How many integers is the array going to store? \n");
    scanf("%d", &size);

    //If an array stores 5 elements, it goes from 0 to 4
    size --;
    int array[size];

    for (int aux1 = 0; aux1 <= size; aux1 ++) {

        printf("\nEnter the value for the element %d: \n", aux1);
        scanf("%d", &array[aux1]);
    }

    printf("\n\nYou entered: \n");

    for (int aux2 = 0; aux2 <= size; aux2 ++) {

        printf("%d ", array[aux2]);
    }

    printf("\n\nLet's check this array mode...\n");
    int mode = array_mode(array, size);

    if (mode == 1) {

        printf("\nThe mode could be any element...\n");
    }

    printf("The mode is %d.\n\n", mode);

    printf("\nNow, let's sort our array to find the median...\n");
    array_sort(array, size);
    float median = array_median(array, size);
    printf("\n\nThe median is %.2f.\n", median);

    printf("\nFor last, the mean...\n");
    float mean = array_mean(array, size);
    printf("It's %.2f.\n\n", mean);

    return 0;
}


//Definition
int array_mode(int *array, int size) {
//Returns the array mode

    int mode;
    int element;
    int count;
    int max_count = 0;

    for (int aux1 = 0; aux1 <= size; aux1 ++) {

        count = 0;
        element = array[aux1];

        for (int aux2 = 0; aux2 <= size; aux2 ++) {

            if (array[aux2] == element) {

                count++;
            }
        }

        if (count >= max_count) {

            //With some work we can also retrieve max_count to show to the user
            max_count = count;
            mode = element;
        }
    }

    return mode;
}


void array_sort(int *array, int size) {
//Sorts the array in increasing order

    for (int aux1 = 0; aux1 <= size; aux1 ++) {

        for (int aux2 = 0; aux2 <= size; aux2 ++) {

            if (array[aux2] > array[aux1]) {

                int temp = array[aux1];
                array[aux1] = array[aux2];
                array[aux2] = temp;
            }
        }
    }

    printf("\nSorted array: \n");
    for (int aux3 = 0; aux3 <= size; aux3 ++) {

        printf(" %d ", array[aux3]);
    }
}


float array_median(int *array, int size) {
//Returns the array median

    float median;;
    size ++;

    if (size % 2 == 0) {

        size = size/2;
        float a = array[size];
        float b = array[size - 1];
        median = (a + b)/2.0;
    }

    else {

        median = array[size/2];
    }

    return median;
}


float array_mean(int *array, float size) {
//Returns the array mean

    float total = 0;
    float mean;

    for (int aux1 = 0; aux1 <= size; aux1 ++) {

        total = total + array[aux1];
    }

    mean = total/(size + 1.0);

    return mean;
}
