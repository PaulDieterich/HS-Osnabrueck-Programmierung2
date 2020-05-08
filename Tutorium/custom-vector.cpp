#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long size_t;
typedef unsigned int uint;

class CustomVector
{
    int length = 2;
    int next = 0;
    int *items = new int[length];

    int t[];

public:
    CustomVector()
    {
        items = new int[2];
    }

    int operator[](int index)
    {
        return items[index];
    }

    CustomVector operator+(CustomVector &v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            cout << v[i] << endl;
            hinzu(v[i]);
        }
        return *this;
    }

    void operator()(string suffix)
    {
        string out = "";
        for (int i = 0; i < next; ++i)
        {
            out += (to_string(items[i]) + "_" + suffix);
            if (i < next - 1)
            {
                out += " ";
            }
        }
        cout << out << endl;
    }

    string operator()(string suffix, string prefix)
    {
        string out = "";

        for (int i = 0; i < next; ++i)
        {
            out += (prefix + "_" + to_string(items[i]) + "_" + suffix);
            if (i < next - 1)
            {
                out += " ";
            }
        }
        return out;
    }

    CustomVector operator<<(string in)
    {
        cout << in << endl;
        for (char c : in)
        {
            if (!isspace(c))
            {
                hinzu(c);
            }
        }
        return *this;
    }

    void hinzu(int zahl)
    {
        if (next == length)
        {
            reallocate();
        }
        items[next++] = zahl;
    }

    int size()
    {
        return next;
    }

private:
    void reallocate()
    {
        const int newLength = length * 2;
        int *nextItems = new int[newLength];
        for (int i = 0; i < length; ++i)
        {
            nextItems[i] = items[i];
        }
        items = nextItems;
        length = newLength;
    }
};

void printVector(CustomVector v);

int main()
{
    CustomVector v;
    CustomVector w;
    for (int i = 0; i < 5; ++i)
    {
        v.hinzu(i);
        w.hinzu(i * 5);
    }
    CustomVector o = v + w;
    CustomVector *bla = new CustomVector();
    bla->hinzu(5);
    (*bla).hinzu(5);
    // for (int i = 0; i < o.size(); ++i)
    // {
    //     cout << o[i] << " ";
    // }
    // v("hello");
    // string out = v("hello", "world");
    // cout << "Ausgabe:\n"
    //      << out << endl;

    printVector(w);
    w << "hello";
    printVector(w);
    return 0;
}

void printVector(CustomVector v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
}