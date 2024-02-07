#include <iostream>
#include <fstream>
#include <cstring>

#define MAX 2005

using namespace std;

struct Point
{
    int x; // diem dau cua doan
    int y; // diem cuoi cua doan
};

bool readFile(char inFileName[], Point a[], int &n)
{
    ifstream fi;
    fi.open(inFileName, ios::in);

    if (!fi.is_open())
        return false;

    fi >> n;
    for (int i = 0; i < n; i++)
        fi >> a[i].x >> a[i].y;

    return true;
}

void deQuy(Point a[], int n, int i, int &max, int dem);

int solve(Point a[], int n)
{
    int max = 0;
    int dem = 1;

    for (int i = 0; i < n; i++)
    {
        dem = 1;
        deQuy(a, n, i, max, dem);
    }
    return max;
}

void deQuy(Point a[], int n, int i, int &max, int dem)
{
    for (int j = 0; j < n; j++)
    {
        if (a[i].y == a[j].x)
        {
            dem++;
            // cout << a[i].x << ' ' << a[i].y << ' ' << a[j].x << ' ' << a[j].y << '-';
            deQuy(a, n, j, max, dem);
            dem--;
            // cout << tmp << '\n';
        }
    }
    // cout << '\n';
    if (dem > max)
    {
        max = dem;
    }
}

int main()
{
    char inFileName[] = "input.txt";
    Point a[MAX];
    int n;

    if (!readFile(inFileName, a, n))
    {
        cout << "Can't open the file\n";
        system("pause");
        return 0;
    }

    cout << solve(a, n) << '\n';

    system("pause");
    return 0;
}