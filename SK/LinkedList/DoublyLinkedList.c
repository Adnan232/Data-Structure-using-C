#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}*head = NULL, *tail = NULL;

int length = 0;
void display(int);

void prepend(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    if(head == NULL) {
        head = tail = node;
        node->next = NULL;
        length++;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
    length++;
}

void append(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    if(head == NULL) {
        node->prev = NULL;
        head = tail = node;
        length++;
        return;
    }
    tail->next = node;
    node->prev = tail;
    tail = node;
    length++;
}

void insertBefore(int index, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(index == 0) {
        prepend(data);
        return;
    }
    if(index == length-1) {
        append(data);
        return;
    }
    struct Node* temp = head;
    int i = 1;
    while(i <= index) {
        temp = temp->next;
        i++;
    }
    node->prev = temp->prev;
    node->next = temp;
    temp->prev->next = node;
    temp->prev = node;
    length++;
}

void insertAfter(int index, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    int i = 1;
    struct Node* temp = head;
    while(i <= index) {
        temp = temp->next;
        i++;
    }
    node->prev = temp;
    node->next = temp->next;
    temp->next->prev = node;
    temp->next = node;
    length++;
}

void removeBeg() {
    if(head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }
    printf("Deleted Element : %d\n", head->data);
    head = head->next;
    head->prev = NULL;
    length--;
    printf("\t");
    display(0);
}

void removeLast() {
    if(head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }
    printf("Deleted Element : %d\n", tail->data);
    tail = tail->prev;
    length--;
    printf("\t");
    display(0);
}

void removeIndex(int index) {
    if(head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }
    if(index == 0) {
        removeBeg();
        return;
    }
    if(index == length-1) {
        removeLast();
        return;
    }
    int i = 1;
    struct Node* temp = head;
    while(i <= index) {
        temp = temp->next;
        i++;
    }
    printf("Deleted Element : %d\n", temp->data);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    length--;
    printf("\t");
    display(0);
}

void search(int element) {
    if(head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    int i = 1;
    struct Node* temp = head;
    while(temp != NULL) {
        if(temp->data == element) {
            printf("Element is present at position %d\n", i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("Element is not present!\n");
}

void display(int reverse) {
    if(reverse) {
        struct Node* temp = tail;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
    } else {
        struct Node* temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    removeBeg();
    append(0);
    append(1);
    append(2);
    append(3);
    display(0);
    prepend(4);
    display(0);
    insertBefore(2, 5);
    display(0);
    insertAfter(2,6);
    display(0);
    printf("Reverse Order Traversal:\n");
    printf("\t");
    display(1);
    removeBeg();
    removeLast();
    removeIndex(2);
    search(6);
    search(5);
    return 0;
}
