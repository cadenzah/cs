#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> sticks;
    for (int i = 0 ; i < arrangement.length() ; i++) {
        if (arrangement[i] == '(') {
            if (i < arrangement.length() - 1 && arrangement[i + 1] == ')') {
                // () 등장: 현재 스택에 있는 개수만큼 총 개수++
                ++i;
                answer += sticks.size();
            } else {
                // ( 등장: 스택에 1개 추가
                sticks.push('(');
            }
        } else {
            // ) 등장: 스택에서 1개 빼면서 총 개수++
            sticks.pop();
            ++answer;
        }
    }

    return answer;
}
