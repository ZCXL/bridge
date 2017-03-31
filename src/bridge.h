//
// Created by �쳬 on 2017/3/16.
//

#ifndef BRIDGE_BRIDGE_H_H
#define BRIDGE_BRIDGE_H_H
#include "bridge_jni.h"
#include "bridge_conf.h"
#include "bridge_object.h"
#define DEFINE_START_NAMESPACE() \
    namespace java {
#define DEFINE_CLASS(className) \
    class J##className: public JavaObject {
#define DEFINE_END() \
    }                \
    ;
#define DEFINE_END_NAMESPACE() \
	}

#endif //BRIDGE_BRIDGE_H_H
