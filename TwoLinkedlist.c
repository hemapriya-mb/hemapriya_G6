/*!2:26$!32:665$!64:65$ take digits before ':' as input to the first linked list 
and digit before $ to second linked list insertion starts from ! Separate them and print take user input*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insertNode(struct node** head, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    char str[50];
    printf("Enter input string in the format(!2:26$!32:665$): ");
    fgets(str, 50, stdin);
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int i = 0;
    while (str[i] != '\0') {
           if (str[i] == '!') {
              i++;
                   int num1 = 0;
                   while (str[i] != ':') {
                       num1 = num1 * 10 + (str[i] - '0');
                       i++;
                   }
                   i++;
            
                   int num2 = 0;
                   while (str[i] != '$') {
                       num2 = num2 * 10 + (str[i] - '0');
                       i++;
                   }
            insertNode(&head1, num1);
            insertNode(&head2, num2);
            i++;
           } 
           else {
               i++;
           }
    }
    printf("Linked List 1: ");
    printList(head1);
    printf("\nLinked List 2: ");
    printList(head2);

    return 0;
}
