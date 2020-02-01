#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int temp1, temp2, count;
  cin >> count;

  for (int i = 0 ; i < count ; i++) {
    cin >> temp1 >> temp2;
    cout << "Case #" << i + 1 << ": " << temp1 << " + " << temp2 << " = " << temp1 + temp2 << "\n";
  }
  return 0;
}
