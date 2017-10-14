/* De bai: 1 du khach du kien di du lich qua cac
 * thanh pho T1, T2, ... Tn. Chi phi di tu thanh pho
 * Ti den thanh pho Tj la c[i][j]. Tim lo trinh
 * cho du khach sao de di tat ca n thanh pho voi
 * chi phi thap nhat.
 *
 *
 * Moi phuong an X la hoan vi cua n phan tu,
 * voi phan tu dau tien x1 = 1 (boi vi nguoi khach
 * di vong tron, nen cac diem xuat phat la nhu nhau)
 * Ta can tim duong di sao cho chi phi di lai la
 * nho nhat. Chi phi = (tong cua c[xi][x[i+1]],
 * voi i bat dau tu 1 den n - 1) + c[xn][x1]
 */

#include <iostream>
using namespace std;

int n, Fopt;
int x[100], Xopt[100], c[20][20];

//Bai toan nguoi du lich

bool cuoi()
{
    for (int i = 1; i < n; ++i)
        if (x[i] < x[i+1]) return false;

    return true;
}

void sinh()
{
    int i;
    for (i = n; x[i] >= x[i+1] ; --i);

    for (int j = n; j > i; --j)
        if (x[j] > x[i])
        {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
            break;
        }
 
    for (int a = i+1, b = n; a < b; ++a, --b)
    {
        int t = x[a];
        x[a] = x[b];
        x[b] = t;
    }
}

void in()
{
    for (int i = 1; i <=n; ++i)
        cout << Xopt[i] << ' ';
    cout << endl << Fopt << endl;
}

int chiphi()
{
    int cp = 0;
    for (int i = 1; i<n; ++i)
        cp += c[x[i]][x[i+1]];
        
    cp += c[x[n]][x[1]];
    
    return cp;
}

void update()
{
    for (int i = 1; i<=n; ++i)
        Xopt[i] = x[i];

    Fopt = chiphi();
}

void kt()
{
    for (int i = 1; i<=n; ++i)
        x[i] = i;

    Fopt = chiphi(); //Khoi tao gia tri ban dau cho Fopt
}

void nhap()
{
    cout << "Nhap so thanh pho n = ";
    cin >> n;
    cout << "Nhap ma tran chi phi c[i][j]: \n";
    for (int i = 1; i<=n; ++i)
        for (int j = 1; j <=n; ++j)
            cin >> c[i][j];
}
int main()
{
    nhap();
    kt();
    while(!cuoi())
    {
        if (chiphi() < Fopt) //Neu co phuong an tot hon thi update
            update();
        sinh();
    }
    in();

    return 0;
}
