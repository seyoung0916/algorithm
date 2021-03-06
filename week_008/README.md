# SWEA 2117 (홈 방법 서비스)
:pushpin: 유형  
* 완전 탐색, 시뮬레이션  

:question: 문제  
* 범위 K이내에 존재하는 집 개수 구하기  
	-> 완전 탐색(중심 좌표와 k를 이용)  
* 모든 지역을 탐색하고자 할 때 K의 범위  
	-> 1부터 N+1까지 탐색  

:heavy_check_mark: 해결  
* getHouseCnt(int r, int c, int k)  
	-> 중심 좌표 r, c 이고 방범 범위 k  
	-> 중심으로부터 거리가 k-1 이내이고 집이 있을 때 카운트!
* getHouseCnt의 반환값을 이용해 이익을 구하기  
	-> 0 이상인 경우에 최대 집 개수 구하기

:heavy_plus_sign: 추가
* 마름모 범위를 중심으로부터의 거리를 이용해 푸는 것을 새로 알게 됨    

---  

# SWEA 2105 (디저트 카페)
:pushpin: 유형  
* DFS  

:question: 문제  
* 디저트 카페들 사이에서 대각선으로 움직임  
	-> 사각형을 그리며 시작점으로 돌아와야 함  
* 같은 숫자를 파는 카페는 갈 수 없음    
* 왔던 길 돌아가기 X, 한 디저트 카페만 X  

:heavy_check_mark: 해결  
* 가능한 모든 좌표에서 탐색, 시작 방향은 무조건 오른쪽 아래로  
	-> 시작 가능한 위치 : i = 0~N-2, j = 1~N-2  
	-> 시작점을 전역 변수로 저장  
* dfs(int i, int j, int d, int cnt)  
	-> 들어온 위치 i, j 방문 처리, 디저트 값 방문 처리  
	-> 시작점으로 돌아오면 return  
	-> 현재 위치에서 기존 방향 유지 or 90도 시계 방향 회전  
	-> 다음 위치가 범위 내 && nx <= 시작점 행 값(Sx) : 모든 행 값은 처음 행 값보다 항상 작음  
		1) 방문 처리 안 된 경우 : 방문 처리 + dfs  
		2) 시작점인 경우 : dfs

---  

# SWEA 1953 (탈주범 검거)
:pushpin: 유형  
* BFS  

:question: 문제  
* 터널끼리 연결된 경우 이동 가능    
* 탈주범이 있을 수 있는 위치 개수 계산    
* 시간당 1씩 움직임
* 1시간 후 맨홀 위치에 있음  

:heavy_check_mark: 해결  
* bfs()  
	-> 현재 위치 R, C 방문 처리, q에 push  
	-> while 문을 통해 정해진 시간까지 반복  
	-> 시간이 되면 방문된 개수 세기 (result)
	-> 큐 크기만큼 반복 (이전 큐 크기 변수에 저장)  
	-> 현재 파이프에서 갈 수 없는 방향은 제외 (dx, dy)  
	-> 걸러진 방향에 대해서 다음 좌표를 구함  
	-> 범위, 방문, 파이프 존재 여부를 확인하고  
	-> 각 방향에 따라 올 수 있는 파이프를 제한

:heavy_plus_sign: 추가
* 처음 생각한 방법  
  * 각 위치의 파이프 번호를 구하고, 파이프 방향에 따라 올 수 있는 다음 파이프 번호를 체크  
    -> 코드가 길어지고 헷갈림  
* 새로 바꾼 방법  
  * 각 위치의 파이프 번호에 대해 모든 방향을 체크  
    -> 파이프 번호일 때 && (안되는 방향 || 방향2) 이런 식으로 다음으로 갈 수 있는 방향 체크  
	-> 다음 좌표에 있는 파이프 번호가 올 수 있는 위치인지 체크 (방향에 따라 올 수 있는 파이프가 다름)  

---  