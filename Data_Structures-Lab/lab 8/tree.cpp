// Program to implement Tree ADT using linked list

#include <stdio.h>
#include <stdlib.h>

class Tree
{
private:
    struct node
    {
        char data;
        struct node *left;
        struct node *right;
    } *root;

public:
    Tree();
    node *getRoot();
    void insert(char);
    void preorder(node *root);
    void inorder(node *root);
    void postorder(node *root);
    bool search(char);
};

int main()
{
    int choice;
    char val;
    Tree tree;
    do
    {
        printf("\n\nMENU :\n 1. Insert\n 2. Preorder\n 3. Inorder\n 4. Postorder\n 5. Search\n 6. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert : ");
            scanf(" %c", &val);
            tree.insert(val);
            printf("Insertion Successful.\n");
            break;

        case 2:
            tree.preorder(tree.getRoot());
            break;

        case 3:
            tree.inorder(tree.getRoot());
            break;

        case 4:
            tree.postorder(tree.getRoot());
            break;

        case 5:
            printf("Enter element to search for : ");
            scanf(" %c", &val);
            if (tree.search(val))
            {
                printf("Element found !!\n");
            }
            else
            {
                printf("Element not found !!\n");
            }
            break;

        case 6:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Enter again.\n");
            break;
        }
    } while (choice != 6);
}

// Constructor function to initialize root to NULL
Tree::Tree()
{
    root = NULL;
}

// Getter function to get root
Tree::node *Tree::getRoot()
{
    return root;
}

// Function to insert an element using level order
// Time complexity - O(n)
void Tree::insert(char val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        return;
    }
    queue<node *> q;
    q.push(root);
    while (true)
    {
        node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = newnode;
            return;
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = newnode;
            return;
        }
    }
}

// Function to display the tree in preorder format
//Time complexity - O(n)
void Tree::preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c  ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to display the tree in inorder format
//Time complexity - O(n)
void Tree::inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%c  ", root->data);
    inorder(root->right);
}

// Function to display the tree in postorder format
//Time complexity - O(n)
void Tree::postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c  ", root->data);
}

// Function to search for an element
//Time complexity - O(h)
int Tree::search(char val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return 0;
    }
    queue<node *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        depth++;
        node *temp = q.front();
        q.pop();
        if (temp->data == val)
        {
            return log2(depth);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return -1;
}