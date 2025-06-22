class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // idea is we can only send 2 person max in one boat
        // try to pack light + heavy at every stage cause
        // if you send heavy person and possible pairing with lightest
        // you are solving your bigger problem first.

        // If you have to eat 2 frogs everyday eat the biggest one first in
        // morning.

        int i = 0;
        int j = people.size() - 1;
        int boatCount = 0;
        sort(people.begin(), people.end());
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
            boatCount++;
        }
        return boatCount;
    }
};