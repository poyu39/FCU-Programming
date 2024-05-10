#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *create_node(int data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *insert_node(Node *head, int data){
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

Node *sort_node(Node *head){
    Node *temp = head;
    while(temp != NULL){
        Node *temp2 = temp->next;
        while(temp2 != NULL){
            if(temp->data > temp2->data){
                int temp_data = temp->data;
                temp->data = temp2->data;
                temp2->data = temp_data;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return head;
}

int sum_node(Node *head) {
    int sum = 0;
    Node *temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

float avg_node(Node *head) {
    int sum = 0;
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    return (float) sum / count;
}

void display_node(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        printf(temp->next == NULL ? "" : " ");
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;
    int input;
    int counter = 0;
    while (counter < 15) {
        scanf("%d", &input);
        head = insert_node(head, input);
        counter++;
        if (counter % 3 == 0) {
            head = sort_node(head);
            display_node(head);
            printf("\n");
        }
    }
    printf("Sum: %d\n", sum_node(head));
    printf("Average: %.2f\n", avg_node(head));
    return 0;
}