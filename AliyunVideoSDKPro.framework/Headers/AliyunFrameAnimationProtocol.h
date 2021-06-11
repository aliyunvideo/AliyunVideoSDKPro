//
//  sss.h
//  AliyunVideoSDKPro
//
//  Created by mengyehao on 2021/5/25.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AliyunAction;

@protocol AliyunFrameAnimationProtocol <NSObject>

/**
 添加帧动画效果
 
 @param action 动画参数，@see AliyunAction.
 */
- (void)addFrameAnimation:(AliyunAction *)action;


/**
 移除帧动画效果
 
 @param action 动画参数，@see AliyunAction.
 */
- (void)removeFrameAnimation:(AliyunAction *)action;

@end
