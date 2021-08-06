//
//  AEPTransitionEffect.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/27.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AEPEffect.h"
#import "AliyunTransitionEffect.h"
#import "AliyunTransitionEffectTranslate.h"
#import "AliyunTransitionEffectShuffer.h"

/**
 转场效果的基类
 */
/**
 A base class that defines transition effects.
 */
@interface AEPTransitionEffect : AEPEffect

/**
 转场时间，需要保证转场时间小于等于视频片段时长
 */
/**
 The transition duration. The transition duration must not be longer than that of the video clip.
 */
@property (nonatomic, assign, readonly) float overlapDuration;

/**
 编辑器用的转场对象
 */
/**
 The transition effect obj for editor
 */
@property (nonatomic, strong, readonly) AliyunTransitionEffect *editorEffect;

@end


/**
 百叶窗效果的转场
 */
/**
 A class that defines blinds transitions.
 */
@interface AEPTransitionShufferEffect : AEPTransitionEffect

/**
 百叶窗叶片宽度 范围是0.0-1.0
 */
/**
 The width of each blind. Valid values: [0.0, 1.0]
 */
@property (nonatomic, assign, readonly) float lineWidth;

/**
 平移方向属性
 */
/**
 The direction that the blinds open and close.
 */
@property (nonatomic, assign, readonly) ORIENTATION_TYPE orientation;
@end


/**
 平移效果的转场
 */
@interface AEPTransitionTranslateEffect : AEPTransitionEffect

/**
 移动方向
 */
/**
 The direction of the translational motion.
 */
@property (nonatomic, assign, readonly) DIRECTION_TYPE direction;
@end


/**
 多边形转场效果
 */
/**
 A class that defines polygon transitions.
 */
@interface AEPTransitionStarEffect : AEPTransitionEffect
@end


/**
 淡入淡出转场
 */
@interface AEPTransitionFadeEffect : AEPTransitionEffect
@end


/**
 圆形效果转场
 */
@interface AEPTransitionCircleEffect : AEPTransitionEffect
@end


/**
 自定义转场
 */
/**
 Custom transition effect
 */
@interface AEPTransitionCustomEffect : AEPTransitionEffect

/**
 自定义转场资源
 */
/**
 The source for custom transition effect
 */
@property (nonatomic, strong, readonly) AEPSource *source;
/**
 自定义转场参数
 */
/**
 The param for custom transition effect
 */
@property (nonatomic, copy, readonly) NSString *paramString;

@end
