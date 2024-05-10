#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char data[100];
	struct node *next;
};
typedef struct node Node;

Node *create_node(char data[100]){
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

Node *insert_node(Node *head, char data[100]){
    Node *new_node = create_node(data);
    if(head == NULL){
        head = new_node;
    } else {
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

void display_node(Node *head, FILE *output_file){
    Node *temp = head;
    while(temp != NULL){
        fprintf(output_file, "%s", temp->data);
        fprintf(output_file, temp->next == NULL ? "" : "\n");
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    char data[100];
    while (fscanf(input_file, "%s", data) != EOF) {
        head = insert_node(head, data);
    }
    display_node(head, output_file);
    return 0;
}