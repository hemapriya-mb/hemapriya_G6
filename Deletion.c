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

void print(struct node *root) {
    if (root == NULL) {
        return ;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
  
    return ;
}

struct node* delete_node(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete_node(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            
            return NULL;
        }
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            
            return temp;
        }
        else {
            struct node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    
    return root;
}

int main(){
    struct node *root=NULL;
    int num,data,value,to_delete;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for (int i=0;i<num;i++){
        scanf("%d",&data);
        root = insert(root,data);
    }
    printf("Inorder traversal of the tree: ");
    print(root);
    printf("\n");
    printf("enter the value to be deleted\n");
    scanf("%d",&to_delete);
    root = delete_node(root,to_delete);
    printf("After deletion: ");
    print(root);
    printf("\n");
   
    return 0;
}
