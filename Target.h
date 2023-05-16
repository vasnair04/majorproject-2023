#ifndef TARGET_H
#define TARGET_H

class Target{
    protected:
    double* x;
    double* y;
    public:
    Target();
    virtual void hit()=0;
    virtual void despawn()=0;
};


#endif