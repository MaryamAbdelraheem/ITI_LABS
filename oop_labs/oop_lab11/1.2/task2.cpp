#include <iostream>
#include <cctype> //
using namespace std;

class Stack_num {
    int data[100];
    int top;
public:
    //constructor 
    Stack_num() { top = -1; }
    //push
    void push(int val) { if (top < 99) data[++top] = val; }
    //pop
    int pop() { return (top >= 0) ? data[top--] : 0; }
    
    bool isEmpty() { return top == -1; }
    int peek() { return (top >= 0) ? data[top] : 0; }
};

class Stack_op {
    char data[100];
    int top;

    //-------------------------------------------------------------
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    //-------------------------------------------------------------
    int applyOp(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return b != 0 ? a / b : 0;
        }
        return 0;
    }

public:
    Stack_op() { top = -1; }

    void push(char val) { if (top < 99) data[++top] = val; }
    char pop() { return (top >= 0) ? data[top--] : '\0'; }
    char peek() { return (top >= 0) ? data[top] : '\0'; }
    bool isEmpty() { return top == -1; }

    //-----------------------------------------------------------------
    void doPreviousOperation(Stack_num &nums) {
        if (isEmpty() || nums.isEmpty()) return;
        char op = pop();
        int b = nums.pop();
        int a = nums.pop();
        nums.push(applyOp(a, b, op));
    }

    //-----------------------------------------------------------------
    void flush(Stack_num &nums) {
        while (!isEmpty()) {
            doPreviousOperation(nums);
        }
    }

    //------------------------------------------------------------------
    int precedenceCheck(char currentOp, Stack_num &nums) {
        while (!isEmpty() && peek() != '(' &&
               precedence(peek()) >= precedence(currentOp)) {
            doPreviousOperation(nums);
        }
        return 0;
    }
};

int main() {
    char eq[] = "(1+3)*2/(1+1)";
    Stack_num nums;
    Stack_op ops;

    for (int i = 0; eq[i] != '\0'; i++) {
        char ch = eq[i];

        if (isspace(ch)) continue;

        // Handle numbers
        if (isdigit(ch)) {
            int num = 0;
            // allow multi-digit numbers
            while (isdigit(eq[i])) {
                num = num * 10 + (eq[i] - '0');
                i++;
            }
            i--; // step back since loop will increment
            nums.push(num);
        }

        // Handle '('
        else if (ch == '(') {
            ops.push(ch);
        }

        // Handle ')'
        else if (ch == ')') {
            while (!ops.isEmpty() && ops.peek() != '(') {
                ops.doPreviousOperation(nums);
            }
            ops.pop(); // remove '('
        }

        // Handle operators
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            ops.precedenceCheck(ch, nums);
            ops.push(ch);
        }
    }

    // Finish all remaining ops
    ops.flush(nums);

    cout << "Result: " << nums.pop() << endl;
    return 0;
}
