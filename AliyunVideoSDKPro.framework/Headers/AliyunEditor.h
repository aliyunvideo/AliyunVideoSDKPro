//
//  AliyunNewEditor.h
//  QUSDK
//
//  Created by Vienta on 2018/1/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunActionProtocol.h"
#import "AliyunAlphaAction.h"
#import "AliyunCustomAction.h"
#import "AliyunEffectBlurBackground.h"
#import "AliyunEffectDub.h"
#import "AliyunEffectFilter.h"
#import "AliyunEffectImage.h"
#import "AliyunEffectMV.h"
#import "AliyunEffectMusic.h"
#import "AliyunEffectRunningDisplayMode.h"
#import "AliyunEffectStaticImage.h"
#import "AliyunEffectTimeFilter.h"
#import "AliyunIClipConstructor.h"
#import "AliyunIExporter.h"
#import "AliyunIExporterCallback.h"
#import "AliyunIPasterRender.h"
#import "AliyunIPlayer.h"
#import "AliyunIPlayerCallback.h"
#import "AliyunMoveAction.h"
#import "AliyunPasterManager.h"
#import "AliyunRotateAction.h"
#import "AliyunRotateByAction.h"
#import "AliyunRotateRepeatAction.h"
#import "AliyunRotateToAction.h"
#import "AliyunScaleAction.h"
#import "AliyunTransitionEffect.h"
#import "AliyunVideoParam.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 编辑模式枚举值

 - AliyunEditorModeNull:    Null
 - AliyunEditorModePlay:    播放模式
 - AliyunEditorModeExport:  合成导出模式
 */
typedef NS_ENUM(NSUInteger, AliyunEditorMode) {
    AliyunEditorModeNull,
    AliyunEditorModePlay,   
    AliyunEditorModeExport
};

/**
 编辑器
 */
@interface AliyunEditor : NSObject

/**
 播放，合成，渲染回调类
 */
@property(nonatomic, weak) id<AliyunIPlayerCallback, AliyunIExporterCallback, AliyunIRenderCallback> delegate;

/**
 初始化Editor

 @param taskPath taskPath文件夹路径
 @param preview 编辑预览视图
 @return Editor
 */
- (instancetype)initWithPath:(NSString *)taskPath preview:(UIView *)preview;

/**
 创建相关资源
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 参数不正确 ALIVC_COMMON_INVALID_PARAM
 组件初始化失败 ALIVC_SVIDEO_EDITOR_INIT_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_CREATE_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_RE_CREATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)startEdit;

/**
 销毁相关资源
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)stopEdit;

/**
 获取媒体片段构造器

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

 @param mv
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 解析动图失败 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 调用后，播放器将处于暂停状态
 */
- (int)applyMV:(AliyunEffectMV *)mv;

/**
 移除MV
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 调用后，播放器将处于暂停状态
*/
- (int)removeMV;

/**
 移除mv音乐
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 解析动图失败 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 调用后，播放器将处于暂停状态
 */
- (int)removeMVMusic;

/**
 使用音乐
 @param music music对象
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 调用后，播放器将处于暂停状态
 */
- (int)applyMusic:(AliyunEffectMusic *)music;

/**
 删除某一路音乐
 @param music 音乐
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 调用后，播放器将处于暂停状态
 */
- (int)removeMusic:(AliyunEffectMusic *)music;

/**
 移除所有音乐
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 调用后，播放器将处于暂停状态
 */
- (int)removeMusics;

/**
 添加配音
 @param dub 配音对象 支持变速功能
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 调用后，播放器将处于暂停状态
 */
- (int)applyDub:(AliyunEffectDub *)dub;

/**
 移除配音
 @param dub 配音对象
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 调用后，播放器将处于暂停状态
 */
- (int)removeDub:(AliyunEffectDub *)dub;

/**
 移除所有配音
 @return 返回值
 调用后，播放器将处于暂停状态
 */
- (int)removeDubs;

/**
 使用滤镜
 @param filter filter对象
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)applyFilter:(AliyunEffectFilter *)filter;

/**
 删除滤镜
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)removeFilter;

/**
 使用特效滤镜
 @param filter filter对象
 @return
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)applyAnimationFilter:(AliyunEffectFilter *)filter;

/**
 更新特效滤镜
 @param filter filter对象
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)updateAnimationFilter:(AliyunEffectFilter *)filter;

/**
 移除某个特效滤镜
 @param filter filter对象
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)removeAnimationFilter:(AliyunEffectFilter *)filter;

/**
 使用时间特效
 @param filter 特效对象
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 参数设置不正确 ALIVC_COMMON_INVALID_PARAM
 特效不支持（多个流的情况下）ALIVC_SVIDEO_EDITOR_TIME_EFFECT_NOT_SUPPORT
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILE
 调用后，播放器将处于暂停状态
 */
- (int)applyTimeFilter:(AliyunEffectTimeFilter *)filter;

/**
 API_AVAILABLE(3.7.0)

 删除某一个时间特效 目前只能删变速的时间特效
 @param filter 待删除的时间特效
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 调用后，播放器将处于暂停状态
 */
- (int)removeTimeFilter:(AliyunEffectTimeFilter *)filter;

/**
 删除全部的时间特效

 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED]
 调用后，播放器将处于暂停状态
 */
- (int)removeTimeFilter;

/**
 获取当前的时间特效类型

 @return 时间特效种类  TIME_EFFECT_NONE = 0, 无效果
 TIME_EFFECT_SPEED = 1,加速或者减速
 TIME_EFFECT_REPEAT = 2,反复
 TIME_EFFECT_INVERT = 3 倒放
 */
- (int)getTimeFilter;

/**
 加入静态贴纸

 @param staticImage 静态贴纸
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 图片类型不支持 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED
 */
- (int)applyStaticImage:(AliyunEffectStaticImage *)staticImage;

/**
 移除静态贴纸

 @param staticImage 静态贴纸
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)removeStaticImage:(AliyunEffectStaticImage *)staticImage;

/**
 使用涂鸦

 @param paintImage 涂鸦图片
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 图片类型不支持 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED
 */
- (int)applyPaint:(AliyunEffectImage *)paintImage;

/**
 API_AVAILABLE(3.7.0)

 添加转场   注意：
               ① 如果只有一个视频片段，不可调用此接口
               ② 转场的时长不能超过前后两段视频中最短的视频时长
               ③ 使用此接口前，先调用[_editor stopEdit]，然后调用此接口，接着调用 [_editor startEdit] 和[_player play]

 [----A视频段----] [----B视频段----] [----C视频段----]...[----N段视频----]
                 ^                ^                 ^
 clipIndex:      0                1                N-1


 @param transition 具体的转场
 @param clipIdx 视频片段交叉序列点
 @return 返回值为ALIVC_COMMON_RETURN_FAILED失败
 ALIVC_COMMON_RETURN_SUCCESS成功
 */
- (int)applyTransition:(AliyunTransitionEffect *)transition atIndex:(int)clipIdx;

/**
 API_AVAILABLE(3.7.0)

 更新转场   注意：
               ① 如果只有一个视频片段，不可调用此接口
               ② 转场的时长不能超过前后两段视频中最短的视频时长

 [----A视频段----] [----B视频段----] [----C视频段----]...[----N段视频----]
                 ^                ^                 ^
 clipIndex:      0                1                N-1


 @param transition 具体的转场
 @param clipIdx 视频片段交叉序列点
 @return 返回值为ALIVC_COMMON_RETURN_FAILED失败
 ALIVC_COMMON_RETURN_SUCCESS成功
 */
-(int)updateTransition:(AliyunTransitionEffect *)transition atIndex:(int)clipIdx;

/**
 API_AVAILABLE(3.7.0)

 删除某个转场效果  注意：
 使用此接口前，先调用[_editor stopEdit]，然后调用此接口，接着调用 [_editor startEdit] 和[_player play]

 @param clipIdx 序列号
 */
- (int)removeTransitionAtIndex:(int)clipIdx;

/**
 API_AVAILABLE(3.7.0)

 加帧动画

 注意：1.主流不支持alpha帧动画  2.在倒播特效下，不支持此功能
 @param obj 动画作用的对象
 @param action 动画
 */
- (void)add:(id<AliyunActionProtocol>)obj withFrameAnimation:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 删帧动画

 @param obj 动画作用的对象
 @param action 动画
 */
- (void)remove:(id<AliyunActionProtocol>)obj withFrameAnimation:(AliyunAction *)action;

/**
 删除涂鸦
 
 @param paintImage 涂鸦图片
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)removePaint:(AliyunEffectImage *)paintImage;

/**
 设置水印
 
 @param waterMark 水印
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 图片类型不支持 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED
 */
- (int)setWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置片尾水印

 AliyunEffectImage对象需要设置endtime属性，此属性代表距离视频结尾的时长。

 @param waterMark 片尾水印
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)setTailWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置是否静音

 @param mute 静音
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_AUDIO_PROCESS_CTL_INPUT_ERROR
 */
- (int)setMute:(BOOL)mute;

/**
 设置音量

 @param volume 音量：0-200
 默认值100,原始的音量大小
 大于100可能会破音，建议0-100
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_AUDIO_PROCESS_CTL_INPUT_ERROR
 */
- (int)setVolume:(int)volume;

/**
 设置混音权重

 @param weight 混音权重0-100
 设为100时，主流权重为0，只有配乐
 设为0时，配乐流权重为0，只有原音
 设为50时，主流和配乐流权重都为100
 如需单独调节每个流的音量权重，可以使用以下接口：
 - (int)setAudioWeight:(int)weight streamId:(int)streamId;
 - (int)setMainStreamsAudioWeight:(int)weight;
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 */
- (int)setAudioMixWeight:(int)weight;

/**
 设置单路音频流音量权重

 @param weight 权重 0-100，100 代表原始大小
 @param streamId 流id
 主流id:AliyunClip.streamId
 配乐流id：AliyunEffectMusic.effectVid
 MV音乐流id：AliyunEffectMV.audioEffectVid
 @return
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 */
- (int)setAudioWeight:(int)weight streamId:(int)streamId;

/**
 设置主流音量权重

 @param weight 混音权重 0-100
 100 代表原始大小
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)setMainStreamsAudioWeight:(int)weight;

/**
 设置单路音频去噪

 @param denoise 是否去噪
 @param streamId 流id
 AliyunEffectMusic流id：effectVid
 AliyunEffectMV流id：audioEffectVid
 @return
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 */
- (int)setAudioDenoise:(BOOL)denoise streamId:(int)streamId;

/**
 设置主流音频去噪

 @param denoise 是否去噪
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)setMainStreamsAudioDenoise:(BOOL)denoise;

/**
 设置单路流音效

 如果素材无音轨，该接口返回成功，但是没有效果
 @param type 音效类型
 @param weight 音效权重0-100
 @param streamId 流id
 @return 返回值
 */
- (int)setAudioEffect:(AliyunAudioEffectType)type weight:(int)weight streamId:(int)streamId;

/**
 去除单路流音效

 @param type 音效类型
 @param streamId 流id
 @return 返回值
 */
- (int)removeAudioEffect:(AliyunAudioEffectType)type streamId:(int)streamId;

/**
 设置主流音效

 如果素材无音轨，该接口返回成功，但是没有效果
 @param type 音效类型
 @param weight 音效权重0-100
 @return 返回值
 */
- (int)setMainStreamsAudioEffect:(AliyunAudioEffectType)type weight:(int)weight;

/**
 去除主流音效

 @param typ 音效类型
 @return 返回值
 */
- (int)removeMainStreamsAudioEffect:(AliyunAudioEffectType)typ;

/**
 画面填充模式

 @param mode  AliyunScaleModeFit = 0,      // 填充    
 AliyunScaleModeFill = 1         // 裁剪 
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)setScaleMode:(AliyunScaleMode)mode;

/**
 视频渲染最底层背景颜色

 在填充模式下具有效果
 @param color 颜色
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)setRenderBackgroundColor:(UIColor *)color;

/**
 API_AVAILABLE(3.7.0)

 在填充模式下，设置高斯模糊视频播放背景 支持多段时间段 注意：如果背景色为clearColor将默认是此效果，如果是非clearColor此接口才有效果

 @param blur 视频高斯模糊效果
 */
- (void)applyBlurBackgroundPlay:(AliyunEffectBlurBackground *)blur;

/**
 API_AVAILABLE(3.7.0)

 移除视频高斯模糊播放背景

 @param blur 视频高斯模糊效果
 */
- (void)removeBlurBackgroundPlay:(AliyunEffectBlurBackground *)blur;

#pragma mark - deprecated. It is not recommended to use the following methods.
/**
 API_AVAILABLE(3.7.0)

 添加动态播放模式 已废弃

 @param mode 播放模式
 */
- (void)applyRunningDisplayMode:(AliyunEffectRunningDisplayMode *)mode __deprecated_msg("deprecated, will remove");

/**
 API_AVAILABLE(3.7.0)

 删除动态播放模式 已废弃

 @param mode 播放模式
 */
- (void)removeRunningDisplayMode:(AliyunEffectRunningDisplayMode *)mode __deprecated_msg("deprecated, will remove");

/**
 request id
 */
- (NSString *)getRequestId __deprecated_msg("deprecated, will remove");

/**
 版本号
 */
+ (NSString *)version __deprecated_msg("deprecated, will remove");

/**
 设置最大内存缓存大小
 默认值250Mb，建议200M以上
 必须在startEdit之前或stopEdit后才能生效
 @param cacheSize 内存缓存大小，单位：byte
 */
- (void)setMaxCacheSize:(int)cacheSize __deprecated_msg("deprecated, will remove");

/**
 获取当前设置的最大内存缓存大小

 @return 内存缓存大小
 */
- (int)getMaxCacheSize __deprecated_msg("deprecated, will remove");

/**
 获取视频需要的最大内存缓存大小
 已废弃
 判断视频是否支持倒播，可以通过[AliyunNativeParser getGopSize]获取gop
 建议gop > 35的视频倒播转码
 @param path 视频路径
 @return 内存缓存大小
 */
- (int)getMaxEstimatedCacheSize:(NSString *)path __deprecated_msg("deprecated, will remove");

/**
 准备播放
 预解码部分音视频数据，加快起播速度
 @param mode 编辑模式
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 参数不正确 ALIVC_COMMON_INVALID_PARAM
 已废弃，无需调用
 */
- (int)prepare:(AliyunEditorMode)mode __deprecated_msg("deprecated, will remove");

/**
 添加视频路径 返回值为streamId

 @param path 视频路径
 Deprecated 建议使用getClipConstructor
 */
- (int)addPath:(NSString *)path startTime:(float)startTime duration:(float)duration fadeDuration:(float)fadeDuration inDuration:(float)inDuration outDruation:(float)outDuration mode:(int)mode __deprecated_msg("Use `IClipConstructor`");

/**
 添加图片路径 返回值为streamId

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
 @return 返回结果 本接口弃用，返回值为0
 第一段视频设置无效,转场时长不能超过最短视频时长的一半
 Deprecated 建议使用getClipConstructor获取IClipConstructor进行管理
 */
- (int)setClipFadeDuration:(CGFloat)fadeDuration inDuration:(CGFloat)inDuration outDuration:(CGFloat)outDuration atIndex:(NSInteger)index __deprecated_msg("Use `IClipConstructor`");

/**
 添加片尾水印

 @param image 图片
 @param frame
 @param duration 时长
 @return 返回值为片尾id或错误码  详细：如果返回值范围为 >0  && < ALIVC_FRAMEWORK_ERROR_START， 则为片尾id；否则为错误码。
 */
- (int)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration __deprecated_msg("use setTailWaterMark:(AliyunEffectImage *)waterMark");

/**
 添加视频水印

 @param imagePath 视频水印路径
 @param frame 水印frame
 @return 返回值为水印id或者错误码 详细：如果返回值范围为 >0  && < ALIVC_FRAMEWORK_ERROR_START， 则为水印id；否则为错误码。
 */
- (int)setWaterMark:(NSString *)imagePath frame:(CGRect)frame __deprecated_msg("use setWaterMark:(AliyunEffectImage *)waterMark");
@end
