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
@interface AliyunCustomAction : AliyunAction

/**
 自定义动画的片元着色器代码
 */
@property(nonatomic, copy) NSString *fragmentShader;

/**
 片元着色器的参数设置：为字典结构
 */
@property(nonatomic, strong) NSDictionary *customUniformsMapper;

/**
 初始化方法

 @param dict 初始化参数
 @return 自定义动画实例
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
