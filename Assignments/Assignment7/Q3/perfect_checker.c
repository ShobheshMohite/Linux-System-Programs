#include<stdbool.h>
#include<stdio.h>

#include"perfect_checker.h"

bool CheckPerfect(int No)
{
    int iSum = 0;
    int iCnt = 0;
    for(iCnt = 1;iCnt <= No/2 ; iCnt++)
    {
        if(No % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if(iSum == No)
    {
        return true;
    }
    else
    {
        return false;
    }
}
