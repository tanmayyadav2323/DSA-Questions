class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;

        while(n>1)
        {
            int temp = n/5;
            num += temp;
            n = temp;
        }

        return num;
    }
};