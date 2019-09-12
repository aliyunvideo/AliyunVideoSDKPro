//
//  AliyunCanvasView.h
//  QUSDK
//
//  Created by TripleL on 17/6/7.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunIPaint.h"
#import <UIKit/UIKit.h>

@protocol AliyunICanvasViewDelegate <NSObject>

/**
 开始画图

 @param startPoint 开始point
 */
/****
 Starts drawing.
 
 @param startPoint The start point.
 */
- (void)startDrawingWithCurrentPoint:(CGPoint)startPoint;

/**
 结束画图

 @param endPoint 结束point
 */
/****
 Ends drawing.
 
 @param endPoint The end point.
 */
- (void)endDrawingWithCurrentPoint:(CGPoint)endPoint;
@end

/**
 画布view
 */
/****
 The canvas view.
 */
@interface AliyunICanvasView : UIView

/**
 回调
 */
/****
 The callback.
 */
@property (nonatomic, weak) id<AliyunICanvasViewDelegate> delegate;

/**
 是否允许越界画图，默认不允许
 */
/****
 Whether the drawing can go beyond the border. Default is NO. 
 */
@property (nonatomic, assign) BOOL enableCrossBorder;

/**
 画笔
 */
/****
 The paint brush.
 */
@property (nonatomic, strong) AliyunIPaint *paint;

/**
 初始化方法

 @param frame 画板frame
 @param paint 画笔
 @return self
 */
/****
 Initializer.

 @param frame The canvas frame.
 @param paint The paint brush.
 @return self
 */
- (instancetype)initWithFrame:(CGRect)frame
                        paint:(AliyunIPaint *)paint;


/**
 更改画笔配置

 @param paint 画笔
 */
/****
 Changes the paint brush.

 @param paint The paint brush.
 */
- (void)changePaint:(AliyunIPaint *)paint;

/**
 清空所有线条(不可恢复)
 */
/****
 Clears the canvas. This operation is irreversible.
 */
- (void)remove;

/**
 撤销上一步
 */
/****
 Undoes the last stroke.
 */
- (void)undo;

/**
 恢复上一步
 */
/****
 Redoes the last stroke.
 */
- (void)redo;

/**
 撤销本次涂鸦所有的操作
 */
/****
 Undoes all strokes.
 */
- (void)undoAllChanges;

/**
 完成

 @return 涂鸦图片
 */
/****
 Completes the drawing.

 @return The doodle image.
 */
- (UIImage *)complete;

@end
