package com.mygrabcut.mygrabcut;

/**
 * Created by Administrator on 2018/1/25 0025.
 */

public class NativeGrabCut {
    static {
        System.loadLibrary("grabcut");
    }
    public native long grabCutFromJNI(long m,int l,int t,int r,int b);
}
