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

Node *merge_node(Node *head_1, Node *head_2){
    Node *temp = head_1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head_2;
    return head_1;
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

void display_node(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        printf(temp->next == NULL ? "" : " ");
        temp = temp->next;
    }
}


int main() {
    Node *head_1 = NULL;
    Node *head_2 = NULL;
    Node *merged = NULL;
    int input;
    while (scanf("%d", &input) != EOF) {
        head_1 = insert_node(head_1, input);
        // 檢查換行
        if (getchar() == '\n') break;
    }
    while (scanf("%d", &input) != EOF) {
        head_2 = insert_node(head_2, input);
        if (getchar() == '\n') break;
    }
    merged = merge_node(head_1, head_2);
    merged = sort_node(merged);
    display_node(merged);
    return 0;
}