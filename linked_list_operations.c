#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to merge two linked lists in the specified order
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* head = NULL;
    struct Node** tail = &head;

    while (head1 != NULL && head2 != NULL) {
        *tail = createNode(head1->data);
        tail = &((*tail)->next);
        head1 = head1->next;

        *tail = createNode(head2->data);
        tail = &((*tail)->next);
        head2 = head2->next;
    }

    while (head1 != NULL) {
        *tail = createNode(head1->data);
        tail = &((*tail)->next);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        *tail = createNode(head2->data);
        tail = &((*tail)->next);
        head2 = head2->next;
    }

    return head;
}

// Function to find common elements in two linked lists
void printCommonElements(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    printf("Common elements: ");
    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                printf("%d ", temp1->data);
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    printf("\n");
}

// Function to delete nodes with negative keys
struct Node* deleteNegativeNodes(struct Node* head) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data < 0) {
            if (prev == NULL) {
                head = temp->next;
                free(temp);
                temp = head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

// Function to split a linked list into two lists: one with positive numbers and one with negative numbers
void splitList(struct Node* head, struct Node** positiveList, struct Node** negativeList) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data >= 0) {
            *positiveList = createNode(temp->data);
            positiveList = &((*positiveList)->next);
        } else {
            *negativeList = createNode(temp->data);
            negativeList = &((*negativeList)->next);
        }
        temp = temp->next;
    }
}

int main() {
    // Create linked lists A and B
    struct Node* A = createNode(1);
    A->next = createNode(2);
    A->next->next = createNode(3);
    A->next->next->next = createNode(4);
    A->next->next->next->next = createNode(5);
    A->next->next->next->next->next = createNode(6);

    struct Node* B = createNode(7);
    B->next = createNode(8);
    B->next->next = createNode(9);
    B->next->next->next = createNode(10);
    B->next->next->next->next = createNode(11);
    B->next->next->next->next->next = createNode(12);

    // Merge lists A and B into list C
    struct Node* C = mergeLists(A, B);
    printf("Merged list C: ");
    printList(C);

    // Print common elements in lists A and B
    printCommonElements(A, B);

    // Delete nodes with negative keys from list A
    struct Node* D = createNode(-1);
    D->next = createNode(2);
    D->next->next = createNode(-3);
    D->next->next->next = createNode(4);
    D->next->next->next->next = createNode(-5);
    D->next->next->next->next->next = createNode(6);

    printf("List D before deleting negative nodes: ");
    printList(D);
    D = deleteNegativeNodes(D);
    printf("List D after deleting negative nodes: ");
    printList(D);

    // Split list D into positive and negative lists
    struct Node* positiveList = NULL;
    struct Node* negativeList = NULL;
    splitList(D, &positiveList, &negativeList);

    printf("Positive list: ");
    printList(positiveList);
    printf("Negative list: ");
    printList(negativeList);

    return 0;
}