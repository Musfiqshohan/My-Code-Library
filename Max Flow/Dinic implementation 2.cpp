#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

const int maxnodes = 5000;

int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge {
  int to, rev;
  int f, cap;
};

vector<Edge> g[maxnodes];

// Adds bidirectional edge
void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, cap};
  g[s].push_back(a);
  g[t].push_back(b);
}



bool dinic_bfs(int src, int dest)
{
    memset(dist,-1,sizeof dist);
    dist[src]=0;
    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int j=0; j<g[u].size(); j++)
        {
            Edge &e= g[u][j];

            if(dist[e.to]<0 && e.f<e.cap)
            {
                //printf("%d->%d\n",u,e.to);
                dist[e.to]=dist[u]+1;
                q.push(e.to);
            }
        }

    }
    return dist[dest]>=0;

}



int dinic_dfs(int u, int f) {
  if (u == dest)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow(int _src, int _dest) {
  src = _src;
  dest = _dest;
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INT_MAX))
      result += delta;
  }
  return result;
}

int main() {
    int n = 3;
    nodes = n;

    int capacity[][3] = { { 0, 3, 2 }, { 0, 0, 2 }, { 0, 0, 0 } };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (capacity[i][j] != 0)
                addEdge(i, j, capacity[i][j]);
    cout << (4 == maxFlow(0, 2)) << endl;
}
