//
//  AliyunIClipConstructor.h
//  QUSDK
//
//  Created by Worthy on 2018/3/28.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunClip.h"
#import <Foundation/Foundation.h>

/**
 媒体片段构造器协议
 */
@protocol AliyunIClipConstructor <NSObject>

/**
 增加媒体片段

 @param clip 媒体片段
 */
- (void)addMediaClip:(AliyunClip *)clip;

/**
 设置所有媒体片段

 @param clips 媒体片段列表
 */
- (void)setMediaClips:(NSArray<AliyunClip *> *)clips;

/**
 增加媒体片段

 @param clip 媒体片段
 @param index index
 */
- (void)addMediaClip:(AliyunClip *)clip atIndex:(NSInteger)index;

/**
 更新媒体片段

 @param clip 媒体片段
 @param index index
 */
- (void)updateMediaClip:(AliyunClip *)clip atIndex:(NSInteger)index;

/**
 删除媒体片段

 @param index index
 */
- (void)deleteMediaClipAtIndex:(NSInteger)index;

/**
 删除所有媒体片段
 */
- (void)deleteAllMediaClips;

/**
 获取媒体片段

 @param index index
 @return 媒体片段
 */
- (AliyunClip *)mediaClipAtIndex:(NSInteger)index;

/**
 删除前一个媒体片段
 */
- (void)deleteLastMediaClip;

/**
 获取所有媒体片段

 @return 媒体片段列表
 */
- (NSArray<AliyunClip *> *)mediaClips;


#pragma mark - It is not recommended to use the following methods.


/**
 添加视频路径

 已废弃
 @param videoPath 视频路径
 @param animDuration 转场动画时长,单位秒

 duartion为当前视频片段和上段视频片段间的转场时长，不能小于视频本身时长
 添加的第一段视频没有转场，duartion需要设为0
 Deprecated 建议使用addMediaClip:
 */
- (void)addVideoWithPath:(NSString *)videoPath animDuration:(CGFloat)animDuration __deprecated_msg("Use `addMediaClip`");

/**
 添加视频路径


 已废弃
 @param videoPath 视频路径
 @param animDuration 转场动画时长,单位秒

 duartion为当前视频片段和上段视频片段间的转场时长，不能小于视频本身时长
 添加的第一段视频没有转场，duartion需要设为0
 Deprecated 建议使用addMediaClip:
 */
- (void)addVideoWithPath:(NSString *)videoPath startTime:(CGFloat)startTime duration:(CGFloat)duration animDuration:(CGFloat)animDuration __deprecated_msg("Use `addMediaClip`");

/**
 增加图片


 已废弃
 @param image 照片
 @param duration 播放时间
 @param animDuration 动画过渡时间

 @return 图片路径
 Deprecated 建议使用addMediaClip:
 */
- (NSString *)addImage:(UIImage *)image duration:(CGFloat)duration animDuration:(CGFloat)animDuration __deprecated_msg("Use `addMediaClip`");

@end
