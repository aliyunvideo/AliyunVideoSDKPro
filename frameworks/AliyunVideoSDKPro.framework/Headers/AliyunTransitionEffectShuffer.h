//
//  AliyunTransitionEffectShuffer.h
//  QUSDK
//
//  Created by Vienta on 2018/5/31.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunTransitionEffect.h"
#import <AliyunVideoSDKPro/AliyunVideoSDKPro.h>
/**
 平移方向

 ORIENTATION_HORIZONTAL:横向
 ORIENTATION_VERTICAL:纵向
 */
/****
 The direction that the blinds open and close.
 
 ORIENTATION_HORIZONTAL: Horizontal
 ORIENTATION_VERTICAL: Vertical
 */
typedef NS_ENUM(NSInteger, ORIENTATION_TYPE) {
    ORIENTATION_HORIZONTAL = 0,
    ORIENTATION_VERTICAL,
};

/**
 百叶窗效果的转场
 */
/****
 A class that defines blinds transitions.
 */
@interface AliyunTransitionEffectShuffer : AliyunTransitionEffect

/**
 平移方向属性
 */
/****
 The direction that the blinds open and close.
 */
@property(nonatomic, assign) ORIENTATION_TYPE orientation;

/**
 百叶窗叶片宽度 范围是0.0-1.0
 */
/****
 The width of each blind. Valid values: [0.0, 1.0] 
 */
@property(nonatomic, assign) float lineWidth;

/**
 初始化方法

 @param dict 初始化参数
 @return 百叶窗实例对象
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return A blinds transition object.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
