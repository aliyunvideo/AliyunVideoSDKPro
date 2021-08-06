//
//  AliyunWipeAction.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/6/23.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunAction.h"

/**
 线性擦除方向
 */
/**
 The Direction of wipe action
 */
typedef NS_ENUM(NSUInteger, AliWipeActionDirection) {
    AliWipeActionDirection_LeftToRight = 0,
    AliWipeActionDirection_UpToDown    = 1,
    AliWipeActionDirection_RightToLeft = 2,
    AliWipeActionDirection_DownToUp    = 3,
};

/**
 擦除模式
 */
/**
 The mode of wipe action
 */
typedef NS_ENUM(NSUInteger, AliWipeActionMode) {
    AliWipeActionMode_Appear       = 0,
    AliWipeActionMode_Disappear    = 1,
};

/**
 线性擦除动画
 */
/**
 The action of wip
 */
@interface AliyunWipeAction : AliyunAction

/**
 擦除模式
 */
/**
 The mode of wipe action
 */
@property (nonatomic, assign) AliWipeActionMode wipeMode;

/**
 线性擦除方向
 */
/**
 The Direction of wipe action
 */
@property (nonatomic, assign) AliWipeActionDirection direction;
@end
