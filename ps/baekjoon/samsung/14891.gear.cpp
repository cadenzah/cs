// 4개의 톱니바퀴, 톱니마다 8개의 톱니
// 맞닿은 부분이 서로 다른 극이면, 상대방도 맞물려서 회전
// 맞닿은 부분이 서로 같은 극이면, 상대방은 회전하지 않는다
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 맨 위부터, 시계 방향으로
// N극 = 0, S극 = 1
vector<string> gears(5); // 0번은 쓰지 않는다
// char gears[4][8]= {
  
//   {  }
// }

int K;
void rotate(int no, int dir) {
  char temp;
  // no번 톱니바퀴를 dir로 돌린다
  if (dir == 1) {
    // 시계 방향으로 돌렸을 때
    // 0 1 2 3 4 5 6 7 -> 7 0 1 2 3 4 5 6
    // 0번째 배열 요소 자리에 7번째 배열 요소의 값이 대입되는 식으로 교체
    temp = gears[no][0];
    gears[no][0] = gears[no][7];
    gears[no][7] = gears[no][6];
    gears[no][6] = gears[no][5];
    gears[no][5] = gears[no][4];
    gears[no][4] = gears[no][3];
    gears[no][3] = gears[no][2];
    gears[no][2] = gears[no][1];
    gears[no][1] = temp;
  } else {
    // 반시계방향으로 돌렸을 때
    // 0 1 2 3 4 5 6 7 -> 1 2 3 4 5 6 7 0
    temp = gears[no][0];
    gears[no][0] = gears[no][1];
    gears[no][1] = gears[no][2];
    gears[no][2] = gears[no][3];
    gears[no][3] = gears[no][4];
    gears[no][4] = gears[no][5];
    gears[no][5] = gears[no][6];
    gears[no][6] = gears[no][7];
    gears[no][7] = temp;
  }
}

// 시계 방향: 1, 반시계 방향: -1
void move(int no, int dir) {
  // 8가지 방법을 써준다
  // 1번째의 2번 톱니, 2번째의 2번과 7번 톱니, 3번째의 2번과 7번 톱니, 4번째의 7번 톱니
  // 를 보고서 각 톱니가 어떻게 돌아갈지 판단
  
  // 맞닿은 극이 같은지 여부
  bool onetwo = false, twothree = false, threefour = false;

  if (gears[1][2] == gears[2][6]) {
    // 같으면, 상대방은 회전하지 않는다
    onetwo = true;
  }
  if (gears[2][2] == gears[3][6]) {
    // 같으면, 상대방은 회전하지 않는다
    twothree = true;
  }
  if (gears[3][2] == gears[4][6]) {
    // 같으면, 상대방은 회전하지 않는다
    threefour = true;
  }

  if (dir == 1) {
    switch(no) {
      case 1: // 1번째 톱니를 돌릴 때
        rotate(1, 1);
        if (onetwo == false) {
          rotate(2, -1);
          if (twothree == false) {
            rotate(3, 1);
            if (threefour == false)
              rotate(4, -1);
          }
        }
        break;
      case 2: // 2번째 톱니를 돌릴 때
        rotate(2, 1);
        if (onetwo == false)
          rotate(1, -1);
        if (twothree == false) {
          rotate(3, -1);
          if (threefour == false)
            rotate(4, 1);
        }
        break;
      case 3: // 3번째 톱니를 돌릴 때
        rotate(3, 1);
        if (twothree == false) {
          rotate(2, -1);
          if (onetwo == false)
            rotate(1, 1);
        }
        if (threefour == false)
          rotate(4, -1);
        break;
      case 4: // 4번째 톱니를 돌릴 때
        rotate(4, 1);
        if (threefour == false) {
          rotate(3, -1);
          if (twothree == false) {
            rotate(2, 1);
            if (onetwo == false)
              rotate(1, -1);
          }
        }
        break;
    }
  } else {
    // 반시계 방향으로 돌렸을 때
    switch(no) {
      case 1: // 1번째 톱니를 돌릴 때
        rotate(1, -1);
        if (onetwo == false) {
          rotate(2, 1);
          if (twothree == false) {
            rotate(3, -1);
            if (threefour == false)
              rotate(4, 1);
          }
        }
        break;
      case 2: // 2번째 톱니를 돌릴 때
        rotate(2, -1);
        if (onetwo == false)
          rotate(1, 1);
        if (twothree == false) {
          rotate(3, 1);
          if (threefour == false)
            rotate(4, -1);
        }
        break;
      case 3: // 3번째 톱니를 돌릴 때
        rotate(3, -1);
        if (twothree == false) {
          rotate(2, 1);
          if (onetwo == false)
            rotate(1, -1);
        }
        if (threefour == false)
          rotate(4, 1);
        break;
      case 4: // 4번째 톱니를 돌릴 때
        rotate(4, -1);
        if (threefour == false) {
          rotate(3, 1);
          if (twothree == false) {
            rotate(2, -1);
            if (onetwo == false)
              rotate(1, 1); 
          }
        }
        break;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 1 ; i <= 4 ; i++) {
    cin >> gears[i];
  }
  cin >> K;
  for (int i = 0 ; i < K ; i++) {
    int no, dir;
    cin >> no >> dir;
    move(no, dir); // no번 톱니바퀴, dir 방향
  }

  int sum = 0;
  if (gears[1][0] == '1')
    sum += 1;
  if (gears[2][0] == '1')
    sum += 2;
  if (gears[3][0] == '1')
    sum += 4;
  if (gears[4][0] == '1')
    sum += 8;

  cout << sum;

  return 0;
}
