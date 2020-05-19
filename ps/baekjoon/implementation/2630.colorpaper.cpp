#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// 2^k * 2^k 크기의 종이 (1 <= k <= 7) ' 128 * 128

// 가로 세로가 n이고, 시작 좌표가 i, j인 경우에 대하여 (왼쪽 위부터 0,0)
// (y축 시작, x축 시작, y 길이, x 길이)에 대하여 확인하는데,
// (ybase, xbase, ylength, xlength)로 하고
// ybase, xbase 부터 ybase + ylength / 2, xbase + xlength / 2까지
// 식으로 4개 영역에 대하여 모두 같은 색인지 확인
  // 같은 색이면, 나누지 않는다
  // 하나라도 다르면, 또 4개로 분할한다
int white = 0;
int blue = 0;
int map[128][128];

// (y축 시작, x축 시작, 현재 길이)
void count(int ybase, int xbase, int paperLength) {
  // base: 길이가 1 -> 다 나누었다.
  if (paperLength == 1) {
    if (map[ybase][xbase] == 0)
      white++;
    else
      blue++;
    return;
  }

  // 그 밖의 경우: 현재 영역을 돌면서
  // 다 같은 색깔이면 해당 색을 개수 새고
  // 아니면 분할로 탐색
  int color = map[ybase][xbase];
  bool isFullPaper = true;
  for (int i = ybase ; i < ybase + paperLength ; i++) {
    for (int j = xbase ; j < xbase + paperLength ; j++) {
      // 직전 종이와 이번 종이의 색이 다르면, 분할탐색
      if (color != map[i][j]) {
        isFullPaper = false;
        count(ybase, xbase, paperLength / 2);
        count(ybase + paperLength / 2, xbase, paperLength / 2);
        count(ybase, xbase + paperLength / 2, paperLength / 2);
        count(ybase + paperLength / 2, xbase + paperLength / 2, paperLength / 2);
        break;
      }
    }
    if (isFullPaper == false)
      break;
  }

  // 여기 올 때까지 isFullPaper가 true이면, 한장이라는 것
  if (isFullPaper == true) {
    if (color == 0)
      white++;
    else
      blue++;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(&map, 0, sizeof(map));
  int N;

  cin >> N;
  for (int i = 0 ; i < N ; i++)
    for (int j = 0 ; j < N ; j++)
      cin >> map[i][j];
  
  count(0, 0, N);

  cout << white << "\n" << blue;

  return 0;
}
