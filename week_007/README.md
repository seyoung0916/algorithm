# 백준 16637 (괄호 추가하기)
:pushpin: 유형  
* DFS  

:question: 문제  
* 괄호를 어떻게 추가할지  
	-> 완전 탐색(추가 후 계산, 다음에 추가 후 계산)  
* 괄호를 씌운 후 계산하는 방법  

:heavy_check_mark: 해결  
* 재귀(N/2번이 최대 >> 연산자 개수)  
* 괄호를 적용해서 재귀를 호출, 다음 연산자에 적용해서 호출    

:heavy_plus_sign: 추가
* 연산자 개수 & 인덱스를 헷갈려 시간을 잡아먹음  
  => 변수가 어떤 용도인지 잘 기억하기  

---  
# 백준 17070 (파이프 옮기기 1)
:pushpin: 유형  
* DFS  

:question: 문제  
* 파이프가 움직이는 세 가지 방법  
	-> 가로, 세로, 대각선(이전에 놓인 위치에 따라 다름)  
* 모든 방법 수를 계산  

:heavy_check_mark: 해결  
* dfs(int x, int y, int op)
	-> op는 이전 파이프의 진행 방향  
	-> N-1, N-1에 도착하면 종료  

:heavy_plus_sign: 추가
* 연산자 개수 & 인덱스를 헷갈려 시간을 잡아먹음  
  => 변수가 어떤 용도인지 잘 기억하기  

---  

# 백준 17135 (캐슬 디펜스)
:pushpin: 유형  
* 조합, 시뮬레이션  

:question: 문제  
* 궁수의 위치 선정   
* 궁수의 사정 거리에 따른 적 제거  
	-> 모든 적 정보 저장  
	-> 궁수에 대해 가장 가까운 적을 찾고 arr에서 0으로 바꿈  
		= 적 정보에서 바로 삭제는 x, 궁수가 같은 적을 없앨 수 있기 때문  
	-> 모든 적 다시 찾음  

:heavy_check_mark: 해결  
* next_permutation을 이용해 궁수 위치를 임의 선택  
	-> 굉장히 유용한 것 같음  
* solve()
	-> 궁수 위치마다 가장 가까운 적을 target에 저장  
	-> target의 중복값 제거(unique() 사용)  
	-> 적 정보에서 target 인덱스를 제거  
		(이 때 shoot 변수를 사용하는 이유 : 벡터를 지우고 한 칸 씩 뒤로 밈)  
	-> 적 정보 중 다음 칸으로이동했을 때 범위 이내인 것을 copyTemp에 넣고 enemy 벡터 갱신  

:heavy_plus_sign: 추가
* 기존의 방법(문제 부분에 쓴 것)이 TC는 다 맞는데 안됨  
	=> 궁수 위치를 따로 N행에 배치했기 때문에 MAX 값을 1 증가한 값으로 해줘서 해결!!!  

---  

# 백준 17136 (색종이 붙이기)
:pushpin: 유형  
* 백트래킹   

:question: 문제  
* 10*10 배열의 1에 색종이를 덮을 수 있는 최소 개수 (각 색종이는 5개씩)   
* 배열에서 1이면 그 자리에 크기가 5인 것부터 붙일 수 있는지 체크  

:heavy_check_mark: 해결  
* dfs(int x, int y, int attachCnt)  
	-> x, y, 현재 붙인 종이 개수  
	-> 열의 끝에 다다르면 행+1, 행의 끝에 다다르면 종이 수 체크  
	
:heavy_plus_sign: 추가
* 런타임 에러  
	=> 색종이를 붙였을 때 범위 체크  
	=> 색종이 개수 체크로 해결  

---  

# 백준 17281 (⚾)
:pushpin: 유형  
* 시뮬레이션   

:question: 문제  
* N이닝 동안 게임 진행   
* 경기 전 타순을 정함 (경기 중에는 변경 불가)  
* 경기 중  
	-> 안타, 2루타, 3루타, 홈런, 아웃 중 하나
	-> 3아웃 시 이닝 끝
	-> 타순은 이닝이 변경되도 유지
	-> 홈 도착 시 +1점  
* 타순 정하기  
	-> 4번 타자는 1번 선수로 고정  
* 야구 게임 플레이  

:heavy_check_mark: 해결  
* dfs(int cnt)  
	-> cnt는 플레이어 번호  
	-> select를 이용해 cnt(플레이어)를 할당되지 않은 순서에 할당  
	-> dfs(cnt+1)   
	-> dfs 호출 끝나면 select 변경한 값은 다시 false로 변경  
	-> cnt==PLAYER이면 게임 진행  
* play()  
	-> score, start(시작할 플레이어 번호), base 정보 초기화  
	-> N이닝 동안 진행  
	-> start 부터 끝까지 (for문 끝나고 out 3회가 아니면 다시 1로 돌아감)  
	-> 플레이어 능력에 따라 홈 이동 및 점수 추가  
	-> out 3회이면 다음 플레이어로 순서 저장하고 종료  

---

# 백준 17471 (게리맨더링)
:pushpin: 유형  
* 조합, BFS   

:question: 문제  
* 지역 두 개로 나누기   
* 각 지역이 서로 연결되어 있는지 확인  
* 인구 차이 계산 (최소 차이 출력)  
* 지역을 나눌 수 없으면 -1 출력    

:heavy_check_mark: 해결  
* vector<int> qu[MAX]에 서로 연결되어 있는 지역을 입력받음  
* 1~N까지 차례로 구역 선택  
	-> permutation용 벡터를 만들어 조합 생성  
* check(vector<int> v)  
	-> v에는 지역 정보 저장  
	-> 첫 원소를 넣고 bfs  
	-> 지역끼리 연결되어 있는지를 체크해야 하므로 v.size()만큼 반복  
		현재 지역에서 v[i]로 이동할 수 있는지 체크 (find 이용)  
		visit[v[i]] 처리가 안 되어 있는지 체크
		만족해야 queue에 push  
	-> v에 담긴 지역들이 모두 visit 처리 되어 있으면 모두 연결된 것 (true 반환)  
	
---