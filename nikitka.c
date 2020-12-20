#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50

int isL(char * s) {

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
    int p = 0;
    for(i = 0; i < m; i++) {
        if(a[i][0] == 1) {
            if(m == 1) {
                return 0;
            }
            for(j = 0; j < z; j++) {

                if(b[i][j] == 1) {
                   // printf("x%d", j+1);
                    p++;
                }

            }
            if(p > 1) {
                return 1;
            }
            //printf("%d\n", p);
            p = 0;

        }
    }
    return 0;
}
int isT0(char * s) {
    if(s[0] == '0') {
        return 0;
    }
    return 1;
}

int isT1(char * s) {
    int m = strlen(s);
    if(s[m-1] == '1') {
        return 0;
    }
    return 1;
}

int isM(char * s) {
    int m = strlen(s);
    int k = log(m) / log(2);
    for(int i = 0; i < k ; i++) {
        int l = pow(2, k);
        for(int j = 0; j + l < m; j++) {
            if(s[j] - s[j + l] > 0) {
                return 0;
            }
        }
    }
    return 1;
}

int inS(char * s) {
    int m = strlen(s);
    for(int i = 0; i < m/2; i++) {
        if(s[i] == s[m-i - 1]) {
            return 1;
        }
    }
    return 0;
}


int main() {
    int k;
    scanf("%d", &k);
    int t1 = 0, t0 = 0, m = 0, s0 = 0, l = 0;
    char * s = malloc(SIZE * sizeof(char));
    int i;
    for(i = 0; i < k; i++) {
        scanf("%s", s);
        t1 += isT1(s);
        t0 += isT0(s);
        m += isM(s);
        l += isL(s);
        s0 += inS(s);
        //printf("%d", isL(s));
    }
   // printf("%d", isL(s));
    if(t1 * t0 * m * l * s0 != 0) {
        printf("YES");
    } else {
        printf("NO");
    }
    //printf("%d", isM(s));
    free(s);

    printf("\n'e' to exit\n");
    char c;
    while((c = getchar()) != 0) {
        if(c == 'e') {
            return 0;
        }
    }
    return 0;
}
