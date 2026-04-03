#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void copy(int src[], int dest[])
{
    for (int i = 0; i < N; i++)
        dest[i] = src[i];
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble(int v[])
{
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(&v[j], &v[j + 1]);
}

void insertion(int v[])
{
    for (int i = 1; i < N; i++)
    {
        int key = v[i], j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void selection(int v[])
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
            if (v[j] < v[min]) min = j;
        swap(&v[i], &v[min]);
    }
}


void merge(int v[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = v[l + i];
    for (int j = 0; j < n2; j++) R[j] = v[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        v[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int v[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}



int partition(int v[], int low, int high)
{
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (v[j] < pivot)
        {
            i++;
            swap(&v[i], &v[j]);
        }

    swap(&v[i + 1], &v[high]);
    return i + 1;
}

void quickSort(int v[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}



int main()
{
    int original[N];
    int v[N];

    srand(time(NULL));


    for (int i = 0; i < N; i++)
        original[i] = rand() % 100000;

    double t_bubble, t_insertion, t_selection, t_merge, t_quick;

    clock_t start, end;

    copy(original, v);
    start = clock();
    bubble(v);
    end = clock();
    t_bubble = (double)(end - start) / CLOCKS_PER_SEC;


    copy(original, v);
    start = clock();
    insertion(v);
    end = clock();
    t_insertion = (double)(end - start) / CLOCKS_PER_SEC;


    copy(original, v);
    start = clock();
    selection(v);
    end = clock();
    t_selection = (double)(end - start) / CLOCKS_PER_SEC;


    copy(original, v);
    start = clock();
    mergeSort(v, 0, N - 1);
    end = clock();
    t_merge = (double)(end - start) / CLOCKS_PER_SEC;

    copy(original, v);
    start = clock();
    quickSort(v, 0, N - 1);
    end = clock();
    t_quick = (double)(end - start) / CLOCKS_PER_SEC;


    printf("Timp Bubble:    %.5f sec\n", t_bubble);
    printf("Timp Insertion: %.5f sec\n", t_insertion);
    printf("Timp Selection: %.5f sec\n", t_selection);
    printf("Timp Merge:     %.5f sec\n", t_merge);
    printf("Timp Quick:     %.5f sec\n", t_quick);


    double min = t_bubble;
    char *best = "Bubble";

    if (t_insertion < min) { min = t_insertion; best = "Insertion"; }
    if (t_selection < min) { min = t_selection; best = "Selection"; }
    if (t_merge < min) { min = t_merge; best = "Merge"; }
    if (t_quick < min) { min = t_quick; best = "Quick"; }

    printf("\nCel mai rapid: %s (%.5f sec)\n", best, min);

    return 0;
}