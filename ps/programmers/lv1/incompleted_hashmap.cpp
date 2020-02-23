// https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> checklist;
    
    for (int i = 0 ; i < completion.size() ; i++) {
        unordered_map<string, int>::iterator current = checklist.find(completion[i]);
        if (current == checklist.end()) {
            // 완주한 사람들을 입력, 각 이름 별로 value = 1 부여하면서 새로 추가
            checklist.insert(make_pair(completion[i], 1));
        } else {
            // 동명이인인 경우, value + 1 한다
            ++current->second;
        }
    }
    
    // 참가자 명단을 돌면서, 완주 명단에서 검색
    for (int i = 0 ; i < participant.size() ; i++) {
        unordered_map<string, int>::iterator current = checklist.find(participant[i]);
        if (current == checklist.end()) {
            // 완주 못한 사람을 찾은 경우
            return participant[i];
        } else {
            --current->second;
            if (current->second < 0) {
                // 동명이인 중 완주 못한 사람을 찾은 경우
                return participant[i];
            }
        }
    }
    
}
