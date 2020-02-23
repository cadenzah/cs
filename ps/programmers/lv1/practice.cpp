// https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1번
// 1, 2, 3, 4, 5, ...
// 2번
// 2, 1, 2, 3, 2, 4, 2, 5, ...
// 3번
// 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

const int ONE[] = { 1, 2, 3, 4, 5 }; // 5
const int TWO[] = { 2, 1, 2, 3, 2, 4, 2, 5 }; // 8
const int THREE[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; // 10

struct Person {
    int name;
    int result;
    Person(int _name) { name = _name; result = 0; }
};

struct comparor {
    bool operator() (Person& a, Person& b) {
        if (a.result == b.result) {
            // 동점자면, 이름 오름차순으로
            return a.name < b.name;
        }
        return a.result > b.result;
    }
};

vector<int> solution(vector<int> answers) {
    Person one(1), two(2), three(3);
    vector<Person> list;
    
    // 모든 문제를 순회하면서 각 사람들의 답안을 채점
    for (int i = 0 ; i < answers.size() ; i++) {
        // 각 사람마다 찍기 패턴이 있으므로 이에 따라 첨자를 나머지 연산 해준다
        int answer1 = ONE[i % 5];
        int answer2 = TWO[i % 8];
        int answer3 = THREE[i % 10];
            
        // 맞출 때마다 PERSON.result++ 한다
        if (answer1 == answers[i]) ++one.result;
        if (answer2 == answers[i]) ++two.result;
        if (answer3 == answers[i]) ++three.result;
    }
    
    // 제일 많이 맞춘 사람만 리턴
    // 동점자가 있으면, 오름차순으로 다같이
    list.push_back(one);
    list.push_back(two);
    list.push_back(three);
    sort(list.begin(), list.end(), comparor());
    
    if (list[0].result == list[1].result) {
        if (list[1].result == list[2].result) {
            // 동점자 3명
            return { 1, 2, 3 };
        } else {
            // 동점자 2명
            return { list[0].name, list[1].name };
        }
        
    } else {
        return { list[0].name };
    }
}
