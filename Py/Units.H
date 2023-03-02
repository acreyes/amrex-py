#ifndef Units_H_
#define Units_H_

class Units
{
public:
    virtual ~Units() {};

    // call before main evolution loop
    virtual void Init(){};

//     // call in main evolution loop
    virtual void Evolve(){};

//     // call after main evolution loop before exiting
    virtual void Finalize(){};

private:

//     // call just before entering this unit's Evolve
    virtual void Adjust(){};

};
#endif