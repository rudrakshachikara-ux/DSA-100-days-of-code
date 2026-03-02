#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;       
    int exp;        
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insertSorted(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->exp >= exp) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if (temp->exp != 0) {
            printf("x^%d", temp->exp);
        }
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int n, coeff, exp;
    struct Node* poly = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertSorted(&poly, coeff, exp);
    }
    printPolynomial(poly);
    return 0;
}

