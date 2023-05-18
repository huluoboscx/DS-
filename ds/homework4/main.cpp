#include"..\..\ds\homework4\Graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int main() {
    Graph g(6);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 8);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 9);

    cout << "DFS 遍历:" << endl;
    g.DFS(0);
    cout << endl;

    cout << "BFS 遍历:" << endl;
    g.BFS(0);
    cout << endl;

    cout << "最小支撑树:" << endl;
    g.Prim();

    cout << "最短路径:" << endl;
    g.Dijkstra(0);

    cout << "优先队列样例:" << endl;
    g.priorityQueueExample();

    return 0;
}
