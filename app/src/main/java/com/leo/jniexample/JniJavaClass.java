package com.leo.jniexample;

/**
 * Created by Leo on 2016/8/2.
 */

public class JniJavaClass {
    static {
        System.loadLibrary("hellojni");
    }

    public static native int calculate(int x);
}
