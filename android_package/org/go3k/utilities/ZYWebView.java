package org.go3k.utilities;

import android.app.Activity;
import android.util.Log;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.LinearLayout;
import android.widget.LinearLayout.LayoutParams;

public class ZYWebView {
	static private ZYWebView	m_instance;
	static private Activity 	m_activity;
	private LinearLayout 		m_webLayout;
	private WebView				m_webView;
	
	public static void setActivity(Activity ac) {
		m_activity = ac;
	}
	
	public static Object getZYWebView() {
		if (m_instance == null)
		{
			m_instance = new ZYWebView();
		}
		return m_instance;
	}
	
    //WebView
    public void displayWebView(final int x, final int y, final int width, final int height) {
//    	Log.e("Vincent", "showWebView");
    	
    	if (m_activity == null)
    		Log.e("Vincent", "showWebView m_activity is null.");
    	else
    		Log.e("Vincent", "showWebView m_activity is ok.");
    	
    	m_activity.runOnUiThread(new Runnable() {
            public void run() {
//            	LinearLayout layout = new LinearLayout(actInstance);
//            	actInstance.addContentView(layout, new LayoutParams(LayoutParams.FILL_PARENT,LayoutParams.FILL_PARENT));
        		//web layout 
            	if (m_webLayout == null)
            	{
            		m_webLayout = new LinearLayout(m_activity);
            		m_activity.addContentView(m_webLayout, 
            				new LayoutParams(LayoutParams.FILL_PARENT,LayoutParams.FILL_PARENT));
            	}
            	
            	if (m_webView == null)
            	{
            		m_webView = new WebView(m_activity);
                	m_webLayout.addView(m_webView);
            	}
            	
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
    	
    	m_activity.runOnUiThread(new Runnable() {
            public void run() {
            	m_webView.loadUrl(url);
            }
        });
    }
    
    public void removeWebView() {
//    	Log.e("Vincent", "removeWebView");
    	if (m_webLayout == null || m_webView == null) return;
    	
    	m_activity.runOnUiThread(new Runnable() {
            public void run() {
            	m_webLayout.removeView(m_webView);
            	m_webView.destroy();
            	m_webView = null;
            }
        });
    }
}
