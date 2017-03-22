/*************************************
 * File:    bridge_conf.h
 * Author:  zhuchao
 * Date:    12/03/2017
 * Func:    Java virtual machine configuration.
 *************************************/
#ifndef BRIDGE_CONF_H_
#define BRIDGE_CONF_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
#include <jni.h>
namespace bridge {
    extern jint                     g_jvm_version;
    extern jint                     g_jvm_noptions;
    extern jboolean                 g_jvm_ignore_unrecognized;
    extern std::vector<std::string> g_options;
    extern void set_jvm_version(jint version);
    extern void set_jvm_noptions(jint noptions);
    extern void set_jvm_ignoreUnrecognised(jboolean ignoreUnrecognized);
    extern void add_option(const std::string option);
#define SET_JVM_ARGS(name, value) \
    set_jvm_##name(value);
#define ADD_JVM_OPTIONS(value) \
    add_option(std::string(#value));

    class BridgeConf {
    private:
        static JavaVMInitArgs _args;
        static JavaVMOption* _options;
    public:
        static JavaVMInitArgs& get_args();
    };
}
#endif
