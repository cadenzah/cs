#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;
  map<string, int> list;
  vector<string> answers;
  string name;

  for (int i = 0 ; i < N ; i++) {
    cin >> name;
    list[name]++;
  }
  for (int i = 0 ; i < M ; i++) {
    cin >> name;
    list[name]++;
  }

  for (map<string, int>::iterator itr = list.begin() ; itr != list.end() ; itr++) {
    if (itr->second >= 2)
      answers.push_back(itr->first);
  }

  cout << answers.size() << "\n";
  for (int i = 0 ; i < answers.size() ; i++) {
    cout << answers[i] << "\n";
  }

  return 0;
}
