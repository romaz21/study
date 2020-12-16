#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 100

int main() {
    char * s = malloc(SIZE*sizeof(char));
    scanf("%s", s);
    int a[SIZE][SIZE];
    int j, i = 0;
    int m = strlen(s);
    double k = log(m)/log(2);
    int z = (int)k;

    int b[m][z];
    int t = m;

    for(i = 0; i < z; i++) {
        for(j = 0; j < m ; j++) {
            if(j % t >= t/2) {
                b[j][i] = 1;
            } else {
                b[j][i] = 0;
            }
        }
        t /= 2;
    }


    for(i = 0; i < m; i++) {
        a[0][i] = (int)s[i] - 48;
    }
    for(i = 1; i < m; i++) {
        for(j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
    for(i = 1; i < m; i++) {
        for(j = 0; j < m - 1; j++) {

            a[i][j] = (a[i-1][j] + a[i-1][j+1]) % 2;

        }
    }

    for(i = 0; i < m; i++) {
        if(a[i][0] == 1) {
            if(i == 0) {
                printf("1");
            }
            for(j = 0; j < z; j++) {
                if(b[i][j] == 1) {
                    printf("x%d", j+1);
                }

            }
            printf(" ");
        }
    }
    free(s);
    printf("\nNazmite 'e' chrob viitu");
    char c;
    while((c = getchar()) != 0) {
        if(c == 'e') {
            return 0;
        }
    }
    //char x;
    //x = getchar();

    return 0;
}
