#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 293012932
int V, E, S0;

int main()
{
    // 입력 및 초기화
    cin >> V >> E >> S0;
    vector < pair < int, int > > adj[V];//(u, v) u에서 v로의 weight
    vector < int > dist(V, INF);//(u, v) 간선에서 v에서의 최단경로
    dist[S0-1] = 0;
    for (int i = 0; i < E; ++i) {
        int u,v,w; cin >> u >> v >> w;
        adj[u-1].push_back(make_pair(v-1, w));
    }
    vector < bool > visited(V, false);
    visited[S0-1] = false;
    while (true) {
          int closest=INF, u;
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
              int cost = dist[u] + adj[u][i].second;
              dist[v] = dist[v] < cost? dist[v] : cost;
          }
    }
    //
    // priority_queue < pair <int, int> > pq;//(u, v) v까지의 현재 최단 경로
    // pq.push(make_pair(0, S0-1));
    // // cout << " ## searching start ## " << endl;
    // while (!pq.empty()) {
    //     int cost = -pq.top().first;//비용이 가장 큰 녀석은 바닥으로 떨어진다.
    //     int u = pq.top().second;
    //     pq.pop();
    //     if (dist[u] < cost) continue;
    //     // cout << "  > new path is discovered" << endl;
    //     // cout << "\n " << u;
    //     //경로 탐색
    //     for (int j = 0 ; j < adj[u].size(); ++j) {
    //         int v = adj[u][j].first;
    //         // cout << "\n -> " << v << endl;
    //         int weight = adj[u][j].second;
    //         if (dist[v] > cost + weight) {
    //             dist[v] = cost + weight;
    //             // cout << "  > new path=" << v << ", dist " << dist[v] << endl;
    //             pq.push(make_pair(-dist[v], v));
    //         }
    //     }
    // }
    //결과 출력
    for (int i=0; i<dist.size(); ++i) {
      if (dist[i] == INF) { cout << "INF" << endl;}
      else if (i == S0-1) {cout << "0" << endl;}
      else cout << dist[i] << endl;
    }
    return 0;
}
