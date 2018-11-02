//
//  AliyunRotateByAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunRotateAction.h"

@interface AliyunRotateByAction : AliyunRotateAction

@property (nonatomic, assign) float rotateDegree;//在开始角度的基础上再旋转多少弧度

- (id)initWithRestore:(NSDictionary *)dict;

@end
