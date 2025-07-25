class Solution {
public:
    int reverse(int x) {
        int reverse = 0;

        while (x > 0 || x < 0) {
            int mod = x % 10;
            x = x / 10;

            // ✅ Add overflow check before updating reverse
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && mod > 7)) return 0;
            if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && mod < -8)) return 0;

            reverse = (reverse * 10) + mod;
        }

        return reverse;
    }
};


  