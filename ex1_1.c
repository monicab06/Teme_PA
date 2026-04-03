#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int v[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void bubble(int v[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(v[j] > v[j + 1])
                swap(&v[j], &v[j + 1]);
}

void insertion(int v[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while(j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void selection(int v[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(v[j] < v[min])
                min = j;

        swap(&v[i], &v[min]);
    }
}


void merge(int v[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++)
        leftArr[i] = v[left + i];
    for(j = 0; j < n2; j++)
        rightArr[j] = v[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(leftArr[i] <= rightArr[j])
            v[k++] = leftArr[i++];
        else
            v[k++] = rightArr[j++];
    }

    while(i < n1)
        v[k++] = leftArr[i++];

    while(j < n2)
        v[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}

void mergeSort(int v[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);

        merge(v, left, mid, right);
    }
}

int partition(int v[], int low, int high)
{
    int pivot = v[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
        if(v[j] < pivot)
        {
            i++;
            swap(&v[i], &v[j]);
        }

    swap(&v[i + 1], &v[high]);
    return i + 1;
}

void quick(int v[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(v, low, high);
        quick(v, low, pi - 1);
        quick(v, pi + 1, high);
    }
}


int main()
{
    int v[] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10};
    float vf[] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
    char vc[] = {'C','Y','E','B','D','W','a','O','s','Y'};
    int n = 10;

    int v1[10], v2[10], v3[10], v4[10], v5[10];

    for(int i = 0; i < n; i++)
    {
        v1[i] = v[i];
        v2[i] = v[i];
        v3[i] = v[i];
        v4[i] = v[i];
        v5[i] = v[i];
    }

    bubble(v1, n);
    printf("Bubble:    ");
    print(v1, n);

    insertion(v2, n);
    printf("Insertion: ");
    print(v2, n);

    selection(v3, n);
    printf("Selection: ");
    print(v3, n);

    mergeSort(v4, 0, n - 1);
    printf("Merge:     ");
    print(v4, n);

    quick(v5, 0, n - 1);
    printf("Quick:     ");
    print(v5, n);

    return 0;
}