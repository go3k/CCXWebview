//
//  BFWebView.h
//  CCXWebview
//
//  Created by Vincent on 12-11-27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef NewPuzzle_BFWebView_h
#define NewPuzzle_BFWebView_h

#include "cocos2d.h"

USING_NS_CC;

/**
 *	@brief This is a wrapper class of webview. 
 
    @Usage:
        
        ZYWebView* webview = new ZYWebView();
        webview->init();
        webview->showWebView("http://go3k.org", 0, 0, 300, 300);
        // 写到这里，就可以在游戏中显示一个webview 窗口了。
        // Then a webview window will appear in your game.
 
        // 可以按照你的设计意图调用以下接口
        // call these method anywhere as your wish
        webview->updateURL("http://blog.go3k.org");
        webview->removeWebView();
 
        // 释放 webview 指针。如果此前没有调用removeWebView()，析构中会进行调用。
        // release webview heap pointer. If you didn't call removeWebView() before, it will be called in the destructor.
        // So, don't care about this.
        webview->release();
 *
 */
class ZYWebView : public CCObject
{
public:
    ZYWebView();
    ~ZYWebView();
    
	bool init();
    
    /**
     *	@brief	show WebView
     *  @NOTICE You should call this method only once!!!
     *
     *	@param 	url 	link address
     *	@param 	x
     *	@param 	y       NOTICE: top left is (0, 0)
     *	@param 	width
     *	@param 	height
     *
     *
     注意：在cocos2dx DesignResolutionSize机制下，cocos2dx坐标系与对应平台的GUI坐标系可能不一样。在此情况下，需要进行坐标转换。
     目标是：把design坐标转换为screen坐标。
     
     详细内容参考官方文档 http://www.cocos2d-x.org/wiki/Multi_resolution_support
     
     ---
     Notice: We need convert coordinate value from design size coordinate to screen size coordinate.
     
     Learn more detail via: http://www.cocos2d-x.org/wiki/Multi_resolution_support
     */
    void showWebView(const char* url, float x, float y, float width, float height);

    /**
     *	@brief	Update url of webview
     *
     */
    void updateURL(const char* url);
    
    /**
     *	@brief	Remove webview from window
     destructor will call this method, and you can call this method freely.
     */
    void removeWebView();
    
private:
    void _privateShowWebView(const char* url, float x, float y, float width, float height);
};

#endif