class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int children = g.size();
        int cookies = s.size();

        int okChild = 0, cookie = 0;

        while (cookie < cookies && okChild < children) {
            if (s[cookie] >= g[okChild]) {
                okChild++;
            }

            cookie++;
        }

        return okChild;
    }
};