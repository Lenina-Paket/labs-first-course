#include <stdio.h>
#define SIZE 100

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int value;
    int frst_indexes[SIZE], frst_values[SIZE];
    int frst_fill = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &value);
            if (value != 0) {
                //printf("Введенное число с индексом %d;%d: %d\n", i, j, value);
                frst_indexes[frst_fill] = (i - 1) * m + j - 1;
                //printf("Индекс получился: %d\n", frst_indexes[frst_fill]);
                frst_values[frst_fill] = value;
                frst_fill++;
            }
        }
    }

    int a, b;
    scanf("%d %d", &a, &b);
    int scnd_indexes[SIZE], scnd_values[SIZE];
    int scnd_fill = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            scanf("%d", &value);
            if (value != 0) {
                //printf("%d %d", i, j);
                scnd_indexes[scnd_fill] = (i - 1) * b + j - 1;
                scnd_values[scnd_fill] = value;
                scnd_fill++;
            }
        }
    }
    if (a != m) printf("Умножение is impossible!\n");
    else {
        int x, y, x2, y2;
        int index, index2;
        int mult_idx[SIZE], mult_val[SIZE];
        int mult_fill = 0;
        for (int str = 1; str <= n; ++str) {

            for (int clmn = 1; clmn <= b; ++clmn) {
                int sum = 0;
                for (int i = 0; i < frst_fill; i++) {
                    index = frst_indexes[i];

                    x = (index / m) + 1;
                    y = (index % m) + 1;
                    
                    for (int i2 = 0; i2 < scnd_fill; i2++) {
                        index2 = scnd_indexes[i2];
                        
                        x2 = (index2 / b) + 1;
                        y2 = (index2 % b) + 1;
                        //printf("frst %d %d : %d\n", x, y, frst_values[i]);
                        //printf("scnd %d %d : %d\n", x2, y2, scnd_values[i2]);
                        if ((y == x2) && ((x == str) && (y2 == clmn))) {
                            //printf("%d %d : %d\n", x, y, frst_values[i]);
                            //printf("%d %d : %d\n", x2, y2, scnd_values[i2]);
                            sum += frst_values[i] * scnd_values[i2];
                        }
                    }
                }

            if (sum != 0) {
                //printf("Индекс итоговых значений %d %d\n", str, clmn);
                mult_idx[mult_fill] = (str - 1) * b + clmn - 1;
                mult_val[mult_fill] = sum;
                mult_fill++;
            }
            }
        }
        printf("\n");
        

        printf("Первая матрица в представлении:\n");
        for (int i = 0; i < frst_fill; i++) {
            printf("%d : %d\n", frst_indexes[i], frst_values[i]);
        }
        printf("\n");

        printf("Вторая матрица в представлении:\n");
        for (int i = 0; i < scnd_fill; i++) {
            printf("%d : %d\n", scnd_indexes[i], scnd_values[i]);
        }
        printf("\n");

        printf("Итоговая матрица в представлении:\n");
        for (int i = 0; i < mult_fill; i++) {
            printf("%d : %d\n", mult_idx[i], mult_val[i]);
        }
        printf("\n");

        int ans_ind = 0;
        int x_ans, y_ans;
        int isDiag = 1;
        //printf("%d %d\n", n, b);
        if (n != b) isDiag = 0;
        printf("Итоговая матрица в классическом представлении:\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= b; j++) {
                //printf("%d : %d\n", i, x_ans);
                //printf("%d : %d\n", j, y_ans);
                x_ans = (mult_idx[ans_ind] / b) + 1;
                y_ans = (mult_idx[ans_ind] % b) + 1;
                //printf("%d %d\n", x_ans, y_ans);
                if (i == x_ans && j == y_ans) {
                    if (x_ans != y_ans) isDiag = 0;
                    printf ("%d ", mult_val[ans_ind]);
                    ans_ind++;
                } else {
                    printf ("0 ");
                    //printf("%d %d", i, j);
                    if (i == j) isDiag = 0;
                }
            }
            printf("\n");  
        }
    if (isDiag == 1) printf("Diag\n");
    else printf("NO\n");
    }

return 0;    
}
