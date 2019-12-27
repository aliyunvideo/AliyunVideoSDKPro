//
//  AlivcMixStream.h
//  AliyunVideoSDK
//
//  Created by Vienta on 2019/5/13.
//  Copyright © 2019 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunVideoParam.h"
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@interface AliyunMixStream : NSObject

/**
 视频文件路径
 */
@property(nonatomic, copy) NSString *filePath;

/**
 视频在所在轨道上展示的视频本身的裁剪范围  可选  此属性废弃
 */
@property(nonatomic, assign) CGRect innerCropFrame  __deprecated_msg("已废弃");

/**
 视频在轨道上播放的开始时间

 单位：秒
 */
@property(nonatomic, assign) CGFloat streamStartTime;

/**
 视频在轨道上播放的结束时间

 单位：秒
 */
@property(nonatomic, assign) CGFloat streamEndTime;

/**
 视频在轨道上的内容填充模式
 */
@property(nonatomic, assign) AlivcContentMode mode;

@end
