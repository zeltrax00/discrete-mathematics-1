/* De bai: Một hệ gồm có N quá
 * trình thực hiện N việc song hành. Biết mỗi quá trình đều
 * có thể thực hiện được N việc kể trên nhưng với chi phí
 * thời gian khác nhau. Biết c[i][j] là thời gian quá trình i thực
 * hiện việc j Hãy tìm phương án giao việc cho mỗi quá
 * trình sao cho tổng thời gian thực hiện N việc kể trên là ít
 * nhất.
 *
 * Tuong tu nhu bai toan nguoi du lich, nhung ta khong co dinh x[1] nua
 * ma thu tat ca cac truong hop hoan vi. Coi moi cach sap xep cong viec
 * cho quy trinh 1 -> N la 1 hoan vi.
 */


#include <iostream>
using namespace std;

int N, F, Fopt = 0; // F la thoi gian hien tai, Fopt la thoi gian toi uu
int c[20][20], x[20], Xopt[20]; // x[] la hoan vi cua cac cong viec
bool check[20]; // Mang danh dau de sinh hoan vi

void nhap()
{
    cout << "Nhap vao so quy trinh N = ";
    cin >> N;
    cout << "Nhap ma tran thoi gian c:\n";
    for (int i = 1; i<=N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> c[i][j];
}
void kt()
{
    for (int i = 1; i<=N; ++i)
        check[i] = true;

    for (int i = 1, j = 1; i<=N; ++i, ++j) // Khoi tao cho Fopt co gia tri lon nhat co the
        Fopt += c[i][j] + 1;
}
void update()
{
    for (int i = 1; i<=N; ++i)
        Xopt[i] = x[i];
    Fopt = F;
}

void thoigian()
{
    F = 0;
    for (int i = 1; i<=N; ++i)
        F += c[i][x[i]];
}

void Try(int i)
{
    for (int j = 1; j <= N; ++j)
        if (check[j])
        {
            x[i] = j;
            check[j] = false;

            if (i == N)
            {
                thoigian();
                if (F < Fopt) //Neu thoi gian hien tai nho hon thoi gian toi uu, update lai
                    update();
            }
            else Try(i+1);

            check[j] = true;
        }
}

void in()
{
    for (int i = 1; i<= N; ++i)
        cout << "Quy trinh "<< i << " lam viec " << Xopt[i] << '\n';

    cout << "Tong thoi gian: " << Fopt << endl;
} 

int main()
{
    nhap();
    kt();

    Try(1);

    in();

    return 0;
}
