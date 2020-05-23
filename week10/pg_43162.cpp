#include <vector>
#include <queue>
#include <iostream>
#include <memory.h>

using namespace std;

bool visit[200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    memset(visit, 0, sizeof visit);
    
    for (int i = 0; i < n; i++) {
        if (visit[i]) // 이미 방문된 네트워크인 경우 패스
            continue;
        
        answer++; // 네트워크 +1
        
        queue<int> q; // 연결된 네트워크를 담을 큐
        
        visit[i] = true;
        q.push(i);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            vector<int> v = computers[cur]; // cur의 네트워크 배열
            
            for (int j = 0; j < v.size(); j++) {
                
                if (v[j] == 1) { // i랑 연결된 경우
                    if (cur == j) continue;
                    if (!visit[j]) { // 방문 안 했을 경우
                        q.push(j);
                        visit[j] = true;
                    }
                } 
            }
        }
    }
   
    return answer;
}