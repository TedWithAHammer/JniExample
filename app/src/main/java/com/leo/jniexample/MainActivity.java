package com.leo.jniexample;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

    private TextView tip;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tip = (TextView) findViewById(R.id.tip);
        tip.setText("result" + JniJavaClass.calculate(30));
    }
}
