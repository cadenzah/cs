// https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int a = 0 ; a < commands.size() ; a++) {
        // 각각의 i,j,k에 대하여 풀기
        int i = commands[a][0], j = commands[a][1], k = commands[a][2];
        // 1. 자르기
        vector<int> sub_array;
        for (int _i = i - 1 ; _i < j ; _i++) {
            sub_array.push_back(array[_i]);
        }
        
        // 2. 정렬하기
        sort(sub_array.begin(), sub_array.end());
        
        // 3. 3번째 값 반환
        answer.push_back(sub_array[k - 1]);   
    }
    
    return answer;
}
