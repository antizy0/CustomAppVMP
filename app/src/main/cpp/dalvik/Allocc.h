//
// Created by liu meng on 2018/8/31.
//

#ifndef CUSTOMAPPVMP_ALLOC_H
#define CUSTOMAPPVMP_ALLOC_H

#include "Thread.h"
enum {
    ALLOC_DEFAULT = 0x00,
    ALLOC_DONT_TRACK = 0x01,  /* don't add to internal tracking list */
    ALLOC_NON_MOVING = 0x02,
};
typedef Object* (*dvmAllocObject_func)(ClassObject* clazz, int flags);
extern dvmAllocObject_func dvmAllocObjectHook;
typedef void (*dvmAddTrackedAlloc_func)(Object* obj, Thread* self);
extern dvmAddTrackedAlloc_func dvmAddTrackedAllocHook;
typedef void (*dvmReleaseTrackedAlloc_func)(Object* obj, Thread* self);
extern dvmReleaseTrackedAlloc_func dvmReleaseTrackedAllocHook;
bool initAllocFuction(void *dvm_hand,int apilevel);
#endif //CUSTOMAPPVMP_ALLOC_H
