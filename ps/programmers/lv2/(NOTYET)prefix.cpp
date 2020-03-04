#include <string>
#include <vector>
#include <map>
#include <algorithm>
// #include <iostream>

// 틀린 풀이...

using namespace std;

struct comparor {
  bool operator () (string& a, string& b) {
      return a < b;
  }
};

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> list;
    
    string base_string = *min_element(phone_book.begin(), phone_book.end(), comparor());
    int base_length = base_string.length();
    
    for (int i = 0 ; i < phone_book.size() ; i++) {
        string current = phone_book[i].substr(0, base_length);
        if (list[current] == 0) list[current] = 1;
        else return false;
    }
    
    return true;
}

// 길이가 가장 짧은 것 찾기
// 그걸 기준으로 입력 다듬기 
// 그걸로 해시테이블 작성하여 중복 찾기
