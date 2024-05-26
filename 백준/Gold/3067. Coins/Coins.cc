#include <iostream>
#include <vector>

void countWays(int n, const std::vector<int>& coins, int m) {
    std::vector<int> dp(m + 1, 0); // 금액 0부터 m까지의 결과를 저장하는 테이블
    dp[0] = 1; // 금액 0을 만드는 방법은 하나: 아무 동전도 사용하지 않는 것

    for (int coin : coins) {
        for (int i = coin; i <= m; ++i) {
            dp[i] += dp[i - coin]; // 현재 금액에서 해당 동전만큼 뺀 금액을 만드는 방법을 추가
        }
    }

    std::cout << dp[m] << std::endl; // 최종 결과 출력
}

int main() {
    int t; // 테스트 케이스의 수
    std::cin >> t;

    while (t--) {
        int n; // 동전의 종류 수
        std::cin >> n;

        std::vector<int> coins(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> coins[i];
        }

        int m; // 만들어야 할 금액
        std::cin >> m;

        countWays(n, coins, m);
    }

    return 0;
}
