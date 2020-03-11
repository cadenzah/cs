// https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> types;
    
    for (int i = 0 ; i < clothes.size() ; i++) {
        ++types[clothes[i][1]];
    }
    
    for (map<string, int>::iterator itr = types.begin() ; itr != types.end() ; ++itr) {
        answer *= (itr->second + 1);
    }
    
    return answer - 1;
}

// 종류별로 개수를 저장
// (개수 + 1) * (개수 + 1) ... - 1
