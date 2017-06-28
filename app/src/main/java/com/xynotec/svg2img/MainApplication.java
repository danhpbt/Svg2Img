package com.xynotec.svg2img;


import android.app.Application;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.res.AssetManager;
import android.support.v7.app.AppCompatDelegate;
import android.util.Log;

public class MainApplication extends Application
{	
	// Used to load the 'native-lib' library on application startup.
	static {
		System.loadLibrary("native-lib");
	}

	static native void loadAssetManger(AssetManager mgr);

	private static Context context;

	//public static byte[] fontData;
	//public static int fontDataSize;

	public static Context getAppContext() {
		return context;
	}

	public static AssetManager getAssetManager()
	{
		return context.getAssets();
	}

	@Override
	public void onCreate() {

		try {
			Log.d("MainApp", "onCreate");
			//get previous version to check smt
			
			MainApplication.context = getApplicationContext();

			loadAssetManger(context.getAssets());

			//fontData  = com.xynotec.util.Util.loadResAssets(this, "timesi.ttf");
			//fontDataSize = fontData.length;
		}
		catch (Exception e) {
			//e.printStackTrace();
			Log.d("MainApp-onCreate:", e.getMessage());
		}

		super.onCreate();
	}	

	@Override
	public void onLowMemory(){
		super.onLowMemory();
	}

	@Override
	public void onTerminate() {
		// TODO Auto-generated method stub
		super.onTerminate();
		Log.d("MainApplication", "onTerminate");
	}

}