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
@interface AliyunAction : AliyunJSONModel

/**
  API_AVAILABLE(3.7.0)

 动画作用的目标节点，例如如果是视频流，则使用视频流的streamID, 如果是如动图一类的，使用effectId
 */
@property (nonatomic, assign) int targetID;


/**
 API_AVAILABLE(3.7.0)

 必须注意设置
 是否是视频 ，如果是视频 必须是True 如果是其他的则为false
 */
@property (nonatomic, assign) BOOL isStream;


/**
 API_AVAILABLE(3.7.0)

 动画开始的时间
 */
@property (nonatomic, assign) float startTime;


/**
 API_AVAILABLE(3.7.0)

 动画持续的时间
 */
@property (nonatomic, assign) float duration;

/**
 设置动画id 此id由底层分配

 @param actionId 动画id
 */
- (void)setActionID:(int)actionId;

/**
 获取动画id

 @return 动画id
 */
- (int)actionID;

@end
