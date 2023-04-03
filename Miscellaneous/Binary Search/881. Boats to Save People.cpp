class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(),people.end());

        int n = people.size();

        int s=0;
        int e=n-1;
        int boats = 0;

        while(s<=e){
            if(people[s]+people[e] <= limit){
                s++;
                e--;
            }
            else if(people[s]+people[e]>limit){
                e--;
            }
            boats++;
        }
        return boats;
    }
};
