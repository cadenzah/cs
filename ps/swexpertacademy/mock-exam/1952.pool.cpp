// 1952. [모의 SW 역량테스트] 수영장

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 987654321;
int answer = MAX_VALUE;

// index월까지의 비용이 sum일 때, 
// index + 1월 이후의 이용 비용
void calc(vector<int>& fee, vector<int>& plan, int index, int sum) {
  // base case: 현재 sum이 answer보다 크거나 같으면 무의미 ; return으로 스탑
  if (sum >= answer)
    return;
  
  // base case: 현재 index가 13이면, 계산 끝이므로, sum을 answer와 비교하여 갱신
  if (index >= 12) {
    // 모든 월 계획이 0인 경우에만 답이 0이어도 인정
    answer = min(answer, sum);
  }
    
  
  // 각 경우에 대하여 계산
  if (plan[index + 1] > 0) {
    calc(fee, plan, index + 1, sum + plan[index + 1] * fee[0]); // 해당월 계획 = 0 포함
    calc(fee, plan, index + 1, sum + fee[1]);
    calc(fee, plan, index + 3, sum + fee[2]);
    calc(fee, plan, index + 12, sum + fee[3]);
  } else {
    calc(fee, plan, index + 1, sum);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  vector<int> fee, plan;

  for (int ii = 0 ; ii < t ; ii++) {
    vector<int> fee(4, 0);   // 1일, 1달, 3달, 1년
    vector<int> plan(13, 0); // 1월 ~ 12월
    int days = 0;
    for (int i = 0 ; i < 4 ; i++)
      cin >> fee[i];
    for (int i = 1 ; i <= 12 ; i++) {
      cin >> plan[i];
      days += plan[i];
    }

    calc(fee, plan, 0, 0);

    cout << "#" << ii + 1 << " " << answer << "\n";
    answer = MAX_VALUE;
  }

  return 0;
}
