// 이름을 입력하면 번호를 반환하거나
// 번호를 입력하면 이름을 반환하거나

// 1 <= N <= 100000
// 1 <= M <= 100000

// N개 줄에 1 ~ N번째 포켓몬 이름이 들어온다
// M개의 문제
// 알파벳이면, 번호 반환
// 숫자이면, 이름 반환

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct comparer {
  const bool operator() (const string& a, const string& b) {
    return a < b;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;
  vector<string> no_to_name(N + 1);
  map<string, int> name_to_no;

  for (int i = 1 ; i <= N ; i++) {
    cin >> no_to_name[i];
    name_to_no.insert(make_pair(no_to_name[i], i));
  }

  for (int i = 0 ; i < M ; i++) {
    string input;
    cin >> input;

    if (input[0] - '0' < 10) {
      // 숫자
      int number = stoi(input);
      cout << no_to_name[number] << "\n";
    } else {
      cout << name_to_no[input] << "\n";
    }
  }

  return 0;
}
