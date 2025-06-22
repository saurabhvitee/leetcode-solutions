class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;

        // we need to check if stack top is smaller and equal than current price.
        // if it is smaller add this result into our current res 
        // pop those entries from top because we just put greater element in array
        
        while(!st.empty() and st.top().first <= price){
            res += st.top().second;
            st.pop();
        }

        st.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */