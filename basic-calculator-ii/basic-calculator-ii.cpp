// class Solution {
// public:
//     int calculate(string s)
//     {
//         if(s.length() == 0)
//         {
//             return 0;
//         }
        
//         int currentNum = 0;
//         char currentOp ='+';
//         stack<int> st;
//         int answer = 0;
        
//         for(int i = 0; i<s.length(); ++i)
//         {
//             char cur = s[i];
//             if(isdigit(cur))
//             {
//                 currentNum = (currentNum*10) + ( cur -'0');
//             }
//             if(!isdigit(cur) && !iswspace(cur) || i == s.length()-1)
//             {
//                 if(cur == '+')
//                 {
//                     st.push(currentNum);
//                 }
//                 else if(cur == '-')
//                 {
//                     st.push(-currentNum);
//                 }
//                 else if(cur == '*')
//                 {
//                     int temp = st.top();
//                     st.pop();
//                     st.push(temp*currentNum);
//                 }
//                 else if(cur == '/')
//                 {
//                     int temp = st.top();
//                     st.pop();
//                     st.push(temp/currentNum);
//                 }
//                 currentOp = cur;
//                 currentNum = 0;
//             }
//         }
//         while(!st.empty())
//         {
//             answer += st.top();
//             st.pop();
//         }
//         return answer;
        
//     }
// };

class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
};