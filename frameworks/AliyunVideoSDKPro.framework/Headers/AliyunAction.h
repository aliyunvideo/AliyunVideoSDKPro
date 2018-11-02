//
//  AliyunAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunJSONModel.h"


#define ALIYUN_ADD_ACTION_NOTI @"kNotificationAddAction"
#define ALIYUN_REMOVE_ACTION_NOTI @"kNotificationRemoveAction"

@interface AliyunAction : AliyunJSONModel


/**
  API_AVAILABLE(3.7.0)
 
 动画作用的目标节点，例如如果是视频流，则使用视频流的streamID, 如果是如动图一类的，使用effectId
 */
@property (nonatomic, assign) int targetID;//作用的节点ID 例如

/**
 API_AVAILABLE(3.7.0)
 
 必须注意设置
 是否是视频 ，如果是视频 必须是True 如果是其他的则为false
 */
@property (nonatomic, assign) BOOL isStream;//是否是视频


/**
 API_AVAILABLE(3.7.0)
 
 动画开始的时间
 */
@property (nonatomic, assign) float startTime;//开始时间


/**
 API_AVAILABLE(3.7.0)
 
 动画持续的时间
 */
@property (nonatomic, assign) float duration;//持续时间

- (void)setActionID:(int)actionId;
- (int)actionID;

@end
