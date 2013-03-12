//
//  ZYWebView.cpp
//  CCXWebview
//
//  Created by Vincent on 12-11-27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "ZYWebView.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>

/*
 More info about JNI using, check this:
 http://go3k.org/?p=49
 */

ZYWebView::ZYWebView()
{
    
}

ZYWebView::~ZYWebView()
{
    
}

bool ZYWebView::init()
{
	return true;
}

void ZYWebView::showWebView(const char* url, float x, float y, float width, float height)
{
    //1. 获取activity静态对象
    JniMethodInfo minfo;
    //getStaticMethodInfo 次函数返回一个bool值表示是否找到此函数
    bool isHave = JniHelper::getStaticMethodInfo(minfo,
                                                 "com/bianfeng/puzzle/NewPuzzle",
                                                 "getJavaActivity",
                                                 "()Ljava/lang/Object;");
    jobject activityObj;
    if (isHave)
    {
        activityObj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
    }
    
    //2. 查找displayWebView接口，并用jobj调用
    isHave = JniHelper::getMethodInfo(minfo,"com/bianfeng/puzzle/NewPuzzle","displayWebView", "(IIII)V");
    
    if (!isHave)
    {
        CCLog("jni:displayWebView 函数不存在");
    }
    else
    {
        //调用此函数
        jint jX = (int)x;
        jint jY = (int)y;
        jint jWidth = (int)width;
        jint jHeight = (int)height;
        minfo.env->CallVoidMethod(activityObj, minfo.methodID, jX, jY, jWidth, jHeight);
    }
    
    //3. 查找updateURL接口，并用jobj调用
    isHave = JniHelper::getMethodInfo(minfo,"com/bianfeng/puzzle/NewPuzzle","updateURL", "(Ljava/lang/String;)V");
    
    if (!isHave)
    {
        CCLog("jni:updateURL 函数不存在");
    }
    else
    {
        //调用此函数
        jstring jmsg = minfo.env->NewStringUTF(url);
        minfo.env->CallVoidMethod(activityObj, minfo.methodID, jmsg);
    }
}

void ZYWebView::updateURL(const char* url)
{
    //1. 获取activity静态对象
    JniMethodInfo minfo;
    //getStaticMethodInfo 次函数返回一个bool值表示是否找到此函数
    bool isHave = JniHelper::getStaticMethodInfo(minfo,
                                                 "com/bianfeng/puzzle/NewPuzzle",
                                                 "getJavaActivity",
                                                 "()Ljava/lang/Object;");
    jobject activityObj;
    if (isHave)
    {
        activityObj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
    }
    
    //2. 查找updateURL接口，并用jobj调用
    isHave = JniHelper::getMethodInfo(minfo,"com/bianfeng/puzzle/NewPuzzle","updateURL", "(Ljava/lang/String;)V");
    
    if (!isHave)
    {
        CCLog("jni:updateURL 函数不存在");
    }
    else
    {
        //调用此函数
        jstring jmsg = minfo.env->NewStringUTF(url);
        minfo.env->CallVoidMethod(activityObj, minfo.methodID, jmsg);
    }
}

void ZYWebView::removeWebView()
{
    //1. 获取activity静态对象
    JniMethodInfo minfo;
    //getStaticMethodInfo 次函数返回一个bool值表示是否找到此函数
    bool isHave = JniHelper::getStaticMethodInfo(minfo,
                                                 "com/bianfeng/puzzle/NewPuzzle",
                                                 "getJavaActivity",
                                                 "()Ljava/lang/Object;");
    jobject activityObj;
    if (isHave)
    {
        activityObj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
    }
    
    //2. 查找updateURL接口，并用jobj调用
    isHave = JniHelper::getMethodInfo(minfo,"com/bianfeng/puzzle/NewPuzzle","removeWebView", "()V"); 
    
    if (!isHave)
    {
        CCLog("jni:updateURL 函数不存在");
    }
    else
    {
        //调用此函数
        minfo.env->CallVoidMethod(activityObj, minfo.methodID);
    }
}

