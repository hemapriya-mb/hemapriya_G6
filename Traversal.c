#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int value) {
    if (root == NULL) {
        struct node newnode = (struct node) malloc(sizeof(struct node));
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

int height(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
  
    return 1 + max(left_height, right_height);
}

void inorderTraversal(struct node *root) {
    if (root == NULL) {
        return ;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  
    return ;
}

void preorderTraversal(struct node *root) {
    if (root == NULL) {
        return ;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  
    return ;
}

void postorderTraversal(struct node *root) {
    if (root == NULL) {
        return ;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  
    return ;
}

void print_level(struct node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

void breadthFirstTraversal(struct node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        print_level(root, i);
    }
}

int main(){
    struct node *root=NULL;
    int num,data,value;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for (int i=0;i<num;i++){
        scanf("%d",&data);
        root = insert(root,data);
    }
    printf("Inorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder traversal of the tree: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder traversal of the tree: ");
    postorderTraversal(root);
    printf("\n");
    printf("Breadth traversal of the tree: ");
    breadthFirstTraversal( root);
    printf("\n");
      
    return 0;
}
