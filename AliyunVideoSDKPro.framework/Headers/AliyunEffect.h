//
//  AliyunEffect.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunJSONModel.h"
#import <Foundation/Foundation.h>

/**
 音效类型

 - AliyunAudioEffectDefault: 默认
 - AliyunAudioEffectLolita: 萝莉
 - AliyunAudioEffectUncle: 大叔
 - AliyunAudioEffectReverb: 混响
 - AliyunAudioEffectEcho: 回声
 - AliyunAudioEffectRobot: 机器人
 - AliyunAudioEffectBigDevil: 大魔王
 - AliyunAudioEffectMinions: 小黄人
 - AliyunAudioEffectDenoise: 去噪
 */
typedef NS_ENUM(NSInteger, AliyunAudioEffectType) {
    AliyunAudioEffectDefault = 0,
    AliyunAudioEffectLolita,
    AliyunAudioEffectUncle,
    AliyunAudioEffectReverb,
    AliyunAudioEffectEcho,
    AliyunAudioEffectRobot,
    AliyunAudioEffectBigDevil,
    AliyunAudioEffectMinions,
    AliyunAudioEffectDenoise   __deprecated_msg("use AliyunEditor::setAudioDenoiseWeight:streamId:"), // 已失效，请使用AliyunEditor::setAudioDenoise:streamId:
    AliyunAudioEffectDialect
};

/**
 API_AVAILABLE(3.20.0)
 音频淡入淡出函数曲线类型
 
 -AliyunEditorAudioFadeShapeLinear:   线性曲线
 -AliyunEditorAudioFadeShapeSin: 正弦函数曲线
 */
typedef NS_ENUM(NSUInteger, AliyunAudioFadeShape) {
    AliyunAudioFadeShapeLinear,
    AliyunAudioFadeShapeSin,
};

/**
 API_AVAILABLE(3.20.0)
 视频增强类型

 - AliyunVideoAugmentationTypeBrightness: 亮度
 - AliyunVideoAugmentationTypeContrast: 对比度
 - AliyunVideoAugmentationTypeSaturation: 饱和度
 - AliyunVideoAugmentationTypeSharpness: 锐度
 - AliyunVideoAugmentationTypeVignette: 暗角
 */
typedef NS_ENUM(NSUInteger, AliyunVideoAugmentationType) {
    AliyunVideoAugmentationTypeBrightness = 0,
    AliyunVideoAugmentationTypeContrast,
    AliyunVideoAugmentationTypeSaturation,
    AliyunVideoAugmentationTypeSharpness,
    AliyunVideoAugmentationTypeVignette
};


/**
 API_AVAILABLE(3.20.0)
 亮度调节默认值，返回0.5
 */
extern const float AliyunVideoBrightnessDefaultValue;

/**
 API_AVAILABLE(3.20.0)
 对比度调节默认值，返回0.25
 */
extern const float AliyunVideoContrastDefaultValue;

/**
 API_AVAILABLE(3.20.0)
 饱和度调节默认值，返回0.5
 */
extern const float AliyunVideoSaturationDefaultValue;

/**
 API_AVAILABLE(3.20.0)
 锐度调节默认值，返回0.0
 */
extern const float AliyunVideoSharpnessDefaultValue;

/**
 API_AVAILABLE(3.20.0)
 暗角调节默认值，返回0.0
 */
extern const float AliyunVideoVignetteDefaultValue;


id QUSDKObjectOrNull(id object);

/**
 特效model基类
 */
@interface AliyunEffect : AliyunJSONModel

/**
 路径
 */
@property(nonatomic, copy) NSString *path;

/**
 图标路径
 */
@property(nonatomic, copy) NSString *icon;

/**
 名称
 */
@property(nonatomic, copy) NSString *name;

/**
 id

 @return id
 */
- (int)effectVid;

/**
 设置id

 @param vid id
 */
- (void)setEffectVid:(int)vid;

/**
 通过文件夹路径初始化effect对象

 @param path effect资源文件夹对象
 @return effect实例对象
 */
- (instancetype)initWithFile:(NSString *)path;

/**
 内部调用方法

 @param dict dict
 @return AliyunEffect
 */
- (instancetype)initWithDict:(NSDictionary *)dict;

@end

/**
 音效model类
 */
@interface AliyunAudioEffect : AliyunJSONModel

/**
 音效类型
 */
@property(nonatomic, assign) AliyunAudioEffectType type;

/**
 音效值0-100
 */
@property(nonatomic, assign) int weight;

@end


/**
 API_AVAILABLE(3.20.0)
 音频淡入淡出Model
 */
@interface AliyunAudioFade : AliyunJSONModel

/**
 API_AVAILABLE(3.20.0)
 曲线
 */
@property(nonatomic, assign) AliyunAudioFadeShape shape;

/**
 API_AVAILABLE(3.20.0)
 时长（单位：秒）
 */
@property(nonatomic, assign) float duration;

@end
