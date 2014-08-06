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
 http://blog.go3k.org/jni0/
 */
const char* kZYWebViewJNIPakageName = "org/go3k/utilities/ZYWebView";

ZYWebView::~ZYWebView()
{
    removeWebView();
}

// 获取ZYWebView Android 对象
// get ZYWebView Android object
jobject getZYWebView()
{
    JniMethodInfo minfo;
    bool isHave = JniHelper::getStaticMethodInfo(minfo,
                                                 kZYWebViewJNIPakageName,
                                                 "getZYWebView",
                                                 "()Ljava/lang/Object;");
    jobject activityObj;
    if (isHave)
    {
        CCLog("jni:getZYWebView have.");
        activityObj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
    }
    return activityObj;
}

void ZYWebView::_privateShowWebView(const char* url, float x, float y, float width, float height)
{
    CCLog("jni:showWebView 1.");
    JniMethodInfo minfo;
    jobject activityObj = getZYWebView();
    CCLog("jni:showWebView 2.");
    
    // call displayWebView
    bool isHave = JniHelper::getMethodInfo(minfo, kZYWebViewJNIPakageName, "displayWebView", "(IIII)V");
    
    if (!isHave)
    {
        CCLog("jni:displayWebView is undefined.");
    }
    else
    {
        jint jX = (int)x;
        jint jY = (int)y;
        jint jWidth = (int)width;
        jint jHeight = (int)height;
        minfo.env->CallVoidMethod(activityObj, minfo.methodID, jX, jY, jWidth, jHeight);
    }
    
    // call updateURL
    isHave = JniHelper::getMethodInfo(minfo, kZYWebViewJNIPakageName, "updateURL", "(Ljava/lang/String;)V");
    
    if (!isHave)
    {
        CCLog("jni:updateURL is undefined.");
    }
    else
    {
        jstring jmsg = minfo.env->NewStringUTF(url);
        minfo.env->CallVoidMethod(activityObj, minfo.methodID, jmsg);
    }
}

void ZYWebView::updateURL(const char* url)
{
    JniMethodInfo minfo;
    jobject activityObj = getZYWebView();
    
    // call updateURL
    bool isHave = JniHelper::getMethodInfo(minfo, kZYWebViewJNIPakageName, "updateURL", "(Ljava/lang/String;)V");
    
    if (!isHave)
    {
        CCLog("jni:updateURL is undefined.");
    }
    else
    {
        jstring jmsg = minfo.env->NewStringUTF(url);
        minfo.env->CallVoidMethod(activityObj, minfo.methodID, jmsg);
    }
}

void ZYWebView::removeWebView()
{
    JniMethodInfo minfo;
    jobject activityObj = getZYWebView();
    if (!activityObj) return;
    
    // call removeWebView
    bool isHave = JniHelper::getMethodInfo(minfo, kZYWebViewJNIPakageName, "removeWebView", "()V"); 
    
    if (!isHave)
    {
        CCLog("jni:removeWebView is undefined.");
    }
    else
    {
        minfo.env->CallVoidMethod(activityObj, minfo.methodID);
    }
}

