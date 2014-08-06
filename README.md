CCXWebview
==========

This is a plugin/feature project to show Webview in a cocos2d-x games on both iOS and Android platform, If you want to use this code please fork or star this project, and I am happy to know that.

This project is under MIT License.

## Main Feature

* Support both cocos2d-x v2.x and cocos2d-x v3.x

	* [v2] branch: v2.x implements
	* [v3] branch: v3.x implements

* Just copy and past to use this feature in your game.
* Have both Chinese and English comments in source code.
* Continuous update with cocos2d-x's upgrade.


## Usage

1. Copy the `webview` folder into your `Classes` folder (or anywhere you want to compile them).

2. ** For iOS ** 

	Add these files into your project in XCode.
	
		webview/ZYWebView.h
		webview/ZYWebView.cpp
		webview/ios/ZYWebView.mm
		webview/ios/ZYWebView_iOS.h
		webview/ios/ZYWebView_iOS.mm

	> Don't add `webview/android` folder !!! Which will result compile errors, such as 'xx symbols redefined'.

3. ** For Andriod ** 

	1. Copy the `org` folder in `android_package`, into `src` in your android project folder. For example: `proj.android/src/`.
	
	2. Add these codes into your Android Main Activity Class.
	
			//import package
			import org.go3k.utilities.ZYWebView;
			
			//add code in onCreate function ---- THIS IS IMPORTANT!!!
			ZYWebView.setActivity(this);
			
	3. Update `jni/Android.mk`, add compile files and include folder. For exmaple:
	
			LOCAL_SRC_FILES := hellocpp/main.cpp \
	                   ../../Classes/AppDelegate.cpp \
	                   ../../Classes/webview/ZYWebView.cpp \
	                   ../../Classes/webview/android/ZYWebView_Android.cpp \
	                   ../../Classes/HelloWorldScene.cpp
	
			LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
						$(LOCAL_PATH)/../../Classes/webview


4. **Show webview in cocos2d-x code**

		#include "ZYWebView.h"
		
		ZYWebView* webview = new ZYWebView();
		webview->init();
		webview->showWebView("http://go3k.org", 0, 0, 300, 300);
		// Then a webview window will appear in your game.
		
		// call these method as your wish
		webview->updateURL("http://blog.go3k.org");
		webview->removeWebView();

		//delete the pointer in the end
		delete webview;
		
---
### For Chinese programmer:

如果你想了解这是如何实现的，或者你在使用过程中有些疑问，可以访问下面链接，可能会对你有所帮助。

[如何使用JNI](http://blog.go3k.org/jni0/)

[cocos2dx中嵌入WebView](http://blog.go3k.org/cocos2dx-add-webview/)
