//
//  AEPAction.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunAction.h"
#import "AliyunWipeAction.h"

/**
 动画基类
 */
/**
 The Base action
 */
@interface AEPAction : NSObject

/**
 动画ID
 */
/**
 The id of action
 */
@property (nonatomic, assign, readonly) int actionId;

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
 编辑器中的动画对象
 */
/**
 The action obj for editor
 */
@property (nonatomic, strong, readonly) AliyunAction *editorAction;

@end


/**
 透明度动画
 */
/**
 The action for alpha
 */
@interface AEPAlphaAction : AEPAction

/**
 起始透明度
 */
@property (nonatomic, assign, readonly) float from;
/**
 终点透明度
 */
@property (nonatomic, assign, readonly) float to;

@end


/**
 缩放动画类
 */
@interface AEPScaleAction : AEPAction

/**
 缩放的起始缩放比例
 */
/**
 The initial scale factor.
 */
@property (nonatomic, assign, readonly) float from;
/**
 缩放的终点缩放比例
 */
/**
 The target scale factor.
 */
@property (nonatomic, assign, readonly) float to;
/**
 是否启用缩放锚点，不开启则以物体自身中心点缩放
 */
/**
 using anchor for scale, default center
 */
@property (nonatomic, assign, readonly) BOOL scaleAnchorEnable;

/**
 缩放锚点：参考缩放基准值，用于计算trans偏移，默认为1.0
 */
/**
 The Scale of anchor, using to calculate trans offset; default: 1.0
 */
@property (nonatomic, assign, readonly) float anchorBaseScale;
/**
 锚点坐标，[0,1]，默认值: (0.5, 0.5)
 */
/**
 The Anchor. [0, 1], default: (0.5, 0.5)
 */
@property (nonatomic, assign, readonly) CGPoint anchor;
@end


/**
 平移动画
 */
/**
 A class that defines translational motions.
 */
@interface AEPTranslateAction : AEPAction

/**
 移动的起始坐标

 坐标参考系是为系统屏幕坐标系 （0，0）为左上角  和系统view行为一致
 */
/**
 The coordinates of the start point of the motion.
 
 The coordinate system of the screen is used. The origin (0, 0) is at the top left of the screen.
 */
@property (nonatomic, assign, readonly) CGPoint from;
/**
 移动的终点位置
 */
/**
 The coordinates of the end point of the motion.
 */
@property (nonatomic, assign, readonly) CGPoint to;

@end

/**
 旋转动画的基类
 */
/**
 The rotate aciton base class
 */
@interface AEPRotateBaseAction : AEPAction
/**
 旋转方向

 可以设置为顺时针或者逆时针
 true:顺时针
 false:逆时针
 */
@property (nonatomic, assign, readonly) BOOL  clockwise;
/**
 开始旋转时的弧度

 单位：弧度
 */
@property (nonatomic, assign, readonly) float from;

/**
 旋转的中心点，取值[0,1]
 */
/**
 The center of rotate
 */
@property(nonatomic, assign, readonly) CGPoint normalizedCenter;

/**
 旋转中心点所在的坐标系统，默认为AliyunActionCoordinateSpace_Local
 */
/**
 The CoordinateSpace of Center Point
 */
@property(nonatomic, assign, readonly) AliyunActionCoordinateSpace coordinateSpace;
@end


/**
 旋转到某个角度类

 继承自AliyunRotateAction
 */
@interface AEPRotateToAction : AEPRotateBaseAction
/**
 旋转到目标角度
 */
@property (nonatomic, assign, readonly) float to;
@end


/**
 旋转动画类
 */
@interface AEPRotateByAction : AEPRotateBaseAction

/**
 在当前的旋转弧度上再旋转多少弧度
 */
@property (nonatomic, assign, readonly) float rotate;

@end

/**
 重复旋转类 不停地旋转
 */
@interface AEPRotateRepeatAction : AEPRotateBaseAction
/**
 旋转一圈需要的时间
 */
@property (nonatomic, assign, readonly) float durationPerCircle;
/**
 是否重复；默认YES
 */
/**
 isRepeat; default: YES
 */
@property (nonatomic, assign, readonly) BOOL  repeat;

@end

/**
 线性擦除动画
 */
/**
 The action of wip
 */
@interface AEPWipeAction : AEPAction

/**
 线性擦除方向
 */
/**
 The Direction of wipe action
 */
@property (nonatomic, assign, readonly) AliWipeActionDirection direction;
/**
 擦除模式
 */
/**
 The mode of wipe action
 */
@property (nonatomic, assign, readonly) AliWipeActionMode wipeMode;

@end

/**
 自定义动画
 */
@interface AEPCustomAction : AEPAction
/**
 自定义动画的片元着色器代码
 */
@property (nonatomic, copy, readonly) NSString *fragmentShader;
/**
 片元着色器的参数设置：为字典结构
 */
@property (nonatomic, copy, readonly) NSDictionary *uniforms;

@end
