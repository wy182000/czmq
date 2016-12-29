/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "czmq.h"
#include "org_zeromq_czmq_Ziflist.h"

JNIEXPORT jlong JNICALL
Java_org_zeromq_czmq_Ziflist__1_1new (JNIEnv *env, jclass c)
{
    //  Disable CZMQ signal handling; allow Java to deal with it
    zsys_handler_set (NULL);
    jlong new_ = (jlong) (intptr_t) ziflist_new ();
    return new_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Ziflist__1_1destroy (JNIEnv *env, jclass c, jlong self)
{
    ziflist_destroy ((ziflist_t **) &self);
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Ziflist__1_1reload (JNIEnv *env, jclass c, jlong self)
{
    ziflist_reload ((ziflist_t *) (intptr_t) self);
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_czmq_Ziflist__1_1size (JNIEnv *env, jclass c, jlong self)
{
    jlong size_ = (jlong) ziflist_size ((ziflist_t *) (intptr_t) self);
    return size_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_czmq_Ziflist__1_1first (JNIEnv *env, jclass c, jlong self)
{
    char *first_ = (char *) ziflist_first ((ziflist_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, first_);
    return return_string_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_czmq_Ziflist__1_1next (JNIEnv *env, jclass c, jlong self)
{
    char *next_ = (char *) ziflist_next ((ziflist_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, next_);
    return return_string_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_czmq_Ziflist__1_1address (JNIEnv *env, jclass c, jlong self)
{
    char *address_ = (char *) ziflist_address ((ziflist_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, address_);
    return return_string_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_czmq_Ziflist__1_1broadcast (JNIEnv *env, jclass c, jlong self)
{
    char *broadcast_ = (char *) ziflist_broadcast ((ziflist_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, broadcast_);
    return return_string_;
}

JNIEXPORT jstring JNICALL
Java_org_zeromq_czmq_Ziflist__1_1netmask (JNIEnv *env, jclass c, jlong self)
{
    char *netmask_ = (char *) ziflist_netmask ((ziflist_t *) (intptr_t) self);
    jstring return_string_ = (*env)->NewStringUTF (env, netmask_);
    return return_string_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Ziflist__1_1print (JNIEnv *env, jclass c, jlong self)
{
    ziflist_print ((ziflist_t *) (intptr_t) self);
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Ziflist__1_1test (JNIEnv *env, jclass c, jboolean verbose)
{
    ziflist_test ((bool) verbose);
}

