#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size()-1; i++) {
        // 현재 주식 값
        int cur = prices[i];
        int cnt = 0;
        for (int j = i+1; j < prices.size(); j++) {
            // 초 세기
            cnt++;
            if (cur > prices[j]) { // 감소하면 break
                break;
            }   
        }
        answer.push_back(cnt);
    }
    
    answer.push_back(0); // 끝은 무조건 0
    
    return answer;
}