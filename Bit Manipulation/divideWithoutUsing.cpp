#include<bits/stdc++.h>
using namespace std;

int divide(int divisor,int dividend){
    int sign = ((divisor < 0) ^ (dividend < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor=abs(divisor);

    int quo = 0;
    while(divisor<=dividend){
        quo++;
        dividend -= divisor;
    }
    return quo * sign;
}

int divideBitMani(int divisor, int dividend){
    int sign = ((divisor < 0) ^ (dividend < 0)) ? -1 : 1;
    
}



int main()
{

    
    return 0;
}