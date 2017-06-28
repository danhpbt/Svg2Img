package com.xynotec.util;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.Resources;
import android.graphics.Point;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.os.Build;
import android.provider.Settings;
import android.support.v7.app.AlertDialog;
import android.util.DisplayMetrics;
import android.util.Log;
import android.util.Size;
import android.view.Display;
import android.view.View;
import android.view.WindowManager;
import android.view.inputmethod.InputMethodManager;

import com.xynotec.svg2img.R;

public class Util
{
	public static float dp2px(Resources resources, float dp) {
		final float scale = resources.getDisplayMetrics().density;
		return  dp * scale + 0.5f;
	}

	public static float sp2px(Resources resources, float sp){
		final float scale = resources.getDisplayMetrics().scaledDensity;
		return sp * scale;
	}

	public static boolean DeleteFile(String strFilePath)
	{
		File file = new File(strFilePath);
		boolean bResult = false;
		try
		{
			bResult = file.delete();
		}
		catch (Exception ex)
		{
			bResult = false;
		}
		return bResult;
	}
	
	public static void DeleteFolder(String strFolderPath) 
	{
		File rootDir = new File(strFolderPath);
	    recursiveDelete(rootDir, true);
	}
	 
	public static void recursiveDelete(File rootDir, boolean deleteRoot) {
	    File[] childDirs = rootDir.listFiles();
	    for(int i = 0; i < childDirs.length; i++) {
	        if(childDirs[i].isFile()) {
	            childDirs[i].delete();
	        }
	        else {
	            recursiveDelete(childDirs[i], deleteRoot);
	            childDirs[i].delete();
	        }
	    }
	         
	    if(deleteRoot) {
	        rootDir.delete();
	    }
	}
	public static boolean WriteFile(String strFilePath, String strFileContents)
	{
		File file = new File(strFilePath);
		try
		{
			BufferedWriter bf = new BufferedWriter(new FileWriter(file, false));
			bf.write(strFileContents);
			bf.close();
			return true;
		}
		catch (Exception ex)
		{
			Log.d("Util - WriteFile", ex.getMessage());
			return false;
		}
	}
	
	public static String ReadFile(String strFilePath)
	{
		StringBuffer contents = new StringBuffer();
		File file = new File(strFilePath);
		try
		{
			BufferedReader bufferR = new BufferedReader(new FileReader(file));
			String text = null;
			while ((text = bufferR.readLine()) != null) 
			{
				contents.append(text);
				contents.append("\n");
				//contents.append(System.getProperty("line.separator"));
			}
			bufferR.close();			
		}
		catch (Exception ex)
		{
			Log.d("Util - ReadFile", ex.getMessage());			
		}
		finally
		{	
			if (contents.length() > 0)
				contents.deleteCharAt(contents.length() - 1);
			return contents.toString();
		}		
	}
	
	public static boolean WriteFileInternalStorage(Context context, String fileName, String strFileContents)
	{
		boolean bWrite = false;
		try
		{
			FileOutputStream fos = context.openFileOutput(fileName, Context.MODE_PRIVATE);
			OutputStreamWriter outWriter = new OutputStreamWriter(fos);
			outWriter.write(strFileContents);
			
			outWriter.close();	
			
			bWrite = true;
		}
		catch (Exception ex)
		{
			Log.d("Util - WriteFileInternalStorage", ex.getMessage());
		}
		finally
		{
			return bWrite;
		}		
	}
	
	public static String ReadFileInternalStorage(Context context, String fileName)
	{
		StringBuffer contents = new StringBuffer();
		try
		{
			FileInputStream fis = context.openFileInput(fileName);
			InputStreamReader iReader = new InputStreamReader(fis);
			BufferedReader bufferR = new BufferedReader(iReader);
			
			String text = null;
			while ((text = bufferR.readLine()) != null) 
			{
				contents.append(text);
				contents.append("\n");
			}
			bufferR.close();
		}
		catch (Exception ex)
		{
			Log.d("Util - ReadFileInternalStorage", ex.getMessage());
		}
		finally
		{
			//if (contents.length() > 0)
			//	contents.deleteCharAt(contents.length() - 1);
			return contents.toString();
		}		
	}
	
	public static boolean AppendFile(String strFilePath, String strFileContents)
	{
		File file = new File(strFilePath);
		try
		{
			BufferedWriter bf = new BufferedWriter(new FileWriter(file, true));
			bf.write(strFileContents);
			bf.close();
			return true;
		}
		catch (Exception ex)
		{
			Log.d("FileUtil - AppendFile", ex.getMessage());
			return false;
		}
	}
	
	public static String GetFirstMeanString(String mean)
	{
		int mean_length = mean.length();
		int pos0 = 0;
		int pos1 = 0;
		int pos2 = 0;
		int line = 0;
		String result = "";
		
		for(int i = 0; i < mean_length; i++)
		{
			char ch = mean.charAt(i);
			if (ch == '\n')
			{
				line++;
			
				if (line == 1)
					pos0 = i;
				else if (line == 2)
					pos1 = i;					
				else if (line == 3)
				{
					pos2 = i;
					break;
				}
			}
		}
		
		if (line == 2)
			result = mean.substring(pos0 + 1, pos1);
		else if (line == 3)
			result = mean.substring(pos1 + 1, pos2);

		return result;
	}
	
	
	// 2-byte number
	public static char ShortC2Java(int i)
	{
	    return (char)(((i>>8)&0xff)|((i << 8)&0xff00));
	}

	// 4-byte number
	public static int IntC2Java(int i)
	{
	    return((i&0xff)<<24)|((i&0xff00)<<8)|((i&0xff0000)>>8)|((i>>24)&0xff);
	}
	
	public static boolean hasDataConnection(Context context) 
	{
	    ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
	    NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
	    return activeNetworkInfo != null && activeNetworkInfo.isConnected() && activeNetworkInfo.isAvailable();
	}


	public static void hideEmulatorKeyboard(Activity activity)
	{
		if (activity != null) {
			InputMethodManager im = (InputMethodManager) activity.getSystemService(Activity.INPUT_METHOD_SERVICE);
			im.hideSoftInputFromWindow(activity.getCurrentFocus().getWindowToken(), 0);
		}
	}

	public static Point getDisplaySize(Context context)
	{
		Display display = ((WindowManager) context.getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
		DisplayMetrics displayMetrics = new DisplayMetrics();
		display.getMetrics(displayMetrics);

		int height = displayMetrics.heightPixels;
		int width = displayMetrics.widthPixels;

		Point screenSize = new Point(width, height);
		return screenSize;
	}

	public static void gotoAppSetting(Context context)
	{
		Intent intent = new Intent(Settings.ACTION_APPLICATION_DETAILS_SETTINGS);
		Uri uri = Uri.fromParts("package", context.getPackageName(), null);
		intent.setData(uri);
		intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
		intent.addFlags(Intent.FLAG_ACTIVITY_NO_HISTORY);
		intent.addFlags(Intent.FLAG_ACTIVITY_EXCLUDE_FROM_RECENTS);
		context.startActivity(intent);
	}

	public static void gotoDrawOverSetting(Context context)
	{
		// Check if Android M or higher
		if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.M){
			Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION);
			Uri uri = Uri.fromParts("package", context.getPackageName(), null);
			intent.setData(uri);
			context.startActivity(intent);
		}
	}

	public static byte[] loadResAssets(Context context, String resName)
	{
		byte[] file = null;
		try
		{
			InputStream inputStream = context.getAssets().open(resName);

			byte[] buffer = new byte[8192];
			int bytesRead;
			ByteArrayOutputStream output = new ByteArrayOutputStream();
			while ((bytesRead = inputStream.read(buffer)) != -1) {
				output.write(buffer, 0, bytesRead);
			}
			file = output.toByteArray();
		}
		finally {
			return file;
		}
	}

}
