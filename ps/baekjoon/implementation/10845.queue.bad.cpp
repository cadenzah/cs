#include <iostream>
#include <queue>
using namespace std;


int main (void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  queue<int> container;
  int n;
  cin >> n;

  for (int i = 0 ; i < n ; i++) {
    string command;
    int value;
    cin >> command;

    if (command == "push") {
      cin >> value;
      container.push(value);
    } else if (command == "pop") {
      if (!container.empty()) {
        value = container.front();
        container.pop();
        cout << value << "\n";
      } else
        cout << "-1" << "\n";
    } else if (command == "size") {
      cout << container.size() << "\n";
    } else if (command == "empty") {
      if (container.empty())
        cout << "1" << "\n";
      else
        cout << "0" << "\n";
    } else if (command == "front") {
      if (!container.empty())
        cout << container.front() << "\n";
      else
        cout << "-1" << "\n";
    } else if (command == "back") {
      if (!container.empty())
        cout << container.back() << "\n";
      else
        cout << "-1" << "\n";
    }
  }

  return 0;
}
