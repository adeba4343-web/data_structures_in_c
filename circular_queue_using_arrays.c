#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = x;
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue Underflow\n");
    else if (front == rear) {
        front = -1;
        rear = -1;
    } else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        int i = front;
        while (1) {
            printf("%d ", cq[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int ch, x;

    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}
