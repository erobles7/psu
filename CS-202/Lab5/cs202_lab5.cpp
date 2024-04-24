#include "store.h"
using namespace std;

//Implement each of these using exception handeling
//For each function consider if you should have the try block
//in the function or if you should have the try block in the
//calling routine. If you throw an exception without a
//try block, then add an exception specification list


//Step 5a - throw an exception if there is an invalid response
bool again()
{
    try
    {
        char response;
        cin>>response;
        cin.ignore(100,'\n');
        response = toupper(response); 

        if(response != 'Y'|| response != 'N')
            throw response;
    }
    catch(char)
    {
        cout<<"\nYOU SUCK\n";
        return false;
    }
    return true;
}

//Step 5b - implement the address constructor and throw an
//exception if ther is a null string being copied:
address::address(char * new_street, char * new_zip)
{
    NULL_STRING invalid_response;

    try
    {
        invalid_response.street = new_street;
        invalid_response.zip = new_zip;

        if(!new_street || !new_zip)
            throw invalid_response; 
    }

    catch(NULL_STRING response)
    {
        if(!response.street && !response.zip)
            std::cout<<"\nError no input\n";
        if(!response.street)
            std::cout<<"\nNo input for street\n";
        else
            std::cout<<"No input for the zip\n";
    }

    street = new char[strlen(new_street)+1];
    strcpy(street,new_street);
    zip = new char[strlen(new_zip)+1];
    strcpy(zip,new_zip);
}

//Step 5c - implement the set pay function and throw an
//exception if a zzero or negative pay is requested
void hourly_employee::set_pay_rate(float rate) throw(INVALID_PAY)
{
    INVALID_PAY pay_rate;
    //pay_rate.rate = rate;

    try
    {
         pay_rate.pay= rate;
         if(pay_rate.pay <=0)
             throw pay_rate;
    }

    catch(INVALID_PAY rate)
    {
        std::cout<<"\nYou entered an invalid pay rate\n";
    }

    this->pay_rate = rate;
}

// *************************** Now move to main.cpp and work there


//Step 7 - implement the two compare functions. The first
//compares the employees name. Throw an exception if there is no match
bool employee::compare(const name & match)
{

}

//Now travere the binary search tree of reviews and
//throw an exception if there is no match
bool employee::compare(char * match)
{

}

