#include <stdio.h>
#include <string.h>


/*
    長度:公分、公尺 (centimeter, meter)
    重量:公斤、磅 (kilogram, pound)
    容量:公升、毫升 (liter, milliliter)
*/
struct Unit {
    char type[100];
    char name[100];
    float value;
};

void type_detect(struct Unit *uint) {
    if (strcmp(uint->name, "centimeters") == 0 || strcmp(uint->name, "meters") == 0) {
        strcpy(uint->type, "length");
    } else if (strcmp(uint->name, "kilograms") == 0 || strcmp(uint->name, "pounds") == 0) {
        strcpy(uint->type, "weight");
    } else if (strcmp(uint->name, "liters") == 0 || strcmp(uint->name, "milliliters") == 0) {
        strcpy(uint->type, "volume");
    } else {
        strcpy(uint->type, "unknown");
    }
}

void convert(struct Unit *unit_1, struct Unit *unit_2) {
    if (strcmp(unit_1->type, unit_2->type) == 0) {
        if (strcmp(unit_1->type, "length") == 0) {
            if (strcmp(unit_1->name, "centimeters") == 0) {
                unit_1->value = unit_2->value * 100;
            } else {
                unit_1->value = unit_2->value / 100;
            }
        } else if (strcmp(unit_1->type, "weight") == 0) {
            if (strcmp(unit_1->name, "kilograms") == 0) {
                unit_1->value = unit_2->value / 2.20462;
            } else {
                unit_1->value = unit_2->value * 2.20462;
            }
        } else if (strcmp(unit_1->type, "volume") == 0) {
            if (strcmp(unit_1->name, "liters") == 0) {
                unit_1->value = unit_2->value / 1000;
            } else {
                unit_1->value = unit_2->value * 1000;
            }
        }
    } else {
        if (strcmp(unit_1->type, "unknown") == 0) {
            unit_1->value = -1;
        } else if (strcmp(unit_2->type, "unknown") == 0) {
            unit_2->value = -1;
        } else {
            unit_1->value = -1;
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    char buffer[100];

    while (fgets(buffer, 100, input_file) != NULL) {
        struct Unit unit_1, unit_2;
        sscanf(buffer, "How many %s are in %f %s?", unit_1.name, &unit_2.value, unit_2.name);
        unit_2.name[strlen(unit_2.name) - 1] = '\0';
        type_detect(&unit_1);
        type_detect(&unit_2);
        convert(&unit_1, &unit_2);
        if (unit_1.value == -1 || unit_2.value == -1) {
            // printf("ERROR\n");
            fprintf(output_file, "ERROR\n");
        } else {
            // printf("%s %.1f %s = %s %.1f %s\n", unit_1.type, unit_1.value, unit_1.name, unit_2.type, unit_2.value, unit_2.name);
            // printf("%.1f\n", unit_1.value);
            fprintf(output_file, "%.1f\n", unit_1.value);
        }
    }
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}