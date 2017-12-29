//
//  AliyunPasterUIEventProtocol.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/9.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol AliyunPasterUIEventProtocol <NSObject>

/**
 贴图大小变化

 @param aBounds 贴图大小
 */
- (void)eventBoundsDidChanged:(CGRect)aBounds;

/**
 贴图位置变化

 @param aCenter 位置（锚点（0.5，0.5））
 */
- (void)eventCenterDidChanged:(CGPoint)aCenter;

/**
 贴图角度

 @param aRotate  弧度
 */
- (void)eventRotateDidChanged:(CGFloat)aRotate;

/**
 文字大小变化

 @param aBounds 文字大小
 */
- (void)eventTextBoundsDidChanged:(CGRect)aBounds;

/**
 文字位置变化

 @param aCenter 文字位置
 */
- (void)eventTextCenterDidChanged:(CGPoint)aCenter;

/**
 镜像变化

 @param isMirror 是否镜像
 */
- (void)eventMirrorChanged:(BOOL)isMirror;

/**
 贴图view是否关闭

 @param pasterView 贴图view
 */
- (void)eventPasterViewClosed:(UIView *)pasterView;

/**
 编辑完成
 */
- (void)eventEditDidEnd;

@end
