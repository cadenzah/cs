#include <string>
#include <vector>
#include <queue>

using namespace std;

// 각각의 트럭을 위한 큐를 만들어서 관리한다?

// 현재 하중 체크하여, 트럭을 올렸을 때 하중이 오케이이면 큐에 트럭을 추가
// 추가시, { time, weight } 형태로 추가
// 큐의 맨앞 트럭을 보고, 다리를 건너는 데에 필요한 시간을 체크
  // 필요 시간: (다리_길이) - 진입 시간 (다리 빠져나가는 시간 제외)
// 트럭이 나간 뒤, 다음 트럭이 들어올 수 있는지 체크
  // 못 들어오면, 앞과 마찬가지로 그 다음 큐의 맨앞 트럭을 보고 필요 시간을 누적
// 이렇게 해서 큐가 다 비면, 1을 더한다 (마지막으로 빠져나가는 시간 체크)

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // 현재 시간의 역할
    int index = 0; // 진입 대기 중인 트럭의 시작 인덱스
    int bridge_weight = 0;
    // { first: time, second: weight }
    queue<pair<int, int> > bridge;
    
    bridge.push(make_pair(answer, truck_weights[index]));
    bridge_weight += truck_weights[index];
    ++index;
    
    while (!bridge.empty()) {
        // 큐의 맨앞 트럭을 보고, 다리를 건너는 데에 필요한 시간을 체크
        int required_time = bridge_length - (answer - bridge.front().first);
          // 필요 시간: (다리_길이) - (현재_시간 - 진입_시간) (다리 빠져나가는 시간 제외)
        answer += required_time;
        bridge_weight -= bridge.front().second;
        bridge.pop();
        
        
        // 트럭이 나간 뒤, 다음 트럭이 들어올 수 있는지 체크
        if (index == truck_weights.size()) break;
        if (bridge_weight + truck_weights[index] > weight) {
            // 못 들어오면, 새 트럭을 추가하지 않는다
            continue;
        } else {
            // 들어올 수 있으면, 추가한다
            bridge.push(make_pair(answer + 1, truck_weights[index]));
            bridge_weight += truck_weights[index];
            ++index;
        }
    }
    // 이렇게 해서 큐가 다 비면, 1을 더한다 (마지막으로 빠져나가는 시간 체크)
    ++answer;
    
    return answer;
}
