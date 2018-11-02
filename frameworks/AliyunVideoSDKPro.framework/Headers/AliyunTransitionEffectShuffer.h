//
//  AliyunTransitionEffectShuffer.h
//  QUSDK
//
//  Created by Vienta on 2018/5/31.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import <AliyunVideoSDKPro/AliyunVideoSDKPro.h>
#import "AliyunTransitionEffect.h"

typedef enum : NSUInteger {
    ORIENTATION_HORIZONTAL = 0,
    ORIENTATION_VERTICAL,
} ORIENTATION_TYPE;

@interface AliyunTransitionEffectShuffer : AliyunTransitionEffect

@property (nonatomic, assign) ORIENTATION_TYPE orientation; //0 横向  1纵向
@property (nonatomic, assign) float lineWidth; //百叶窗转场 叶片宽度 0.0-1.0

- (id)initWithRestore:(NSDictionary *)dict;

@end
