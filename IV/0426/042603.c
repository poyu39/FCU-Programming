#include <stdio.h>

#define kuti 10000000
#define lakh 100000
#define hajar 1000
#define shata 100

void get_bangla(long long num){
    if(num >= kuti){
        get_bangla(num / kuti);
        printf(" kuti");
        num %= kuti;
    }
    if(num >= lakh){
        get_bangla(num / lakh);
        printf(" lakh");
        num %= lakh;
    }
    if(num >= hajar){
        get_bangla(num / hajar);
        printf(" hajar");
        num %= hajar;
    }
    if(num >= shata){
        get_bangla(num / shata);
        printf(" shata");
        num %= shata;
    }
    if(num > 0) printf(" %d", num);
}

int main() {
    int counter = 1;
    long long int num;
    while (scanf("%lld", &num) != EOF) {
        printf("%4d.", counter);
        if (num == 0) {
            printf(" 0\n");
            counter++;
            continue;
        }
        get_bangla(num);
        printf("\n");
        counter++;
    }
    return 0;
}