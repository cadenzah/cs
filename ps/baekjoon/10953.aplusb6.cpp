#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int count;
  cin >> count;
  // vector<int> values(count);
  int comma_pos;
  // cin.ignore(256, '\n');

  // 각 입력 받아오기
  for (int i = 0 ; i < count ; i++) {
    int sum;
    string temp;
    cin >> temp;

    comma_pos = temp.find(',');

    // 숫자값 추출
    string operand1_str;
    operand1_str.assign(temp, 0, comma_pos);
    string operand2_str;
    operand2_str.assign(temp, comma_pos + 1, temp.length() - comma_pos);

    // 변환
    int operand1 = stoi(operand1_str);
    int operand2 = stoi(operand2_str);
    sum = operand1 + operand2;
    printf("%d\n", sum);
  }

  return 0;
}
