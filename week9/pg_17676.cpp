#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<string> strtok(string str, char delim = ' ') {
    vector<string> ret;
    int prev = 0;
    
    for (int i=0; i< str.length();i++) {
        if (str[i] == delim) {
            ret.push_back(str.substr(prev, i-prev)); // i-prev 길이만큼 자름
            prev = i + 1;
        }
    }
    // 남은 문자열 넣어줌
    if (str.length() != prev) {
        ret.push_back(str.substr(prev, str.length() - prev));
    }
    return ret;
}

int solution(vector<string> lines) {
    int answer = 0;
    
    // 시작, 완료를 기록
    vector<pair<double, double>> v;
    
    for (int i=0; i < lines.size(); i++) {
        vector<string> tmp = strtok(lines[i]);
        
        vector<string> tstr = strtok(tmp[1], ':');
        double s = stod(tstr[0])*3600 + stod(tstr[1])*60 + stod(tstr[2]); // 초로 변환
        double t = stod(strtok(tmp[2], 's')[0]); // 처리시간의 s 빼고
        
        v.push_back(make_pair(s - t + 0.001, s));
    }
    
    for (int i=0; i< v.size(); i++) {
        double end = v[i].second; // 각 완료 시간
        int cnt = 1;
        // 종료~종료+1초 내를 확인
        for (int j=i+1; j<v.size();j++) {
            if (v[j].first < end + 1) cnt ++;
        }
        answer = max(answer, cnt);
    }
    return answer;
}