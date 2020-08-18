// Given following three values, the task is to find the total number of maximum chocolates you can eat.

// money : Money you have to buy chocolates
// price : Price of a chocolate
// wrap : Number of wrappers to be returned for getting one extra chocolate.


#include<bits/stdc++.h>
using namespace std;


//funtion for calculating numbers of chocolates that can be baught from wrappers
int maxChocolates_wrappers(int chocolates, int wrappers)
{
    if(chocolates<wrappers)
    {
        return 0;
    }

    int newChocolate = chocolates/wrappers;
    
    return newChocolate + maxChocolates_wrappers(newChocolate + chocolates%wrappers ,wrappers);
}

int maxChocolates(int money, int price, int wrap)
{
    if(price>money)
    return 0;

    int chocolates = money/price;

    return chocolates + maxChocolates_wrappers(chocolates, wrap);
}


int main()
{
    int money, price, wrapper;
    cin>>money>>price>>wrapper;

    cout<<maxChocolates(money,price,wrapper);
}