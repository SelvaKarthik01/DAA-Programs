#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

namespace estd {
    struct node {
        int from;
        int to;
        int weight;
        node* next;
    };

    struct vnode {
        string name;
        int d;
        int pi;
    };

    class graph {
        int n, m;
        vnode vertex[10];
        node* elist;
    public:
        void createGraph();
        void INITIALIZE_SINGLE_SOURCE(int s);
        void RELAX(int u, int v, int w);
        bool BELLMAN_FORD(int s);
        void printShortestPaths();
    };

    void graph::createGraph() {
        cout << "Enter number of vertices: ";
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cout << "Enter name of vertex " << i << ": ";
            cin >> vertex[i].name;
        }

        cout << "Enter number of edges: ";
        cin >> m;

        elist = nullptr;
        node* last = nullptr;

        for (int j = 1; j <= m; j++) {
            node* t = new node;
            cout << "Enter from vertex, to vertex, and weight of edge " << j << ": ";
            cin >> t->from >> t->to >> t->weight;
            t->next = nullptr;
            if (last == nullptr)
                elist = t;
            else
                last->next = t;
            last = t;
        }
    }

    void graph::INITIALIZE_SINGLE_SOURCE(int s) {
        for (int i = 1; i <= n; i++) {
            vertex[i].d = INT_MAX;
            vertex[i].pi = -1;
        }
        vertex[s].d = 0;
    }

    void graph::RELAX(int u, int v, int w) {
        if (vertex[v].d > vertex[u].d + w) {
            vertex[v].d = vertex[u].d + w;
            vertex[v].pi = u;
        }
    }

    bool graph::BELLMAN_FORD(int s) {
        INITIALIZE_SINGLE_SOURCE(s);
        for (int i = 1; i <= n - 1; i++) {
            node* t = elist;
            while (t != nullptr) {
                RELAX(t->from, t->to, t->weight);
                t = t->next;
            }
        }

        node* t = elist;
        while (t != nullptr) {
            if (vertex[t->to].d > vertex[t->from].d + t->weight)
                return false;
            t = t->next;
        }
        return true;
    }

    void graph::printShortestPaths() {
        cout << "Shortest path lengths:\n";
        for (int i = 1; i <= n; i++) {
            cout << "Length of vertex " << vertex[i].name << ": " << vertex[i].d << endl;
        }
    }
}

int main() {
    estd::graph G;
    G.createGraph();
    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    if (G.BELLMAN_FORD(source)) {
        cout << "Shortest paths computed successfully." << endl;
        G.printShortestPaths();
    } else {
        cout << "Negative weight cycle detected. Cannot compute shortest paths." << endl;
    }

    return 0;
}
