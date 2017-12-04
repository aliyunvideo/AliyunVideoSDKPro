//
//  AliyunEffectPasterTimeItem.h
//  QUSDK
//
//  Created by Vienta on 2017/5/8.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface AliyunEffectPasterTimeItem : NSObject

@property (nonatomic, assign) CGFloat beginTime;
@property (nonatomic, assign) CGFloat endTime;
@property (nonatomic, assign) BOOL shrink;
@property (nonatomic, assign) CGFloat minTime;
@property (nonatomic, assign) CGFloat maxTime;

@end
