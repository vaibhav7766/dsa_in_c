#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* create(){
    int x;
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node): ");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("Enter left child of %d: ",x);
    newnode->left=create();
    printf("Enter right child of %d: ",x);
    newnode->right=create();
    return newnode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    struct node* root = NULL;
    int choice, data, key;
    
    while (1) {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Node\n");
        printf("6. Delete Node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &key);
                struct node* searchResult = search(root, key);
                if (searchResult != NULL) {
                    printf("Node found: %d\n", searchResult->data);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 6:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}