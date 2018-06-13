//
//  AliyunNewEditor.h
//  QUSDK
//
//  Created by Vienta on 2018/1/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
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
#import "AliyunEffectTimeFilter.h"
#import "AliyunEffectMusic.h"
#import "AliyunEffectImage.h"
#import "AliyunVideoParam.h"
#import "AliyunIExporter.h"
#import "AliyunIClipConstructor.h"

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
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 参数不正确 ALIVC_COMMON_INVALID_PARAM
 * 组件初始化失败 ALIVC_SVIDEO_EDITOR_INIT_FAILED
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_CREATE_FAILED
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_RE_CREATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)startEdit;

/**
 销毁相关资源
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)stopEdit;

/**
 获取 媒体片段构造器
 对媒体片段修改操作，必须在startEdit之前或stopEdit后才能生效
 @return 媒体片段构造器
 */
- (id<AliyunIClipConstructor>)getClipConstructor;

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
 获取渲染窗口像素大小

 @return 渲染窗口像素大小
 */
- (CGSize)getPreviewRenderSize;

/**
 使用mv
 
 @param mv mv配置文件路径
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 解析动图失败 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 */
- (int)applyMV:(AliyunEffectMV *)mv;

/**
 移除MV
 
* 正常返回 ALIVC_COMMON_RETURN_SUCCESS
* 状态不正确 ALIVC_COMMON_INVALID_STATE
*/
- (int)removeMV;

/**
 移除mv音乐
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 解析动图失败 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 */
-(int)removeMVMusic;

/**
 使用音乐
 
 @param music music配置文件路径
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 */
- (int)applyMusic:(AliyunEffectMusic *)music;

/**
 移除所有音乐
 
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 */
- (int)removeMusics;

/**
 使用滤镜
 
 @param filter filter配置文件路径
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)applyFilter:(AliyunEffectFilter *)filter;

/**
 删除滤镜
 
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)removeFilter;

/**
 使用动效滤镜
 
 @param filter filter对象
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)applyAnimationFilter:(AliyunEffectFilter *)filter;

/**
 更新动态滤镜

 @param filter filter对象
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)updateAnimationFilter:(AliyunEffectFilter *)filter;

/**
 移除某个动效滤镜
 
 @param filter filter对象
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)removeAnimationFilter:(AliyunEffectFilter *)filter;

/**
 使用时间特效
 
 @param filter 特效对象
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 特效不支持（多个流的情况下）ALIVC_SVIDEO_EDITOR_TIME_EFFECT_NOT_SUPPORT
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 */
- (int)applyTimeFilter:(AliyunEffectTimeFilter *)filter;

/**
 删除时间特效
 
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED]
 */
- (int)removeTimeFilter;


/**
 获取当前的时间特效类型

 @return 时间特效种类  TIME_EFFECT_NONE = 0, 无效果
 TIME_EFFECT_SPEED = 1,加速或者减速
 TIME_EFFECT_REPEAT = 2,反复
 TIME_EFFECT_INVERT = 3 导致
 */
- (int)getTimeFilter;

/**
 加入静态贴纸
 
 @param staticImage 静态贴纸
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * 图片类型不支持 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED
 */
- (int)applyStaticImage:(AliyunEffectStaticImage *)staticImage;

/**
 移除静态贴纸
 
 @param staticImage 静态贴纸
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)removeStaticImage:(AliyunEffectStaticImage *)staticImage;


/**
 使用涂鸦
 
 @param paintImage 涂鸦图片
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * 图片类型不支持 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED
 */
- (int)applyPaint:(AliyunEffectImage *)paintImage;


/**
 删除涂鸦
 
 @param paintImage 涂鸦图片
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)removePaint:(AliyunEffectImage *)paintImage;

/**
 消除各种效果
 */
- (int)destroyAllEffect;


/**
 设置水印

 @param waterMark 水印
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * 图片类型不支持 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED
 */
- (int)setWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置片尾水印

 @param waterMark 片尾水印
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)setTailWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置是否静音
 
 @param mute 静音
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_CTL_INPUT_ERROR
 */
- (int)setMute:(BOOL)mute;

/**
 设置音量
 
 @param volume 音量：0-200
 默认值100,原始的音量大小
 大于100可能会破音，建议0-100
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_CTL_INPUT_ERROR
 */
- (int)setVolume:(int)volume;

/**
 设置混音权重
 
 @param weight 混音权重0-100
 设为100时，主流权重为0，只有配乐
 设为0时，配乐流权重为0，只有原音
 设为50时，主流和配乐流权重都为100
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 */
- (int)setAudioMixWeight:(int)weight;


/**
 设置单路音频流的权重

 @param weight 权重 0-100
 100 代表原始大小
 @param streamId 流id
 AliyunEffectMusic流id：effectVid
 AliyunEffectMV流id：audioEffectVid
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 */
- (int)setAudioWeight:(int)weight streamId:(int)streamId;

/**
 设置主流混音权重

 @param weight 混音权重 0-100
 100 代表原始大小
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)setMainStreamsAudioWeight:(int)weight;

/**
 画面填充模式
 
 @param mode 0:截断填充， 1:黑边填充
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)setScaleMode:(int)mode;

/**
 视频渲染最底层背景颜色 在填充模式下具有效果
 
 @param color 颜色
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)setRenderBackgroundColor:(UIColor *)color;

/**
 设置最大内存缓存大小
 默认值250Mb，建议200M以上
 必须在startEdit之前或stopEdit后才能生效
 @param cacheSize 内存缓存大小，单位：byte
 */
- (void)setMaxCacheSize:(int)cacheSize;


/**
 获取当前设置的最大内存缓存大小

 @return 内存缓存大小
 */
- (int)getMaxCacheSize;


/**
 获取视频需要的最大内存缓存大小

 @param path 视频路径
 @return 内存缓存大小
 */
- (int)getMaxEstimatedCacheSize:(NSString *)path;

/**
 request id
 */
- (NSString *)getRequestId;

/**
 版本号
 */
+ (NSString *)version;

#pragma mark - deprecated 不建议使用的API

/**
 添加视频路径
 
 @param path 视频路径
 Deprecated 建议使用getClipConstructor
 */
- (int)addPath:(NSString *)path startTime:(float)startTime duration:(float)duration fadeDuration:(float)fadeDuration inDuration:(float)inDuration outDruation:(float)outDuration mode:(int)mode __deprecated_msg("Use `IClipConstructor`");

/**
 添加图片路径
 
 @param path 图片路径
 Deprecated 建议使用getClipConstructor获取IClipConstructor进行管理
 */
- (int)addImagePath:(NSString *)path duration:(float)duration fadeDuration:(float)fadeDuration inAnimateDuration:(float)inDuration outAnimateDuration:(float)outDuration mode:(int)mode __deprecated_msg("Use `IClipConstructor`");

/**
 获取所有播放的视频的本地路径
 
 @return 路径数组
 Deprecated 建议使用getClipConstructor获取IClipConstructor进行管理
 */
- (NSArray *)getVideoUrls __deprecated_msg("Use `IClipConstructor`");


/**
 获取媒体片段
 
 @return 媒体片段数组
 Deprecated 建议使用getClipConstructor获取IClipConstructor进行管理
 */
- (NSArray *)getMediaClips __deprecated_msg("Use `IClipConstructor`");


/**
 设置转场时长
 
 @param fadeDuration 转场时长
 @param inDuration 暂时无效
 @param outDuration 暂时无效
 @param index 视频index
 @return 返回结果
 第一段视频设置无效,转场时长不能超过最短视频时长的一半
 Deprecated 建议使用getClipConstructor获取IClipConstructor进行管理
 */
- (int)setClipFadeDuration:(CGFloat)fadeDuration inDuration:(CGFloat)inDuration outDuration:(CGFloat)outDuration atIndex:(NSInteger)index __deprecated_msg("Use `IClipConstructor`");


/**
 添加片尾水印
 
 @param image 图片
 @param frame
 @param duration 时长
 */
- (int)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration __deprecated_msg("use setTailWaterMark:(AliyunEffectImage *)waterMark");

/**
 添加视频水印
 
 @param imagePath 视频水印路径
 @param frame 水印frame
 */
- (int)setWaterMark:(NSString *)imagePath frame:(CGRect)frame __deprecated_msg("use setWaterMark:(AliyunEffectImage *)waterMark");
@end
