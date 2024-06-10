#include <stdio.h>
#include <stdlib.h>

struct Point {
    float x;
    float y;
};

struct Rect {
    struct Point points[2];
};


int main() {
    char flag = ' ';
    struct Rect rect[10];
    int rect_count = 0;
    while (scanf("%s", &flag) != EOF) {
        if (flag == '*') break;
        scanf("%f %f %f %f", &rect[rect_count].points[0].x, &rect[rect_count].points[0].y, &rect[rect_count].points[1].x, &rect[rect_count].points[1].y);
        rect_count++;
    }
    struct Point input_point = {0, 0};
    int point_count = 1;
    while (scanf("%f %f", &input_point.x, &input_point.y) != EOF) {
        if (input_point.x >= 9999.9 && input_point.y >= 9999.9) break;
        int is_in = 0;
        for (int i = 0; i < rect_count; i++) {
            if (input_point.x > rect[i].points[0].x && input_point.x < rect[i].points[1].x && input_point.y < rect[i].points[0].y && input_point.y > rect[i].points[1].y) {
                printf("Point %d is contained in figure %d\n", point_count, i + 1);
                is_in = 1;
            }
        }
        if (!is_in) printf("Point %d is not contained in any figure\n", point_count);
        point_count++;
    }
}
