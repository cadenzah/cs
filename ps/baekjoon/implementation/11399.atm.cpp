#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// 부분합
int cache[1000];
int sum = 0;

// 정렬하고,
// cache[i] == 1부터 i까지의 시간합
// cache[i+1] = cache[i] + P(i+1)

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(&cache, 0, sizeof(cache));

  int N;
  cin >> N;
  vector<int> people(N);
  for (int i = 0 ; i < N ; i++)
    cin >> people[i];

  sort(people.begin(), people.end());
  cache[0] = people[0];
  sum += cache[0];
  for (int i = 1 ; i < N ; i++) {
    cache[i] = cache[i - 1] + people[i];
    sum += cache[i];
  }
    
  cout << sum;

  return 0;
}
