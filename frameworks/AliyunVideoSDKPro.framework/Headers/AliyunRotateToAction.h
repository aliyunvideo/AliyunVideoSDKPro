//
//  AliyunRotateToAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunRotateAction.h"

//旋转到某个角度
@interface AliyunRotateToAction : AliyunRotateAction

@property (nonatomic, assign) float toDegree;//旋转到目标角度

- (id)initWithRestore:(NSDictionary *)dict;

@end
