#include <iostream>
#include <stdio.h>
#include <string.h>
 
using namespace std;
 
int N;
int map[49][49];
int answer;
 
int main() {
 
    int test_case;
    int T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; test_case++) {
 
        //초기화
        N = 0;
        memset(map, 0, sizeof(map));
        answer = 0;
 
        //입력
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%1d", &map[i][j]);
            }
        }
 
        //해법
        /*
        위 삼각형, 아래 삼각형 나누어서 계산(마름모 별찍기 응용 문제)
        */
        for (int i = 0; i < N / 2; i++) {
            for (int j = N / 2 - i; j <= N / 2 + i; j++) {
                answer += map[i][j];
            }
        }
        for (int i = 0; i <= N / 2; i++) {
            for (int j = i; j < N - i; j++) {
                answer += map[i + N / 2][j];
            }
        }
 
        //결과 출력
        cout << "#" << test_case << " " << answer << "\n";
    }
    
    //종료
    return 0;
}
