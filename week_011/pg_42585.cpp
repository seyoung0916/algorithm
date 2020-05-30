#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    
    for (int i = 0; i < arrangement.length();i++) {
        
        if (arrangement[i] == '(' && arrangement[i+1] == ')') { // 파이프
            answer+=s.size(); // 파이프 개수
            i++; // 레이저 부분 패스
            continue;
        }
        
        s.push(arrangement[i]); // 현재 값
        
        if (arrangement[i] == ')') {
            s.pop(); // ')' pop
            s.pop(); // '(' pop
            answer+=1;
        }
    }
    if (!s.empty())
        answer += s.size();
    return answer;
}