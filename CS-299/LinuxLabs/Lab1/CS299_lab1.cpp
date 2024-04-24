//My Name: Eduardo Robles
//Sample program to get you familiar with linux

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int count = 0;
    int userInput = 0;

    while(userInput != -1)
    {
        sum = sum + userInput;
        cout << "Enter a postive number or -1 to quit\n";
        cin >> userInput;
        count++;
    }

    cout << "The average of the numbers is : " <<static_cast<float>(sum/count) << "\n";

    return 0;

}
