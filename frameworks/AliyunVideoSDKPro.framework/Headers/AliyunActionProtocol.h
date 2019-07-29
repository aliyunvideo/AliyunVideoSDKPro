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
@protocol AliyunActionProtocol <NSObject>

/**
 添加动画

 @param action 动画
 */
- (void)addAction:(AliyunAction *)action;

/**
 移除动画

 @param action 动画
 */
- (void)removeAction:(AliyunAction *)action;

/**
 获取动画id，一个id对应具体的某个动画

 @return 动画id
 */
- (int)getNodeID;

/**
 是否是视频流

 @return BOOL值
 */
- (BOOL)isVideoStream;

@end

#endif /* AliyunActionProtocol_h */
