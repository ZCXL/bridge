PWD = $(shell pwd)
CXX := g++
LINKER := g++
CXXFLAGS := -pipe -Wall -O2 -g -fPIC
LIBS :=
INCLUDE :=
LINKFLAGS := -fPIC -shared
AR := ar
JAVA_PATH = ${JAVA_HOME}
OBJECTS = src/bridge_jni.o \
	src/bridge_object.o \
	src/bridge_conf.o

CORE_DEPS = src/bridge.h \
	src/bridge_conf.h \
	src/bridge_jni.h \
	src/bridge_object.h

DEP_INCPATH = -I$(JAVA_PATH)/include/ -I$(JAVA_PATH)/include/linux/
DEP_LDFLAGS = -L$(JAVA_PATH)/jre/lib/amd64/server/
DEP_LDLIBS = -ljvm
INCPATH = -I src/
default:lib/libbridge.so lib/libbridge.a
	cp src/bridge.h include/
	cp src/bridge_conf.h include/
	cp src/bridge_jni.h include/
	cp src/bridge_object.h include/

lib/libbridge.so:$(OBJECTS)
	$(LINKER) $(DEP_LDFLAGS) $(DEP_LDLIBS) $(LINKFLAGS) -o $@ $(OBJECTS)

lib/libbridge.a:$(OBJECTS)
	$(AR) -r $@ $(OBJECTS)

src/bridge_jni.o:$(CORE_DEPS) \
	src/bridge_jni.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/bridge_jni.cpp

src/bridge_object.o:$(CORE_DEPS) \
    src/bridge_object.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/bridge_object.cpp

src/bridge_conf.o:$(CORE_DEPS) \
    src/bridge_conf.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ src/bridge_conf.cpp

all:clean default

install:
	cp lib/libbridge.so /usr/local/lib/
	cp include/* /usr/local/include/

clean:
	rm src/*.o
	rm lib/*
	rm include/*
