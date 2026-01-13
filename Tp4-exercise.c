#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack Node [cite: 12, 17]
typedef struct SNode {
    char data;
    struct SNode *next;
} SNode;

// Queue Node [cite: 22, 25]
typedef struct QNode {
    char data;
    struct QNode *next;
} QNode;

// Queue structure [cite: 28, 33]
typedef struct {
    QNode *front;
    QNode *rear;
} Queue;

// Stack Functions
SNode* push(SNode* top, char ch) { // [cite: 49, 50]
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = ch;
    newNode->next = top;
    return newNode;
}

SNode* pop(SNode* top, char* value) { // [cite: 51, 54]
    if (top == NULL) return NULL;
    SNode* temp = top;
    *value = temp->data;
    top = top->next;
    free(temp);
    return top;
}

// Queue Functions
void enqueue(Queue* q, char ch) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = ch;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

char dequeue(Queue* q) {
    if (q->front == NULL) return '\0';
    QNode* temp = q->front;
    char data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

int main() {
    char input[100];
    SNode* top = NULL;
    Queue q = {NULL, NULL};
    int isPalindrome = 1;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // [cite: 39]

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) { // [cite: 41]
            char ch = toupper(input[i]); // [cite: 40, 8]
            top = push(top, ch); // [cite: 42, 50]
            enqueue(&q, ch);     // 
        }
    }

    char sChar, qChar;
    while (top != NULL) {
        top = pop(top, &sChar); // [cite: 45, 54]
        qChar = dequeue(&q);    // [cite: 46]
        if (sChar != qChar) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) printf("Palindrome\n"); // [cite: 47]
    else printf("Not Palindrome\n");

    return 0;
}
