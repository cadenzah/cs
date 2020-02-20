// https://programmers.co.kr/learn/courses/30/lessons/12915

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct compare {
    int index;
    compare(int _index) { index = _index; }
    bool operator() (string& a, string& b) {
        if (a[index] < b[index]) return true;
        else if (a[index] == b[index]) {
            return a <= b;
        }
        else return false;
    }
};

vector<string> solution(vector<string> strings, int n) {
    // vector<string> answer;
    sort(strings.begin(), strings.end(), compare(n));
    return strings;
}
