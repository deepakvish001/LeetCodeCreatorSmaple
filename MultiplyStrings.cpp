43. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
  
  
Solution

Intuition:

Big integer multiplication can actually be converted into big integer addition. Refer to the vertical calculation method of 
multiplication, multiply num2 with each bit of num1, and then add these values ​​bit by bit. Finally, handle the carry, 
and then flip the answer.

Algorithm: Simulation

1. Open a size n + m ( n for num1 length, m for num2 Length), because the product length of any two integers will not exceed 
their own length.
2. Pass two for Loop to Multiply, use each bit num1[ i ] Go by num2 get res[ i + j + 1 ] + = (num1[ i ] − ′ 0 ′) ∗ (num2 [ j ] − ′ 0 ′). 
Here we do not rush to deal with carry.
3. After the calculation is over, we start to process the carry, for each pair 10, Take modulo and carry.
4. Then convert the result to a string.

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n = num1.length() + num2.length(); 
        vector<int> res(n,0);
        // Simulate multiplication vertical calculation
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        // handle carry
        for (int i = n - 1; i > 0; i--) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
        // Convert the array to a string
        string ans;
        for (int i = 0; i < n; i++) {
            if (res[i] == 0 && ans.empty()) { // handle leading zeros
                continue;
            } 
            ans += char(res[i] + '0');
        }
        return ans;
    }
};

Complexity Analysis

Time Complexity: O(n*m), n is the length of num1, m is the length of num2.
Space Complexity: O(n+m), n is the length of num1, m is the length of num2.
