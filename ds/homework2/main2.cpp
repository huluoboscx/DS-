#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
    bool empty() const {
        return top == nullptr;
    }
    void push(const T& data) {
        top = new Node(data, top);
    }
    void pop() {
        if (!empty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    T& peek() const {
        if (!empty()) {
            return top->data;
        }
        else {
            throw "Stack is empty";
        }
    }
};

int maxs(int* heights, int n) {
    Stack<int> s;
    int k = 0;
    int i = 0;
    while (i < n) {
        if (s.empty() || heights[i] >= heights[s.peek()]) {
            s.push(i++);
        }
        else {
            int tp = s.peek();
            s.pop();
            int l = heights[tp] * (s.empty() ? i : i - s.peek() - 1);
            if (l > k) {
                k = l;
            }
        }
    }
    while (!s.empty()) {
        int tp = s.peek();
        s.pop();
        int l = heights[tp] * (s.empty() ? i : i - s.peek() - 1);
        if (l > k) {
            k = l;
        }
    }
    return k;
}

int main() {
    srand(time(nullptr));
    const int n = 10;
    int heights[n];
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < n; i++) {
            heights[i] = rand() % 10 + 1;
            cout << heights[i] << " ";
        }
        cout << endl;
        cout << "最大面积: " << maxs(heights, n) << endl;
    }
    int m = 0;
    int a;
    int q[150];
    cout << "请输入各柱子高度（输入0截止）: " << endl;
    while (scanf("%d", &a), a != 0){
        q[m]=a; 
        m++;
    }
    cout << "最大面积: " <<maxs(q, m) << endl;
    return 0;
}