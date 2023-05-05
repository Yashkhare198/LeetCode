class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
         int cnt = 0;
         int maxi = INT_MIN;
        for(int i = 0; i<k ;i++){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' || s[i]=='u'){
                    cnt++;
            }
        }
        maxi = max(maxi,cnt);

        for(int i = k; i < n ; i++){
            char reduce = s[i-k];
            if(reduce  == 'a' ||reduce  == 'e' || reduce  == 'i' || reduce  == 'o'  || reduce  == 'u'){
                cnt--;
            }
            char add = s[i];
            if(add  == 'a' ||add   == 'e' || add   == 'i' || add   == 'o'  || add   == 'u'){
                cnt++;;
            }
            maxi = max(maxi,cnt);
            if(maxi ==k){
                return maxi;
            }
        }
        return maxi;
    }
};
