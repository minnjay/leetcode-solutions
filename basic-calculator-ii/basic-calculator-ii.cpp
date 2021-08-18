// class Solution {
// public:
//     int calculate(string s)
//     {
//         int len = s.length();
//         if(len == 0)
//         {
//             return 0;
//         }
//         stack<int> st;
//         int currentNum = 0;
//         char currentOp = '+';
//         int i = 0;
//         string pro = "";
//         for(int v = 0; v<len; ++v)
//         {
//             if(!iswspace(s[v]))
//             {
//                 pro += s[v];
//             }
//         }
        
        
//         while(i<pro.length())
//         {
//             char cur = pro[i];
//             if(isdigit(cur))
//             {
//                 currentNum = (currentNum * 10) + ( cur - '0');
//             }
            
//             if(!isdigit(cur) || i == len-1)
//             {
//                 if(cur == '-')
//                 {
//                     st.push( -currentNum );
//                 }
//                 else if(cur == '+')
//                 {
//                     st.push(currentNum);
//                 }
//                 else if(cur == '*')
//                 {
//                     int track = i+1;
//                     int anotherNum = 0;
//                     while(isdigit(pro[track]))
//                     {
//                         anotherNum = (anotherNum * 10) + ( pro[track] - '0');
//                         track ++;
//                     }
//                     st.push(currentNum*anotherNum);
//                     i = track;
//                 }
//                 else if(cur == '/')
//                 {
//                     int track = i+1;
//                     int anotherNum = 0;
//                     while(isdigit(pro[track]))
//                     {
//                         anotherNum = (anotherNum * 10) + ( pro[track] - '0');
//                         track ++;
//                     }
//                     st.push(currentNum/anotherNum);
//                     i = track;
//                 }
//                 currentOp = cur;
//                 currentNum = 0;
//             }
//             i++;
//         }

        
//         int answer = 0;
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
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};
