#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct person {
  int age;
  int order;
  string name;
};

struct comparor {
  bool operator() (const struct person& a, const struct person& b) {
    if (a.age != b.age) return a.age < b.age;
    return a.order < b.order;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<struct person> list(n);
  for (int i = 0 ; i < n ; i++) {
    cin >> list[i].age;
    cin >> list[i].name;
    list[i].order = i;
  }
  sort(list.begin(), list.end(), comparor());

  for (int i = 0 ; i < n - 1 ; i++) {
    cout << list[i].age << " " << list[i].name << "\n";
  }
  cout << list[n - 1].age << " " << list[n - 1].name;

  return 0;
}
