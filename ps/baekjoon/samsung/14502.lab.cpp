#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int answer = 987654321; // 바이러스 전파 개수
const int direction[4][2] = {
  // 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽
  { -1, 0 },
  { 0, 1 },
  { 1, 0 },
  { 0, -1 }
};

// N * M 크기의 연구소
// 바이러스는 상하좌우로만 전파 가능
// 벽은 3개까지 설치 가능

// 현재 추가 설치된 벽을 기반으로 바이러스 전파시켜본다
int bfs(vector<vector<int> >& map, vector<vector<bool> >& visited, int y, int x) {
  queue<pair<int, int> > q;
  int count = 0;

  q.push(make_pair(y, x));
  visited[y][x] = true;
  count++;

  while(!q.empty()) {
    int prevY = q.front().first;
    int prevX = q.front().second;
    q.pop();

    // prevY, prevX에 인접한 4방향 모두 큐에 넣는다
    for (int i = 0 ; i < 4 ; i++) {
      // 다음 좌표를 얻는다
      int nextY = prevY + direction[i][0];
      int nextX = prevX + direction[i][1];
      
      // base: 영역 밖인지 체크
      if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0)
        continue;
      
      // base: 벽이면 통과하지도 조사하지도 않는다
      if (map[nextY][nextX] == 1)
        continue;

      // 이미 조사한 빈 공간이라면 가지 않는다
      if (visited[nextY][nextX] == true)
        continue;

      // 큐에 좌표를 삽입한다 및 방문 처리한다
      q.push(make_pair(nextY, nextX));
      visited[nextY][nextX] = true;

      // 조사한다
      count++;
    }
  }

  return count;
}

// 중복 제거해야 한다
void count(vector<vector<int> >& map) {
  int virusCount = 0;
  vector<vector<bool> > visited(N, vector<bool>(M, false));
  // 1. 전파
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < M ; j++) {
      if (map[i][j] == 2 && visited[i][j] == false) {
        virusCount += bfs(map, visited, i, j);
      }

      // 기존에 조사한 개수를 초과해버렸으면, 더 이상 조사하지 않는다
      if (virusCount >= answer)
        return;
    }
  }

  // 2. 개수 새기
  answer = min(answer, virusCount);
}

// 현재 map에 벽이 추가로 walls개 설치된 상황. 3개까지만 더 설치
// map은 원본부터 최초 사용, walls는 0부터 최초 호출
void calc(vector<vector<int> >& map, int walls) {
  if (walls == 3) {
    count(map);
    return;
  }

  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < M ; j++) {
      if (map[i][j] == 0) {
        map[i][j] = 1;        // 벽 설치하고
        calc(map, walls + 1); // 그걸 기반으로 또 설치하거나 개수 새고
        map[i][j] = 0;        // 해당 위치에 벽 다시 제거하고
      }
    }
  }
}

// bfs로 퍼지는것 살피고, 안전 영역 최대 크기 구하기

// 3개를 설치하고
// 설치한 경우마다 bfs해서 안전 영역 크기 구하기
  // 안전영역 = 전체 - 벽 - 바이러스개수 이므로
  //  바이러스 개수의 최소값을 구하자
// 모든 경우에 대하여 반복
// 바이러스 개수가 기존의 최소값을 초과하면 더 이상 진행 필요 없음

// 벽 놓기 루프 재귀함수
  // 벽 놓고
    // 벽 개수 3개이면, 개수 새기
    // 3개 미만이면, 재귀
  // 벽 없애기

// 개수 새기
// 매번 개수를 새기 위하여 visited[N][M]을 선언
// 지도를 돌면서 2인 지점에서 4방향 bfs시작
// 1을 만나면 나아가지 못한다
// 0을 만나면 감염 개수를 샌다

// 마지막에, 답을 기반으로 안전 영역 크기 반환
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int originalWalls = 0;

  cin >> N >> M;
  vector<vector<int> > map(N, vector<int>(M));
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < M ; j++) {
      cin >> map[i][j];

      if (map[i][j] == 1)
        originalWalls++;
    }
  }

  calc(map, 0);

  // 3. 최종 답 구하기
  cout << N * M - originalWalls - 3 - answer;

  return 0;
}
