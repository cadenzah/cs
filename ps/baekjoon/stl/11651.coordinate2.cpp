// 왜 런타임 오류가 발생할까?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct comparer {
  const bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
    // if (a.second < b.second) return a.second < b.second;
    // else return a.first < b.first;
    if (a.second < b.second) return true;
    else if (a.second == b.second) {
      if (a.first < b.first) return true;
    }
    return false;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<pair<int, int> > coordinates(N);
  for (int i = 0 ; i < N ; i++) {
    cin >> coordinates[i].first >> coordinates[i].second;
  }

  sort(coordinates.begin(), coordinates.end(), comparer());

  for (int i = 0 ; i < N ; i++) {
    cout << coordinates[i].first << " " << coordinates[i].second;
    if (i < N - 1) cout << "\n";
  }

  return 0;
}
