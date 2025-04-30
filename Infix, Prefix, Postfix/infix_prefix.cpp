#include<iostream>
#include<stack>

using namespace std;

string reverse(string s) {
    int j = 0, k = s.length() - 1;
    while (j < k) {
        swap(s[j], s[k]);
        j++;
        k--;
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    return s;
}

int priority(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPrefix(string s){
    s = reverse(s);

    int i = 0;
    stack<char> st;
    string ans = "";

    while (i < s.length()) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans = ans + s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans = ans + st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() &&
                   ((s[i] == '^' && priority(s[i]) <= priority(st.top())) ||  // Fix for right-associative ^
                    (s[i] != '^' && priority(s[i]) < priority(st.top())))) { // Left-associative operators
                ans = ans + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }

    ans = reverse(ans);

    return ans;
}

int main() {
    string s = "F+D-C*(B+A)";

    string ans = infixToPrefix(s);

    cout << ans << endl;

    return 0;
}
