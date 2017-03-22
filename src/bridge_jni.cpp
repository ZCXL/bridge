/*************************************
 * File:    bridge_jni.cpp
 * Author:  zhuchao
 * Date:    12/03/2017
 * Func:    Create object of jvm, 
 *          and Manage it's life cycle.
 *************************************/

#include "bridge_jni.h"
#include "bridge_conf.h"

namespace bridge {
    BridgeJni* BridgeJni::_object = NULL;
    BridgeJni* BridgeJni::getInstance() {
        if (_object == NULL) {
            _object = new(std::nothrow) BridgeJni();
        }
        return _object;
    }

    BridgeJni::BridgeJni() {
        _env = NULL;
        _jvm = NULL;
        ADD_JVM_OPTIONS("-Djava.class.path=.")
        JavaVMInitArgs &vm_args = BridgeConf::get_args();
        _status = JNI_CreateJavaVM(&_jvm, (void **) &_env, &vm_args);
    }

    BridgeJni::~BridgeJni() {
        _jvm->DestroyJavaVM();
    }

    JavaVM *BridgeJni::get_vm()const {
        if (_jvm != NULL) {
            return _jvm;
        }
        return NULL;
    }

    JNIEnv *BridgeJni::get_env()const {
        if (_env != NULL) {
            return _env;
        }
        return NULL;
    }
}
