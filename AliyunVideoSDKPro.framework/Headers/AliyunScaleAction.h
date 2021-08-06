//
//  AliyunScaleAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"
#import <UIKit/UIKit.h>

/**
 缩放动画类
 */
@interface AliyunScaleAction : AliyunAction

/**
 缩放的起始缩放比例
 */
@property(nonatomic, assign) float fromScale;

/**
 缩放的终点缩放比例
 */
@property(nonatomic, assign) float toScale;

/**
 是否启用缩放锚点，不开启则以物体自身中心点缩放，默认NO
 */
/**
 is enabled using anchor, if not, anchor on center of self; default: NO
 */
@property(nonatomic, assign) BOOL enabledAnchor;

/**
 锚点坐标，[0,1]，默认值: (0.5, 0.5)
 */
/**
 The Anchor. [0, 1], default: (0.5, 0.5)
 */
@property(nonatomic, assign) CGPoint anchor;

/**
 缩放锚点：参考缩放基准值，用于计算trans偏移，默认为1.0
 */
/**
 The Scale of anchor, using to calculate trans offset; default: 1.0
 */
@property(nonatomic, assign) CGFloat anchorBaseScale;

/**
 初始化方法

 @param dict 初始化参数
 @return 缩放动画实例
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
