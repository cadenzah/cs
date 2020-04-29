#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Person {
  int superiors;
  int weight; // x
  int height; // y
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  // 명단 초기화
  vector<struct Person> list(N);
  for (int i = 0 ; i < N ; i++) {
    cin >> list[i].weight >> list[i].height;
    list[i].superiors = 0;
  }

  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < N ; j++) {
      // 나보다 큰 사람 수 체크
      if (i == j) continue;
      if (list[i].weight < list[j].weight && list[i].height < list[j].height)
        list[i].superiors++;
    }
  }

  for (int i = 0 ; i < N ; i++) {
    cout << list[i].superiors + 1;
    if (i < N - 1) cout << " ";
  }
  
  return 0;
}
