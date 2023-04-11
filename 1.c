#include<stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
  stack[++top] = value;
}

int pop() {
  return stack[top--];
}

int peek() {
  return stack[top];
}

void find_greatest_to_left(int arr[], int n) {
  int i;
  
  for (i = 0; i < n; i++) {
    while (top != -1 && peek() <= arr[i]) {
      pop();
    }
    if (top == -1) {
      printf("-1 ");
    } else {
      printf("%d ", peek());
    }
    push(arr[i]);
  }
}


