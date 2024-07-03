#include <bits/stdc++.h>
using namespace std;

// Function to mix two colors
char mixColors(char a, char b) {
    if ((a == 'R' && b == 'B') || (a == 'B' && b == 'R')) return 'P'; // Red + Blue = Purple
    if ((a == 'R' && b == 'G') || (a == 'G' && b == 'R')) return 'Y'; // Red + Green = Yellow
    if ((a == 'B' && b == 'G') || (a == 'G' && b == 'B')) return 'C'; // Blue + Green = Cyan
    return ' ';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string colors;
        cin >> colors;

        stack<char> st;

        for (char color : colors) {
            if (st.empty()) {
                st.push(color);
            } else {
                char top = st.top();
                if ((top == 'R' && color == 'R') ||
                    (top == 'G' && color == 'G') ||
                    (top == 'B' && color == 'B') ||
                    (top == 'P' && color == 'P') ||
                    (top == 'Y' && color == 'Y') ||
                    (top == 'C' && color == 'C')) {
                    st.pop(); // Same colors vanish each other
                } else {
                    char mixedColor = mixColors(top, color);
                    if (mixedColor != ' ') {
                        st.pop();
                        // Check the stack again after mixing
                        while (!st.empty() && mixedColor != ' ' && st.top() == mixedColor) {
                            st.pop();
                            mixedColor = ' ';
                        }
                        if (mixedColor != ' ') {
                            st.push(mixedColor);
                        }
                    } else {
                        st.push(color);
                    }
                }
            }
        }

        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        cout << result << endl;
    }

    return 0;
}
