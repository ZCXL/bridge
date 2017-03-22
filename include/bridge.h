//
// Created by ÷Ï≥¨ on 2017/3/16.
//

#ifndef BRIDGE_BRIDGE_H_H
#define BRIDGE_BRIDGE_H_H
#include "bridge_jni.h"
#include "bridge_conf.h"
#include "bridge_object.h"
#define DEFINE_NAMESPACE \
    namespace java {
#define DEFINE_CLASS(className) \
    class #className: Object {
#define DEFINE_FIELD(privilege, type, name, sign) \
    privilege##:\
        #type #name

#endif //BRIDGE_BRIDGE_H_H
