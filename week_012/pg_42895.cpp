#include <string>
#include <vector>

using namespace std;

int answer = 987654321, n, goal;
vector<int> v;

void dfs(int cnt, int num) {
    if (cnt > 8) { // 8번 넘게 사용하면 멈춤
        return;
    }
    if (num == goal) {
        answer = (answer > cnt) ? cnt : answer;
        return;
    }
    
    int cur = 0;
    for (int i = 0 ; i < 8; i++) {
        cur = (cur*10) + n; // n, nn, nnn ...
        // 연산자의 우선순위는 고려X
        // 5+5*5인 경우 30이 정답이지만 내 코드에서는 50으로 나옴
        // 모든 경우를 탐색하기 때문에 5*5+5로 30이 나오는 경우가 있기 때문
        dfs(cnt+i+1, num+cur); // i+1번 사용, +
        dfs(cnt+i+1, num-cur); // -
        if (num!=0) {
            dfs(cnt+i+1, num*cur); 
            dfs(cnt+i+1, num/cur);
        }    
    }
}

int solution(int N, int number) {
    n = N;
    goal = number;
    
    dfs(0, 0);
    if (answer==987654321) answer=-1;
    
    return answer;
}