
#include <stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

void push(node **top, int data) {
    node *tmp = (node *) malloc(sizeof(node));
    
    if(tmp == NULL) {
        printf("Memory allocation is failed");
        return;
    }
    tmp -> data = data;
    tmp -> next = NULL;
    
    if(*top == NULL) {
        *top = tmp;
        return;
    } else {
        tmp -> next = *top;
        *top = tmp;
    }
}

int pop(node **top) {
    if(top == NULL) {
        return -1;
    }
    node *tmp = *top;
    *top = (*top) -> next;
    int data = tmp -> data;
    free(tmp);
    return data;
}

int main()
{
    int n, ele, index;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    
    node *s = NULL;
    
    for(index = 0; index < n; index++) {
        scanf("%d", &ele);
        push(&s, ele);
    }
    
    int data = pop(&s);
    
    printf("%d", data);
    
    data = pop(&s);
    
    printf("%d", data);
    
    data = pop(&s);
    
    printf("%d", data);
    return 0;
}
