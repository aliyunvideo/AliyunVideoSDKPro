//
//  AliyunGifSticker.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/24.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunSticker.h"

/**
 Gif贴纸类型 API_AVAILABLE(3.22.0)
 */
/**
 The type of gif sticker API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSUInteger, AliyunGifStickerType) {
    /**
     普通动图 API_AVAILABLE(3.22.0)
     */
    /**
     The normal gif API_AVAILABLE(3.22.0)
     */
    AliyunGifStickerType_Normal = 0,
    /**
     人脸动图 API_AVAILABLE(3.22.0)
     */
    /**
     The gif of face API_AVAILABLE(3.22.0)
     */
    AliyunGifStickerType_Face   = 1,
};

@class AliyunEffectPasterTimeItem;
@class AliyunEffectPasterFrameItem;
@interface AliyunGifSticker : AliyunSticker<NSCopying>
/**
 * 模板文件夹路径 API_AVAILABLE(3.22.0)
 */
/**
 * the template for bubble text,styleTemplate template path API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSString *templateDirectory;

/**
动图类型 API_AVAILABLE(3.22.0)
*/
@property (nonatomic, readonly) AliyunGifStickerType gifType;

/**
 关键帧图片 API_AVAILABLE(3.22.0)
 */
@property(nonatomic, strong) UIImage *kernelImage;

/**
 动画的场景集合 API_AVAILABLE(3.22.0)
 
 例如：动画场景可以分为进场、场中和出场
 */
@property(nonatomic, readonly) NSArray<AliyunEffectPasterTimeItem *> *timeItems;

/**
 动画帧集合 API_AVAILABLE(3.22.0)
 
 即指定在某时间播放某一张图片
 */
@property(nonatomic, readonly) NSArray<AliyunEffectPasterFrameItem *> *frameItems;


/**
 动图最小播放时长 API_AVAILABLE(3.22.0)
 
 配置文件内配置
 */
@property(nonatomic, assign, readonly) CGFloat minDuration;

/**
 动图原始时长 API_AVAILABLE(3.22.0)
 
 从动图的配置文件解析而来
 */
@property(nonatomic, assign, readonly) CGFloat originDuration;

- (instancetype) initWithTemplateDirectory:(NSString *)path;
@end
