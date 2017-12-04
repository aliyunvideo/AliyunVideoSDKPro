//
//  AliyunEffectCaption.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffectPasterBase.h"
#import <UIKit/UIKit.h>
#import "AliyunEffectPasterTimeItem.h"
#import "AliyunEffectPasterFrameItem.h"
/**
 既有动图序列帧又有文字
 */
@interface AliyunEffectCaption : AliyunEffectPasterBase

@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *captionFontName;//用户后台配置的字体名称
@property (nonatomic, assign) NSInteger captionFontId;//用户后台配置的字体id
@property (nonatomic, assign) CGFloat textRelativeToBeginTime;//文字开始出现的时间 相对于动图本身坐标系
@property (nonatomic, assign) CGFloat textRelativeToEndTime;//文字消失的时间 相对于动图本身坐标系
@property (nonatomic, assign) CGRect textFrame;//文字的位置大小 相对于动图本身坐标
@property (nonatomic, assign) CGPoint textCenter;//文字的中心点位置 相对于动图本身坐标
@property (nonatomic, assign) CGSize textSize;//文字的大小 相对于动图本身坐标
@property (nonatomic, strong) UIImage *kernelImage;//关键帧图片
@property (nonatomic, assign) BOOL textStroke;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *textStrokeColor;
@property (nonatomic, copy) NSString *fontName;//字体名称

@property (nonatomic, copy) NSArray<AliyunEffectPasterTimeItem *> *timeItems;
@property (nonatomic, copy) NSArray<AliyunEffectPasterFrameItem *> *frameItems;
@property (nonatomic, assign) CGFloat originDuration;//原始时长
@property (nonatomic, assign) CGFloat originTextDuration;//文字原始时长
@property (nonatomic, assign) CGFloat originTextBeginTime;//文字原始开始时间 相对于动图
//@property (nonatomic, assign) AliyunPasterType type;

- (id)initWithRestore:(NSDictionary *)dict;


@end
