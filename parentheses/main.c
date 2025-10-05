#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    char items[SIZE];
    int top;
} STACK;

void push(STACK *s, char c) {
    if (s->top != SIZE - 1) {
        s->items[++(s->top)] = c;
    }
}

char pop(STACK *s) {
    if (s->top != -1) {
        return s->items[(s->top)--];
    }
    return '\0'; // return null char if stack is empty
}

char peek(STACK *s) {
    if (s->top != -1) {
        return s->items[s->top];
    }
    return '\0'; // return null char if stack is empty
}

int isbalanced(STACK s, char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char top = peek(&s);
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                pop(&s);
            } else {
                return 0; // mismatch
            }
        }
    }
    return s.top == -1; // valid if stack is empty
}

int main() {
    STACK s;
    s.top = -1;
    char str[SIZE];

    printf("Enter a string of parentheses: ");
    scanf("%s", str);

    if (isbalanced(s, str)) {
        printf("Valid parentheses\n");
    } else {
        printf("Invalid parentheses\n");
    }

    return 0;
}
