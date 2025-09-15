//
// Created by 李洋 on 2023/10/21.
// 以邻接矩阵实现的INT图及其具体操作
//

#ifndef LEECODE_C_GRAPH_H
#define LEECODE_C_GRAPH_H

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <iostream>
#include <stack>

using namespace std;

class Graph {
public:
    int size;

    Graph(int n, bool direction) {
        this->size = n;
        G = vector<vector<int>>(size, vector<int>(size, 0));
        visited = vector<int>(size, 0);

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 1);

        if (!direction) {
            for (int i = 0; i < size; ++i) {
                for (int j = i + 1; j < size; ++j) {
                    if (dis(gen)) {
                        G[i][j] = 1;
                        G[j][i] = 1;
                    }
                }
            }
        } else {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (i == j) {
                        continue;
                    }
                    if (dis(gen)) {
                        G[i][j] = 1;
                    }
                }
            }
        }
    }

//    0 1 0 0 0 0
//    1 0 1 1 0 0
//    0 1 0 0 0 1
//    0 1 0 0 0 0
//    0 0 0 0 0 1
//    0 0 1 0 1 0
    Graph(int x) {
        size = 6;
        G = vector<vector<int>>(size, vector<int>(size, 0));
        visited = vector<int>(size, 0);
        vector<vector<int>> Edges;
        if (x == 1) {
            Edges.push_back({0, 1});
            Edges.push_back({1, 2});
            Edges.push_back({1, 3});
            Edges.push_back({2, 5});
            Edges.push_back({4, 5});
        }
        if (x == 2) {

        }
        for (auto Edge: Edges) {
            G[Edge[0]][Edge[1]] = 1;
            G[Edge[1]][Edge[0]] = 1;
        }
    }

    Graph *GraphByEdge(vector<vector<int>> &Edges) {
        for (auto Edge: Edges) {
            vertex.insert(Edge[1]);
            vertex.insert(Edge[2]);
        }

        size = vertex.size();
        G = vector<vector<int>>(size, vector<int>(size, 0));

        for (auto Edge: Edges) {
            G[Edge[1]][Edge[2]] = 1;
        }
        return this;
    }


    void printG() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << G[i][j] << " ";
            }
            cout << endl;
        }
    }

    queue<int> DFS(int start) {
        queue<int> Q;
        stack<pair<int, int>> S;
        Q.push(start);
        S.emplace(start, -1);
        visited[0] = 1;
        while (!S.empty()) {
            auto temp = S.top();
            auto next = NextPoint(temp.first, temp.second);
            S.top().second = next;
            if (next == -1) {
                S.pop();
                continue;
            }
            if (visited[next]) {
                continue;
            }
            Q.push(next);
            visited[next] = 1;
            S.emplace(next, -1);
        }
        if (Q.size() != size) {
            // 将其他的点再进行DSF
        }
        return Q;
    }

    queue<int> BFS(int start) {
        queue<int> Q;
        queue<pair<int, int>> S;
        Q.push(start);
        S.emplace(start, -1);
        visited[0] = 1;
        while (!S.empty()) {
            auto temp = S.front();
            auto next = NextPoint(temp.first, temp.second);
            S.front().second = next;
            if (next == -1) {
                S.pop();
                continue;
            }
            if (visited[next]) {
                continue;
            }
            Q.push(next);
            visited[next] = 1;
            S.emplace(next, -1);
        }
        if (Q.size() != size) {
            // 将其他的点再进行BSF
        }
        return Q;
    }

    int NextPoint(int vex, int now) {
        auto row = G[vex];
        for (int i = now + 1; i < size; ++i) {
            if (row[i] != 0) {
                return i;
            }
        }
        return -1;
    }

private:
    vector<vector<int>> G; // adjacent matrix
    vector<int> visited;

    set<int> vertex;   // The collection of vertex
    set<set<int>> ccp; // The graph has multiple connected components.


};

#endif //LEECODE_C_GRAPH_H
