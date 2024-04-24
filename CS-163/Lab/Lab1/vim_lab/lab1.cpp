//Eduardo Robles
//Sample program to get familiar with linux
#include <iostream>
using namespace std;

int main()
{
    int total = 0;
    int count = 0;
    int input = 0;

    while(input >= 0)
    {
        cin>>input;
        total = total + input;
        ++count;
    }

    std::cout<<total/count<<std::endl;
    return 0;
}
