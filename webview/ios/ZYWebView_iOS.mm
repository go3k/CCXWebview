//
//  ZYWebView_iOS.m
//  CCXWebview
//
//  Created by Vincent on 12-11-27.
//  Copyright (c) 2012 go3k.org. All rights reserved.
//

#import "ZYWebView_iOS.h"
#import <UIKit/UIKit.h>

@implementation ZYWebView_iOS


- (void)showWebView_x:(float)x y:(float)y width:(float) width height:(float)height
{
    if (!m_webview)
    {
        UIWindow* window = [[UIApplication sharedApplication] keyWindow];
        if (!window) return;
        
        float scale = [[UIScreen mainScreen] scale];
        x /= scale; y /= scale; width /= scale; height /= scale;
        
        m_webview = [[UIWebView alloc] initWithFrame:CGRectMake(x, y, width , height)];
        [m_webview setDelegate:self];

        if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
        {
            [window addSubview:m_webview];
        }
        else
        {
            // use this method on ios6
            [window.rootViewController.view addSubview:m_webview];
        }
        [m_webview release];
        
        m_webview.backgroundColor = [UIColor clearColor];
        m_webview.opaque = NO;
        
        for (UIView *aView in [m_webview subviews])  
        { 
            if ([aView isKindOfClass:[UIScrollView class]])  
            { 
                UIScrollView* scView = (UIScrollView *)aView;
                
                // 是否显示右侧的滚动条 （水平的类似）
                // set Vertical Scroll bar visible
//                [(UIScrollView *)aView setShowsVerticalScrollIndicator:NO];
                [scView setShowsHorizontalScrollIndicator:NO];
//                scView.bounces = NO;
                
                for (UIView *shadowView in aView.subviews)  
                {
                    if ([shadowView isKindOfClass:[UIImageView class]]) 
                    {
                        // 隐藏上下滚动出边界时的黑色的图片 也就是拖拽后的上下阴影
                        // hide black background when webpage is out of border.
                        shadowView.hidden = YES;
                    } 
                } 
            } 
        }  
    }
}

- (void)updateURL:(const char*)url
{
    NSString *request = [NSString stringWithUTF8String:url];
    [m_webview loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:request] 
                                            cachePolicy:NSURLRequestReloadIgnoringLocalCacheData 
                                        timeoutInterval:60]];
}

- (void)removeWebView
{
    if (m_webview)
    {
        [m_webview removeFromSuperview];
        m_webview = NULL;
    }
}

#pragma mark - WebView
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType
{
    return true;
}

- (void)webViewDidStartLoad:(UIWebView *)webView
{
    
}

- (void)webViewDidFinishLoad:(UIWebView *)webView
{
    
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error
{
    
}

@end
