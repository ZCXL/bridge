/*************************************
 * Author: ÷Ï≥¨
 * Email: zhuchao1995@hotmail.com
 * Date: 2017/3/22
 * Function:
 *************************************/

#include "bridge_conf.h"
namespace bridge{
    jint        g_jvm_version               = JNI_VERSION_1_2;
    jint        g_jvm_noptions              = 0;
    jboolean    g_jvm_ignore_unrecognized   = JNI_TRUE;
    std::vector<std::string> g_options;

    void set_jvm_version(jint version) {
        g_jvm_version = version;
    }
    void set_jvm_noptions(jint noptions) {
        g_jvm_noptions = noptions;
    }
    void set_jvm_ignoreUnrecognised(jboolean ignoreUnrecognized) {
        g_jvm_ignore_unrecognized = ignoreUnrecognized;
    }
    void add_option(const std::string option) {
        g_jvm_noptions++;
        g_options.push_back(option);
    }

    JavaVMOption* BridgeConf::_options = NULL;
    JavaVMInitArgs BridgeConf::_args;
    JavaVMInitArgs& BridgeConf::get_args(){
        _args.version = g_jvm_version;
        _args.nOptions = g_jvm_noptions;
        _args.ignoreUnrecognized = g_jvm_ignore_unrecognized;
        if (_options != NULL) {
            delete []_options;
            _options = NULL;
        }
        _options = new JavaVMOption[g_options.size()];
        int i = 0;
        for (std::vector<std::string>::iterator it = g_options.begin(); it != g_options.end(); it++) {
            _options[i].optionString = new char[it->length() + 1];
            memset(_options[i].optionString, '\0', it->length() + 1);
            strcpy(_options[i++].optionString, it->c_str());
        }
        _args.options = _options;

        return _args;
    }
}
