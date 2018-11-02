//
//  AliyunTransitionEffectTranslate.h
//  QUSDK
//
//  Created by Vienta on 2018/5/31.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import <AliyunVideoSDKPro/AliyunVideoSDKPro.h>
#import "AliyunTransitionEffect.h"

typedef enum : NSUInteger {
    DIRECTION_LEFT = 0,
    DIRECTION_RIGHT = 1,
    DIRECTION_TOP = 2,
    DIRECTION_BOTTOM
} DIRECTION_TYPE;//移动方向

@interface AliyunTransitionEffectTranslate : AliyunTransitionEffect

@property (nonatomic, assign) DIRECTION_TYPE direction;

- (id)initWithRestore:(NSDictionary *)dict;

@end
