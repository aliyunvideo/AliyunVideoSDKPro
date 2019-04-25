//
//  AliyunEffectPasterBase.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"
#import "AliyunActionProtocol.h"
#import "AliyunEffect.h"
#import <CoreGraphics/CoreGraphics.h>

static const double kQUSDKPasterBase = 640.f;

struct PasterPosition {
    double centerX;
    double centerY;
    double width;
    double height;
};
typedef struct PasterPosition PasterPosition;

/**
 所有动图 字幕的基类
 */
@interface AliyunEffectPasterBase : AliyunEffect <AliyunActionProtocol>

@property(nonatomic, assign) CGFloat startTime;   //开始时间
@property(nonatomic, assign) CGFloat endTime;     //结束时间
@property(nonatomic, assign) CGFloat minDuration; //最短时间
@property(nonatomic, assign) CGFloat rotate;      //旋转角度
@property(nonatomic, assign) CGSize displaySize;  // editzoneview
@property(nonatomic, assign) CGSize outputSize;   //动图所在的视频的输入分辨率
@property(nonatomic, assign) CGRect frame;        //位置大小
@property(nonatomic, assign) CGPoint position;    //位置
@property(nonatomic, assign) CGSize size;         //大小
@property(nonatomic, assign) double width;
@property(nonatomic, assign) double height;
@property(nonatomic, assign) BOOL mirror;

- (id)initWithDict:(NSDictionary *)dict;

- (PasterPosition)convertToPasterBaseSize;

/**
   API_AVAILABLE(3.7.0)

 @return 返回相对位置
 */
- (PasterPosition)convertToRatioPasterSize;

- (PasterPosition)convertToDisplaySize;

/**
 API_AVAILABLE(3.7.0)

 @return 返回相对位置
 */
- (PasterPosition)convertToRatioDisplaySize;

- (NSMutableArray *)convertActions;

- (void)convertFromJsonActions:(NSArray *)jsonActions;

/**
 API_AVAILABLE(3.7.0)

 添加动画 注意：在倒播特效下，不支持此功能

 @param action 动画
 */
- (void)runAction:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 停止动画

 @param action 动画
 */
- (void)stopAction:(AliyunAction *)action;

- (void)stopAllActions;

- (NSArray *)allActions;

@end
