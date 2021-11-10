//
// Created by blast on 11/7/21.
//

#ifndef RS_MONITOR_RAMOBJECT_H
#define RS_MONITOR_RAMOBJECT_H
#include "ResourceObject.h"
#include <vector>

class RamObject : public ResourceObject{
public:
    virtual void update() = 0;

    unsigned long getTotal();
    unsigned long getFree();
    unsigned long getUsage();

protected:
    void setFree(unsigned long _free);
    void setTotal(unsigned long _total);

private:
    unsigned long total;
    unsigned long free;



};


#endif //RS_MONITOR_RAMOBJECT_H
