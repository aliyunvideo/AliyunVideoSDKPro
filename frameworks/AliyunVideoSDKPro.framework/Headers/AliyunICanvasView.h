//
//  AliyunCanvasView.h
//  QUSDK
//
//  Created by TripleL on 17/6/7.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AliyunIPaint.h"

@protocol AliyunICanvasViewDelegate <NSObject>

/**
 开始画图
 
 @param startPoint 开始point
 */
- (void)startDrawingWithCurrentPoint:(CGPoint)startPoint;


/**
 结束画图
 
 @param endPoint 结束point
 */
- (void)endDrawingWithCurrentPoint:(CGPoint)endPoint;
@end

@interface AliyunICanvasView : UIView


/**
 回调
 */
@property (nonatomic, weak) id<AliyunICanvasViewDelegate> delegate;


/**
 是否允许越界画图，默认不允许
 */
@property (nonatomic, assign) BOOL enableCrossBorder;



/**
 画笔
 */
@property (nonatomic, strong) AliyunIPaint *paint;



/**
 init

 @param frame 画板frame
 @param paint 画笔
 @return self
 */
- (instancetype)initWithFrame:(CGRect)frame
                        paint:(AliyunIPaint *)paint;



/**
 更改画笔配置

 @param paint 画笔
 */
- (void)changePaint:(AliyunIPaint *)paint;



/**
 清空所有线条(不可恢复)
 */
- (void)remove;


/**
 撤销上一步
 */
- (void)undo;


/**
 恢复上一步
 */
- (void)redo;



/**
 完成

 @return 涂鸦图片
 */
- (UIImage *)complete;

@end
