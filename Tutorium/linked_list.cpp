#include <iostream>

using namespace std;

class ListSegment
{
    int value;
    ListSegment *next = nullptr;

public:
    ListSegment(int value)
    {
        this->value = value;
    }
    void setNext(ListSegment *next)
    {
        this->next = next;
    }
    ListSegment *getNext()
    {
        return next;
    }

    int getValue()
    {
        return value;
    }
};

class List
{
    ListSegment *head = nullptr;

public:
    List(int value)
    {
        ListSegment *s = nullptr;
        for (int i = 0; i < value; ++i)
        {
            ListSegment *segment = new ListSegment(i);
            if (s != nullptr)
            {
                s->setNext(segment);
            }
            else
            {
                head = segment;
            }
            s = segment;
        }
        delete s;
    }

    int operator[](int i)
    {
        ListSegment *tmp = head;
        for (int j = 0; j < i; ++j)
        {
            if (!tmp->getNext())
            {
                throw "Bereichsueberschreitung";
            }
            tmp = tmp->getNext();
        }
        return tmp->getValue();
    }
};

int main()
{
    List list(5);
    cout << "value: " << list[3] << endl;
    return 0;
}