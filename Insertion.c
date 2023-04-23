#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int value) {
    if (root == NULL) {
        struct node *newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        
        return newnode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

void print(struct node *root) {
    if (root == NULL) {
        return ;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
    
    return ;
}

int main(){
    struct node *root=NULL;
    int num,data;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for (int i=0;i<num;i++){
        scanf("%d",&data);
        root = insert(root,data);
    }
    print(root);
    printf("\n");
  
return 0;
}
