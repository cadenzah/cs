#include <string>
#include <vector>

using namespace std;

struct Stage {
    int stage_number;
    double fail_rate;
    Stage(int _number, double _rate) { stage_number = _number; fail_rate = _rate; }
};

// 부분합
// S(k): k을 클리어했거나 도전하고 있는 사람 = a(k) + a(k+1) + ... a(N+1)
// S(k) = S(k+1) + a(k)
// S(k) - S(k+1) = k를 실패한 사람 
// a(k): k를 도전하고 있는 사람

// S(k) - S(k+1) / S(k)

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<int> S(N + 2, 0); // 다 깬 사람 포함, 0은 안 씀
    vector<int> A(N + 2, 0);
    vector<Stage> list(N+1);
    
    // 1. a를 다 구한다
    for (int i = 0 ; i < stages.size() ; i++) {
        ++A[stages[i]];
    }
    // 2. s를 다 구한다
    S[N+1] = A[N+1]; // 다 깬 사람
    for (int i = N ; i > 0 ; i--) {
        S[i] = S[i + 1] + A[i];
    }
    
    // 3. 각 스테이지 정보를 넣는다
    list.push_back(Stage(0, 0.0)); // 0번째 더미
    for (int i = 1 ; i < N+1 ; i++) {
        list.push_back(Stage(i, (S[i] - S[i+1]) / S[i]));
    }
    
    return answer;
}

// 실패 == 해당 스테이지에는 도달했지만, 아직 클리어는 못한 경우
// 실패율 = 실패한 사람 / 스테이지에 도달한 사람

// 1 <= N <= 500
// stages에는 각각 멈춰있는 스테이지 번호가 담겨있다
// 즉, 해당 번호 - 1까지는 다 깬거
// 해당번호는 못 깬거 ; 실패 처리
// N+1인 경우: 다 깬거
// 답: 실패율 내림차순 기준으로 스테이지 번호 정렬

// 1.
// stages 배열을 돌면서, 각각의 값을 answer에 저장하는데,
// answer[1...k-1]
