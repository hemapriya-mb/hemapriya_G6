#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int value) {
    if (root == NULL) {
        struct node *newnode = (struct node) malloc(sizeof(struct node));
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

int max(int a, int b) {
    return (a > b ? a : b);
}

//to find height function
int height(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
  
    return 1 + max(left_height, right_height);
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
    int TreeHeight = height(root);
    printf("Height of the tree: %d\n",TreeHeight );
  
return 0;
}
