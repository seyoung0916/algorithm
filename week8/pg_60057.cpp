#include <bits/stdc++.h>

using namespace std;

// 프로그래머스
// https://programmers.co.kr/learn/courses/30/lessons/60057

int split(int n, string s) {

	string result = ""; // 압축된 문자열을 담음
	vector<pair<int, string>> tmp; // 횟수와 문자열을 담아줌
	int vIdx = 0; // 이번에 넣어야 할 tmp 인덱스

	// i가 인덱스를 나타내고 인덱스는 n씩 증가(자르는 문자열 크기)
	for (int i = 0; i < s.length(); i += n) {
		string cur = s.substr(i, n); // i번째 인덱스부터 n만큼

		// tmp비어 있으면 무조건 추가
		if (tmp.empty()) {
			tmp.push_back( { 1, cur });
			vIdx++;
		} else { // 안 비어 있으면 이전 인덱스와 비교
			// 다르면 추가
			if (tmp[vIdx - 1].second != cur) {
				tmp.push_back( { 1, cur });
				vIdx++;
			} else { // 같으면 이전의 횟수값 + 1
				tmp[vIdx - 1].first += 1;
			}
		}
	}

	for (auto it = tmp.begin(); it != tmp.end(); it++) {

		if (it->first == 1) { // 횟수가 1인건 생략
			result = result + it->second;
		} else {
			result = result + to_string(it->first) + it->second;
		}
		//cout << it->first << " + " << it->second << endl;
	}

	return result.length();
}

int solution(string s) {
	int answer = 987654321;

	// 자르는 기준 1~s길이
	for (int i = 1; i <= s.length(); i++) {
		int len = i;

		int res = split(len, s);
		//cout << "Res " << res << endl;

		// 길이가 작은 것은 answer로
		answer = min(answer, split(len, s));
	}
	return answer;
}

int main() {

	string s;
	cin >> s;
	cout << solution(s);
	return 0;
}
