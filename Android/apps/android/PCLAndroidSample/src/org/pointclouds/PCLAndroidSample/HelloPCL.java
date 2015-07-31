package org.pointclouds.PCLAndroidSample;


import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;
import android.os.Environment;
import java.io.File;
import java.lang.Exception;
 
public class HelloPCL extends Activity {
	
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		
		TextView  tv = new TextView(this);
		int       x  = 1000;
		int       y  = 42;
		
		// here, we dynamically load the library at runtime
		// before calling the native method.
		//
		System.loadLibrary("helloPCLWorld");
	
		int z = 26;
		File path = Environment.getExternalStorageDirectory();
		File Fname = new File(path, "cloud2.pcd");
		try {
			tv.setText( "The sum of " + x + " and " + y + " is " + z + " and boost: " + new HelloPCL().boostMkDir(Fname.toString()));
		}
		catch(Exception e)
		{
			System.out.println(e.toString());
		}
		System.out.println();

		setContentView(tv);
	}	
	
	public native String boostMkDir (String dir);
	public native String smoothPointCloud ();
 }
