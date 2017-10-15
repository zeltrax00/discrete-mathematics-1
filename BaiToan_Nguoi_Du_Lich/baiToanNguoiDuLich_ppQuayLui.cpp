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
bool check[100];

void kt()
{
    for (int i = 1; i<=n; ++i)
        check[i] = true;
    x[1] = 1;
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
    for (int i= 1; i<=n; ++i)
        Xopt[i] = x[i];

    Fopt = chiphi();
}

void Try(int i)
{
    for (int j = 2; j<=n; ++j)
        if (check[j])
        {
            x[i] = j;
            check[j] = false;
            if (i == n)
            {
                if (Fopt > chiphi())
                    update();
            }
            else Try(i+1);

            check[j] = true;
        }
}

void in()
{
    for (int i = 1; i<= n; ++i)
        cout << Xopt[i] << ' ';
    cout << endl << Fopt << endl;
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

    for (int i = 1; i<n; ++i)
        Fopt += c[i][i+1];
    Fopt += c[n][1];

    Try(2);

    in();
    return 0;
}

