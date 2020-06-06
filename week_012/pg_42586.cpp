#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int tmp[progresses.size()];
    memset(tmp, 0, sizeof tmp);
    map <int,int> m;
    
    for (int i = 0; i < progresses.size(); i++) {
        int curP = progresses[i];
        int curS = speeds[i];
        int cnt = 0;
        
        while (curP < 100) { // 업무 완료 시점을 구함
            curP += curS;
            cnt++;
        }
        
        tmp[i] = cnt;
    }
    // 앞 기능의 배포 기간이 느리면 앞에 맞춤
    for (int i = 0; i < progresses.size() - 1; i++) { 
        if (tmp[i] > tmp[i+1]) {
            tmp[i+1] = tmp[i];
        }
    }
    // 배포 기간, 기간 횟수를 맵에 저장
    for (int i = 0; i < progresses.size(); i++) { 
        m[tmp[i]] += 1;
    }
    // 각 기간 횟수를 answer에 저장
    for (auto it = m.begin(); it!=m.end();it++) {
        answer.push_back(it->second);
    }
    return answer;
}