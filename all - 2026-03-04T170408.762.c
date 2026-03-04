#include <stdio.h>
#define MAX 1000  
int arr[MAX];
int top = -1;
void insert(int value) {
    if (top == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    arr[++top] = value;
}
void removeElement() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;  
}
void show() {
    if (top == -1) {
        printf("Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(value);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        removeElement();
    }
    show();
    return 0;
}

