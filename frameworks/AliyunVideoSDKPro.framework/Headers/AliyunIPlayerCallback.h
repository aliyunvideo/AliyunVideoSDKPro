//
//  AliyunIPlayerCallback.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/15.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AliyunIPlayerCallback <NSObject>

/**
 开始播放
 */
- (void)playerDidStart;

/**
 播放结束
 */
- (void)playerDidEnd;


/**
 seek结束
 */
- (void)seekDidEnd;


/**
 播放进度

 @param sec 单位：s
 */
- (void)playProgress:(double)sec;


/**
 播放异常

 @param errorCode 错误码
 */
- (void)playError:(int)errorCode;

@end

@protocol AliyunIRenderCallback <NSObject>

@optional

/**
 自定义渲染接口
 
 @param srcTexture 原始视频帧纹理id
 @param size 原始视频帧纹理size
 @return 返回纹理id
 */
- (int)customRender:(int)srcTexture size:(CGSize)size;

@end
