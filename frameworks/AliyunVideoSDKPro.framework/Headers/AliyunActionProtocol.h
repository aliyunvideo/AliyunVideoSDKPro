//
//  AliyunActionProtocol.h
//  QUSDK
//
//  Created by Vienta on 2018/5/29.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#ifndef AliyunActionProtocol_h
#define AliyunActionProtocol_h

#import "AliyunAction.h"

/**
 帧动画协议
 */
/****
 The protocol of animations.
 */
@protocol AliyunActionProtocol <NSObject>

/**
 添加动画

 @param action 动画
 */
/****
 Adds an animation.

 @param action The animation to be added.
 */
- (void)addAction:(AliyunAction *)action;

/**
 移除动画

 @param action 动画
 */
/****
 Removes an animation.

 @param action The animation to be removed.
 */
- (void)removeAction:(AliyunAction *)action;

/**
 获取动画id，一个id对应具体的某个动画

 @return 动画id
 */
/****
 Gets the id of an animation.

 @return The id of an animation.
 */
- (int)getNodeID;

/**
 是否是视频流

 @return BOOL值
 */
/****
 Gets whether an object is a video stream.

 @return BOOL 
 */
- (BOOL)isVideoStream;

@end

#endif /* AliyunActionProtocol_h */
