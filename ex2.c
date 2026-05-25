#include <stdio.h>

int dp[6][16]; 

int rezolvaRucsac(int capacitate, int greutati[], int valori[], int n) {

    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= capacitate; w++)


            if (i == 0 || w == 0)
                dp[i][w] = 0;
                
            else if (greutati[i - 1] <= w) {
                
                int nu_iau = dp[i - 1][w];
                int iau = valori[i - 1] + dp[i - 1][w - greutati[i - 1]];

                if (iau > nu_iau)
                    dp[i][w] = iau;
                else
                    dp[i][w] = nu_iau;
                    
            } 

            else
                dp[i][w] = dp[i - 1][w];

    return dp[n][capacitate];
}

int main() {

    int capacitate = 15;
    int n = 5;
  
    int valori[]   = {4,  2, 2, 1, 10};
    int greutati[] = {12, 2, 1, 1, 4};


    int valoare_maxima = rezolvaRucsac(capacitate, greutati, valori, n);
    printf("Valoarea maxima posibila: $%d\n\n", valoare_maxima);


    printf("Obiectele alese sunt:\n");
    int w = capacitate;
    
    for (int i = n; i > 0; i--)
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d kg - val: $%d\n", greutati[i - 1], valori[i - 1]);

            w = w - greutati[i - 1];
        }

    return 0;
}