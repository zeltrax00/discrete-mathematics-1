/* De bai: Một ông chủ có một chiếc máy
 * cho thuê. Đầu tháng ông nhận được yêu cầu của M
 * khách hàng thuê máy cho N ngày kế tiếp. Mỗi khách
 * hàng cho biết tập Ni ngày họ cần thuê máy. Ông chủ có
 * quyền hoặc từ chối yêu cầu của khách hàng, hoặc nếu
 * chấp nhận yêu cầu của khách ông phải bố trí máy theo
 * đúng những ngày mà khách yêu cầu. Hãy tìm phương án
 * thuê máy giúp ông chủ sao cho tổng số ngày thuê máy là
 * nhiều nhất.
 *
 * Moi cach chon khach hang la 1 to hop cua M phan tu.
 * Co the bieu dien bang xau nhi phan. Cho thue = 1, khong cho = 0.
 * Tuong tu nhu bai toan cai tui.
 */

#include <iostream>
using namespace std;

// S la so truong hop cho khach thue may
int S[100], Xopt[100], A[20][20] = {0}; // Xopt la gia tri toi uu cua S
int M, N, Fopt  = 0; // Fopt la gia tri toi uu cua F
int songay, ngay, F; //F la tong so ngay cho thue

void kt()
{
    for (int i = 1; i<=M; ++i)
        S[i] = 0;
}

bool cuoi()
{
    for (int i = 1; i<=M; ++i)
        if (S[i] != 1) return false;

    return true;
}

void sinh()
{
    int i;
    for (i = M; S[i] == 1; --i)
        S[i] = 0;
    S[i] = 1;
}

void in()
{
    cout << "Cho khach ";
    for (int i = 1; i<=M; ++i)
        if (Xopt[i]) cout << i << ", ";
    cout << "thue\n";
    cout << "Tong so ngay thue: " << Fopt << " ngay\n";
}

bool check()
{
    // Kiem tra lich thue cua khach xem co bi
    // trung lap khong
    F = 0;
    int temp;
    for (int j = 1; j<=N; ++j)
    {
        temp = 0;
        for (int i  = 1; i<=M; ++i)
            temp += S[i]*A[i][j];   // Cong tong cac cot cua ma tran A
        if (temp > 1) return false; // Neu lon hon 1 tuc la bi trung lich
        else F+=temp;   // Neu khong trung lich thi + ngay do vao tong so ngay cho thue
    }
    return true;
}

void update()
{
    for (int i = 1; i<=M; ++i)
        Xopt[i] = S[i];
    Fopt = F;
}

void nhap()
{
    cout << "Nhap so khach thue may M = "; cin >> M;
    cout << "Nhap so ngay cho thue may N = "; cin >> N;
    for (int i = 1; i<=M; ++i)
    {
        cout << "Nhap so ngay khach " << i << " thue\n";
        cin >> songay;
        cout << "Nhap vao lich thue cua khach " << i << ": ";
        for (int j = 1; j <= songay; ++j)
        {
            cin >> ngay;
            A[i][ngay] = 1;
        }
    }
}

int main()
{
    nhap();
    kt();
    while (!cuoi())
    {
        //for (int i = 1; i<=M; ++i)
        //    cout << S[i] << ' '; cout << endl;
        if (check())
            if (F > Fopt) update();
        sinh();
    }
    if (check())
        if (F > Fopt) update();
    
    in();

    return 0;
}
