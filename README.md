# Coding for the First Time!
Joined the CS club finally. This is my first repo, coding in C language as well as learning the ins-and-outs of being a programmer. So, trying to set up VS Code, the C compiler, a debugger (still not figured out), Git and its literal blackmagic commands, WSL (or even dual-booting), GitHub and more.

## What All I've Learned..
*A bit too much to summarise in one file, but i'll try..*

-**Basic Syntax and Very Basic Problem Solving:** How `int main()` and `return` keywords work, `printf()`, `scanf()` etc., if..else nests and loops. Also the different operators, especially the modulus (%) and logicals.

-**Nested Loops, Algorithms:** `for` loops in 'mario' really drove me crazy initially. Another especially hard program was 'primes':
```C
    int isPrime = 1;
    int divisor = 2;
    while(divisor <= sqrt(n))
    {
        if((n % divisor) == 0)
        {
            isPrime = 0;
            break;
        }
        divisor++; 
    }
    if(isPrime == 1)
    {
        prime++;
    }
    else
    {
        composite++;
    }
```
Hard logic to internalise but learnt that whenever a check must go on repeatedly, it's better to assume true until proven false.
