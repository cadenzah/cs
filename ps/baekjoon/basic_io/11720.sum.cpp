#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);  
  
  string numbers;
  int count, sum = 0;
  cin >> count >> numbers;

  for (int i = 0 ; i < count ; i++) {
    int value = numbers[i] - 48;
    sum = sum + value;
  }

  cout << sum;

  return 0;
}
