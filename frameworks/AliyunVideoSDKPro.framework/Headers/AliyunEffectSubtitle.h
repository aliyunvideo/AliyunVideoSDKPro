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
 纯文字
 */
@interface AliyunEffectSubtitle : AliyunEffectPasterBase

@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *fontName;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, assign) BOOL isStroke;
@property (nonatomic, strong) UIColor *textLabelColor;
@property (nonatomic, assign) BOOL hasTextLabel;

- (id)initWithRestore:(NSDictionary *)dict;

@end
