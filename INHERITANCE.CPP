#include <iostream>
using namespace std;
class human
{
    int age;
    int height;
    int weight;

public:
    int getage()
    {
        return this->age;
    }
    void setweight(int w)
    {
        weight = w;
    }
};

class male : public human
{
public:
    string color;
    void getcolor()
    {
        cout << "Male is here.";
    }
};
int main()
{male m1;
cout<<m1.getage()<<endl;
m1.getcolor();
int i ;
for(i =0;i<10;i++);
{cout<<i;}
}
