#include <stdio.h>

int main() 
{
    int v[] = {3, 1, 4, 15, 9, 2, 6, 5, 8, 12};
    int n = sizeof(v) / sizeof(v[0]);
    int sum;

    while(1) {
        printf("\nIntrodu suma sau -1 pentru a iesi: ");
        scanf("%d", &sum);
        if (sum == -1)
            break;

        int gasit = 0;
        
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(v[i] + v[j] == sum) {
                    printf("Perechea: %d + %d = %d\n", v[i], v[j], sum);
                    gasit = 1;
                    break;
                }
            }
            if(gasit)
                break;
        }
        
        if(!gasit) {
            printf("Nu exista");
        }
    }

    return 0;
}