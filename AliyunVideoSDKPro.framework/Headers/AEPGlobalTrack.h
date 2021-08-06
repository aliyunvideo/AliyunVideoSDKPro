//
//  AEPGlobalTrack.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPTrack.h"
#import "AliyunEffectImage.h"

@interface AEPGlobalTrack : AEPTrack
@end

@class AliyunICanvasLineData;
/**
 涂鸦图片
 */
/**
 The Image of paint
 */
@interface AEPGlobalPaintTrack : AEPGlobalTrack

/**
 涂鸦图片资源
 */
/**
 The resoruce of paint
 */
@property (nonatomic, strong, readonly) AEPSource *source;

/**
 涂鸦归一化位置
 */
/**
 The normalized center
 */
@property (nonatomic, assign, readonly) CGPoint normalizedCenter;
/**
 涂鸦归一化大小
 */
/**
 The normlized size
 */
@property (nonatomic, assign, readonly) CGSize normalizedSize;

/**
 涂鸦线数据
 */
/**
 The data of lines
 */
@property (nonatomic, strong, readonly) NSArray<AliyunICanvasLineData *> *linesData;

/**
 编辑中使用的涂鸦对象
 */
/**
 The paint obj for editor
 */
@property (nonatomic, strong, readonly) AliyunEffectImage *editorPaint;

@end

/**
 水印
 */
/**
 The watermark
 */
@interface AEPGlobalWatermarkTrack : AEPGlobalTrack

/**
 水印图片资源
 */
/**
 The resource of watermark
 */
@property (nonatomic, strong, readonly) AEPSource *source;

/**
 水印归一化位置
 */
/**
 The normalized center
 */
@property (nonatomic, assign, readonly) CGPoint normalizedCenter;
/**
 水印归一化大小
 */
/**
 The normlized size
 */
@property (nonatomic, assign, readonly) CGSize normalizedSize;

/**
 动画列表
 */
/**
 The list of action
 */
@property (nonatomic, copy, readonly) NSArray<AEPAction *> *actions;

/**
 编辑器中使用的水印对象
 */
/**
 The watermark obj for editor
 */
@property (nonatomic, strong, readonly) AliyunEffectImage *editorWatermark;

@end

/**
 尾部水印
 */
/**
 The tail water
 */
@interface AEPGlobalTailWatermarkTrack : AEPGlobalWatermarkTrack

/**
 持续时间
 */
/**
 The Duration
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

@end
