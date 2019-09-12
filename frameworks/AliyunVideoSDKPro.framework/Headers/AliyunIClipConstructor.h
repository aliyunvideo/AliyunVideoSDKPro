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
/****
 The protocol of clip constructors. 
 */
@protocol AliyunIClipConstructor <NSObject>

/**
 增加媒体片段

 @param clip 媒体片段
 */
/****
 Adds a media clip.

 @param clip The media clip to be added.
 */
- (void)addMediaClip:(AliyunClip *)clip;

/**
 设置所有媒体片段

 @param clips 媒体片段列表
 */
/****
 Sets all media clips.

 @param clips The media clips in an array.
 */
- (void)setMediaClips:(NSArray<AliyunClip *> *)clips;

/**
 增加媒体片段

 @param clip 媒体片段
 @param index index
 */
/****
 Adds a media clip to an index position.

 @param clip The media clip to be added. 
 @param index The index position.
 */
- (void)addMediaClip:(AliyunClip *)clip atIndex:(NSInteger)index;

/**
 更新媒体片段

 @param clip 媒体片段
 @param index index
 */
/****
 Replaces a media clip at an index position.

 @param clip The media clip to be added.
 @param index The index position.
 */
- (void)updateMediaClip:(AliyunClip *)clip atIndex:(NSInteger)index;

/**
 删除媒体片段

 @param index index
 */
/****
 Deletes a media clip at an index position.

 @param index The index position.
 */
- (void)deleteMediaClipAtIndex:(NSInteger)index;

/**
 删除所有媒体片段
 */
/****
 Deletes all media clips.
 */
- (void)deleteAllMediaClips;

/**
 获取媒体片段

 @param index index
 @return 媒体片段
 */
/****
 Gets a media clip at an index position.

 @param index The index position.
 @return A media clip.
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
/****
 Gets all media clips.

 @return The media clips in an array.
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
/****
 Adds a video path.
 
 Deprecated.
 @param videoPath The path of the video clip.
 @param animDuration The transition duration in seconds.
 
 The duration is the time interval between this video clip and its preceding video clip.
 The duration must not be longer than the duration of the video clip and must be set to 0 
 if the video clip is added to the very beginning of the video stream.
 Deprecated. It is recommended to use addMediaClip instead.
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
/****
 Adds a video path.
 
 Deprecated.
 @param videoPath The path of the video clip.
 @param animDuration The transition duration in seconds. 
 
 The duration is the time interval between this video clip and its preceding video clip.
 The duration must not be longer than the duration of the video clip and must be set to 0 
 if the video clip is added to the very beginning of the video stream.
 Deprecated. It is recommended to use addMediaClip instead.
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
/****
 Add an image.
 
 Deprecated. 
 @param image The image to be added.
 @param duration The playback time of the image. 
 @param animDuration The transition duration.
 @return The image path.
 Deprecated. It is recommended to use addMediaClip instead.
 */
- (NSString *)addImage:(UIImage *)image duration:(CGFloat)duration animDuration:(CGFloat)animDuration __deprecated_msg("Use `addMediaClip`");

@end
