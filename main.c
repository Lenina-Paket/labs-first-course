#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Структура для хранения группы рядом с минимальным баллом
typedef struct Values {
    int group;
    double ball;
} Val;

//Структура для хранения количества учеников групп с минимальным баллом
typedef struct Counters {
    int counter;
    int group;
} Cntrs;

int main(void) {
    FILE* fp = fopen("data.csv", "r");
    char dataRead[150]; 

    //Считал первую строку, чтобы не мешалась
    char* first;
    first = fgets(dataRead, 150, fp);

    char* cur_line;
    char* tmp;
    
    double min = 6;
    int i = 0, n = 8;
    Val mas[n];
    
    while (cur_line = fgets(dataRead, 150, fp)) {
        double sum = 0;
        int cnt = 0, gr;

        tmp = strtok(cur_line, ";");

        while (tmp != NULL) {
            if (cnt == 4) gr = atoi(tmp);
            if (cnt > 4) sum += atoi(tmp);
            tmp = strtok (NULL, ";");
            cnt++;
        }

        if (sum / 4 <= min) min = sum / 4;

        Val x;
        x.group = gr;
        x.ball = sum / 4;
        mas[i] = x;
        i++;
    }

    Cntrs sp[n];
    int fill = 0, firstFlag = 1;
    for (int i = 0; i < n; i++) {
        if ((mas[i].ball) == min) {
            if (firstFlag) {
                //printf("%d\n", mas[i].group);
                Cntrs x;
                x.counter = firstFlag;
                x.group = mas[i].group;
                sp[fill] = x;
                fill++;
                firstFlag--;
            } else {
                //printf("%d\n", mas[i].group);
                int flag = 1;
                for (int k = 0; k < fill+1; k++) {
                    if (mas[i].group == sp[k].group) {
                        sp[k].counter++;
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    Cntrs x;
                    x.group = mas[i].group;
                    x.counter = flag;
                    sp[fill] = x;
                    fill++;
                }
            }
        } 
    }
 
    int max = 0, ans;
    for (int j = 0; j < fill; j++) {
        if (sp[j].counter > max) {
            max = sp[j].counter;
            ans = sp[j].group;
        }
    }
    printf("%d\n", ans);
return 0;
}
