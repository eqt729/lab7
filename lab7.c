#include <stdio.h>

void bubbleSwap(int size, int arr[], int swapArr[]) {
    int nSwaps = 0, temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapArr[arr[j]]++;
                swapArr[arr[j + 1]]++;

                nSwaps++;
            }
        }
    }

    
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", arr[i], swapArr[arr[i]]);
    }
    printf("%d\n", nSwaps);
}

void selectSort(int size, int arr[], int swapArr[]) {
    int temp, nSwaps = 0;

    for (int i = 0; i < size - 1; i++) {
        int minPos = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minPos]) {
                minPos = j;
               

            }
        }


        if (minPos != i) {
            temp = arr[minPos];
            arr[minPos] = arr[i];
            arr[i] = temp;

            swapArr[i ]++;  
            swapArr[minPos]++;
       
            

            nSwaps++;
        }
    }

    
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", arr[i], swapArr[i]);
    }
    printf("%d\n", nSwaps);
}

void resetArrays(int size, int arr[], int swapArr[], int originalOrder[]) {
    for (int i = 0; i < size; i++) {
        arr[i] = originalOrder[i];
        swapArr[i] = 0;
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int originalOrder1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int originalOrder2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int swap1[100] = {0};
    int swap2[100] = {0};

  


    printf("\narray1 bubble sort:\n");
    bubbleSwap(size1, array1, swap1);
    printf("\narray2 bubble sort:\n");
    resetArrays(size1, array1, swap1, originalOrder1);
    bubbleSwap(size2, array2, swap2);

    resetArrays(size2, array2, swap2, originalOrder2);

    printf("\narray1 selection sort:\n");
    selectSort(size1, array1, swap1);
    resetArrays(size1, array1, swap1, originalOrder1);
    printf("\narray2 selection sort:\n");
    selectSort(size2, array2, swap2);
    

    return 0;
}
