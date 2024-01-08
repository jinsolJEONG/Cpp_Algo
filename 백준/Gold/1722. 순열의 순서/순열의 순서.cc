#include <iostream>
#include <vector>

using namespace std;

static int N, Q;
static long F[21], S[21];
static bool visited[21] = {false};

int main(){
    // reset

    //input
    cin >> N >> Q;
    F[0] = 1;
    for(int i = 1; i <= N; i++){
        F[i] = F[i-1] *i;
    }

    //solve, output
    if(Q==1){
        long K;
        cin >> K;

        for(int i = 1; i <= N; i++){
            for(int j = 1, cnt = 1; j <= N; j++){
                if(visited[j])continue;
                if(K <= cnt * F[N - i]){
                    K -= ((cnt - 1) * F[N - i]);
                    S[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt ++;
            }
        }
        for(int i = 1; i <= N; i++){
            cout << S[i] << " ";
        }
    }
    else{
        long K = 1;
        for(int i = 1; i <= N; i++){
            cin >> S[i];
            long cnt = 0;

            for(int j = 1; j < S[i]; j++){
                if(visited[j] == false){
                    cnt++;
                }
            }
            K += cnt * F[N - i];
            visited[S[i]] = true;
        }
        cout << K << endl;
    }
    return 0;
}