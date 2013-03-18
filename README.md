CCXWebview
==========

A example code of show Webview in a cocos2d-x games on both iOS and Android platform.

##Main Info

Base cocos2d-x version: 2.0.4

##Usage

###iOS usage

Just open the project in XCode, build & run.

###Andriod usage

1. In terminal: 
	`cd CCXWebview/CCXWebview/CCXWebview/proj.android`
	(this is a example, maybe diffirent with yours).
	
	`./build_native.sh`	, run this c++ .so build shell, this will result in a .so file.
	
2. New Android project from existing code, choose the android.proj folder.
	
	Build and run your code.

3. (Optional) If you wanna use this CCXWebview in your project, please notice the `/Classes/webview/android/BFWebView.cpp` file. Please modify the `kJNIPakageName` constant varible on the top of this .cpp file.

---
If you do know much about JNI please read articles below(all written in chinese).

[How to use JNI](http://go3k.org/?p=49)


[How show webview in coco2d-x games](http://go3k.org/?p=30)
