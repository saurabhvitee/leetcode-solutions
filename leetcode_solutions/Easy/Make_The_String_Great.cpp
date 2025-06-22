class Solution {
public:
    string makeGood(string s) {
        // string res = "";
        // int n = s.size();

        // for(int i=0;i<n;i++){
        //     if(!res.empty() && abs(res.back() - s[i]) == 32){
        //         res.pop_back();
        //     }else{
        //         res.push_back(s[i]);
        //     }
        // }

        // return res;


        // Version 2 - use same string provided in function
        // O(1) space
        int n = s.size();

        int end = 0; // this is the pointer that we will use to track good string 

        for(int curr=0; curr < n; curr++){
            if(end > 0 and abs(s[curr] - s[end-1]) == 32){
                // By doing below end-- we are skipping previous character 
                // since if it is the last char in good string it will not be 
                // considered in final result good string or else if this is in bw 
                // in next iteration we will put some other good character at this 
                // index
                end--;
            }else{
                s[end] = s[curr]; // simply put current char at end
                end++; // increase the pointer for good string
            }
        }

        return s.substr(0, end);
    }
};