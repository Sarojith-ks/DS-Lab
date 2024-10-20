#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

void enqueue(int item);
void dequeue();
void display();

int main() {
    int n, choice;
    printf("\nQueue using linked list\n");
    printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    
    return 0;
}

void enqueue(int element) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    temp->link = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    temp = front;
    printf("Deleted element is: %d\n", temp->data);
    front = front->link;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display() {
    temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

