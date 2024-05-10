#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char data;
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

Node *reverse_node(Node *head){
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void display_node(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%c", temp->data);
        printf(temp->next == NULL ? "" : " ");
        temp = temp->next;
    }
}

int main() {
    Node *head = NULL;
    char input;
    while (scanf("%c", &input) != EOF) {
        if (input == '\n') break;
        head = insert_node(head, input);
    }
    head = reverse_node(head);
    display_node(head);
    return 0;
}