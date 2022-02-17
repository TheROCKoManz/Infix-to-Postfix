#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

void Postfix(int vars[], char ops[], int n)
{
    stack<int> vstack;
    stack<char> ostack;

    for(int i=0; i<n; i++)
        vstack.push(vars[i]);

    for(int i=n-2; i>=0; i--)
        ostack.push(ops[i]);

    double res=vstack.top();
    char c;

    while(!vstack.empty() && !ostack.empty()) 
    {
        vstack.pop();
        c= ostack.top();
        switch(c)
        {
            case '+': res = vstack.top() + res; break;
            case '-': res = vstack.top() - res; break;
            case '*': res = vstack.top() * res; break;
            case '/': res = vstack.top() / res; break;
            case '^': res = pow(vstack.top(),res); break;
        }
        ostack.pop();
    }
    cout<<endl<<res<<endl;

}

int main()
{
    cout<<"\nEnter number of Operators: ";
    int n;
    cin>>n;
    cout<<endl;
    int vars[n];
    char ops[n-1];
    for(int i=0;i<n;i++)
        cin>>vars[i];
    for(int i=0;i<n-1;i++)
        cin>>ops[i];
    Postfix(vars,ops,n);
}
