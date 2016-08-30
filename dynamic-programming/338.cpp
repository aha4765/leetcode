class Solution {

public:

    vector<int> countBits(int num) {

        vector<int> table(num+1, -1);

        table[0] = 0;

        for (int i = 0; i <= num; ++i) {

            helper(i, table);

        }

        return table;

    }

    

    int helper(int num, vector<int>& table) {

        if (table[num] != -1) return table[num];

        if (num & 1 == 1) {

            table[num] = helper(num >> 1, table) + 1;

        }

        else {

            table[num] = helper(num >> 1, table);

        }

        return table[num];

    }

};
