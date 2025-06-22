class MovingAverage {
public:
    queue <int> q;
    double curr_sum = 0;
    int window = 0;

    MovingAverage(int size) {
        window = size;
    }
    
    double next(int val) {
        while(!q.empty() and q.size()+1 > window){
            curr_sum -= q.front();
            q.pop();
        }

        curr_sum += val;
        q.push(val);

        return curr_sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */