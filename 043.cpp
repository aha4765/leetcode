class Solution {
public:
    string multiply(string num1, string num2) {
        string res("0");
        int size2 = num2.size();
        
        if ((num2 == "0") || (num1 == "0")) return res;
        
        int count = 0;
        for (int i = size2-1; i >= 0; --i) {
            string temp = multichar(num1, num2[i]);
            for (int j = 0; j < count; ++j) {
                temp += '0';
            }
            res = addstring(res, temp);
            count++;
        }
        return res;
    }
    
    string addstring(string& num1, string& num2) {
        string res;
        int size1 = num1.size();
        int size2 = num2.size();
        int c = 0;
        int i1 = size1 - 1, i2 = size2 - 1;
        int a1, a2;
        while ((i1 >= 0) || (i2 >= 0) || (c != 0)) {
            if (i1 >= 0) {
                a1 = num1[i1] - '0';
                --i1;
            }
            else {
                a1 = 0;
            }
            
            if (i2 >= 0) {
                a2 = num2[i2] - '0';
                --i2;
            }
            else {
                a2 = 0;
            }
            
            int tempsum = a1 + a2 + c;
            c = tempsum/10;
            res += (tempsum%10+'0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string multichar(string& num, char m) {
        string res; 
        int size = num.size();
        int i = size - 1;
        int c = 0;
        int a;
        int multi = m - '0';
        if (multi == 0) {
            return string("0");
        }
        if (multi == 1) {
            return num;
        }
        while ((i >= 0) || (c != 0)) {
            if (i >= 0) {
                a = num[i] - '0';
                --i;
            }
            else {
                a = 0;
            }
            
            int tempres = a * multi + c;
            c = tempres/10;
            res += (tempres%10+'0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
