#include <string>
#include <vector>
#include <memory.h>
#include <iostream>

#define MAX 100

using namespace std;

bool visit[MAX];
int arr[MAX][MAX];

bool check(int n) {
    for (int i = 0; i<n;i++ ) {
        if (visit[i] == false) return false;
    }
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> tmp;
	
    int min = costs[0][2]; // 처음 것이 최소라 가정
    int n1 = costs[0][0], n2 = costs[0][1];
	
    for (int i = 0; i < costs.size(); i++) {
        tmp = costs[i];
        arr[tmp[0]][tmp[1]] = tmp[2]; // 목적지, 비용
        arr[tmp[1]] [tmp[0]] = tmp[2];
        
        if (costs[i][2] < min) {
            min = costs[i][2];
            n1 = costs[i][0];
            n2 = costs[i][1];
        }
    }
    // 가장 작은 비용을 연결
    answer += min;
    visit[n1] = true;
    visit[n2] = true;
    min = -1; // 최솟값 리셋
    
    // 모두 방문할 때까지 실행
    while(!check(n)) {
        // cout << "here" <<endl;
		
		// 방문 처리된 지점에서 아직 방문 안된 곳 중 가장 짧은 곳을 찾음
        for (int i = 0; i < n; i++) {
            if (visit[i] == false) continue;
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != 0 && (min == -1 || min > arr[i][j]) && visit[j] == false) {
                    n1 = i;
                    n2 = j;
                    min = arr[i][j];
                }
            }
        } 
        cout << n1 << " " << n2 << " " << endl;
        visit[n1] = true;
        visit[n2] = true;
        answer += min;
        min = -1;
    }
     
    return answer;
}