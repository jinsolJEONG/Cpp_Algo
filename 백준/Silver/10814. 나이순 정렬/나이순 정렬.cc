#include <bits/stdc++.h>
using namespace std;

int n;
multimap<int, string> age_name;

int main() {
    //r
    
    //i
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int age;
        string name;
        cin >> age >> name;
        age_name.emplace(age, name);
    }

    for (auto i : age_name) {
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}
