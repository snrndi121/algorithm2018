#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int>* graph;
bool* visited;
int V, E ,S;

void init()
{
    fill(visited, visited + V + 1, false);
}
void input()
{
    cin >> V >> E >> S;
    int u , v;
    graph = new vector <int>[V+1];
    visited = new bool[E];
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
}
void searchDFS(vector <int>* _graph, bool* _visited, int S)
{
    _visited[S] = true;
    cout << S << ' ' ;
    for (int i = 0; i < _graph[S].size(); ++i) {
        int next = _graph[S][i];
        if (!_visited[next]) {
            searchDFS(_graph, _visited, next);
        }
    }
}
void searchBFS(vector <int>* _graph, bool* _visited, int S)
{
    queue < int > mque;
    mque.push(S);
    _visited[S] = true;
    while (!mque.empty()) {
        int top = mque.front(); mque.pop();
        cout << top << ' ';
        for (int i = 0; i < _graph[top].size(); ++i) {
            int next = _graph[top][i];
            if (!_visited[next]) {
                mque.push(next);
                _visited[next] = true;
            }
        }
    }
}
void solution()
{
    //dfs
    cout << "DFS" << endl;
    searchDFS(graph, visited, S);
    cout << endl;
    //bfs
    init();
    cout << "BFS" << endl;
    searchBFS(graph, visited, S);
    cout << endl;
}
int main()
{
    input();
    solution();
    return 0;
}
