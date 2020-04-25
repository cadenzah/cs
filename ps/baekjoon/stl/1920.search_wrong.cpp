// set을 사용하여, 이 안에 수를 저장
// search해서 찾으면 1, 안나오면 0
#include <iostream>
// #include <set>
#include <vector>
#include <algorithm>
using namespace std;

// nlogn이 아닌 n만큼 시간이 걸리게끔

struct entry {
  int order;
  int value;
  int isExist;
};

struct comparer {
  const bool operator() (const struct entry& a, const struct entry& b) {
    return a.value < b.value;
  }
};

struct comparer2 {
  const bool operator() (const struct entry& a, const struct entry& b) {
    return a.order < b.order;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, temp;
  cin >> n;
  vector<int> list(n);
  for (int i = 0 ; i < n ; i++) {
    cin >> list[i];
  }
  sort(list.begin(), list.end());

  cin >> n;
  vector<struct entry> wanted(n);
  for (int i = 0 ; i < n; i++) {
    int temp;
    cin >> temp;
    wanted[i].isExist = 0;
    wanted[i].order = i;
    wanted[i].value = temp;
  }
  // 값 순서대로 정렬
  // second에는 본래 위치가 들어있다
  sort(wanted.begin(), wanted.end(), comparer());

  int cursor = 0, index = 0;
  while (index != n) {
    // list가 먼저 끝나버리면, 항상 맨 끝을 가리킨다
    if (cursor == n) cursor--;

    // wanted의 앞에서부터 쭉 나아가면서
    // list 내에 값이 존재하는지 확인
    // 존재할 때마다 cursor(list의 현재 커서를 가리키는 값)을 증가
    
    // list의 끝에 도달했는데, wanted[index] > list[cursor] 이면
    // 존재하지 않는 것이므로,
    // cout << 0
    // index++
    if (cursor == n - 1 && wanted[index].value > list[cursor]) {
      wanted[index].isExist = 0;
      index++;
    }
    // 만약 wanted[index] < list[cursor] 이면 지나친 것이므로,
    // cout << 0
    // continue
    else if (wanted[index].value < list[cursor]) {
      wanted[index].isExist = 0;
    }
    // wanted[index] == list[cursor]이면, 존재하므로
    // cout << 1
    // cursor++
    // continue
    else if (wanted[index].value == list[cursor]) {
      wanted[index].isExist = 1;
      cursor++; index++;
    }

    else {
      cursor++;
    }
  }

  sort(wanted.begin(), wanted.end(), comparer2());

  for (int i = 0 ; i < n - 1 ; i++) {
    cout << wanted[i].isExist << "\n";
  }
  cout << wanted[n - 1].isExist;

  return 0;
}
