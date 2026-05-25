#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int max = i;
    int stanga = 2 * i + 1;
    int dreapta = 2 * i + 2;


    if (stanga < n && arr[stanga] > arr[max])
        max = stanga;


    if (dreapta < n && arr[dreapta] > arr[max])
        max = dreapta;


    if (max != i) {
        int aux = arr[i];
        arr[i] = arr[max];
        arr[max] = aux;

        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;

        heapify(arr, i, 0);
    }
}

void afiseaza(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

int main() {
    int vector[] = {12, 11, 13, 5, 6, 7, 2, 8};
    int n = 8; 

    printf("Vector initial:\n");
    afiseaza(vector, n);

    heapSort(vector, n);

    printf("Vector sortat (Heap Sort):\n");
    afiseaza(vector, n);

    return 0;
}