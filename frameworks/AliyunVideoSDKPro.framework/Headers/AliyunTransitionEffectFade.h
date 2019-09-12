//
//  AliyunTransitionEffectFade.h
//  QUSDK
//
//  Created by Vienta on 2018/5/31.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunTransitionEffect.h"

/**
 淡入淡出转场
 */
/****
 A class that defines fade transitions.
 */
@interface AliyunTransitionEffectFade : AliyunTransitionEffect

/**
 初始化方法

 @param dict 初始化参数
 @return 淡入淡出转场实例
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return A fade transition object.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
