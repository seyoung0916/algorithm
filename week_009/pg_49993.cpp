#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<int> v(skill.length(), -1); // skill 길이만큼을 -1로 채움
    for (int i=0; i < skill_trees.size(); i++) {
        string cur = skill_trees[i];
        int idx = 0;
        
        // skill이 CBD이고 cur이 BACDE면
        // v에는 2, 0, 3이 저장됨
        // cur에 나오는 skill의 인덱스 저장
       for (int j = 0; j < skill.length(); j++) {
           char ch = skill[j];
           v[j] = cur.find(ch);
       }

        bool flag = true; // 인덱스가 오름차순이어야 정상, 정상이라고 가정
        for (int j = 1; j < v.size(); j++) {
            if (v[j] != -1) { // 현재 원소가 -1이 아닐 때, 즉 존재할 때
                if (v[j-1] > v[j]) flag = false; // 인덱스가 오름차순 X
                if (v[j-1] == -1) flag = false; // 앞 스킬 안 배움
            }
        }
        
        if (flag == true) answer++;
        
        cout << answer<<endl;
    }
    return answer;
}