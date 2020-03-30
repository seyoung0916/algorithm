package hash;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* 예시
classic pop classic classic pop zazz zazz
500 600 150 800 2500 2100 1000*/
public class programmers_BestAlbum {
	// 요구사항 정리
	// 1. 가장 많이 재생된 장르를 찾는다
	// 2. 같은 장르의 노래중 재생 횟수가 높은 노래가 먼저 재생된다.
	// 3. 재생횟수가 같은 경우에는 인덱스가 낮은 노래가 먼저 재생된다.
	public int[] solution(String[] genres, int[] plays) {
		int[] answer = {};
		Map<String, Integer> topPlay = new HashMap<>();
		Map<String, Map<Integer, Integer>> firstSong = new HashMap<>();
		Map<Integer, Integer> countList = null;
		int genLength = genres.length;
		for (int i = 0; i < genLength; i++) {
			// 가장 많이 재생된 장르 찾기
			if (topPlay.get(genres[i]) == null) {
				topPlay.put(genres[i], plays[i]);
			} else {
				topPlay.put(genres[i], topPlay.get(genres[i]) + plays[i]);
			}
			if (firstSong.containsKey(genres[i])) {
				countList = firstSong.get(genres[i]);
			} else {
				countList = new HashMap<>();
			}
			countList.put(i, plays[i]);
			firstSong.put(genres[i], countList);
		}
		System.out.println(firstSong);
		// 리스트에 map의 키 값 담기, 장르 이름이 담김
		List<String> topPlayKey = new ArrayList<>(topPlay.keySet());
		Collections.sort(topPlayKey, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				// 내림차순, value 값으로 정렬
				return topPlay.get(o2).compareTo(topPlay.get(o1));
				// 오름차순
				// return topPlay.get(o1).compareTo(topPlay.get(o2));
			}
		});
		System.out.println("sort 후 ====");
		for (String key : topPlayKey) {
			System.out.println(key);
		}
		System.out.println("====");
		// System.out.println("firstSong : " + firstSong);
		// 키값 안의 재생 횟수를 내림차순으로 정렬
		List<Integer> temp = new ArrayList<>();
		for (String key : topPlayKey) {
			List<Map.Entry<Integer, Integer>> list = new ArrayList<>(firstSong.get(key).entrySet());
			System.out.println(list);
			Collections.sort(list, new Comparator<Map.Entry<Integer, Integer>>() {
				@Override
				public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
					return o2.getValue().compareTo(o1.getValue());
					/*
					 * if (o1.getValue() == o2.getValue()) { return
					 * o1.getKey().compareTo(o2.getKey()); } else { return
					 * o2.getValue().compareTo(o1.getValue()); }
					 */
				}
			});
			/*
			 * Map<Integer, Integer> map = new HashMap<>(); map.entrySet().toArray();
			 */
			int index = 0;
			for (Map.Entry<Integer, Integer> entrys : list) {
				if (index < 2) {
					int entrysKey = entrys.getKey();
					temp.add(entrysKey);
					index++;
				}
			}
		}
		System.out.println(temp);
		answer = new int[temp.size()];
		for (int i = 0; i < temp.size(); i++) {
			answer[i] = temp.get(i);
		}
		return answer;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] genres = br.readLine().split(" ");
		String[] playstmp = br.readLine().split(" ");
		int[] plays = new int[playstmp.length];
		int i = 0;
		for (String var : playstmp) {
			plays[i] = Integer.parseInt(var);
			i++;
		}
		programmers_BestAlbum ba = new programmers_BestAlbum();
		int[] answer = ba.solution(genres, plays);
		for (int ans : answer) {
			System.out.println(ans);
		}
	}
}