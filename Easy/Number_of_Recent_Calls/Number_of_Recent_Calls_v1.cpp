class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {}

    int ping(int t) {
        while (!q.empty() and (q.front() + 3000 < t)) {
            q.pop();
        }
        q.push(t);

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */