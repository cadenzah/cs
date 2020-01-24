// ,를 기준으로 인덱스 찾은 뒤
// 그 앞, 그 뒤를 스트링으로 얻어내서
// 그걸 숫자로 변환
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
  int count; cin >> count;
  vector<int> sum(count);
  cin.ignore(256, '\n');

  for (int i = 0 ; i < count ; i++) {
    string temp;
    cin >> temp;
    int comma_pos = temp.find(',');
    string a = temp.substr(comma_pos);
    string b = temp.substr(comma_pos, temp.length)
  }
}
