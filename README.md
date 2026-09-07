# Coding for the First Time!
Joined the CS club finally. This is my first repo, coding in C language as well as learning the ins-and-outs of being a programmer. So, trying to set up VS Code, the C compiler, a debugger (still not figured out), Git and its literal blackmagic commands, WSL (or even dual-booting), GitHub and more.

## What All I've Learned..
*A bit too much to summarise in one file, but I'll try..*

-**Basic Syntax and Very Basic Problem Solving:** How `int main()` and `return` keywords work, `printf()`, `scanf()` etc., if..else nests and loops. Also the different operators, especially the modulus operator (to shave off digits, like in 'credit', among other uses) and logicals.

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

-**1D Arrays:** Easier than nested loops for the most part, biggest learning was to think of arrays as literally integers (can use as indices henceforth which was hard to grasp). Implemented a bubble sort as in 'tideman'.

-**2D Arrays and Structs:** 'plurality' introduced `structs` and kind of felt like the first "real" program. Familiarity with Command-Line Arguments and accessing within a struct, plus finding the maximum from something. Then 'runoff' felt fairly starightforward althugh really learnt to workk with functions here and:
```C
for(int i = 0; i < voter_count; i++)
{
    for(int j = 0; j < candidate_count; j++)
    {
        if(!candidates[preferences[i][j]].eliminated)
        {
            candidates[preferences[i][j]].votes++;
            break;
        }
    }
}
```
Using the preferences 2D-array as an index for candidates struct was hard to grasp.

-**Recursion:** By far the hardest yet in 'tideman'. Also, had to make my own function to implement it which was like a "helper function" (used it again in 'matrix'). Learnt about Call Stacks and wrote a whole lotta programs for this topic (atoi, collatz, happy number, recently matrix).

-**Pointers:** Currently doing...
