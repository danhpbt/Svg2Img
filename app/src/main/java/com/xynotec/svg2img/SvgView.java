package com.xynotec.svg2img;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

/**
 * Created by Danh Phan on 6/12/2017.
 */

public class SvgView extends View {

    protected Bitmap bmpBuffer = null;
    Paint paint = new Paint();

    static native void testAgg2D(int[] intData, int width, int height);

    public SvgView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        // TODO Auto-generated constructor stub
    }

    public SvgView(Context context, AttributeSet attrs) {
        super(context, attrs);
        // TODO Auto-generated constructor stub
    }

    public SvgView(Context context) {
        super(context);
        // TODO Auto-generated constructor stub
    }

    @Override
    protected void onDraw(Canvas canvas) {
        // TODO Auto-generated method stub
        canvas.drawBitmap(bmpBuffer, 0, 0, paint);

    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        // TODO Auto-generated method stub
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);

        int width = MeasureSpec.getSize(widthMeasureSpec);
        int height = MeasureSpec.getSize(heightMeasureSpec);

        bmpBuffer = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
    }

    public void TestAgg2D()
    {
        int width = bmpBuffer.getWidth();
        int height = bmpBuffer.getHeight();
        int[] data = new int[width * height];
        //bmpBuffer.getPixels(data, 0, width, 0, 0, width, height);

        testAgg2D(data, width, height);

        bmpBuffer.setPixels(data, 0, width, 0, 0, width, height);

        invalidate();
    }
}
