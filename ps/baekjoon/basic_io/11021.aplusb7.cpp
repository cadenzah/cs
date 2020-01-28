#include <iostream>
using namespace std;

int main(void) {
  int count;
  cin >> count;
  for (int i = 0 ; i < count ; i++) {
    int operand1, operand2;
    cin >> operand1 >> operand2;
    printf("Case #%d: %d\n", i + 1, operand1 + operand2);
  }

  return 0;
}
