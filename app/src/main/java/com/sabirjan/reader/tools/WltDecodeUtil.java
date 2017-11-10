package com.sabirjan.reader.tools;
/**
 * Created by Sabirjan on 2017/11/6.
 * WltDecodeUtil.
 *  新疆精灵通电子科技有限公司
 */
public class WltDecodeUtil {

	public native int Wlt2Bmp(byte[] wlt,byte[] bmp);
	static{
		System.loadLibrary("Wlt2Bmp");
	}
}
