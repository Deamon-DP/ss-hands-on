># Semaphore
* it performs two operations p(),v() (these are atomic operations).
* It will `avoid busy waiting` unlike spin lock.


* Incrementing operation.
```c
int v(int i)
{
    i=i+1;
    unlock()
    return i;
}

```

* Decrementing Operation
```c
int p(int i)
{
    if(i>0)
        i--;
        lock()
    else 
        wait till i>0;

    return i;  
}

```