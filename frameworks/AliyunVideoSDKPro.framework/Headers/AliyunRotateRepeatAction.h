//
//  AliyunRotateRepeatAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunRotateAction.h"

@interface AliyunRotateRepeatAction : AliyunRotateAction

@property(nonatomic, assign) float durationPerCircle;//旋转一圈需要的时间

- (id)initWithRestore:(NSDictionary *)dict;

@end
