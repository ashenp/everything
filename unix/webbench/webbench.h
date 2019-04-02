#ifndef BENCHER_H_
#define BENCHER_H_

class Bencher{

public:

void bench();

Bencher() 
    : c(1) //concurrency
    , t(1) //thread
    , during(30)
    , timeout(5)
{
     
}

};

#endif

