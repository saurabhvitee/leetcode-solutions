class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        for(const auto& stone: stones){
            int largest=-1, second_largest=-1;
            if(!maxHeap.empty()){
                largest = maxHeap.top();
                maxHeap.pop();
            }

            if(largest == -1){
                return 0;
            }

            if(!maxHeap.empty()){
                second_largest = maxHeap.top();
                maxHeap.pop();
            }

            if(second_largest == -1){
                return largest;
            }

            if(largest != second_largest){
                largest = largest - second_largest;
                maxHeap.push(largest);
            }
        }
        return 0;
    }
};