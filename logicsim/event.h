#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

/* The operator() will take two Event*'s as it’s input and needs to sort them using the 
 * Event::time data member in such a way that your heap will be a min-heap. i.e. 
 * Event's are sorted by time.*/
typedef struct EventLess 
{
    //write the operator() required to make this a functor that compares Events by time
    bool operator()(Event* a, Event* b)
    {
        return ((a->time) < (b->time));
    }

} EventLess;
	
#endif
