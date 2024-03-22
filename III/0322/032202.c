#include <stdio.h>
#include <string.h>

void gen_matrix(int *matrix, int n) {
    int *ptr_matrix = matrix;
    int *ptr_n = &n;
    for (int i = 0; i < *ptr_n; i++) {
        // 字串轉數字
        char input_str[*ptr_n];
        scanf("%s", input_str);
        for (int j = 0; j < *ptr_n; j++) {
            *(ptr_matrix + i * *ptr_n + j) = input_str[j] - '0';
        }
    }
}

void row(int *matrix, int n, int a, int b) {
    int *ptr_matrix = matrix;
    int *ptr_n = &n;
    int *ptr_a = &a;
    int *ptr_b = &b;
    // -1 去對應到 0-based index
    *ptr_a = *ptr_a - 1;
    *ptr_b = *ptr_b - 1;

    for (int i = 0; i < *ptr_n; i++) {
        int temp = *(ptr_matrix + *ptr_a * *ptr_n + i);
        *(ptr_matrix + *ptr_a * *ptr_n + i) = *(ptr_matrix + *ptr_b * *ptr_n + i);
        *(ptr_matrix + *ptr_b * *ptr_n + i) = temp;
    }
}

void col(int *matrix, int n, int a, int b) {
    int *ptr_matrix = matrix;
    int *ptr_n = &n;
    int *ptr_a = &a;
    int *ptr_b = &b;
    // -1 去對應到 0-based index
    *ptr_a = *ptr_a - 1;
    *ptr_b = *ptr_b - 1;

    for (int i = 0; i < *ptr_n; i++) {
        int temp = *(ptr_matrix + i * *ptr_n + *ptr_a);
        *(ptr_matrix + i * *ptr_n + *ptr_a) = *(ptr_matrix + i * *ptr_n + *ptr_b);
        *(ptr_matrix + i * *ptr_n + *ptr_b) = temp;
    }
}

void inc(int *matrix, int n) {
    int *ptr_matrix = matrix;
    int *ptr_n = &n;
    for (int i = 0; i < *ptr_n; i++) {
        for (int j = 0; j < *ptr_n; j++) {
            *(ptr_matrix + i * *ptr_n + j) = (*(ptr_matrix + i * *ptr_n + j) + 1) % 10;
        }
    }
}

void dec(int *matrix, int n) {
    int *ptr_matrix = matrix;
    int *ptr_n = &n;
    for (int i = 0; i < *ptr_n; i++) {
        for (int j = 0; j < *ptr_n; j++) {
            *(ptr_matrix + i * *ptr_n + j) = *(ptr_matrix + i * *ptr_n + j) - 1;
            if (*(ptr_matrix + i * *ptr_n + j) < 0) {
                *(ptr_matrix + i * *ptr_n + j) = 10 + *(ptr_matrix + i * *ptr_n + j);
            }
        }
    }
}

void transpose(int *matrix, int n) {
    int *ptr_matrix = matrix;
    int *ptr_n = &n;
    for (int i = 0; i < *ptr_n; i++) {
        for (int j = i; j < *ptr_n; j++) {
            int temp = *(ptr_matrix + i * *ptr_n + j);
            *(ptr_matrix + i * *ptr_n + j) = *(ptr_matrix + j * *ptr_n + i);
            *(ptr_matrix + j * *ptr_n + i) = temp;
        }
    }
}

void exec_command(int *matrix, int n, char *command) {
    if (strcmp(command, "row") == 0) {
        int a, b;
        int *ptr_a = &a;
        int *ptr_b = &b;
        scanf("%d %d", ptr_a, ptr_b);
        row(matrix, n, a, b);
    } else if (strcmp(command, "col") == 0) {
        int a, b;
        int *ptr_a = &a;
        int *ptr_b = &b;
        scanf("%d %d", ptr_a, ptr_b);
        col(matrix, n, a, b);
    } else if (strcmp(command, "inc") == 0) {
        inc(matrix, n);
    } else if (strcmp(command, "dec") == 0) {
        dec(matrix, n);
    } else if (strcmp(command, "transpose") == 0) {
        transpose(matrix, n);
    }
}

void output(int *matrix, int n) {
    static int case_counter = 1;
    int *ptr_case_counter = &case_counter;
    int *ptr_matrix = matrix;
    int *ptr_n = &n;
    printf("Case #%d\n", *ptr_case_counter);
    for (int i = 0; i < *ptr_n; i++) {
        for (int j = 0; j < *ptr_n; j++) {
            printf("%d", *(ptr_matrix + i * *ptr_n + j));
        }
        printf("\n");
    }
    printf("\n");
    *ptr_case_counter = *ptr_case_counter + 1;
}

int main() {
    int t;
    int *ptr_t = &t;
    scanf("%d", ptr_t);

    for (int i = 0; i < *ptr_t; i++) {
        int n;
        int *ptr_n = &n;
        scanf("%d", ptr_n);
        
        int matrix[*ptr_n * *ptr_n];
        gen_matrix(matrix, *ptr_n);
        
        int m;
        int *ptr_m = &m;
        scanf("%d", ptr_m);

        for (int i = 0; i < *ptr_m; i++) {
            char command[15];
            scanf("%s", command);
            exec_command(matrix, *ptr_n, command);
        }
        output(matrix, *ptr_n);
    }
    return 0;
}