#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    
    // 본격 Mix
    while(pq.top() < K) {
        
        if(pq.size() < 2) {  // pq에 원소 1개만 남았는데 K보다 작음 (mix 불가능)
            answer = -1;
            break;
        }
        
        int min1 = pq.top();
        pq.pop();
        
        int min2 = pq.top();
        pq.pop();
        
        int mixed = min1 + min2 * 2;
        pq.push(mixed);
        answer++;
    }
    
    
    
    return answer;
}