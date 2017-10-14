/* De bai: Mot ke trom dot nhap vao nha va lay di
 * mot vai do vat. Nhung cai tui chi chua duoc mot
 * khoi luong nhat dinh. Tim cach lay do sao cho
 * gia tri lay duoc la nhieu nhat.
 *
 * Moi cach chon ra cac do vat la 1 to hop
 * cua n phan tu. Ta co the bieu dien moi
 * phuong an X = 1 xau nhi phan, voi moi do vat
 * duoc chon se danh so 1, khong duoc chon danh so 0.
 */


#include <iostream>

using namespace std;

int x[100], a[100], c[100], Xopt[100];
int B, n, Fopt;

//Bai toan cai tui
bool cuoi()
{
    for (int i = 1; i<=n; ++i)
        if (x[i] == 0) return false;

    return true;
}

void sinh()
{
    int i;
    for (i = n; x[i] != 0; --i)
        x[i] = 0;
    x[i] = 1;
}

void in()
{
    for (int i = 1; i<=n ; ++i)
        if (Xopt[i]) cout << i << ' ';

    cout << endl << Fopt << endl;

}

void kt()
{
    for (int i = 1; i<=n ; ++i)
        x[i] = 0;
}

int khoiluong()
{
    int kl = 0;
    for (int i = 1; i<=n; ++i)
        kl += a[i]*x[i];

    return kl;
}

int giatri()
{
    int gt = 0;
    for (int i = 1; i<=n; ++i)
        gt+= c[i]*x[i];
    return gt;
}

void update()
{
    for (int i = 1; i<=n; ++i)
        Xopt[i] = x[i];
    Fopt = giatri();
}

void nhap()
{
    cout << "Nhap vao so luong do vat n = ";
    cin >> n;
    cout << "Nhap vao gia tri cua tung do vat theo thu tu: ";
    for (int i = 1; i<=n; ++i)
        cin >> c[i];
    cout << "Nhap vao khoi luong cua tung do vat theo thu tu: ";
    for (int i = 1; i<=n; ++i)
        cin >> a[i];
    cout << "Nhap vao khoi luong toi da B = ";
    cin >> B;
}

int main()
{
    nhap();
    kt();
    while(!cuoi())
    {
        if (khoiluong() <= B) // Kiem tra tong khoi luong khong vuot qua B
            if (Fopt < giatri()) // Neu co phuong an tot hon thi update
                update();
        sinh();
    }

    if (khoiluong() <= B)
        if (Fopt < giatri()) 
            update();

    in();
    return 0;
}
