//
//  AliyunRollCaptionItemStyle.h
//  AliyunVideoSDKPro
//
//  Created by mengyehao on 2021/2/26.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface AliyunRollCaptionItemStyle : NSObject

/**
 文字 API_AVAILABLE(3.20.0)
 */
@property(nonatomic, copy, readonly) NSString *text;

/**
 设置开始时间 API_AVAILABLE(3.20.0)
 
 单位：秒
 */
@property(nonatomic, assign, readonly) CGFloat startTime;

/**
 文字颜色, 默认白色 API_AVAILABLE(3.20.0)
 */
@property(nonatomic, strong) UIColor *textColor;

/**
 描边颜色, 默认nil API_AVAILABLE(3.20.0)
 */
@property(nonatomic, strong) UIColor *strokeColor;

/**
 字体，默认系统Helvetica API_AVAILABLE(3.20.0)
 */
@property(nonatomic, copy) NSString *fontName;


/**
 * 初始化方法 API_AVAILABLE(3.20.0)
 *
 * @param text 单个字幕文本
 * @param startTime 单个字幕开始的时间，单位：秒
 */
- (instancetype)initWithText:(NSString *)text startTime:(CGFloat)startTime;

@end

