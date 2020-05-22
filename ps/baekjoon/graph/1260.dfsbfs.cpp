#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[1001];
vector<vector<int> > graph;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  cout << start << " ";

  while (!q.empty()) {
    int prev = q.front();
    q.pop();

    for (int i = 0 ; i < graph[prev].size() ; i++) {
      int here = graph[prev][i];

      if (visited[here] == true)
        continue;
      
      visited[here] = true;
      q.push(here);
      cout << here << " ";
    }
  }
}

void dfs(int here) {
  if (visited[here] == true)
    return;
  
  visited[here] = true;
  cout << here << " ";

  for (int i = 0 ; i < graph[here].size() ; i++) {
    int there = graph[here][i];
    dfs(there);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, V;
  cin >> N >> M >> V;
  graph = vector<vector<int> >(N + 1, vector<int>());
  for (int i = 0 ; i < M ; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1 ; i <= N ; i++)
    sort(graph[i].begin(), graph[i].end());

  memset(&visited, 0, sizeof(visited));
  dfs(V);
  cout << "\n";

  memset(&visited, 0, sizeof(visited));
  bfs(V);

  return 0;
}
