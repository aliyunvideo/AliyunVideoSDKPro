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
@interface AliyunEffectSubtitle : AliyunEffectPasterBase

/**
 文字
 */
@property(nonatomic, copy) NSString *text;

/**
 字体
 */
@property(nonatomic, copy) NSString *fontName;

/**
 文字颜色
 */
@property(nonatomic, strong) UIColor *textColor;

/**
 描边颜色
 */
@property(nonatomic, strong) UIColor *strokeColor;

/**
 是否描边
 */
@property(nonatomic, assign) BOOL isStroke;

/**
 文字背景颜色
 */
@property(nonatomic, strong) UIColor *textLabelColor;

/**
 是否有文字背景色
 */
@property(nonatomic, assign) BOOL hasTextLabel;

- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
