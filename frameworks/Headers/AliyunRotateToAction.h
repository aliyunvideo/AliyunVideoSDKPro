//
//  AliyunRotateToAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunRotateAction.h"

/**
 旋转到某个角度类

 继承自AliyunRotateAction
 */
@interface AliyunRotateToAction : AliyunRotateAction

/**
 旋转到目标角度
 */
@property(nonatomic, assign) float toDegree;

/**
 初始化方法

 @param dict 初始化参数
 @return 旋转实例对象
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
