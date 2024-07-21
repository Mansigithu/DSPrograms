#include <stdio.h>
#include <stdlib.h>

#define N 5

void insert(int queue[], int *rear, int *j);
void delete(int queue[], int *front, int *rear, int *x);
void display(int queue[], int front, int rear);

int main() {
    int queue[N], ch = 1, front = 0, rear = 0, j = 1, x = N;

    printf("Queue using Array\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (ch) {
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert(queue, &rear, &j);
                break;
            case 2:
                delete(queue, &front, &rear, &x);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options\n");
        }
    }
    return 0;
}

void insert(int queue[], int *rear, int *j) {
    if (*rear == N)
        printf("Queue is Full\n");
    else {
        printf("Enter number %d: ", (*j)++);
        scanf("%d", &queue[*rear]);
        (*rear)++;
    }
}

void delete(int queue[], int *front, int *rear, int *x) {
    if (*front == *rear)
        printf("Queue is empty\n");
    else {
        printf("Deleted Element is %d\n", queue[*front]);
        (*front)++;
        (*x)++;
    }
}

void display(int queue[], int front, int rear) {
    int i;
    if (front == rear)
        printf("Queue is Empty\n");
    else {
        printf("Queue Elements are:\n");
        for (i = front; i < rear; i++)
            printf("%d\n", queue[i]);
    }
}
