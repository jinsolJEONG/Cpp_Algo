#include <bits/stdc++.h>
using namespace std;

int n;

int round_double(double num) {
    return round(num);
}

int main() {
    //r
    double avg = 0;
    double sum = 0;
    //i
    cin >> n;
    vector<int> scores(n);
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }else{
        for (int i = 0; i < n; ++i) {
            cin >> scores[i];
        }
    }
    //s
    sort(scores.begin(), scores.end());
    int jersa = round_double(n * 0.15);
    
    vector<int> filter(scores.begin() + jersa, scores.end() - jersa);

    for (int score : filter) sum += score;
    avg = sum / filter.size();
    //o
    cout << round_double(avg);
    
    return 0;
}
