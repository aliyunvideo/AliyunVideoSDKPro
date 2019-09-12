//
//  AliyunEffectCaption.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffectPasterBase.h"
#import "AliyunEffectPasterFrameItem.h"
#import "AliyunEffectPasterTimeItem.h"
#import <UIKit/UIKit.h>
/**
 既有动图序列帧又有文字的字幕model类
 */
/****
 A model class that defines animated captions. Each animated caption contains a piece of text and a background sticker.
 */
@interface AliyunEffectCaption : AliyunEffectPasterBase

/**
 文字内容
 */
/****
 The text contents.
 */
@property(nonatomic, copy) NSString *text;

/**
 用户配置的字体名称

 默认值从动图配置文件解析而来
 */
/****
 The name of the user-configured text font.
 
 Default is the font name specified in the configuration file.  
 */
@property(nonatomic, copy) NSString *captionFontName;

/**
 用户配置的字体id

 默认值从动图配置文件解析而来
 */
/****
 The id of the user-configured text font.
 
 Default is the font id specified in the configuration file.  
 */
@property(nonatomic, assign) NSInteger captionFontId;

/**
 文字开始出现的时间

 参考坐标系为动图本身
 例如:textRelativeToBeginTime=2,代表动图第一帧开始出现后的第2秒文字才开始出现
 */
/****
 The time when the text appears.
 
 The time is relative to the time when the background sticker appears.
 For example, textRelativeToBeginTime=2 indicates that the text appears two seconds later than the background sticker. 
 */
@property(nonatomic, assign) CGFloat textRelativeToBeginTime;

/**
 文字消失的时间

 参考坐标系为动图本身
 */
/****
 The time when the text disappears.
 
 The time is relative to the time when the background sticker appears.
 */
@property(nonatomic, assign) CGFloat textRelativeToEndTime;

/**
 文字的位置大小

 参考坐标系为动图本身
 */
/****
 The size of the display area where the text is rendered.
 
 The size is relative to the size of the background sticker.
 */
@property(nonatomic, assign) CGRect textFrame;

/**
 文字的中心点位置

 参考坐标系为动图本身
 */
/****
 The position of the centroid of the text.
 
 The position of the centroid is relative to the position of the background sticker.
 */
@property(nonatomic, assign) CGPoint textCenter;

/**
 文字的大小

 参考坐标系为动图本身
 */
/****
 The text size.
 
 The text size is relative to the size of the background sticker.
 */
@property(nonatomic, assign) CGSize textSize;

/**
 关键帧图片
 */
/****
 The key frame image.
 */
@property(nonatomic, strong) UIImage *kernelImage;

/**
 文字是否描边
 */
/****
 Whether the text is stroked.
 */
@property(nonatomic, assign) BOOL textStroke;

/**
 文字颜色
 */
/****
 The text color.
 */
@property(nonatomic, strong) UIColor *textColor;

/**
 文字描边颜色
 */
/****
 The text stroke color.
 */
@property(nonatomic, strong) UIColor *textStrokeColor;

/**
 文字背景颜色
 */
/****
 The text background color.
 */
@property(nonatomic, strong) UIColor *textLabelColor;

/**
 字体名称
 */
/****
 The text font name.
 */
@property(nonatomic, copy) NSString *fontName;

/**
 字幕动图的场景集合

 字幕动图也可以分为进场、场中和出场
 */
/****
 The stages when rendering the animated caption.
 
 The stages include: appear, display, and disappear.
 */
@property(nonatomic, copy) NSArray<AliyunEffectPasterTimeItem *> *timeItems;

/**
 动画帧集合
 */
/****
 The frames of the animation.
 */
@property(nonatomic, copy) NSArray<AliyunEffectPasterFrameItem *> *frameItems;

/**
 字幕动图原始时长
 */
/****
 The original display duration of the animated caption. 
 */
@property(nonatomic, assign) CGFloat originDuration;

/**
 字幕动图中的文字原始持续时长
 */
/****
 The original display duration of the text in the animated caption. 
 */
@property(nonatomic, assign) CGFloat originTextDuration;

/**
 字幕动图中的文字原始的开始时间

 参考坐标系为动图本身
 */
/****
 The time when the text appears.
 
 The time is relative to the time when the background sticker appears.
 */
@property(nonatomic, assign) CGFloat originTextBeginTime;

- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
