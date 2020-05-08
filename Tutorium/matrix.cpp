#include <iostream>

using namespace std;

class Helper
{
    int n;

public:
    Helper()
    {
        cout << "init Helper" << endl;
    }

    Helper(int n)
    {
        this->n;
    }

    ~Helper()
    {
        cout << "Destroy helper" << endl;
    }

    void set(int n)
    {
        this->n = n;
    }

    int get()
    {
        return n;
    }
};

class Matrix
{
    Helper **f;
    int m;
    int n;

    void init()
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                f[i][j].set(0);
            }
        }
    }

public:
    Matrix(int m, int n)
    {
        this->m = m;
        this->n = n;

        f = new Helper *[m];
        for (int i = 0; i < m; ++i)
        {
            f[i] = new Helper[n];
        }
        init();
    }

    ~Matrix()
    {
        for (int i = 0; i < m; ++i)
        {
            delete[] f[i];
        }
        cout << "Destroy matrix" << endl;
        delete[] f;
    }

    void print()
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << f[i][j].get() << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int a = 5;
    Matrix m(5, 5);
    m.print();
    return 0;
}