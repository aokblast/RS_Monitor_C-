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
    void setUsage(unsigned long _usage);
    void setTotal(unsigned long _total);

private:
    unsigned long total;
    unsigned long used;



};


#endif //RS_MONITOR_RAMOBJECT_H
