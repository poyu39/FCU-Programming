#include <stdio.h>


void hex2dec(int hex, int *dec) {
    char hex_char[8] = {0};
    sprintf(hex_char, "%d", hex);
    sscanf(hex_char, "%x", dec);
}

void dec2bin(int dec, int *bin) {
    int i = 0;
    while (dec > 0) {
        bin[i] = dec % 2;
        dec /= 2;
        i++;
    }
}

int count1s(int *bin) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (bin[i] == 1) count++;
    }
    return count;
}


int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int dec = 0;
        scanf("%d", &dec);
        
        int dec_bin[32] = {0};
        dec2bin(dec, dec_bin);
        int dec_1s = count1s(dec_bin);
        
        int hex_dec = 0;
        hex2dec(dec, &hex_dec);
        int hex_dec_bin[32] = {0};
        dec2bin(hex_dec, hex_dec_bin);

        int hex_dec_1s = count1s(hex_dec_bin);

        printf("%d %d\n", dec_1s, hex_dec_1s);
    }
}