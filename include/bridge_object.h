/*************************************
 * File:    bridge_jni.h
 * Author:  zhuchao
 * Date:    14/03/2017
 * Func:    Java jni base class
 *************************************/

#ifndef BRIDGE_BRIDGE_OBJECT_H
#define BRIDGE_BRIDGE_OBJECT_H
#include <jni.h>
#include "bridge_jni.h"
namespace bridge {
    class BridgeObject {
    public:
        BridgeObject();
        virtual ~BridgeObject();
    protected:
        BridgeObject(std::string class_name);
    protected:
        std::string _class_name;
        JNIEnv* _env;
        JavaVM* _vm;
        const BridgeJni* _jni;

        jclass _clazz;
        jobject _object;
	public:
		virtual std::string getClassName();
    };
}
#endif //BRIDGE_BRIDGE_OBJECT_H
