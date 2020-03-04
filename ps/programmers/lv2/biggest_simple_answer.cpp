#include <string>
#include <vector>
#include <algorithm>

/*
 * 가장 큰 수 (https://programmers.co.kr/learn/courses/30/lessons/42746)
 * 
 * 결국 이 문제도 정렬 문제고, "각 값들을 어떤 기준으로 비교하여 앞뒤 관계를 만들 것인지"를 고민해야 한다.
 * 비교는 두 요소에 대하여 이루어지므로, "두 요소"에 대하여 어떤 기준으로 순서를 부여할 것인가를 따져보자...
 * (i) 두 요소를 보아, ~~한 조건일 때에는, 두 요소 중 앞의 요소가 더 앞이다
 * (ii) (i)과 같은 비교를 기반으로, 확대하여 적용할 수 있는가?
 * (iii) 익스트림 반례를 놓치지 말자 ("000"의 경우)
*/

using namespace std;

struct comparor {
  bool operator() (int a, int b) {
      if (to_string(a) + to_string(b) > to_string(b) + to_string(a)) return true;
          else return false;
  }
};

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comparor());
    
    if (numbers[0] == 0) return "0";

    for (int i = 0 ; i < numbers.size() ; i++) {
        answer = answer + to_string(numbers[i]);
    }
    
    return answer;
}
