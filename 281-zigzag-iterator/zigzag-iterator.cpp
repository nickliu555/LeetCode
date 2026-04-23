class ZigzagIterator {
public:
    bool turn;
    queue<int> q1, q2;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        turn = true;
        for (int v: v1) q1.push(v);
        for (int v: v2) q2.push(v);
    }

    int next() {
        int ans;
        if (turn && !q1.empty()) {
            ans = q1.front();
            q1.pop();
            if (!q2.empty()) turn = false;
        } else {
            ans = q2.front();
            q2.pop();
            if (!q1.empty()) turn = true;
        }
        return ans;
    }

    bool hasNext() {
        return !q1.empty() || !q2.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */