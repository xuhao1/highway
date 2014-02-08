#!/usr/bin/python
import cv,os
for i in range(1000):
    k=i+1
    path='/Users/xuhao/Develop/modeling/highway/src/data/p'+str(k)+'.png'
    cv.ShowImage("play",cv.LoadImage(path) )
    cv.ResizeWindow("yqx",300,1000)
    if cv.WaitKey(30)!=0:
        continue
