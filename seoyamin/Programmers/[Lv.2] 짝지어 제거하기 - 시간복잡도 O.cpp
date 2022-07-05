#include <iostream>
#include <string>
#include <stack>

using namespace std;


int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    stk.push(s[0]); // 일단 0번째 원소 push
    

    for(int i=1 ; i<s.size() ; i++) {
        
        // case 1) stk 텅 빔
        if(stk.empty()) {    
            stk.push(s[i]);
        }
        
        // case 2) stk 저장 원소 있는데 동일함 -> pop
        else if(stk.top() == s[i]) {
            stk.pop();
        }
        
        // case 3) stk 저장 원소 있는데 동일 X -> push
        else stk.push(s[i]);

    }
    
    // '짝지어 제거' 가능 여부 결정
    if(stk.empty()) answer = 1;
    else answer = 0;
    

    return answer;
}