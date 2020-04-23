// 현재 인덱스, 그 전까지 상태

#include <iostream>
#include <vector>
using namespace std;

// status 0: asec, 1: dsec
void determine(vector<int>& score, int index, int status) {
  // base case
  if (index == 7) {
    if (status == 0) cout << "ascending";
    else if (status == 1) cout << "descending";
  }
  else {
    // ascending 유지
    if (status == 0 && score[index] + 1 == score[index + 1]) determine(score, index + 1, 0);
    // descending 유지
    else if (status == 1 && score[index] - 1 == score[index + 1]) determine(score, index + 1, 1);
    else cout << "mixed";
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> score(8);

  for (int i = 0 ; i < 8 ; i++) {
    cin >> score[i];
  }

  if (score[0] == 1) determine(score, 0, 0);
  else if (score[0] == 8) determine(score, 0, 1);
  else cout << "mixed";

  return 0;
}
