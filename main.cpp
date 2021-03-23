#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using Graph = vector<vector<int>>;

int N;
vector<long long> w;
Graph G;

vector<int> dp1, dp2;

void dfs(int v, int p = -1) {
    for (auto ch : G[v]) {
        if (ch == p) continue;
        dfs(ch, v);
    }

    dp1[v] = 0, dp2[v] = w[v];
    for (auto ch : G[v]) {
        if (ch == p) continue;
        dp1[v] += max(dp1[ch], dp2[ch]);
        dp2[v] += dp1[ch];
    }
}

int main() {
    cin >> N;


};