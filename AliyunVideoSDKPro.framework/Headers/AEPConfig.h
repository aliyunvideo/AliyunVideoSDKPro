//
//  AEPConfig.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunVideoParam.h"
#import <UIKit/UIKit.h>

/**
 工程配置
 */
/**
 The config of editor project
 */
@interface AEPConfig : NSObject

/**
 两个I帧之间的间隔，GOP大小
 */
/**
 The Group of picture
 */
@property (nonatomic, assign, readonly) int GOP;

/**
 视频质量
 */
/**
 The video quality.
 */
@property (nonatomic, assign, readonly) AliyunVideoQuality videoQuality;

/**
 码率

 单位bps 建议：
 480P:1000000-2000000
 540P:2000000-3000000
 720P:2000000-4000000
 1080:2000000-6000000
 设置bitrate参数后，videoQuality设置无效
 */
/**
 The bitrate.
 
 Unit: bit/s
 Recommended values:
 480P: 1,000,000-2,000,000
 540P: 2,000,000-3,000,000
 720P: 2,000,000-4,000,000
 1080: 2,000,000-6,000,000
 If specified, the bitrate parameter overrides the videoQuality parameter.
 */
@property (nonatomic, assign, readonly) int bitrate;

/**
 帧率

 默认25 建议20 - 60 不超过60
 */
/**
 The frame rate.
 
 Default is 25. Recommended values: [20, 60]
 */
@property (nonatomic, assign, readonly) int FPS;

/**
 视频质量因子
 默认值：23
 */
/**
 The video quality factor
 default: 23
 */
@property (nonatomic, assign, readonly) int CRF;

/**
 编码类型
 */
/**
 The encoder type.
 */
@property (nonatomic, assign, readonly) AliyunVideoCodecType videoCodec;

/**
 缩放比
 默认值：1.0
 */
/**
 The scale
 default: 1.0
 */
@property (nonatomic, assign, readonly) float scale;

/**
 视频输出宽度
 */
/**
 The video output width
 */
@property (nonatomic, assign, readonly) int outputWidth;

/**
 视频输出高度
 */
/**
 The video output height
 */
@property (nonatomic, assign, readonly) int outputHeight;

/**
 是否静音
 */
/**
 The Mute value
 */
@property (nonatomic, assign, readonly) BOOL mute;

/**
 音量
 */
/**
 The Volume
 */
@property (nonatomic, assign, readonly) int volume;

/**
 背景颜色
 */
/**
 The background Color
 */
@property (nonatomic, strong, readonly) UIColor *backgroundColor;

/**
 裁剪模式

 - AliyunScaleModeFit: 裁剪
 - AliyunScaleModeFill: 填充
 */
@property (nonatomic, assign, readonly) AliyunScaleMode displayMode;

@end
