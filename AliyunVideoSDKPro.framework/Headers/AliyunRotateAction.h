//
//  AliyunRotateAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"
#import <UIKit/UIKit.h>

/**
 旋转动画类
 */
@interface AliyunRotateAction : AliyunAction

/**
 旋转方向

 可以设置为顺时针或者逆时针
 true:顺时针
 false:逆时针
 */
@property(nonatomic, assign) bool clockwise;

/**
 开始旋转时的弧度

 单位：弧度
 */
@property(nonatomic, assign) float fromDegree;

/**
 旋转的中心点，取值[0,1]
 */
/**
 The center of rotate
 */
@property(nonatomic, assign) CGPoint normalizedCenter;

/**
 旋转中心点所在的坐标系统，默认为AliyunActionCoordinateSpace_Local
 */
/**
 The CoordinateSpace of Center Point
 */
@property(nonatomic, assign) AliyunActionCoordinateSpace coordinateSpace;

/**
 初始化方法

 @param dict 初始化参数
 @return 旋转动画实例对象
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
