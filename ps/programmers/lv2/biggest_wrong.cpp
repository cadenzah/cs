#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int get_digits(int value) {
    int base_length = 1;
    while ( value / 10 != 0) {
        value /= 10;
        ++base_length;
    }
    return base_length;
}

// string to_string(int value) {
//     string result = "";
//     while (value / 10 != 0 || value % 10 != 0) {
//         result = string(1, value % 10 + 48) + result;
//         value /= 10;
//     }
//     return result;
// }

struct comparor {
  bool operator() (pair<int, int>& a, pair<int, int>& b) {
      return a.first > b.first;
  }
};

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<pair<int, int>> list;
    int max_value = *max_element(numbers.begin(), numbers.end());
    int base_length = get_digits(max_value);
    
    for (int i = 0 ; i < numbers.size() ; i++) {
        // 각 수의 맨 마지막 자릿값을 얻고
        int digit = numbers[i] % 10;
        int current_length = get_digits(numbers[i]);
        int newValue = numbers[i];
        
        // 현재 최대 길이만큼으로 뻥튀기하며, 각 자리값은 원본의 마지막 자리값으로
        for (int j = 0 ; j < base_length - current_length ; j++) {
            newValue = newValue * 10 + digit;
        }
        // first: 비교용 변환값; second: 원본
        list.push_back(pair<int, int>(newValue, numbers[i]));
    }
    
    sort(list.begin(), list.end(), comparor());

    for (int i = 0 ; i < list.size() ; i++) {
        answer = answer + to_string(list[i].second);
    }
    
    return answer;
}

// 각 수를 배열 내 최대 자리수만큼으로 뻥튀기
// 이 때, 맨 끝자리 기준으로 뻥튀기
// ex) 32 320 -> 322 320
// ex) 3 30 34 -> 33 30 34
// 이걸 정렬
// 붙이기
