#include <iostream>
#include <queue>
using namespace std;
class Graph
{
private:
    int V; // ͼ�Ķ�����
    vector<vector<int>> adjMatrix; // �ڽӾ���

public:
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // ��ӱ�
    void addEdge(int u, int v, int w) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // ����ͼ
    }

    // DFS����
    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < V; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFS(start, visited);
    }

    // BFS����
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            cout << v << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[v][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    // Prim�㷨
    void Prim() {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        key[0] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = -1;
            for (int j = 0; j < V; j++) {
                if (!inMST[j] && (u == -1 || key[j] < key[u])) {
                    u = j;
                }
            }

            inMST[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "��С֧�����ı�:" << endl;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " : " << adjMatrix[parent[i]][i] << endl;
        }
    }

    // Dijkstra�㷨
    void Dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        dist[start] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = -1;
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] && !visited[v]) {
                    dist[v] = min(dist[v], dist[u] + adjMatrix[u][v]);
                }
            }
        }

        cout << "�붥�����̾��� " << start << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " : " << dist[i] << endl;
        }
    }

    // ���ȼ�����ʾ��
    void priorityQueueExample() {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 1; i <= 10; i++) {
            maxHeap.push(i);
            minHeap.push(i);
        }

        cout << "Max heap:" << endl;
        while (!maxHeap.empty()) {
            cout << maxHeap.top() << " ";
            maxHeap.pop();
        }
        cout << endl;

        cout << "Min heap:" << endl;
        while (!minHeap.empty()) {
            cout << minHeap.top() << " ";
            minHeap.pop();
        }
        cout << endl;
    }
};