#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, S0;
unsigned long long INF = ((unsigned long long)100000 * 100000);

int main()
{
    // 입력 및 초기화
    cin >> V >> E;
    vector < bool > visited(V, false);
    vector < pair < int, unsigned long long > > adj[V];//(u, v) u에서 v로의 weight
    vector < unsigned long long > dist(V, INF);//(u, v) 간선에서 v에서의 최단경로
    for (int i = 0; i < E; ++i) {
        int u,v;unsigned long long w; cin >> u >> v >> w;
        adj[u-1].push_back(make_pair(v-1, w));
    }
    //마지막 입력
    int S0, E0; cin >> S0 >> E0;
    dist[S0-1] = 0;
    visited[S0-1] = false;
    while (true) {
          unsigned long long closest=INF; int u;
          for (int i = 0; i < V; ++i) {
              if (dist[i] < closest && !visited[i]) {
                  u = i;
                  closest = dist[i];
              }
          }
          if (closest == INF) { break;}
          visited[u] = true;
          for (int i=0; i < adj[u].size(); ++i) {
              int v=adj[u][i].first;
              if (visited[v]) { continue;}
              unsigned long long cost = dist[u] + adj[u][i].second;
              dist[v] = dist[v] < cost? dist[v] : cost;
          }
    }
    //결과 출력
    cout << dist[E0-1] << endl;
    return 0;
}
