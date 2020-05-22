// 완전 탐색 + DP

// (다음으로 시작할 날짜, 그 전까지의 총 상담금액)
// n일부터 상담했을 때 받을 수 있는 총 상담금액의 최댓값
// = n일 상담했을 때 받는 금액 + 그 다음에 가능한 m일 부터 상담했을 때 받을 수 있는 상담금액의 최댓값
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int cache[16];
int N;

// startdate부터 마지막날까지 상담했을 때 얻을 수 있는 최대 상담금액
int calc(int startdate, vector<int>& T, vector<int>& P) {
  // base case
  if (startdate > N)
    return 0;
  
  int& ret = cache[startdate];
  if (ret != -1)
    return ret;

  // startdate는 상담을 진행하고, 그 이후 첫번쨰 날부터 끝날까지 돌아가면서.
  for (int i = startdate ; i <= N ; i++) {
    // 다음 상담을 진행할 수 있는 첫번째 날 이후의 날들
    int nextdate = i + T[startdate];
    if (nextdate - 1 > N) {
      if (ret == -1)
        ret = 0;
      break;
    }

    ret = max(ret, P[startdate] + calc(nextdate, T, P));
  }

  return ret;
}
// 해당 DP에서의 최적해가 없는 경우의 처리를 빼먹으면 안된다 (30번째 라인)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(&cache, -1, sizeof(cache));

  cin >> N;
  vector<int> T(N + 1), P(N + 1);
  for (int i = 1 ; i <= N ; i++) {
    cin >> T[i] >> P[i];
  }

  int answer = -1;
  for (int i = 1 ; i <= N ; i++)
    answer = max(answer, calc(i, T, P));

  cout << answer;

  return 0;
}

// 틀렸다
int calc1(int startdate, vector<int>& T, vector<int>& P) {
  // basecase
  if (startdate > N) return 0;
  
  int& ret = cache[startdate];
  if (ret != -1) return ret;

  // 해당 날짜 기준, 모든 경우를 돌려본다
  for (int i = startdate ; i <= N ; i++) {
    int nextdate = i + T[i];

    // base case: 끝나는 날이 N 이후인 경우 제외
    if (nextdate - 1 > N) return 0;
    ret = max(ret, P[i] + calc(nextdate, T, P));
  }

  return ret;
}

// 이것도 틀렸다
// startdate부터 마지막날까지 상담했을 때 얻을 수 있는 최대 상담금액
int calc2(int startdate, vector<int>& T, vector<int>& P) {
  // base case
  if (startdate > N)
    return 0;
  
  int& ret = cache[startdate];
  if (ret != -1)
    return ret;

  // 다음 상담을 진행할 수 있는 첫번째 날
  int nextdate = startdate + T[startdate];
  // startdate에 진행하는 상담이 마지막날 이후에 끝난다면, 수행하지 않는다
  if (nextdate - 1 > N)
    return ret = 0;

  // startdate는 상담을 진행하고, 그 이후 첫번쨰 날부터 끝날까지 돌아가면서.
  for (int i = nextdate ; i <= N ; i++) {
    ret = max(ret, P[startdate] + calc(i, T, P));
  }
  // startdate == 8일 때, nextdate == 11이 되버리면서 for문이 아예 안 돈다
  // 예제 입력 4 기준

  return ret;
}
