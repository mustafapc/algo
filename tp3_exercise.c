#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// --- Data Structures ---

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node *next;
} Node;

// --- Q1: Initialization and Empty Check ---

Node* createEmptyList() {
    return NULL;
}

bool isListEmpty(Node* head) {
    return head == NULL;
}

// --- Helper function for creating a new Node ---

Node* createNode(Product newProd) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed for new Node");
        return NULL;
    }
    newNode->Prod = newProd;
    newNode->next = NULL;
    return newNode;
}


// --- Q2: Insertion Functions ---

Node* insertAtBeginning(Node* head, Product newProd) {
    Node* newNode = createNode(newProd);
    if (newNode == NULL) return head;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

    newNode->next = head;
    current->next = newNode;
    
    return newNode;
}

Node* insertAtEnd(Node* head, Product newProd) {
    Node* newNode = createNode(newProd);
    if (newNode == NULL) return head;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    
    newNode->next = head;
    current->next = newNode;
    
    return head;
}


// --- Q3: Display Function ---

void displayList(Node* head) {
    if (isListEmpty(head)) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    
    printf("--- Circular Product List ---\n");
    do {
        printf("ID: %d, Name: %s, Price: %d\n", 
               current->Prod.ID, 
               current->Prod.Name, 
               current->Prod.Price);
        current = current->next;
    } while (current != head);
    printf("---------------------------\n");
}

// --- Memory Cleanup Function ---

void freeList(Node* head) {
    if (head == NULL) {
        return;
    }
    
    Node* current = head->next;
    Node* temp;
    
    head->next = NULL;
    
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    
    free(head);
}


// --- Main Function (Tests) ---

int main() {
    Node* listHead = NULL;
    
    printf("--- Testing Q1: Initialization and Empty Check ---\n");
    
    listHead = createEmptyList();
    printf("1. List created.\n");
    
    printf("2. Is list empty? %s\n", isListEmpty(listHead) ? "**True**" : "False");
    
    displayList(listHead);
    
    printf("\n--- Testing Q2 & Q3: Insertion and Display ---\n");
    
    Product p1 = {101, "Laptop", 1200};
    Product p2 = {102, "Mouse", 25};
    Product p3 = {103, "Keyboard", 75};
    Product p4 = {104, "Monitor", 300};
    
    printf("\n--- Test 1: insertAtEnd (101) ---\n");
    listHead = insertAtEnd(listHead, p1);
    displayList(listHead);
    
    printf("\n--- Test 2: insertAtBeginning (102) ---\n");
    listHead = insertAtBeginning(listHead, p2);
    displayList(listHead);
    
    printf("\n--- Test 3: insertAtEnd (103) ---\n");
    listHead = insertAtEnd(listHead, p3);
    displayList(listHead);
    
    printf("\n--- Test 4: insertAtBeginning (104) ---\n");
    listHead = insertAtBeginning(listHead, p4);
    displayList(listHead);
    
    printf("\n3. Is list empty? %s\n", isListEmpty(listHead) ? "True" : "**False**");
    
    printf("\n--- Cleanup ---\n");
    freeList(listHead);
    printf("Memory freed.\n");

    return 0;
}
