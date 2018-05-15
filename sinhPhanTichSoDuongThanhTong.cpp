#include <iostream>
using namespace std;

int x[100] = {0};
int n = 7;
void init()
{
    for (int i = 1; i<=n;++i)
       x[i] = 1;
}

bool isFinal()
{
    if (x[1] == n) return true;
    else return false;
}

void print()
{
    int i;
    for (i= 2; x[i] != 0 && i <= n;++i)
        cout << x[i-1] << " + ";
        
        cout << x[i-1] << endl;
}

void genNext()
{
    int i;
    // tim vi tri xi thu 2 khac 0 tu ben phai
    for (i =n; x[i] == 0;--i);
    x[i] = 0;
    // tim vi tri dau tien xt nho hon x(t-1)
    // ke tu vi tri cua xi
    
    --i;
    while (x[i] == x[i-1] && i>1)  
    {
        x[i] = 0;
        --i;
    }
    // tang vi tri xt len 1 don vi va
    // gan cac vi tri tu xt ve ben phai = 1 
    // sao cho tong cac so 1 do bang
    // n - (tong cac vi tri tu x1 -> xt)
    ++x[i];
    int sum = 0;
    for (int j = 1; j<=i;++j) sum += x[j];
    
    for (int j = i+1; sum < n; sum++,j++)
        x[j] = 1;
}

int main()
{
    init();
    cout << n << " = \n";
    while(!isFinal())
    {
        print();
        genNext();
    }
    print();
    
    return 0;
}