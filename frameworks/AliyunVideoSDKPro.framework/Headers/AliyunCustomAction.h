//
//  AliyunCustomAction.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/6/19.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"

/**
 自定义动画
 */
/****
 A class that defines custom animations.
 */
@interface AliyunCustomAction : AliyunAction

/**
 自定义动画的片元着色器代码
 */
/****
 The fragment shader of this custom animation. 
 */
@property(nonatomic, copy) NSString *fragmentShader;

/**
 片元着色器的参数设置：为字典结构
 */
/****
 The parameters of the fragment shader.
 */
@property(nonatomic, strong) NSDictionary *customUniformsMapper;

/**
 初始化方法

 @param dict 初始化参数
 @return 自定义动画实例
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return A custom animation object.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
