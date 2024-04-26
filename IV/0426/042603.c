#include <stdio.h>

#define kuti 10000000
#define lakh 100000
#define hajar 1000
#define shata 100

void get_bangla(long long int num, long long int *plc) {
    if (num / kuti > 0) {
        plc[0] = num / kuti;
        num %= kuti;
    }
    if (num / lakh > 0) {
        plc[1] = num / lakh;
        num %= lakh;
    }
    if (num / hajar > 0) {
        plc[2] = num / hajar;
        num %= hajar;
    }
    if (num / shata > 0) {
        plc[3] = num / shata;
        num %= shata;
    }
    plc[4] = num;
}

int check_bangla(long long int num) {
    if (num / kuti > 0) return 1;
    if (num / lakh > 0) return 1;
    if (num / hajar > 0) return 1;
    if (num / shata > 0) return 1;
    return 0;
}

int main() {
    int counter = 1;
    int need_space = 0;
    char bangla[5][6] = {"kuti", "lakh", "hajar", "shata", ""};
    long long int num;
    while (scanf("%lld", &num) != EOF) {
        int lp = 0;
        long long int output[10][5] = {0};
        while (1) {
            long long int plc[5] = {0, 0, 0, 0, 0};
            get_bangla(num, plc);
            if (lp > 0 && plc[4] > 0) {
                output[lp - 1][0] = plc[4];
            }
            for (int i = 0; i < 5; i++) {
                output[lp][i] = plc[i];
            }
            num = plc[0];
            if (check_bangla(num)) {
                lp++;
            } else {
                break;
            }
        }
        printf("%4d. ", counter);
        for (int i = lp; i >= 0; i--) {
            for (int j = 0; j < 5; j++) {
                if (output[i][j] != 0) {
                    if (need_space) printf(" ");
                    printf("%lld %s", output[i][j], bangla[j]);
                    need_space = 1;
                }
            }
        }
        printf("\n");
        counter++;
    }
    return 0;
}