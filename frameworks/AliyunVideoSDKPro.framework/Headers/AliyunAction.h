//
//  AliyunAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunJSONModel.h"
#import <Foundation/Foundation.h>

#define ALIYUN_ADD_ACTION_NOTI @"kNotificationAddAction"
#define ALIYUN_REMOVE_ACTION_NOTI @"kNotificationRemoveAction"

/**
 动画基类
 */
/****
 A base animation class.
 */
@interface AliyunAction : AliyunJSONModel

/**
  API_AVAILABLE(3.7.0)

 动画作用的目标节点，例如如果是视频流，则使用视频流的streamID, 如果是如动图一类的，使用effectId
 */
/****
  API_AVAILABLE(3.7.0)
 
 The id of the object on which this animation is performed. If the target object is a video stream, use streamID.
 If the target object is a sticker, use effectId. 
 */
@property (nonatomic, assign) int targetID;


/**
 API_AVAILABLE(3.7.0)

 必须注意设置
 是否是视频 ，如果是视频 必须是True 如果是其他的则为false
 */
/****
 API_AVAILABLE(3.7.0)
 
 Must be set to true if the target object is a video. Otherwise, set to false. 
 */
@property (nonatomic, assign) BOOL isStream;


/**
 API_AVAILABLE(3.7.0)

 动画开始的时间
 */
/****
 API_AVAILABLE(3.7.0)
 
 The start time of this animation.
 */
@property (nonatomic, assign) float startTime;


/**
 API_AVAILABLE(3.7.0)

 动画持续的时间
 */
/****
 API_AVAILABLE(3.7.0)
 
 The duration of this animation.
 */
@property (nonatomic, assign) float duration;

/**
 设置动画id 此id由底层分配

 @param actionId 动画id
 */
/****
 Sets the id of this animation. This id is assigned by the system.

 @param actionId The animation id.
 */
- (void)setActionID:(int)actionId;

/**
 获取动画id

 @return 动画id
 */
/****
 Gets the id of this animation.

 @return The animation id.
 */
- (int)actionID;

@end
