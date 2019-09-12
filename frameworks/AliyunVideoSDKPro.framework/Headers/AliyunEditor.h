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
/****
 Edit modes in an enumerated type.

 - AliyunEditorModeNull:    Null
 - AliyunEditorModePlay:    Playback
 - AliyunEditorModeExport:  Export 
 */
typedef NS_ENUM(NSUInteger, AliyunEditorMode) {
    AliyunEditorModeNull,
    AliyunEditorModePlay,   
    AliyunEditorModeExport
};

/**
 编辑器
 */
/****
 A class that defines editors.
 */
@interface AliyunEditor : NSObject

/**
 播放，合成，渲染回调类
 */
/****
 The playback, export, and rendering callbacks.
 */
@property(nonatomic, weak) id<AliyunIPlayerCallback, AliyunIExporterCallback, AliyunIRenderCallback> delegate;

/**
 初始化Editor

 @param taskPath taskPath文件夹路径
 @param preview 编辑预览视图
 @return Editor
 */
/****
 Initializer.

 @param taskPath The path of the taskPath folder.
 @param preview The view for preview. 
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
/****
 Creates resources.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_COMMON_INVALID_PARAM if the parameter setting is incorrect.
 ALIVC_SVIDEO_EDITOR_INIT_FAILED if an error occurs while initializing components.
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
/****
 Releases resources.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 */
- (int)stopEdit;

/**
 获取媒体片段构造器

 对媒体片段修改操作，必须在startEdit之前或stopEdit后才能生效
 @return 媒体片段构造器
 */
/****
 Gets a clip constructor.
 Changes to media clips only take effect before startEdit is called or after stopEdit is called.
 @return A clip constructor.
 */
- (id<AliyunIClipConstructor>)getClipConstructor;

/**
 获取播放器接口实例

 @return AliyunIPlayer
 */
/****
 Gets a player object.

 @return AliyunIPlayer
 */
- (id<AliyunIPlayer>)getPlayer;

/**
 获取导出接口实例

 @return AliyunIExporter
 */
/****
 Gets an exporter object.

 @return AliyunIExporter
 */
- (id<AliyunIExporter>)getExporter;

/**
 获取PasterRender实例

 @return PasterRender
 */
/****
 Gets a PasterRender object.

 @return PasterRender
 */
- (id<AliyunIPasterRender>)getPasterRender;

/**
 获取动图管理类

 @return AliyunPasterManager
 */
/****
 Gets a sticker manager object.

 @return AliyunPasterManager
 */
- (AliyunPasterManager *)getPasterManager;

/**
 获取渲染窗口像素大小

 @return 渲染窗口像素大小
 */
/****
 Gets the size of the preview window. 

 @return The size of the preview window.
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
/****
 Applies an MV effect. 

 @param mv
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED if an error occurs during image parsing. 
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 The player is paused after this method is invoked.
 */
- (int)applyMV:(AliyunEffectMV *)mv;

/**
 移除MV
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 调用后，播放器将处于暂停状态
*/
/****
 Removes an MV effect.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 The player is paused after this method is invoked.
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
/****
 Removes audio from an MV effect.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED if an error occurs during image parsing.
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 The player is paused after this method is invoked.
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
/****
 Applies a music effect.
 @param music The music effect to be applied.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 The player is paused after this method is invoked.
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
/****
 Removes a music effect.
 @param music The music effect to be removed.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 The player is paused after this method is invoked.
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
/****
 Removes all music effects.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 The player is paused after this method is invoked.
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
/****
 Applies a voiceover effect. 
 @param dub The voiceover effect to be applied. Playback speed change is supported.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED
 The player is paused after this method is invoked.
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
/****
 Removes a voiceover effect.
 @param dub The voiceover effect to be removed.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 The player is paused after this method is invoked.
 */
- (int)removeDub:(AliyunEffectDub *)dub;

/**
 移除所有配音
 @return 返回值
 调用后，播放器将处于暂停状态
 */
/****
 Removes all voiceover effects.
 @return A return value.
 The player is paused after this method is invoked.
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
/****
 Applies a filter effect.
 @param filter The filter effect to be applied.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Removes a filter effect.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Applies an animated filter effect.
 @param filter The filter effect to be applied.
 @return
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Updates an animated filter effect.
 @param filter The filter effect to be updated.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Removes an animated filter effect.
 @param filter The filter effect to be removed.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Applies a timeline effect.
 @param filter The timeline effect to be applied.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_COMMON_INVALID_PARAM if the parameter setting is incorrect.
 ALIVC_SVIDEO_EDITOR_TIME_EFFECT_NOT_SUPPORT if the effect is not supported when there are multiple audio or video streams.
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILE
 The player is paused after this method is invoked.
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
/****
 API_AVAILABLE(3.7.0)

 Removes a timeline effect. This method can only remove timeline effects that change playback speeds.
 @param filter The timeline effect to be removed.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 The player is paused after this method is invoked.
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
/****
 Removes all timeline effects.

 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_AUDIO_PROCESS_FILE_STREAM_LIST_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_OPTION_LIST_FAILED]
 The player is paused after this method is invoked.
 */
- (int)removeTimeFilter;

/**
 获取当前的时间特效类型

 @return 时间特效种类  TIME_EFFECT_NONE = 0, 无效果
 TIME_EFFECT_SPEED = 1,加速或者减速
 TIME_EFFECT_REPEAT = 2,反复
 TIME_EFFECT_INVERT = 3 倒放
 */
/****
 Gets the type of the current timeline effect.

 @return The type of the current timeline effect.
 TIME_EFFECT_NONE = 0 No effect,
 TIME_EFFECT_SPEED = 1 Change the playback speed,
 TIME_EFFECT_REPEAT = 2 Repeat the playback,
 TIME_EFFECT_INVERT = 3 Reverse the playback.
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
/****
 Applies an image. 

 @param staticImage The image object to be applied.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST if the image file does not exist.
 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED if the image file type is not supported.
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
/****
 Removes an image.

 @param staticImage The image object to be removed.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Applies a doodle.

 @param paintImage The doodle object to be applied.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST if the image file does not exist.
 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED if the image file type is not supported.
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
/****
 API_AVAILABLE(3.7.0)

 Applies a transition effect. Note：
               ① Do not call this method if there is only one video clip.
               ② The duration of a transition must not be greater than the duration of the video clips before or after this transition.
               ③ To invoke this method, [_editor stopEdit] must be invoked first. [_editor startEdit] and [_player play] must be invoked after this method.

 [----Video clip A----] [----Video clip B----] [----Video clip C----]...[----Video clip N----]
                      ^                      ^                      ^
 clipIndex:           0                      1                     N-1


 @param transition The transition effect to be applied.
 @param clipIdx The position where the transition effect is inserted.
 @return 
 ALIVC_COMMON_RETURN_FAILED if the invocation fails.
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 */
- (int)applyTransition:(AliyunTransitionEffect *)transition atIndex:(int)clipIdx;

/**
 API_AVAILABLE(3.7.0)

 删除某个转场效果  注意：
 使用此接口前，先调用[_editor stopEdit]，然后调用此接口，接着调用 [_editor startEdit] 和[_player play]

 @param clipIdx 序列号
 */
/****
 API_AVAILABLE(3.7.0)

 Removes a transition effect.  Note:
 To invoke this method, [_editor stopEdit] must be invoked first. [_editor startEdit] and [_player play] must be invoked after this method.

 @param clipIdx The position of the transition effect to be removed.
 */
- (int)removeTransitionAtIndex:(int)clipIdx;

/**
 API_AVAILABLE(3.7.0)

 加帧动画

 注意：1.主流不支持alpha帧动画  2.在倒播特效下，不支持此功能
 @param obj 动画作用的对象
 @param action 动画
 */
/****
 API_AVAILABLE(3.7.0)

 Applies an animation.
 
 Note: 1. Alpha animations cannot be applied to source streams. 2. This method is not applicable when the reverse playback effect is used.
 @param obj The object that the animation is applied to.
 @param action The animation to be applied.
 */
- (void)add:(id<AliyunActionProtocol>)obj withFrameAnimation:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 删帧动画

 @param obj 动画作用的对象
 @param action 动画
 */
/****
 API_AVAILABLE(3.7.0)

 Removes an animation.

 @param obj The object that the animation is applied to.
 @param action The animation to be removed.
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
/****
 Removes a doodle.
 
 @param paintImage The doodle object to be removed.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Adds a watermark.
 
 @param waterMark The watermark object to be added.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST if the image file does not exist.
 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED if the image file type is not supported. 
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
/****
 Adds a watermark to the end of the video.

 The endtime property of the AliyunEffectImage must be specified. 
 This property indicates the time interval between the time when the watermark appears and the end time of the video.

 @param waterMark The watermark object to be added.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST if the image file does not exist.
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
/****
 Mutes or unmutes the video.

 @param mute Whether to mute the video.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Sets the volume.

 @param volume Valid values: [0, 200]
 Default is 100, which is the original volume size.
 It is recommended to set a value between 0 and 100 to avoid loss of audio quality.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Sets the mixing weights of audio streams.

 @param weight Valid values: [0, 100]
 A value of 100 indicates that the weight of the source stream is set to 0. The source stream is muted.  
 A value of 0 indicates that the weights of material streams are all set 0. All material streams are muted. 
 A value of 50 indicates that the weights of the source stream and material streams are all set to 100. 
 Use the following methods to change the volumes of audio streams by id.
 - (int)setAudioWeight:(int)weight streamId:(int)streamId;
 - (int)setMainStreamsAudioWeight:(int)weight;
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Sets the volume of an audio stream.

 @param weight Valid values: [0, 100]
 A value of 100 indicates the original volume size.
 @param streamId The stream id.
 The source stream id: AliyunClip.streamId
 The material stream id：AliyunEffectMusic.effectVid
 The MV stream id：AliyunEffectMV.audioEffectVid
 @return
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Sets the volume of the source stream.

 @param weight Valid values: [0, 100]
 A value of 100 indicates the original volume size.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Denoises an audio stream.

 @param denoise Whether to denoise the stream.
 @param streamId The stream id.
 The material stream id：AliyunEffectMusic.effectVid
 The MV stream id：AliyunEffectMV.audioEffectVid
 @return
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Denoises the source stream.

 @param denoise Whether to denoise the stream.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
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
/****
 Adds a sound effect to an audio stream.
 
 If there is no audio track in the target stream, the invocation has no effect.
 @param type The effect type.
 @param weight The weight of the effect. Valid values: [0, 100]
 @param streamId The stream id.
 @return A return value.
 */
- (int)setAudioEffect:(AliyunAudioEffectType)type weight:(int)weight streamId:(int)streamId;

/**
 去除单路流音效

 @param type 音效类型
 @param streamId 流id
 @return 返回值
 */
/****
 Removes a sound effect from an audio stream.

 @param type The effect type.
 @param streamId The stream id.
 @return A return value.
 */
- (int)removeAudioEffect:(AliyunAudioEffectType)type streamId:(int)streamId;

/**
 设置主流音效

 如果素材无音轨，该接口返回成功，但是没有效果
 @param type 音效类型
 @param weight 音效权重0-100
 @return 返回值
 */
/****
 Adds a sound effect to the source stream.
 
 If there is no audio track in the target stream, the invocation has no effect.
 @param type The effect type.
 @param weight The weight of the effect. Valid values: [0, 100]
 @return A return value.
 */
- (int)setMainStreamsAudioEffect:(AliyunAudioEffectType)type weight:(int)weight;

/**
 去除主流音效

 @param typ 音效类型
 @return 返回值
 */
/****
 Removes a sound effect from the source stream.

 @param typ The effect type.
 @return A return value.
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
/****
 Sets the video display mode.

 @param mode  AliyunScaleModeFit = 0,          // Fill mode
 AliyunScaleModeFill = 1          // Cut mode
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)setScaleMode:(AliyunScaleMode)mode;

/**
 视频渲染最底层背景颜色

 在填充模式下具有效果
 如果color设置为clearColor 那么默认背景为视频高斯模糊播放效果
 @param color 颜色
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
/****
 Sets the background color.

 This method only takes effect when the display mode is set to fill.
 If the background color is set to clearColor, the Gaussian blur effect is used to fill the background by default.
 @param color The background color.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the editor's state is incorrect.
 */
- (int)setRenderBackgroundColor:(UIColor *)color;

/**
 API_AVAILABLE(3.7.0)

 在填充模式下，设置高斯模糊视频播放背景 支持多段时间段 注意：如果背景色为clearColor将默认是此效果，如果是非clearColor此接口才有效果

 @param blur 视频高斯模糊效果
 */
/****
 API_AVAILABLE(3.7.0)

 Applies a Gaussian blur effect to the background. Supports multiple time periods.
 This method only takes effect when the display mode is set to fill and the background color is not set to clearColor.
 If the background color is set to clearColor, the Gaussian blur effect is used to fill the background by default.

 @param blur The Gaussian blur effect to be applied.
 */
- (void)applyBlurBackgroundPlay:(AliyunEffectBlurBackground *)blur;

/**
 API_AVAILABLE(3.7.0)

 移除视频高斯模糊播放背景

 @param blur 视频高斯模糊效果
 */
/****
 API_AVAILABLE(3.7.0)

 Removes a Gaussian blur effect.

 @param blur The Gaussian blur effect to be removed.
 */
- (void)removeBlurBackgroundPlay:(AliyunEffectBlurBackground *)blur;

#pragma mark - deprecated. It is not recommended to use the following methods.
/**
 API_AVAILABLE(3.7.0)

 添加动态播放模式 已废弃

 @param mode 播放模式
 */
/****
 API_AVAILABLE(3.7.0)

 Applies a display mode to a specified object.

 @param mode The display mode to be applied.
 */
- (void)applyRunningDisplayMode:(AliyunEffectRunningDisplayMode *)mode __deprecated_msg("deprecated, will remove");

/**
 API_AVAILABLE(3.7.0)

 删除动态播放模式 已废弃

 @param mode 播放模式
 */
/****
 API_AVAILABLE(3.7.0)

 Removes a display mode.

 @param mode The display mode to be removed.
 */
- (void)removeRunningDisplayMode:(AliyunEffectRunningDisplayMode *)mode __deprecated_msg("deprecated, will remove");

/**
 request id
 */
/****
 The request id.
 */
- (NSString *)getRequestId __deprecated_msg("deprecated, will remove");

/**
 版本号
 */
/****
 The SKD version.
 */
+ (NSString *)version __deprecated_msg("deprecated, will remove");

/**
 设置最大内存缓存大小
 默认值250Mb，建议200M以上
 必须在startEdit之前或stopEdit后才能生效
 @param cacheSize 内存缓存大小，单位：byte
 */
/****
 Sets the maximum cache memory size.
 Default is 250 MB. It recommended to set a value greater than 200 MB.
 This method must be invoked before startEdit or after stopEdit.
 @param cacheSize The cache memory size in bytes.
 */
- (void)setMaxCacheSize:(int)cacheSize __deprecated_msg("deprecated, will remove");

/**
 获取当前设置的最大内存缓存大小

 @return 内存缓存大小
 */
/****
 Gets the maximum cache memory size.
 
 @return The cache memory size.
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
/****
 Gets the maximum cache memory size required for video processing.
 Deprecated.
 To see if the video can be played backwards, use [AliyunNativeParser getGopSize] to get the GOP size.
 If the GOP size of a video is greater than 35, it is recommended to transcode the video before calling the reverse playback method.
 @param path The path to the video file.
 @return The cache memory size.
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
/****
 Gets prepared for playback. 
 Predecoding is performed to speed up the playback.
 @param mode The edit mode.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_PARAM if the parameter setting is incorrect.
 Deprecated.
 */
- (int)prepare:(AliyunEditorMode)mode __deprecated_msg("deprecated, will remove");

/**
 添加视频路径 返回值为streamId

 @param path 视频路径
 Deprecated 建议使用getClipConstructor
 */
/****
 Adds a video path. The return value is the streamId of the video.

 @param path The path of the video file.
 Deprecated. It is recommended to use getClipConstructor instead.
 */
- (int)addPath:(NSString *)path startTime:(float)startTime duration:(float)duration fadeDuration:(float)fadeDuration inDuration:(float)inDuration outDruation:(float)outDuration mode:(int)mode __deprecated_msg("Use `IClipConstructor`");

/**
 添加图片路径 返回值为streamId

 @param path 图片路径
 Deprecated 建议使用getClipConstructor获取IClipConstructor进行管理
 */
/****
 Adds an image path. The return value is the streamId of the image.

 @param path The path of the image file.
 Deprecated. It is recommended to use getClipConstructor to get IClipConstructor for management.
 */
- (int)addImagePath:(NSString *)path duration:(float)duration fadeDuration:(float)fadeDuration inAnimateDuration:(float)inDuration outAnimateDuration:(float)outDuration mode:(int)mode __deprecated_msg("Use `IClipConstructor`");

/**
 获取所有播放的视频的本地路径

 @return 路径数组
 Deprecated 建议使用getClipConstructor获取IClipConstructor进行管理
 */
/****
 Gets the paths of all video files that are played. 

 @return The paths in an array.
 Deprecated. It is recommended to use getClipConstructor to get IClipConstructor for management.
 */
- (NSArray *)getVideoUrls __deprecated_msg("Use `IClipConstructor`");

/**
 获取媒体片段

 @return 媒体片段数组
 Deprecated 建议使用getClipConstructor获取IClipConstructor进行管理
 */
/****
 Gets all media clips.

 @return The media clips in an array.
 Deprecated. It is recommended to use getClipConstructor to get IClipConstructor for management.
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
/****
 Sets the transition duration. 

 @param fadeDuration The duration of the transition.
 @param inDuration Invalid parameter.
 @param outDuration Invalid parameter.
 @param index The video index.
 @return This method is deprecated. The return value is 0.
 The index cannot be set to indicate the first video clip. 
 The transition duration must not be greater than half the duration of the shortest video clip.
 Deprecated. It is recommended to use getClipConstructor to get IClipConstructor for management.
 */
- (int)setClipFadeDuration:(CGFloat)fadeDuration inDuration:(CGFloat)inDuration outDuration:(CGFloat)outDuration atIndex:(NSInteger)index __deprecated_msg("Use `IClipConstructor`");

/**
 添加片尾水印

 @param image 图片
 @param frame
 @param duration 时长
 @return 返回值为片尾id或错误码  详细：如果返回值范围为 >0  && < ALIVC_FRAMEWORK_ERROR_START， 则为片尾id；否则为错误码。
 */
/****
 Adds a watermark to the end of the video.

 @param image The watermark image to be added.
 @param frame
 @param duration The display duration of the watermark.
 @return The watermark id or an error code.
 */
- (int)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration __deprecated_msg("use setTailWaterMark:(AliyunEffectImage *)waterMark");

/**
 添加视频水印

 @param imagePath 视频水印路径
 @param frame 水印frame
 @return 返回值为水印id或者错误码 详细：如果返回值范围为 >0  && < ALIVC_FRAMEWORK_ERROR_START， 则为水印id；否则为错误码。
 */
/****
 Adds a watermark.

 @param imagePath The path of the watermark image to be added.
 @param frame The size of the watermark in the video.
 @return The watermark id or an error code.
 */
- (int)setWaterMark:(NSString *)imagePath frame:(CGRect)frame __deprecated_msg("use setWaterMark:(AliyunEffectImage *)waterMark");
@end
