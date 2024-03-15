#include <stdio.h>

void sort(int* arr, int len) {
    int *ptr_arr = arr;
    int *ptr_len = &len;
    for (int i = 0; i < *ptr_len; i++) {
        for (int j = 0; j < *ptr_len - i - 1; j++) {
            if (*(ptr_arr + j) > *(ptr_arr + j + 1)) {
                int temp = *(ptr_arr + j);
                *(ptr_arr + j) = *(ptr_arr + j + 1);
                *(ptr_arr + j + 1) = temp;
            }
        }
    }
}

int median(int* arr, int len) {
    int *ptr_arr = arr;
    int *ptr_len = &len;
    if (*ptr_len % 2 == 0) {
        return (*(ptr_arr + *ptr_len / 2) + *(ptr_arr + *ptr_len / 2 - 1)) / 2;
    } else {
        return *(ptr_arr + *ptr_len / 2);
    }
}

int main() {
    int t;
    int *ptr_t = &t;
    scanf("%d", ptr_t);
    for(int i = 0; i < *ptr_t; i++) {
        int members_age[11];
        int *ptr_members_age = members_age;
        int len = 0;
        int *ptr_len = &len;
        scanf("%d", ptr_len);

        for (int j = 0; j < *ptr_len; j++) {
            scanf("%d", ptr_members_age + j);
        }

        sort(ptr_members_age, *ptr_len);
        printf("Case %d: %d\n", i + 1, median(ptr_members_age, *ptr_len));
    }
}