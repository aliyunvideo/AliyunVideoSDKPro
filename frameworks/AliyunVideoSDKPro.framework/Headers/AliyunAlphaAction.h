//
//  AliyunAlphaAction.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/6/4.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//


#import "AliyunAction.h"

/**
 透明度动画

 注意：不支持主流添加此动画
 */
/****
 A class that defines alpha animations.
 
 Note: Alpha animations cannot be applied to source streams.
 */
@interface AliyunAlphaAction : AliyunAction

/**
 起始透明度
 */
/****
 The initial alpha.
 */
@property(nonatomic, assign) float fromAlpha;

/**
 终点透明度
 */
/****
 The target alpha.
 */
@property(nonatomic, assign) float toAlpha;

/**
 初始化方法

 @param dict 初始化参数
 @return 透明度动画实例
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return An alpha animation object.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
