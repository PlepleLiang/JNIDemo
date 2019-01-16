package com.wuzl.cmake;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    private Button mBtGetJniString;
    private Button mBtSetJniString;
    private TextView mTvShowJniString;
    private HelloWorldJNI mHelloWorldJni;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mBtGetJniString = findViewById(R.id.bt_get_jnistring);
        mBtSetJniString = findViewById(R.id.bt_set_jnistring);
        mBtGetJniString.setOnClickListener(this);
        mBtSetJniString.setOnClickListener(this);
        mTvShowJniString = findViewById(R.id.tv_show_jnistring);
        mHelloWorldJni = new HelloWorldJNI();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.bt_get_jnistring:
                String string = mHelloWorldJni.getString();
                mTvShowJniString.setText(string);
                break;
            case R.id.bt_set_jnistring:
                String helloWorld = mHelloWorldJni.setString("HelloWorld");
                mTvShowJniString.setText(helloWorld);
                break;
        }
    }
}
