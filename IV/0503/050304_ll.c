#include <stdio.h>
#include <stdlib.h>

#define CREATION 1
#define INSERTION 2
#define DELETION 3
#define SEARCHING 4

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

Node *delete_node(Node *head, int data){
    if(head == NULL){
        return head;
    }
    if(head->data == data){
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    while(temp->next != NULL){
        if(temp->next->data == data){
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int search_node(Node *head, int data){
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int sort_node(Node *head){
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
}

void display_node(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\b\n");
}

int main() {
    Node *head = NULL;
    int op;
    while (scanf("%d", &op) != EOF) {
        if (op == 0) break;
        if(op == SEARCHING){
            int data;
            scanf("%d", &data);
            if(search_node(head, data)){
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            int data;
            scanf("%d", &data);
            if(op == CREATION){
                
                head = create_node(data);
            } else if(op == INSERTION){
                if (search_node(head, data) == 0) {
                    head = insert_node(head, data);
                }
            } else if(op == DELETION){
                head = delete_node(head, data);
            }
            sort_node(head);
            display_node(head);
        }
    }
    return 0;
}