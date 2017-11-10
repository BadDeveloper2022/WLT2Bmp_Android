package com.sabirjan.reader.tools;

/**
 * Created by Sabirjan on 2017/11/6.
 * Wlt2BmpDemo1.
 *  新疆精灵通电子科技有限公司
 */

import android.graphics.Bitmap;
import android.util.Log;

public class Tool
{
    public static Bitmap getBitmap(byte []data) {
        byte[] arrayOfByte1 = new byte[40960];
        try {
            if(data==null) return null;
            int k = new WltDecodeUtil().Wlt2Bmp(data, arrayOfByte1);

            Log.i("解码", "getBitmap: 解码结果:"+k);
            if (k != 1) {
                return null;
            }
            byte[] arrayOfByte2 = new byte[38556];
            System.arraycopy(arrayOfByte1, 0, arrayOfByte2, 0, 38556);

            return Tool.createRgbBitmap(arrayOfByte2, 102, 126);


        } catch (Exception localException) {
            localException.printStackTrace();
        }
        return null;
    }
    private static int convertByteToInt(byte paramByte)
    {
        int i = paramByte >> 4 & 0xF;
        int j = 0xF & paramByte;
        return i * 16 + j;
    }

    private static int[] convertByteToColor(byte[] paramArrayOfByte, int paramInt1, int paramInt2)
    {
        int i = paramArrayOfByte.length;
        if (i == 0) {
            return null;
        }
        int[] arrayOfInt = new int[i / 3];
        for (int n = 0; n < paramInt2; n++)
        {
            int i1 = n * paramInt1;
            for (int i2 = 0; i2 < paramInt1; i2++)
            {
                int i3 = (i1 + i2) * 3;
                int j = convertByteToInt(paramArrayOfByte[i3]);
                int k = convertByteToInt(paramArrayOfByte[(i3 + 1)]);
                int m = convertByteToInt(paramArrayOfByte[(i3 + 2)]);
                arrayOfInt[((paramInt2 - n - 1) * paramInt1 + i2)] = (j << 16 | k << 8 | m | 0xFF000000);
            }
        }
        return arrayOfInt;
    }

    private static Bitmap createRgbBitmap(byte[] paramArrayOfByte, int paramInt1, int paramInt2)
    {
        int[] arrayOfInt = convertByteToColor(paramArrayOfByte, paramInt1, paramInt2);
        if (arrayOfInt == null) {
            return null;
        }
        Bitmap localBitmap = Bitmap.createBitmap(arrayOfInt, 0, paramInt1, paramInt1, paramInt2, Bitmap.Config.ARGB_8888);
        return localBitmap;
    }
}