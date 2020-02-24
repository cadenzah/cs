// https://programmers.co.kr/learn/courses/30/lessons/17681

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, "");
    vector<int> temp(n);
    
    // 1. 비트마스킹
    // arr1[i] | arr2[i]에서 1은 #, 0은 공백
    for (int i = 0 ; i < n ; i++) {
        temp[i] = (arr1[i] | arr2[i]);
    }
    
    // 2. 각각을 string으로 변환
    for (int i = 0 ; i < n ; i++) {
        for (int j = n - 1 ; j >= 0 ; j--) {
            if (temp[i] & (1 << j)) answer[i] += "#";
            else answer[i] += " ";
        }
    }
    
    return answer;
}
