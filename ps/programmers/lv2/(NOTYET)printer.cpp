#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Document {
    int priority;
    int id;
    Document(int _i, int _p) { id = _i; priority = _p; }
    
    bool operator< (const Document& a) const {
        return priority < a.priority;
    }
};

int solution(vector<int> priorities, int location) {
    queue<Document> print_list;
    int answer = 0;
    
    // 프린트 목록 초기화
    // queue에 싹 다 옮긴다 (push)
    for (int i = 0 ; i < priorities.size() ; i++) {
        print_list.push(Document(i, priorities[i]));
    }

    // 빌 때까지 루프
    while(!print_list.empty()) {
        Document current = print_list.front();
        
        
        // 내 것보다 크면 => 다시 넣는다
        if (current.priority < max_prior->priority) {
            print_list.push(current);
        } else {
        // 내 것보다 작거나 같으면 그대로 진행
            // 출력 완료한 문서 개수
            ++answer;
            if (current.id == location) {
                // 목표로 하는 문서이면
                return answer;
            }
        }   
    }
}
