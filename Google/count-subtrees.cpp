int dfs(vector<vector<int>> &al, int mask, int i, int &n, int &res) {
    int dia = 0, max_dia = 0;
    ++n;
    for (auto j : al[i])
        if (mask & (1 << j)) {
            int dia = 1 + dfs(al, mask ^ (1 << j), j, n, res);
            res = max(res, dia + max_dia);
            max_dia = max(max_dia, dia);
        }
    return max_dia;
}
vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    vector<vector<int>> al(n);
    for (auto &e : edges) {
        al[e[0] - 1].push_back(e[1] - 1);
        al[e[1] - 1].push_back(e[0] - 1);
    }
    vector<int> res(n - 1);
    for (int s = 3; s < 1 << n; ++s) {
        for (int i = 0; i < n; ++i)
            if (s & (1 << i)) {
                int nodes = 0, dia = 0;
                dfs(al, s ^ (1 << i), i, nodes, dia);
                if (dia > 0 && nodes == bitset<16>(s).count())
                    ++res[dia - 1];
                break;
            }
    }
    return res;
}