#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string input;
  char answer;
  vector<int> cnt(26, 0);

  cin >> input;

  // 각 알파벳 별로 개수 세기
  for (int i = 0 ; i < input.length() ; i++) {
    int letter = input[i];
    if (letter >= 92) letter -= 32; // 대문자로 통일
    ++cnt[letter - 65];
  }

  // 답 확인
  vector<int>::iterator itr = max_element(cnt.begin(), cnt.end());
  int max_pos = itr - cnt.begin();

  // 답이 있는지 확인
  sort(cnt.begin(), cnt.end(), greater<int>());

  if (cnt[0] == cnt[1]) answer = '?';
  else answer = max_pos + 65;

  cout << answer;

  return 0;
}
