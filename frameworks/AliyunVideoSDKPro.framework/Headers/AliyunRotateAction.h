//
//  AliyunRotateAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"

@interface AliyunRotateAction : AliyunAction

@property (nonatomic, assign) bool clockwise;//true:顺时针 false:逆时针
@property (nonatomic, assign) float fromDegree;//开始旋转时的弧度 （注意：统一为弧度）

- (id)initWithRestore:(NSDictionary *)dict;

@end
