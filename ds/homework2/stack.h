#include <iostream>
using namespace std;
class Stack {
private:
    int top;
    int size;
    double* values;

public:
    Stack(int s) {
        size = s;
        top = -1;
        values = new double[size];
    }

    ~Stack() {
        delete[] values;
    }

    void push(double value) {
        if (top == size - 1) {
        }
        else {
            top++;
            values[top] = value;
        }
    }

    double pop() {
        if (top == -1) {
            return -1;
        }
        else {
            double value = values[top];
            top--;
            return value;
        }
    }

    double peek() {
        if (top == -1) {
            return -1;
        }
        else {
            return values[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};
