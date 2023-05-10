#include <stdio.h>
#define SIZE 20


typedef struct node{
    int data;
    struct node *next;
}Node;


Node *createListOfNumbers(){

    Node *head; // Always keep the 'head' of the linked list
    Node *cur_node;

    int num;

    printf("Please enter a num or '-1' to finish" );
    scanf("%d", &num);

    if (-1 == num) return NULL;

    head = (Node*)malloc(sizeof(Node));
    cur_node = head;
    cur_node -> data = num;

    printf("Please enter a num or '-1' to finish" );
    scanf("%d", &num);

    while (-1 != num){
        cur_node -> next = (Node*)malloc(sizeof(Node));
        cur_node = cur_node->next;
        cur_node -> data = num;
        printf("Please enter a num or '-1' to finish" );
        scanf("%d", &num);
    }

    cur_node -> next = NULL;
    return head;    // Address of first node in this list
}


int main(){

    puts("Sup dawg");

    return 0;
}