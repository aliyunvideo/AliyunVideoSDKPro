//
//  AliyunRenderModel.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/24.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 渲染模式 API_AVAILABLE(3.22.0)
 */
/**
 the mode of render API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSUInteger, AliyunRenderMode) {
    /**
     不等比拉伸填充 API_AVAILABLE(3.22.0)
     */
    /**
     Stretch to fill layer bounds. API_AVAILABLE(3.22.0)
     */
    AliyunRenderMode_Resize,
    /**
     等比拉伸填充 API_AVAILABLE(3.22.0)
     */
    /**
     Preserve aspect ratio; fill layer bounds. API_AVAILABLE(3.22.0)
     */
    AliyunRenderMode_ResizeAspectFill,
    /**
     等比拉伸留白 API_AVAILABLE(3.22.0)
     */
    /**
     Preserve aspect ratio; fit within layer bounds. API_AVAILABLE(3.22.0)
     */
    AliyunRenderMode_ResizeAspect,
};

/**
 渲染基本数据模型 API_AVAILABLE(3.22.0)
 */
/**
 The base mode of render API_AVAILABLE(3.22.0)
 */
@interface AliyunRenderModel : NSObject<NSCopying>
/**
 大小 API_AVAILABLE(3.22.0)
 */
/**
 the size of render API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGSize size;
/**
 中心点位置 API_AVAILABLE(3.22.0)
 */
/**
 the center position in parent node API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGPoint center;
/**
 旋转角度 API_AVAILABLE(3.22.0)
 */
/**
 The Rotation API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGFloat rotation;
/**
 镜像 API_AVAILABLE(3.22.0)
 */
/**
 is horizontal flip API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) BOOL isMirror;
/**
 开始时间 API_AVAILABLE(3.22.0)
 */
/**
 The start time API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) NSTimeInterval startTime;
/**
 持续时间 API_AVAILABLE(3.22.0)
 */
/**
 The duration API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) NSTimeInterval duration;
/**
 自适应布局策略 API_AVAILABLE(3.22.0)
 */
/**
 the strategy of autoresizing API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) UIViewAutoresizing autoresizingMask;
/**
 渲染模式 API_AVAILABLE(3.22.0)
 */
/**
 the mode of render API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRenderMode renderMode;
@end
