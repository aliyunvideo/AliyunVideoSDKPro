//
//  AliyunCaptionSticker.h
//  AliyunVideoSDKPro
//
//  Created by mengyehao on 2021/5/8.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AliyunSticker.h"

typedef NS_OPTIONS(NSUInteger, AliyunCaptionStickerFaceType) {
    AliyunCaptionStickerFaceTypeNormal                 = 0,     //常规
    AliyunCaptionStickerFaceTypeBold                   = 1 << 0,//粗体
    AliyunCaptionStickerFaceTypeItatic                 = 1 << 1,//斜体
};

@interface AliyunCaptionSticker : AliyunSticker<NSCopying>

/**
 文本 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, copy) NSString *text;

/**
 字幕缩放值，默认为1.0 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) float scale;

/**
 字体样式 @see AliyunCaptionStickerFaceType API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AliyunCaptionStickerFaceType faceType;

/**
 字体名称,优先级高于fontPath，不设置默认使用系统字体 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, copy) NSString *fontName;

/**
 字体大小，默认 30 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGFloat fontSize;

/**
 文字颜色， 默认白色 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, strong) UIColor *color;

/**
 描边宽度，单位：像素 默认0 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) float outlineWidth;

/**
 描边颜色，默认nil API_AVAILABLE(3.22.0)
 */
@property (nonatomic, strong) UIColor *outlineColor;

/**
 阴影的偏移值，默认 UIOffsetZero, x/y单位：像素，默认UIOffsetZero API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) UIOffset shadowOffset;

/**
 阴影颜色，默认nil API_AVAILABLE(3.22.0)
 */
@property (nonatomic, strong) UIColor *shadowColor;

/**
 气泡文字文件夹路径 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, copy) NSString *resourePath;

/**
 花字效果文件夹路径 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, copy) NSString *fontEffectTemplatePath;

@end


