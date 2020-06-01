// 1206. [S/W 문제해결 기본] 1일차 - View (D3)

// 양쪽 모두 거리 2칸 이상의 공간이 확보될 때
// 이러한 세대 수 개수 새서 반환

// 1000 * 255
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
// index번째 빌딩에 대하여
// 조망권이 확보된 집이 몇 채인지 구하여 답에 합산하기
void calc(vector<int>& builds, int index) {
  // builds[i - 2] ; builds[i - 1] ; builds[i] ; builds[i + 1] ; builds[i + 2]를 비교하여
  // builds[i] - (builds[i] 이외의 값 중 최댓값) 을 구해서 0보다 크거나 같은 값이면 합산
  int comparor = max(builds[index - 2], builds[index - 1]);
  comparor = max(comparor, builds[index + 1]);
  comparor = max(comparor, builds[index + 2]);
  
  if (builds[index] - comparor > 0)
    answer += (builds[index] - comparor);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (int ii = 0 ; ii < 10 ; ii++) {
    int length;
    cin >> length; // 빌딩 숲 길이 ; 첫 둘 그리고 마지막 둘은 0
    vector<int> builds(length, 0);
    for (int i = 0 ; i < length ; i++)
      cin >> builds[i];
    
    // 2부터 (length - 3) 까지
    for (int i = 2 ; i <= length - 3 ; i++)
      calc(builds, i);
    
    cout << "#" << ii + 1 << " " << answer << "\n";
    answer = 0;
  }

  return 0;
}
