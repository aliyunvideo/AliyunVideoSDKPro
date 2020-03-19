//
//  AliyunNativeParser.h
//  QUSDK
//
//  Created by Worthy on 2017/6/29.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

#define ALIYUN_VIDEO_STREAM_DIC_KEY_START 0
#define ALIYUN_VIDEO_STREAM_INDEX (ALIYUN_VIDEO_STREAM_DIC_KEY_START)
#define ALIYUN_VIDEO_CODEC (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 1)
#define ALIYUN_VIDEO_START_TIME (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 2)
#define ALIYUN_VIDEO_DURATION (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 3)
#define ALIYUN_VIDEO_FRAME_COUNT (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 4)
#define ALIYUN_VIDEO_BIT_RATE (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 5)
#define ALIYUN_VIDEO_WIDTH (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 6)
#define ALIYUN_VIDEO_HEIGHT (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 7)
#define ALIYUN_VIDEO_CODEC_WIDTH (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 8)
#define ALIYUN_VIDEO_CODEC_HEIGHT (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 9)
#define ALIYUN_VIDEO_FORMAT (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 10)
#define ALIYUN_VIDEO_GOP (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 11)
#define ALIYUN_VIDEO_MAX_BFRAME (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 12)
#define ALIYUN_VIDEO_FPS (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 13)      //
#define ALIYUN_VIDEO_ROTATION (ALIYUN_VIDEO_STREAM_DIC_KEY_START + 14) //

#define ALIYUN_AUDIO_STREAM_DIC_KEY_START 15
#define ALIYUN_AUDIO_STREAM_INDEX (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 0)
#define ALIYUN_AUDIO_CODEC (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 1)
#define ALIYUN_AUDIO_START_TIME (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 2)
#define ALIYUN_AUDIO_DURATION (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 3)
#define ALIYUN_AUDIO_FRAME_COUNT (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 4)
#define ALIYUN_AUDIO_BIT_RATE (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 5)
#define ALIYUN_AUDIO_CHANNELS (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 6)
#define ALIYUN_AUDIO_SAMPLE_RATE (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 7)
#define ALIYUN_AUDIO_FORAMT (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 8)
#define ALIYUN_AUDIO_FRAME_SAMPLES (ALIYUN_AUDIO_STREAM_DIC_KEY_START + 9) // PER CHANNEL

#define ALIYUN_FILE_DIC_KEY_START 25
#define ALIYUN_FILE_NAME (ALIYUN_FILE_DIC_KEY_START + 0)
#define ALIYUN_FILE_FORMAT (ALIYUN_FILE_DIC_KEY_START + 1)
#define ALIYUN_FILE_START_TIME (ALIYUN_FILE_DIC_KEY_START + 2)
#define ALIYUN_FILE_DURATION (ALIYUN_FILE_DIC_KEY_START + 3)
#define ALIYUN_FILE_BIT_RATE (ALIYUN_FILE_DIC_KEY_START + 4)
#define DIC_KEY_END 30

extern NSString *const AliyunNativeParserUnknown;

/**
 视频参数解析器
 */
@interface AliyunNativeParser : NSObject

/**
 初始化参数解析器

 @param path 文件路径
 @return 解析器示例
 */
- (instancetype)initWithPath:(NSString *)path;

/**
 获取文件基本参数

 @param key 参数名
 @return 参数值，统一为string格式
 例：获取视频时长
 CGFloat duration = [[_parser getValueForKey:ALIYUN_VIDEO_DURATION]
                                        integerValue]/1000000.0f;

 */
- (NSString *)getValueForKey:(NSInteger)key;

/**
 获取视频编码格式

 @return 视频编码格式
 内部封装了getValueForKey:方法
 */
- (NSString *)getVideoCodec;

/**
 获取视频时长

 @return 视频时长
 内部封装了getValueForKey:方法
 */
- (CGFloat)getVideoDuration;

/**
 获取视频帧数

 @return 视频帧数
 内部封装了getValueForKey:方法
 */
- (NSInteger)getVideoFrameCount;

/**
 获取视频帧率

 @return 视频帧率
 内部封装了getValueForKey:方法
 */
-(NSInteger)getVideoFrameRate;

/**
 获取视频码率

 @return 视频码率
 内部封装了getValueForKey:方法
 */
- (NSInteger)getVideoBitrate;

/**
 获取视频宽度

 @return 视频宽度
 内部封装了getValueForKey:方法
 */
- (NSInteger)getVideoWidth;

/**
 获取视频高度

 @return 视频高度
 内部封装了getValueForKey:方法
 */
- (NSInteger)getVideoHeight;

/**
 获取音频编码格式

 @return 音频编码格式
 内部封装了getValueForKey:方法
 */
- (NSString *)getAudioCodec;

/**
 获取音频时长

 @return 音频时长
 内部封装了getValueForKey:方法
 */
- (CGFloat)getAudioDuration;

/**
 获取音频帧数

 @return 音频帧数
 内部封装了getValueForKey:方法
 */
- (NSInteger)getAudioFrameCount;

/**
 获取音频码率

 @return 音频码率
 内部封装了getValueForKey:方法
 */
- (NSInteger)getAudioBitrate;

/**
 获取音频声道数

 @return 音频声道数
 内部封装了getValueForKey:方法
 */
- (NSInteger)getAudioChannels;

/**
 获取音频采样率

 @return 音频采样率
 内部封装了getValueForKey:方法
 */
- (NSInteger)getAudioSampleRate;

/**
 获取视频文件时长

 @return 视频文件时长
 内部封装了getValueForKey:方法
 */
- (CGFloat)getFileDuration;

/**
 获取文件格式

 @return 文件格式
 内部封装了getValueForKey:方法
 */
- (NSString *)getFileFormat;

/**
 获取文件码率

 @return 文件码率
 内部封装了getValueForKey:方法
 */
- (NSInteger)getFileBitrate;

/**
 获取视频gop

 @return gop
 */
- (NSInteger)getGopSize;

/**
 检查视频是否存在b帧

 @return 是否存在b帧
 */
- (BOOL)checkBFrame __deprecated_msg("deprecated");

/**
 检查视频是否支持倒播

 @return 是否支持倒播
 */
- (BOOL)checkInvertAvailable __deprecated_msg("deprecated");

/**
 获取视频最大缓存大小

 @return 视频最大缓存大小
 */
- (int)getMaxEstimatedCacheSize __deprecated_msg("deprecated");
@end
