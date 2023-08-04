#include<stdio.h>
#include<dlfcn.h>
#include<stdbool.h>

#include "prime_checker.h"
#include "perfect_checker.h"

int main()
{
    int No = 0;
    void *prime_ptr = dlopen("./libprime.so",RTLD_LAZY);
    void *perfect_ptr = dlopen("./libperfect.so",RTLD_LAZY);

    if(!prime_ptr || !perfect_ptr )
    {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    
    bool(*CheckPrime)(int) = dlsym(prime_ptr,"CheckPrime");
    bool(*CheckPerfect)(int) = dlsym(perfect_ptr,"CheckPerfect");
    

    if(!CheckPerfect || !CheckPrime)
    {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(prime_ptr);
        dlclose(perfect_ptr);
        return 1;
    }

    printf("Enter Any Number To Check :\n");
    scanf("%d",&No);

    if(CheckPerfect(No))
    {
        printf("%d Is Perfect Number..\n",No);
    }
    else
    {
        printf("%d Is Not A Perfect Number..\n",No);
    }

    if(CheckPrime(No))
    {
        printf("%d Is Prime Number..\n",No);
    }
    else
    {
        printf("%d Is Not A Prime Number..\n",No);
    }

    dlclose(prime_ptr);
    dlclose(perfect_ptr);
    
    return 0;
}