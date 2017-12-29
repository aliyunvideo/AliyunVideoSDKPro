//
//  AliyunEditor.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/6.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunIPlayer.h"
#import "AliyunIPasterRender.h"
#import "AliyunPasterManager.h"
#import "AliyunIPlayerCallback.h"
#import "AliyunIExporterCallback.h"
#import "AliyunEffectStaticImage.h"
#import "AliyunEffectMV.h"
#import "AliyunEffectFilter.h"
#import "AliyunEffectMusic.h"
#import "AliyunEffectImage.h"
#import "AliyunVideoParam.h"
#import "AliyunIExporter.h"


@interface AliyunEditor : NSObject

@property (nonatomic, weak) id<AliyunIPlayerCallback, AliyunIExporterCallback, AliyunIRenderCallback> delegate;

/**
 初始化Editor

 @param taskPath 配置文件路径
 @param preview 编辑预览视图
 @return Editor
 */
- (instancetype)initWithPath:(NSString *)taskPath preview:(UIView *)preview;

/**
 创建相关资源
 */
- (int)startEdit;

/**
 销毁相关资源
 */
- (void)stopEdit;

/**
 添加视频路径

 @param path 视频路径
 
 */
- (void)addPath:(NSString *)path fadeDuration:(float)fadeDuration inDuration:(float)inDuration outDruation:(float)outDuration mode:(int)mode;


/**
 添加视频路径
 
 @param path 视频路径
 
 */
- (void)addPath:(NSString *)path startTime:(float)startTime duration:(float)duration fadeDuration:(float)fadeDuration inDuration:(float)inDuration outDruation:(float)outDuration mode:(int)mode;


/**
 获取所有播放的视频的本地路径
 
 @return 路径数组
 */
- (NSArray *)getVideoUrls;


/**
 获取媒体片段

 @return 媒体片段数组
 */
- (NSArray *)getMediaClips;

/**
 获取播放器接口实例

 @return AliyunIPlayer
 */
- (id<AliyunIPlayer>)getPlayer;

/**
 获取导出接口实例

 @return AliyunIExporter
 */
- (id<AliyunIExporter>)getExporter;

/**
 获取PasterRender实例

 @return PasterRender
 */
- (id<AliyunIPasterRender>)getPasterRender;

/**
 获取动图管理类

 @return AliyunPasterManager
 */
- (AliyunPasterManager *)getPasterManager;

/**
 使用mv
 
 @param mv mv配置文件路径
 @return 错误码
 */
- (int)applyMV:(AliyunEffectMV *)mv;

/**
 使用音乐
 
 @param music music配置文件路径
 @return 错误码
 */
- (int)applyMusic:(AliyunEffectMusic *)music;

/**
 使用滤镜
 
 @param filter filter配置文件路径
 @return 错误码
 */
- (int)applyFilter:(AliyunEffectFilter *)filter;


/**
 加入静态贴纸

 @param staticImage 静态贴纸
 */
- (void)applyStaticImage:(AliyunEffectStaticImage *)staticImage;

/**
 移除静态贴纸

 @param staticImage 静态贴纸
 */
- (void)removeStaticImage:(AliyunEffectStaticImage *)staticImage;


/**
 使用涂鸦

 @param paintImage 涂鸦图片
 */
- (void)applyPaint:(AliyunEffectImage *)paintImage;


/**
 删除涂鸦

 @param paintImage 涂鸦图片
 */
- (void)removePaint:(AliyunEffectImage *)paintImage;

/**
 消除各种效果
 */
- (void)destroyAllEffect;

/**
 添加视频水印

 @param imagePath 视频水印路径
 @param frame 水印frame
 */
- (void)setWaterMark:(NSString *)imagePath frame:(CGRect)frame;

/**
 设置是否静音
 
 @param mute 静音
 */
- (void)setMute:(BOOL)mute;  

/**
 设置音量
 
 @param volume 音量：0-200
 */
- (void)setVolume:(int)volume;

/**
 设置混音权重
 
 @param weight 混音权重0-100
 */
- (void)setAudioMixWeight:(int)weight;

/**
 画面填充模式
 
 @param mode 0:截断填充， 1:黑边填充
 */
- (void)setScaleMode:(int)mode;

/**
 视频渲染最底层背景颜色 在填充模式下具有效果
 
 @param color 颜色
 */
- (void)setRenderBackgroundColor:(UIColor *)color;

/**
 设置转场时长
 
 @param fadeDuration 转场时长
 @param inDuration 暂时无效
 @param outDuration 暂时无效
 @param index 视频index
 @return 返回结果
 第一段视频设置无效,转场时长不能超过最短视频时长的一半
 */
- (int)setClipFadeDuration:(CGFloat)fadeDuration inDuration:(CGFloat)inDuration outDuration:(CGFloat)outDuration atIndex:(NSInteger)index;

/**
 request id
 */
- (NSString *)getRequestId;

/**
 版本号
*/
+ (NSString *)version;

@end
