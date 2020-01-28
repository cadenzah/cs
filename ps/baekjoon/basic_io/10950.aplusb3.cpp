#include<iostream>
using namespace std;
int main(void) {
  int count;
  int temp1, temp2;
  cin >> count;
  for (int i = 0 ; i < count ; i++) {
    cin >> temp1 >> temp2;
    cout << temp1 + temp2 << endl;
  }
  return 0;
}
