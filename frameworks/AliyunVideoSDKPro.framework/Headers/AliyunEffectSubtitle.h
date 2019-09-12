//
//  AliyunEffectSubtitle.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffectPasterBase.h"
#import <UIKit/UIKit.h>

/**
 纯文字model类
 */
/****
 A model class that defines standard captions. A standard caption contains a piece of text.
 */
@interface AliyunEffectSubtitle : AliyunEffectPasterBase

/**
 文字
 */
/****
 The text contents.
 */
@property(nonatomic, copy) NSString *text;

/**
 字体
 */
/****
 The text font.
 */
@property(nonatomic, copy) NSString *fontName;

/**
 文字颜色
 */
/****
 The text color.
 */
@property(nonatomic, strong) UIColor *textColor;

/**
 描边颜色
 */
/****
 The text stroke color.
 */
@property(nonatomic, strong) UIColor *strokeColor;

/**
 是否描边
 */
/****
 Whether the text is stroked.
 */
@property(nonatomic, assign) BOOL isStroke;

/**
 文字背景颜色
 */
/****
 The text background color.
 */
@property(nonatomic, strong) UIColor *textLabelColor;

/**
 是否有文字背景色
 */
/****
 Whether the text has a background color.
 */
@property(nonatomic, assign) BOOL hasTextLabel;

- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
