#include<stdbool.h>
#include<stdio.h>
#include"prime_checker.h"

bool CheckPrime(int No)
{
    int i = 0;
    if(No <= 1)
    {
        return false;
    }

    for (i = 2; i * i <= No; i++) {
        if (No % i == 0) 
        {
            return false;
        }
    }
    return true;
}