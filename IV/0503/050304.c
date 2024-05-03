#include <stdio.h>
#include <stdlib.h>

#define CREATION 1
#define INSERTION 2
#define DELETION 3
#define SEARCHING 4

void create_node(int data, int *list, int *size) {
    list[*size] = data;
    *size += 1;
}

void insert_node(int data, int *list, int *size) {
    list[*size] = data;
    *size += 1;
}

void delete_node(int data, int *list, int *size) {
    for (int i = 0; i < *size; i++) {
        if (list[i] == data) {
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];
            }
            *size -= 1;
            return;
        }
    }
}

void sort_node(int *list, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int search_node(int data, int *list, int size) {
    for (int i = 0; i < size; i++) {
        if (list[i] == data) {
            return 1;
        }
    }
    return 0;
}

void display_node(int *list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", list[i]);
        printf(i == size - 1 ? "" : " ");
    }
    printf("\n");
}

int main() {
    int op;
    int list[1000];
    int size = 0;
    while (scanf("%d", &op) != EOF) {
        if (op == 0) break;
        int data;
        scanf("%d", &data);
        if (op == SEARCHING) {
            if (search_node(data, list, size)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            continue;
        }
        if (op == CREATION) {
            create_node(data, list, &size);
        }
        if (op == INSERTION) {
            if (search_node(data, list, size) == 0) {
                insert_node(data, list, &size);
            }
        }
        if (op == DELETION) {
            delete_node(data, list, &size);
        }
        sort_node(list, size);
        display_node(list, size);
    }
    return 0;
}