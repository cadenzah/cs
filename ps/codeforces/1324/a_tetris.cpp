#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  for (int _i = 0 ; _i < t ; _i++) {
    int c_size, base_height; bool flag = true;
    cin >> c_size;
    vector<int> columns(c_size);
    for (int i = 0 ; i < c_size ; i++) cin >> columns[i];

    // 제일 먼저, 현재 입력 상태로 클리어 가능한지 확인
    base_height = *max_element(columns.begin(), columns.end());
    for (int i = 1 ; i < c_size ; i++) {
      // 다르면, 나온다
      if (columns[i] != base_height) {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      // 가능하면, 루프 탈출
      cout << "YES";
      if (_i != t - 1) cout << "\n";
      continue;
    }

    // 그 다음, 각 칸을 순회하며
    // 현재 높이 기준 2의 배수 꼴로 채워질 수 있는지 확인
    for (int i = 0 ; i < c_size ; i++) {
      int current_height = base_height - columns[i];
      if (current_height % 2 != 0) {
        // 하나라도 불가능하면, break
        flag = false;
        break;
      }
      if (i == c_size - 1) flag = true;
    }
    

    if (flag == true) {
      cout << "YES";
      if (_i != t - 1) cout << "\n";
      continue;
    } else {
      cout << "NO";
      if (_i != t - 1) cout << "\n";
      continue;
    }
  }

  return 0;
}
