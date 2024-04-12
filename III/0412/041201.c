#include <stdio.h>
#include <stdlib.h>


struct Tool {
    char name[100];
    int quantity;
    float price;
};

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    
    struct Tool tools[100];
    tools[3] = (struct Tool) {"Electric sander", 7, 57.98};
    tools[17] = (struct Tool) {"Hammer", 76, 11.99};
    tools[24] = (struct Tool) {"Jig saw", 21, 11.00};
    tools[39] = (struct Tool) {"Lawn mower", 3, 79.50};
    tools[56] = (struct Tool) {"Power saw", 18, 99.99};
    tools[68] = (struct Tool) {"Screwdriver", 106, 6.99};
    tools[77] = (struct Tool) {"Sledge Hammer", 11, 21.50};
    tools[83] = (struct Tool) {"Wrench", 34, 7.50};

    int inputs[3];
    while (fscanf(input_file, "%d %d %d", &inputs[0], &inputs[1], &inputs[2]) != EOF){
        // printf("%d %d %d\n", inputs[0], inputs[1], inputs[2]);
        // 1: 進貨 2: 出貨
        int in_out = inputs[0];
        int record = inputs[1];
        int quantity = inputs[2];

        if (in_out == 1) {
            tools[record].quantity += quantity;
            fprintf(output_file, "%d %s %d %.2f\n", record, tools[record].name, tools[record].quantity, tools[record].price);
        } else if (in_out == 2) {
            if (tools[record].quantity < quantity) {
                fprintf(output_file, "insufficient quantity\n");
            } else {
                tools[record].quantity -= quantity;
                fprintf(output_file, "%d %s %d %.2f\n", record, tools[record].name, tools[record].quantity, tools[record].price);
            }
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}