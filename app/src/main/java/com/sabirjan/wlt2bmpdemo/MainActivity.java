package com.sabirjan.wlt2bmpdemo;

import android.app.Activity;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.sabirjan.reader.tools.Tool;

/**
 * 
 * @author Administrator
 *  wlt的图片解码库不支持64位的手机，如果放到64位手机上，解出来的图片可能是黑乎乎的
 */
public class MainActivity extends Activity {
	ImageView image;
	String TAG = "MainActivity";

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		initView();
	}

	public void initView() {
		image = (ImageView) findViewById(R.id.image);
	}

	//点击转换
	public void convert(View view) {
		Log.e(TAG, "------------------convert(View view)");
		Bitmap  ret2 = Tool.getBitmap(TempGlobal.GetWLTData());//获取模拟的身份证图片数据
		if (ret2 !=null) {
			image.setImageBitmap(ret2);
		} else {
			Toast.makeText(this, "解码图片失败！", Toast.LENGTH_SHORT).show();
		}
	}


}
