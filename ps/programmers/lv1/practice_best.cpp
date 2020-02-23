// https://programmers.co.kr/learn/courses/30/lessons/42840/solution_groups?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(),they.end()); // 유용한 STL 함수
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1); // 이렇게 처리하면, 굳이 각 인물의 번호를 따로 기억할 필요가 없다
    }
    return answer;
}
