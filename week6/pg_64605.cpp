#include <bits/stdc++.h>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/64065

bool visit[100001];

bool mySort(vector<int> a, vector<int> b) {
	if (a.size() < b.size())
		return true;
	else
		return false;
}
vector<string> split(string str, char delimiter) {
	vector<string> res;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		res.push_back(temp);
	}

	return res;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> vec;

	vector<string> tmp = split(s, '}');

	for (int i = 0; i < tmp.size(); i++) {
		string str = tmp[i];
		string strTmp;
		vector<string> vc;
		for (int j = 0; j < str.size(); j++) {
			char ch = str[j];
			if (ch >= '0' && ch <= '9' || ch == ',') {
				strTmp += ch;
			}
		}

		vc = split(strTmp, ',');

		vector<int> final;
		for (int i = 0; i < vc.size(); i++) {
			if (vc[i] != "")
				final.push_back(stoi(vc[i]));
		}
		vec.push_back(final);
	}

	sort(vec.begin(), vec.end(), mySort);

	cout << "vec 출력 " << endl;
	for (int i = 0; i < vec.size(); i++) {
		for (auto it2 = vec[i].begin(); it2 != vec[i].end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < vec.size(); i++) {
		vector<int> tmp = vec[i];

		for (int j = 0; j < tmp.size(); j++) {
			if (!visit[tmp[j]]) {
				answer.push_back(tmp[j]);
				visit[tmp[j]] = true;
			}

		}
	}
	cout << endl;
	cout << "answer 출력 " << endl;
	for (auto it = answer.begin(); it != answer.end(); it++) {
		cout << *it << endl;
	}
	return answer;
}

int main() {
	string str = "{{20,111},{111}}";

	solution(str);
	return 0;
}
