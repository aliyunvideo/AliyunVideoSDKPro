//
//  AEPEffect.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPSource.h"

#import "AliyunEffect.h"
#import "AliyunEffectBlurBackground.h"
#import "AliyunEffectRunningDisplayMode.h"

/**
 特效基类
 */
/**
 The base class of effect
 */
@interface AEPEffect : NSObject

/**
 特效ID
 */
/**
 The id of effect
 */
@property (nonatomic, assign, readonly) int effectId;

@end


/**
 变声特效
 */
/**
 The effect for sound
 */
@interface AEPAudioEffect : AEPEffect

/**
 音效类型
 */
@property (nonatomic, assign, readonly) AliyunAudioEffectType effectType;

/**
 音效值0-100
 */
@property (nonatomic, assign, readonly) int effectParam;

/**
 编辑器音效对象
 */
/**
 The audio obj for editor
 */
@property (nonatomic, strong, readonly) AliyunAudioEffect *editorEffect;

@end


/**
 音频淡入淡出Model
 */
/**
 A model class that defines sound effects.
 */
@interface AEPAudioFadeEffect : AEPEffect

/**
 淡入或者淡出
 */
/**
 fadeIn or fadeOut
 */
@property (nonatomic, assign, readonly) BOOL fadeIn;

/**
 曲线
 */
/**
 The shape type.
 */
@property (nonatomic, assign, readonly) AliyunAudioFadeShape shapeType;

/**
 时长（单位：秒）
 */
/**
 effect time in second
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/**
 编辑器的音效对象
 */
/**
 The audio effect obj for editor
 */
@property (nonatomic, strong, readonly) AliyunAudioFade *editorEffect;

@end


/**
 背景模糊效果model类
 */
/**
 A model class that defines blurred background effects.
 */
@interface AEPBlurBackgroundEffect : AEPEffect

/**
 片段内部开始时间（秒）
 */
/**
 The start time on stream. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval clipIn;
/**
 片段内部结束时间（秒）
 */
/**
 The end time on stream. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval clipOut;
/**
 模糊半径

 数值越大越模糊，范围0-29
 */
/**
 The blur radius.

 The higher the radius value, the more blurred the background is. Valid values: [0, 29]
 */
@property (nonatomic, assign, readonly) float blurRadius;

/**
 编辑器的背景模糊对象
 */
/**
 The blur background effect for edtiro
 */
@property (nonatomic, strong, readonly) AliyunEffectBlurBackground *editorEffect;

@end
