#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

void insert(int data, node **root) {
    node *tmp = (node *)malloc(sizeof(tmp));
    
    if (tmp == NULL) {
        return;
    }
    tmp -> data = data;
    tmp -> left = tmp -> right = NULL;
    
    if (*root == NULL) {
        *root = tmp;
        return;
    }
    queue<node *> q;
    q.push(*root);
    
    while(!q.empty()) {
        node *top = q.front();
        q.pop();
        
        if (top -> left != NULL && top -> right != NULL) {
            q.push(top -> left);
            q.push(top -> right);
        } else {
            if (top -> left != NULL && top -> right == NULL) {
                top -> right = tmp;
            } else {
                top -> left = tmp;
            }
            return;
        }
    }
}

void traverse(node *root) {
    if (root == NULL) {
        return;
    }
    queue<node *> q;
    q.push(root);
    
    while(!q.empty()) {
        node *tmp = q.front();
        q.pop();
        
        cout<<tmp->data<<" ";
        
        if (tmp -> left) {
            q.push(tmp->left);
        }
        if (tmp -> right) {
            q.push(tmp -> right);
        }
    }
}

int main()
{
    node *root = NULL;
    
    insert(3, &root);
    insert(4, &root);
    insert(5, &root);
    insert(1, &root);
    insert(2, &root);
    insert(0, &root);
    insert(9, &root);
    
    traverse(root);

    return 0;
}

