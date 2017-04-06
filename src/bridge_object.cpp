/*************************************
 * File:    bridge_object.cpp
 * Author:  zhuchao
 * Date:    14/03/2017
 * Func:    Java jni base class
 *************************************/
#include "bridge_object.h"
#include "bridge_jni.h"
namespace bridge {
    BridgeObject::BridgeObject() {
        _jni = BridgeJni::getInstance();
        _env = NULL;
        _vm = NULL;
        if (_jni != NULL && _jni->get_status() == 0) {
            _env = _jni->get_env();
            _vm = _jni->get_vm();
        }
    }
    BridgeObject::BridgeObject(std::string class_name): _class_name(class_name) {
        _jni = BridgeJni::getInstance();
        _env = NULL;
        _vm = NULL;
        if (_jni != NULL && _jni->get_status() == 0) {
            _env = _jni->get_env();
            _vm = _jni->get_vm();
            _clazz = _env->FindClass(_class_name.c_str());
        }
    }
    BridgeObject::~BridgeObject() {
        _env = NULL;
        _vm = NULL;
    }

	std::string BridgeObject::getClassName() {
		return _class_name;
	}

	jclass BridgeObject::getClass()const {
		return _clazz;
	}

	JNIEnv* BridgeObject::getEnv()const {
		return _env;
	}
}
