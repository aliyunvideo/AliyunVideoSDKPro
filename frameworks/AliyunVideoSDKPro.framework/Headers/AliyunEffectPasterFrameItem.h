//
//  AliyunEffectPasterFrameItem.h
//  QUSDK
//
//  Created by Vienta on 2017/5/8.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

/**
 动图的动画帧类
 */
/****
 A class that defines the frames in a sticker.
 */
@interface AliyunEffectPasterFrameItem : NSObject

/**
 该帧的播放时间点
 */
/****
 The playback time of the frame.
 */
@property(nonatomic, assign) CGFloat time;

/**
 该帧的图片序列号
 */
/****
 The serial number of the frame image.
 */
@property(nonatomic, assign) int pic;

/**
 该帧的所使用的图片地址
 */
/****
 The path of the frame image.
 */
@property(nonatomic, copy) NSString *picPath;

@end
