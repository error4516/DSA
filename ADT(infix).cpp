#include<iostream>
#include<string>
#include<ctype.h>
#include<string.h>
#include<algorithm>

using namespace std;

// Stack for operators and characters
struct stack1 {
    char data;
    stack1* next;
} *top = NULL;

// Stack for integer operands
struct stack2 {
    int data;
    stack2* next;
} *top1 = NULL;

// Utility functions for stack1
void push1(char data) {
    stack1* newnode = new stack1;
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

char pop1() {
    if (top == NULL) return '\0';
    char data = top->data;
    stack1* temp = top;
    top = top->next;
    delete temp;
    return data;
}

// Utility functions for stack2
void push2(int data) {
    stack2* newnode = new stack2;
    newnode->data = data;
    newnode->next = top1;
    top1 = newnode;
}

int pop2() {
    if (top1 == NULL) return 0;
    int data = top1->data;
    stack2* temp = top1;
    top1 = top1->next;
    delete temp;
    return data;
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[30]) {
    string postfix;
    push1('(');
    int l = strlen(infix);
    infix[l] = ')';
    int i = 0;

    while (top != NULL) {
        char ch = infix[i++];
        if (ch == '(') push1(ch);
        else if (isalnum(ch)) postfix += ch;
        else if (ch == ')') {
            while (top->data != '(') postfix += pop1();
            pop1();
        } else {
            while (precedence(top->data) >= precedence(ch)) postfix += pop1();
            push1(ch);
        }
    }
    cout << "\nPostfix Expression is: " << postfix;
}

// Convert infix to prefix
void infixToPrefix(char infix[30]) {
    string prefix;
    reverse(infix, infix + strlen(infix));
    for (int i = 0; i < strlen(infix); ++i)
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';

    infixToPostfix(infix);
    while (top != NULL) prefix += pop1();
    reverse(prefix.begin(), prefix.end());
    cout << "\nPrefix Expression is: " << prefix;
}

// Evaluate postfix expression
void evalPostfix(char postfix[30]) {
    int i = 0;
    while (postfix[i]) {
        char ch = postfix[i++];
        if (isdigit(ch)) push2(ch - '0');
        else {
            int a = pop2(), b = pop2();
            switch (ch) {
                case '+': push2(b + a); break;
                case '-': push2(b - a); break;
                case '*': push2(b * a); break;
                case '/': push2(b / a); break;
            }
        }
    }
    cout << "\nValue of postfix expression is: " << pop2();
}

// Evaluate prefix expression
void evalPrefix(char prefix[30]) {
    reverse(prefix, prefix + strlen(prefix));
    int i = 0;
    while (prefix[i]) {
        char ch = prefix[i++];
        if (isdigit(ch)) push2(ch - '0');
        else {
            int a = pop2(), b = pop2();
            switch (ch) {
                case '+': push2(a + b); break;
                case '-': push2(a - b); break;
                case '*': push2(a * b); break;
                case '/': push2(a / b); break;
            }
        }
    }
    cout << "\nValue of prefix expression is: " << pop2();
}

int main() {
    char expr[30];
    int choice;

    do {
        cout << "\n1. Infix to Postfix"
             << "\n2. Infix to Prefix"
             << "\n3. Evaluate Postfix"
             << "\n4. Evaluate Prefix"
             << "\n5. Exit"
             << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter infix expression: ";
                cin >> expr;
                infixToPostfix(expr);
                break;
            case 2:
                cout << "\nEnter infix expression: ";
                cin >> expr;
                infixToPrefix(expr);
                break;
            case 3:
                cout << "\nEnter postfix expression: ";
                cin >> expr;
                evalPostfix(expr);
                break;
            case 4:
                cout << "\nEnter prefix expression: ";
                cin >> expr;
                evalPrefix(expr);
                break;
        }
    } while (choice != 5);

    return 0;
}
