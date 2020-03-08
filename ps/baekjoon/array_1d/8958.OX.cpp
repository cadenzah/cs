// 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count(string& input) {
    int count = 0, score = 0;
    for (int i = 0 ; i < input.length() ; i++) {
        if (input[i] == 'O') {
            ++count;
        } else {
            score = score + count * (count + 1) / 2;
            count = 0;
        }
    }
    if (count != 0) score = score + count * (count + 1) / 2;
    return score;
}

int main(void) {
    int input_count;
    cin >> input_count;
    vector<string> inputs(input_count);
    
    for (int i = 0 ; i < input_count ; i++) cin >> inputs[i];
    for (int i = 0 ; i < input_count ; i++) cout << count(inputs[i]) << "\n";
    
    return 0;
}
