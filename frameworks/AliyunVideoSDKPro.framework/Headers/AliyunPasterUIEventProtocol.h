//
//  AliyunPasterUIEventProtocol.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/9.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 动图UI事件回调协议
 */
/****
 The protocol of sticker callbacks on UI events.
 */
@protocol AliyunPasterUIEventProtocol <NSObject>

/**
 贴图大小变化

 @param aBounds 贴图大小
 */
/****
 The callback when the size of the sticker is changed.

 @param aBounds 贴图大小
 */
- (void)eventBoundsDidChanged:(CGRect)aBounds;

/**
 贴图位置变化

 @param aCenter 位置（锚点（0.5，0.5））
 */
/****
 The callback when the position of the sticker is changed.

 @param aCenter The position of the sticker. The anchor point is (0.5, 0.5).
 */
- (void)eventCenterDidChanged:(CGPoint)aCenter;

/**
 贴图角度

 @param aRotate  弧度
 */
/****
 The callback when the angle of the sticker is changed.

 @param aRotate The angle of the sticker in radians. 
 */
- (void)eventRotateDidChanged:(CGFloat)aRotate;

/**
 文字大小变化

 @param aBounds 文字大小
 */
/****
 The callback when the size of the text is changed.

 @param aBounds The text size.
 */
- (void)eventTextBoundsDidChanged:(CGRect)aBounds;

/**
 文字位置变化

 @param aCenter 文字位置
 */
/****
 The callback when the position of the text is changed.

 @param aCenter The text position.
 */
- (void)eventTextCenterDidChanged:(CGPoint)aCenter;

/**
 镜像变化

 @param isMirror 是否镜像
 */
/****
 The callback when the flip setting is changed.

 @param isMirror Whether to flip the sticker.
 */
- (void)eventMirrorChanged:(BOOL)isMirror;

/**
 贴图view是否关闭

 @param pasterView 贴图view
 */
/****
 The callback when the view that contains the sticker is changed.

 @param pasterView The view that contains the sticker.
 */
- (void)eventPasterViewClosed:(UIView *)pasterView;

/**
 编辑完成
 */
/****
 The callback when editing is complete.
 */
- (void)eventEditDidEnd;

@end
