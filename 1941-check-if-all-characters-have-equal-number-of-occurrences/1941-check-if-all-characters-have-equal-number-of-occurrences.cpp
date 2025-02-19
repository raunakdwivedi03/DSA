class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n=s.size();
        unordered_map<char,int>map;

        for(int i=0;i<n;i++){
            map[s[i]]++;
        }
        int firstFrequency = map[s[0]]; // yha pe pehle vale character ke frequency decide karenge fir uske 
                                        // according hi baake value hoge;
        for(auto it:map){
            if(it.second != firstFrequency){
                return false;
            }
          
        }
        return true;
    }
    };




















       
    //    //es question me agar A ka count jitna hoga utna hi baake character ka hona chahie toh return kar do true nhi toh return kar do false.
    //         int A_ki_frequency=0;
    //     for(int i=0;i<n;i++){
    //         if(s[i]==s[0]){
    //             A_ki_frequency++;
    //         }
    //     }

    //     // ab baake charcter ko bhi compare kro aur unka count nikalna hai
    //     for(int i=0;i<n;i++){
    //         int count=0;
    //         for(int j=0;j<n;j++){
    //             //yha pe agar tmare s[i]==s[j] hota hai toh uske count ko increase kar dena 

    //             if(s[i]==s[j]){
    //                 count ++;
    //             }
    //         }
    //         if(count!=A_ki_frequency){
    //             return false;
    //         }
    //     }
    //     return true;
    // }







