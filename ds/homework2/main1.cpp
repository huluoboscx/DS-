#include"..\..\ds\homework2\stack.h"
#include"..\..\ds\vector\vector.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

double performOperation(char operation, double operand1, double operand2) {
    if (operation == '+') {
        return operand1 + operand2;
    }
    else if (operation == '-') {
        return operand1 - operand2;
    }
    else if (operation == '*') {
        return operand1 * operand2;
    }
    else if (operation == '/') {
        return operand1 / operand2;
    }
    else {
        return 0;
    }
}

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

double evaluateExpression(string expression) {
    Stack operandStack(expression.length());
    Stack operatorStack(expression.length());

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            continue;
        }
        else if (expression[i] == '(') {
            operatorStack.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                double operand2 = operandStack.pop();
                double operand1 = operandStack.pop();
                char operation = operatorStack.pop();
                operandStack.push(performOperation(operation, operand1, operand2));
            }
            if (!operatorStack.isEmpty() && operatorStack.peek() == '(') {
                operatorStack.pop();
            }
            else {
                return false;
            }
        }
        else if (isOperator(expression[i])) {
            while (!operatorStack.isEmpty() && getPrecedence(operatorStack.peek()) >= getPrecedence(expression[i])) {
                double operand2 = operandStack.pop();
                double operand1 = operandStack.pop();
                char operation = operatorStack.pop();
                operandStack.push(performOperation(operation, operand1, operand2));
            }
            operatorStack.push(expression[i]);
        }
        else if (isNumber(expression[i])) {
            double operand = 0;
            int j = i;
            while (j < expression.length() && (isNumber(expression[j]) || expression[j] == '.')) {
                if (expression[j] == '.') {
                    j++;
                    int k = 1;
                    while (j < expression.length() && isNumber(expression[j])) {
                        operand += (expression[j] - '0') * pow(10, -k);
                        j++;
                        k++;
                    }
                    break;
                }
                else {
                    operand = operand * 10 + (expression[j] - '0');
                    j++;
                }
            }
            i = j - 1;
            operandStack.push(operand);
        }
        else {
            return false;
        }
    }

    while (!operatorStack.isEmpty()) {
        double operand2 = operandStack.pop();
        double operand1 = operandStack.pop();
        char operation = operatorStack.pop();
        operandStack.push(performOperation(operation, operand1, operand2));
    }

    return operandStack.pop();
}

int main() {
    string expression;
    cout << "请输入运算: ";
    getline(cin, expression);

    double result = evaluateExpression(expression);

    if (result == false) {
        cout << "运输格式错误" << endl;
    }
    else {
        cout << "结果: " << result << endl;
    }

    return 0;
}