//
//  AliyunScaleAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"

@interface AliyunScaleAction : AliyunAction

@property (nonatomic, assign) float fromScale;//开始缩放时的缩放比例
@property (nonatomic, assign) float toScale;  //目标的缩放比例

- (id)initWithRestore:(NSDictionary *)dict;

@end
