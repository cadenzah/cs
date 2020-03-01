#include <string>
#include <vector>

using namespace std;

// 경로 + 완전 탐색?
// 주어진 스킬 트리 중에서 규칙 부합하는 것 개수 구하기

// 나머지 확인할 스킬 순서가 이거이고, 남은 스킬트리가 이거일 때, 해당 스킬 트리가 가능한지 여부 반환
bool isValidSkill(string skill, string tree) {
    // 기저1: skill 끝까지 다 가기
    if (skill.length() == 0) return true;
    // 기저2: tree 끝까지 다 가기
    if (tree.length() == 0) return true;
    
    // skill의 맨 앞이랑 tree의 특정 인덱스와 일치하는 걸 만나면
    // true && skill.substr(1), tree.substr(i)로 다시 재귀호출
    for (int i = 0 ; i < tree.length() ; i++) {
        if (skill[0] == tree[i]) {
            return true && isValidSkill(skill.substr(1), tree.substr(i+1));
        }
    }
    
    // 일치 없으므로 실패
    return false;
    
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i = 0 ; i < skill_trees.size() ; i++) {
        if (isValidSkill(skill, skill_trees[i])) ++answer;
    }
    
    return answer;
}
