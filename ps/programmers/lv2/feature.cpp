// https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>

using namespace std;

// progresses는 배포 순서대로 각 작업의 현재 진도 상황이 들어있다
// speeds는 progresses의 각 첨자별 작업에 대한 작업 속도
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int task_idx = 0; // 이번에 시작해야하는 작업 첫번째 지시자
    
    while (task_idx < progresses.size()) {
        // 맨 앞 작업 기준으로 필요한 일수 계산
        int required_days = (100 - progresses[task_idx]) / speeds[task_idx];
        // 나머지가 있을 경우, 하루 더 추가
        if ((100 - progresses[task_idx]) % speeds[task_idx] != 0) ++required_days;
        for (int i = task_idx ; i < progresses.size() ; i++) {
            // 맨 앞 작업이 모두 완료될 때까지, 작업 진행
            progresses[i] += required_days * speeds[i];
        }
        
        // 이번 배포에서 완료된 작업 개수
        int task_count = 0;
        for (int i = task_idx ; i < progresses.size() ; i++) {
            if (progresses[i] >= 100) {
                // 앞에서부터 진행도가 100인 것들만 배포
                ++task_count;
                // 다음 배포 전까지 시작할 작업 지시자 갱신
                task_idx += task_count;
            } else {
                break;
            }
        }
        answer.push_back(task_count);
    }
    
    return answer;
}
