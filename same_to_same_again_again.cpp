#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    stack<int> s;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    list<int> list1;

    while (!s.empty() && !q.empty())
    {
        if (s.top() == q.front())
        {
            list1.push_back(s.top());
            s.pop();
            q.pop();
        }
        else if (s.top() > q.front())
        {
            q.pop();
        }
        else
        {
            s.pop();
        }
    }

    if (list1.size() == n && list1.size() == m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}