// https://programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);

    for (int i = 1 ; i < arr.size() ; i++) {

        // 1. 연속일 떄
        // 2. 마지막으로 answer에 넣은 수와 다를 때
        if (arr[i] == arr[i - 1] && answer[answer.size() - 1] != arr[i]) {
            answer.push_back(arr[i]);
        } else if (arr[i] != arr[i - 1]) {
            answer.push_back(arr[i]);
        }
    }
    return answer;
}
