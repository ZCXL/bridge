/*************************************
 * File:    bridge_jni.h
 * Author:  zhuchao
 * Date:    12/03/2017
 * Func:    Create object of jvm, 
 *          and Manage it's life cycle.
 *************************************/
#ifndef BRIDGE_JNI_H_
#define BRIDGE_JNI_H_

#include <jni.h>
#include <string>
#include <iostream>
#include <stdlib.h>

namespace bridge {
    class BridgeJni {
    public:
        static BridgeJni *getInstance();

    private:
        BridgeJni();

        ~BridgeJni();

    private:
        JavaVM *_jvm;
        JNIEnv *_env;
        long _status;
        static BridgeJni *_object;
    public:
        JavaVM *get_vm()const;

        JNIEnv *get_env()const;

        long get_status()const {
            return _status;
        }
    };
}
#endif