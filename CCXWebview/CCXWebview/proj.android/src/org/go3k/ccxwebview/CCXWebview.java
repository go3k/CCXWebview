/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.go3k.ccxwebview;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.app.Activity;
import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.LinearLayout;
import android.widget.LinearLayout.LayoutParams;

public class CCXWebview extends Cocos2dxActivity{

	public static Activity actInstance;
	private LinearLayout m_webLayout;
	private WebView m_webView;
	
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		
		actInstance = this;
		//web layout 
		m_webLayout = new LinearLayout(this);
		actInstance.addContentView(m_webLayout, 
				new LayoutParams(LayoutParams.FILL_PARENT,LayoutParams.FILL_PARENT));
	}
	
    static {
         System.loadLibrary("game");
    }
    
    public static Object getJavaActivity() {
        return actInstance;
    }
    
    //WebView
    public void displayWebView(final int x, final int y, final int width, final int height) {
//    	Log.e("Vincent", "showWebView");
    	
    	this.runOnUiThread(new Runnable() {
            public void run() {
//            	LinearLayout layout = new LinearLayout(actInstance);
//            	actInstance.addContentView(layout, new LayoutParams(LayoutParams.FILL_PARENT,LayoutParams.FILL_PARENT));
            	m_webView = new WebView(actInstance);
            	m_webLayout.addView(m_webView);
            	
            	LinearLayout.LayoutParams linearParams = (LinearLayout.LayoutParams) m_webView.getLayoutParams();
            	linearParams.leftMargin = x;
            	linearParams.topMargin = y;
            	linearParams.width = width;
            	linearParams.height = height;
            	m_webView.setLayoutParams(linearParams);

            	m_webView.setBackgroundColor(0);
            	m_webView.getSettings().setCacheMode(WebSettings.LOAD_NO_CACHE);
            	m_webView.getSettings().setAppCacheEnabled(false);
            	//m_webView.setBackgroundResource(R.drawable.yourImage);
            	
            	m_webView.setWebViewClient(new WebViewClient(){
                    @Override
                    public boolean shouldOverrideUrlLoading(WebView view, String url){
                            
                            return false;
                            
                    }
                });
            	
            }
        });
    }
    
    public void updateURL(final String url) {
//    	Log.e("Vincent", "updateURL"+url);
    	
    	this.runOnUiThread(new Runnable() {
            public void run() {
            	m_webView.loadUrl(url);
            }
        });
    }
    
    public void removeWebView() {
//    	Log.e("Vincent", "removeWebView");

    	this.runOnUiThread(new Runnable() {
            public void run() {
            	m_webLayout.removeView(m_webView);
            	m_webView.destroy();
            }
        });
    }
}
