#include <iostream>
#include <vector>
using namespace std;

// (r, c)
// 최초 주사위는 모두 0으로 써있다
// 주사위 상태 필요
// 방향에 따라 구를 때, 상태를 어떻게 바꿀지 4방향으로 매핑 필요

// 이동했을 때 바닥이 0이면, 바닥과 맞닿은 주사위면의 숫자가 바닥에 복사
// 이동했을 때 바닥이 0이 아니면, 칸에 있는 수가 주사위로 복사 후 바닥이 0으로

int N, M, K;
                 // 2  4  1  3  5  6 (주사위 전개도 기준)
char dice[6] = { '0', '0', '0', '0', '0', '0' }; // 
int direction[5][2] = {
  { 0, 0 }, // 0은 미사용
  { 0, 1 },
  { 0, -1 },
  { -1, 0 },
  { 1, 0 }
};

// 1: 동 2: 서 3: 북 4: 남
// 지도, 이동방향, 주사위의 좌표
void roll(vector<vector<char> >& map, int dir, int& x, int& y) {
  // base case
  // 이동 후 좌표가 지도 바깥인지 - 무시
  if (y + direction[dir][0] >= N
    || y + direction[dir][0] < 0
    || x + direction[dir][1] >= M
    || x + direction[dir][1] < 0)
    return;

  // 이동
  y += direction[dir][0];
  x += direction[dir][1];
  // 주사위 회전
  char temp;
  switch(dir) {
    case 1: // 동
      // 1 2 3 5 -> 5 1 2 3로 교환
      // 1 2 3 5 위치에 각각 5 1 2 3 배열의 값을 넣는다
      temp = dice[1];
      dice[1] = dice[5];
      dice[5] = dice[3];
      dice[3] = dice[2];
      dice[2] = temp;
      break;
    case 2: // 서
      // 1 2 3 5 -> 2 3 5 1로 교환
      temp = dice[1];
      dice[1] = dice[2];
      dice[2] = dice[3];
      dice[3] = dice[5];
      dice[5] = temp;      
      break;
    case 3: // 북
      // 0 2 4 5 -> 2 4 5 0로 교환
      temp = dice[0];
      dice[0] = dice[2];
      dice[2] = dice[4];
      dice[4] = dice[5];
      dice[5] = temp;
      break;
    case 4: // 남
      // 0 2 4 5 -> 5 0 2 4로 교환
      temp = dice[5];
      dice[5] = dice[4];
      dice[4] = dice[2];
      dice[2] = dice[0];
      dice[0] = temp;
      break;
  }

  // 바닥과 맞닿은 면(6)과 바닥 확인
  if (map[y][x] == '0') {
    //  '0'이면, 주사위 바닥면의 것이 지도로 복사
    map[y][x] = dice[5];
  } else {
    // 아니면, 지도의 것이 주사위 바닥으로 복사하고, 지도는 0으로 수정
    dice[5] = map[y][x];
    map[y][x] = '0';
  }

  // 상단면(1)의 값 출력
  cout << dice[2] << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y;

  cin >> N >> M >> y >> x >> K;

  vector<vector<char> > map(N, vector<char>(M));
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < M ; j++) {
      cin >> map[i][j];
    }
  }
  for (int i = 0 ; i < K ; i++) {
    int direction;
    cin >> direction;
    roll(map, direction, x, y);
  }
  
  return 0;
}
