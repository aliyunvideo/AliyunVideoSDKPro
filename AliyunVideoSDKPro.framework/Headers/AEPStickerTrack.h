//
//  AEPStickerTrack.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPTrack.h"
#import "AliyunCaptionSticker.h"

/**
 贴纸轨道
 */
/**
 The Sticker Track
 */
@interface AEPStickerTrack : AEPTrack
@end

@class AliyunRollCaptionItemStyle;
/**
 翻转字幕元素
 */
/**
 The item of rollcaption
 */
@interface AEPRollCaptionItem : NSObject
/**
 字幕
 */
/**
 The text of roll caption
 */
@property (nonatomic, copy, readonly) NSString *text;
/**
 字体资源，其中sourceId表示字体名称
 */
/**
 the resource of font, the sourceid mean fontName
 */
@property (nonatomic, strong, readonly) AEPSource *font;
/**
 文字颜色
 */
/**
 The Color of text
 */
@property (nonatomic, strong, readonly) UIColor *textColor;
/**
 字体描边颜色
 */
/**
 The color of outline
 */
@property (nonatomic, strong, readonly) UIColor *outlineColor;
/**
 时间线上的开始时间（秒）
 */
/**
 The start time on timeline. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval timelineIn;

/**
 编辑器中使用的翻转字幕元素对象
 */
/**
 The item of rollcaption that using in editor
 */
@property (nonatomic, strong, readonly) AliyunRollCaptionItemStyle *editorItem;
@end

/**
 翻转字幕
 */
/**
 THe Roll Caption
 */
@interface AEPRollCaptionTrack : AEPStickerTrack
/**
 翻转字幕组成元素列表
 */
/**
 The list of roll caption item
 */
@property (nonatomic, copy, readonly) NSArray<AEPRollCaptionItem *> *items;
/**
 编辑器中使用的翻转字幕元素列表
 */
/**
The list of roll caption item that using in editor
 */
@property (nonatomic, copy, readonly) NSArray<AliyunRollCaptionItemStyle *> *editorItems;
@end

/**
 贴子基础类
 */
/**
 The base class of sticker track
 */
@interface AEPStickerBaseTrack : AEPStickerTrack
/**
 贴纸ID
 */
/**
 The id of sticker
 */
@property (nonatomic, assign, readonly) int stickerId;

/**
 时间线上的开始时间（秒）
 */
/**
 The start time on timeline. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval timelineIn;

/**
 时间线上的结束时间（秒）
 */
/**
 The end time on timeline. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval timelineOut;
/**
 旋转角度
 */
/**
 The Rotation
 */
@property (nonatomic, assign, readonly) float rotation;
/**
 镜像
 */
/**
 is horizontal flip
 */
@property (nonatomic, assign, readonly) BOOL mirror;

/**
 归一化中心点位置
 */
/**
 The center point in normalized
 */
@property (nonatomic, readonly) CGPoint normalizedCenter;
/**
 归一化大小
 */
/**
 The size in normlized
 */
@property (nonatomic, readonly) CGSize normalizedSize;

/**
 动画效果列表
 */
/**
 The list of actions
 */
@property (nonatomic, copy, readonly) NSArray<AEPAction *> *actions;
@end

@class AliyunImageStickerController;
/**
 静态图片贴纸
 */
/**
 The sticker track of image
 */
@interface AEPImageStickerTrack : AEPStickerBaseTrack
/**
 贴纸资源
 */
/**
 The resoruce of sticker
 */
@property (nonatomic, strong, readonly) AEPSource *source;

/**
 编辑器中使用的静态贴纸控制器
 */
/**
 The controller of image sticker that using in editor
 */
@property (nonatomic, strong, readonly) AliyunImageStickerController *imageStickerController;
@end

@class AliyunGifStickerController;
/**
 Gif贴纸
 */
/**
 The sticker track of gif
 */
@interface AEPGifStickerTrack : AEPStickerBaseTrack
/**
 贴纸资源
 */
/**
 The resoruce of sticker
 */
@property (nonatomic, strong, readonly) AEPSource *source;
/**
 编辑器中使用的Gif贴纸控制器
 */
/**
 The controller of gif sticker that using in editor
 */
@property (nonatomic, strong, readonly) AliyunGifStickerController *gifStickerController;
@end

/**
 字幕基础类
 */
/**
 The base class of caption
 */
@interface AEPCaptionBaseTrack : AEPStickerBaseTrack
/**
 字幕文字
 */
/**
 The text of caption
 */
@property (nonatomic, copy, readonly) NSString *text;
/**
 字体资源，sourceId表示字体名称
 */
/**
 The resource of font. The sourceId mean fontName
 */
@property (nonatomic, strong, readonly) AEPSource *font;
/**
 文字颜色
 */
/**
 The color of text
 */
@property (nonatomic, strong, readonly) UIColor *textColor;
/**
 文字背景颜色
 */
/**
 The background color of text
 */
@property (nonatomic, strong, readonly) UIColor *textBgColor;
@end

@class AliyunCaptionStickerController;
/**
 字幕轨道
 */
@interface AEPCaptionTrack : AEPCaptionBaseTrack
/**
 气泡资源
 */
/**
 The resoruce of sticker
 */
@property (nonatomic, strong, readonly) AEPSource *source;
/**
 描边颜色
 */
/**
 The outline color of text
 */
@property (nonatomic, strong, readonly) UIColor *outlineColor;
/**
 字体样式 @see AliyunCaptionStickerFaceType
 */
/**
 The FontStyle of caption, @see AliyunCaptionStickerFaceType
 */
@property (nonatomic, assign, readonly) AliyunCaptionStickerFaceType faceType;
/**
 字幕缩放值，默认为1.0
 */
/**
 The scale value of caption, default is 1.0.
 */
@property (nonatomic, assign, readonly) CGFloat scale;
/**
 描边宽度，单位：像素 默认0
 */
/**
 Text stroke width, unit:px, default is 0.
 */
@property (nonatomic, assign, readonly) CGFloat outlineWidth;
/**
 阴影颜色，默认nil
 */
/**
 The shadow color of caption, default is nil.
 */
@property (nonatomic, strong, readonly) UIColor *shadowColor;
/**
 阴影的偏移值，默认 UIOffsetZero, x/y单位：像素，默认UIOffsetZero
 */
/**
 The offset value of the shadow, x/y unit:px，默认0 default is UIOffsetZero.
 */
@property (nonatomic, assign, readonly) UIOffset shadowOffset;
/**
 花字效果文件夹路径
 */
/**
 The flower effct template path.
 */
@property (nonatomic, strong, readonly) AEPSource *fontEffectSource;

/**
 编辑器中使用的字幕控制器
 */
/**
 The controller of caption that using in editor
 */
@property (nonatomic, strong, readonly) AliyunCaptionStickerController *captionStickerController;
@end

/**
 废弃的字幕轨道基类
 */
/**
 The base class of deprecate caption
 */
@interface AEPDeprecatedCaptionTrack : AEPCaptionBaseTrack
/**
 是否有描边
 */
/**
 Whether the text is stroked.
 */
@property (nonatomic, assign, readonly) BOOL hasStroke;
/**
 描边颜色
 */
/**
 The color of stroke
 */
@property (nonatomic, strong, readonly) UIColor *strokeColor;
@end

@class AliyunEffectSubtitle;
/**
 废弃的纯文字
 */
/**
 The deprecate pure text
 */
@interface AEPSubtitleTrack : AEPDeprecatedCaptionTrack
/**
 编辑器中使用的纯文字对象
 */
/**
 The pure text obj that using in editor
 */
@property (nonatomic, strong, readonly) AliyunEffectSubtitle *editorSubtitle;
@end

@class AliyunEffectCaption;
/**
 废弃的气泡字
 */
/**
 The deprecate bubble caption
 */
@interface AEPBubbleCaptionTrack : AEPDeprecatedCaptionTrack
/**
 气泡资源
 */
/**
 The resoruce of sticker
 */
@property (nonatomic, strong, readonly) AEPSource *source;

/**
 归一化的文字大小
 */
/**
 The text size in normlized
 */
@property (nonatomic, assign, readonly) CGSize normalizedTextSize;

/**
 归一化的文字位置（相对于气泡字本身）
 */
/**
 The text center in normliazed. (In Self coordinate system)
 */
@property (nonatomic, assign, readonly) CGPoint normalizedTextCenter;
/**
 在编辑器中使用的气泡字对象
 */
/**
 The bubble caption that using in editor
 */
@property (nonatomic, strong, readonly) AliyunEffectCaption *editorCaption;
@end
