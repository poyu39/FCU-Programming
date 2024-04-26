#include <stdio.h>
#include <string.h>


int get_side(int dic[], int side) {
    return dic[side];
}

int get_command_id(char command[]) {
    // 0: front, 1: right, 2: back, 3: left
    if (strcmp(command, "north") == 0) return 0;
    if (strcmp(command, "east") == 0) return 1;
    if (strcmp(command, "south") == 0) return 2;
    if (strcmp(command, "west") == 0) return 3;
}

void rotate(int *dic, int command_id) {
    int temp_dic[6];
    for (int i = 0; i < 6; i++) {
        temp_dic[i] = dic[i];
    }
    switch (command_id) {
        case 0:
            temp_dic[0] = dic[4];
            temp_dic[1] = dic[0];
            temp_dic[4] = dic[5];
            temp_dic[5] = dic[1];
            break;
        case 1:
            temp_dic[0] = dic[2];
            temp_dic[2] = dic[5];
            temp_dic[3] = dic[0];
            temp_dic[5] = dic[3];
            break;
        case 2:
            temp_dic[0] = dic[1];
            temp_dic[1] = dic[5];
            temp_dic[4] = dic[0];
            temp_dic[5] = dic[4];
            break;
        case 3:
            temp_dic[0] = dic[3];
            temp_dic[2] = dic[0];
            temp_dic[3] = dic[5];
            temp_dic[5] = dic[2];
            break;
    }
    for (int i = 0; i < 6; i++) {
        dic[i] = temp_dic[i];
    }
}

int main() {
    // 0: top, 1: front, 2: left, 3: right, 4: back, 5: down
    int command_num;
    while (scanf("%d", &command_num)) {
        if (command_num == 0) break;
        int dic[6] = {1, 2, 3, 4, 5, 6};
        for (int i = 0; i < command_num; i++) {
            char command[6];
            scanf("%s", command);
            rotate(dic, get_command_id(command));
        }
        printf("%d\n", get_side(dic, 0));
    }
}