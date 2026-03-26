//
// Created by user on 3/27/2026.
//

#ifndef LABS1TO6_ISCHEDULABLE_H
#define LABS1TO6_ISCHEDULABLE_H


class ISchedulable {
public:
    virtual ~ISchedulable() = default;
    virtual bool isAvailable(int timeSlot) = 0;
    virtual void assign(int timeSlot) = 0;
};


#endif //LABS1TO6_ISCHEDULABLE_H