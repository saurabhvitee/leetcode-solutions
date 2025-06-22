class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();
        cout << typeid(s[0]).name() << endl;

        unordered_set<char> seen;
        for(int i=0; i<n; i++){
            if(seen.contains(s[i])){
                return s[i];
            }
            seen.insert(s[i]);

        }
        return ' ';
    }
};