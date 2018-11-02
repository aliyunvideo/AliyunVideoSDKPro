//
//  AliyunTransitionEffectPolygon.h
//  QUSDK
//
//  Created by Vienta on 2018/5/31.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import <AliyunVideoSDKPro/AliyunVideoSDKPro.h>
#import "AliyunTransitionEffect.h"

@interface AliyunTransitionEffectPolygon : AliyunTransitionEffect

@property (nonatomic, assign) int n;//几边形

- (id)initWithRestore:(NSDictionary *)dict;

@end
