// cout에서 서식 지정하는 방법을 알아두자

#include <iostream>
#include <vector>
using namespace std;

double get_ratio(vector<int>& students) {
    int sum = 0, over = 0;
    double average = 0.0;
    
    for (int i = 0 ; i < students.size() ; i++) {
        sum += students[i];
    }
    average = sum * 1.0 / students.size();
    
    for (int i = 0 ; i < students.size() ; i++) {
        if (students[i] > average) ++over;
    }
    
    return over * 1.0 / students.size() * 100;
}

int main(void) {
    int input_count;
    cin >> input_count;
    vector<vector<int> > inputs(input_count);
    
    for (int i = 0 ; i < input_count ; i++) {
        int student_count, temp;
        cin >> student_count;
        for (int j = 0 ; j < student_count ; j++) {
            cin >> temp;
            inputs[i].push_back(temp);
        }
    }
    
    cout.precision(3);
    cout << showpoint << fixed;
    for (int i = 0 ; i < input_count ; i++) cout << get_ratio(inputs[i]) << "%" << "\n";
    
    return 0;
}
