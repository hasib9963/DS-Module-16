#include<bits/stdc++.h>
using namespace std;
class myQueue
{
public:
    void line(string pname)
    {
        q.push(pname);
    }

    void rmvp()
    {
        if (q.empty())
            cout << "Invalid" << endl;
        else
        {
            cout << q.front() << endl;
            q.pop();
        }
    }
    queue<string> q;
};

int main()
{
    int q;
    cin >> q;

    myQueue queue;

    while (q--)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            string name;
            cin >> name;
            queue.line(name);
        }
        else if (x == 1)
        {
            queue.rmvp();
        }
    }
    return 0;
}
