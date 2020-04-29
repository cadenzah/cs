// N <= 10000이니까 걍 666부터 순서대로 순회하자... 한 10000000까지 해보고 답 나오나 보자

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(int input) {
  int digit = 0;
  int consecutive = 0;
  while (input % 10 != 0 || input / 10 != 0) {
    digit = input % 10;
    if (digit == 6)
      consecutive++;
    else
      consecutive = 0;
    
    if (consecutive == 3) return true;
    
    input = input / 10;
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<int> answer;


  for (int i = 666 ; i < 10000667 ; i++) {
    if (isValid(i)) answer.push_back(i);
  }

  cout << answer[N - 1];

  return 0;
}
