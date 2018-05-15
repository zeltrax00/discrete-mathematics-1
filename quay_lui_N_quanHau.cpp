#include <iostream>

using namespace std;

int x[100], n = 10;
bool a[100], cheo1[100], cheo2[100];

void kt()
{
    for (int i = 1; i<=n; ++i)
        a[i] = true;
        
     for (int i = 1; i<= 2*n-1; ++i)
         cheo1[i] = cheo2[i] = true;
         
}

void in()
{
    for (int i = 1; i<=n; ++i)
        cout << x[i] << ' ';
        
        cout << endl;
}

void LK(int i)
{
    for (int j = 1; j<=n; ++j)
        if (a[j] && cheo1[i-j +n] && cheo2[i+j -1])
        {
            x[i] = j;
            a[j]=cheo1[i-j +n] = cheo2[i+j -1] = false;
            if (i == n) in();
            else LK(i+1);
            
            a[j]=cheo1[i-j +n] = cheo2[i+j -1] = true;
        }
}
int main()
{
    kt();
    LK(1);
    
    return 0;
}
