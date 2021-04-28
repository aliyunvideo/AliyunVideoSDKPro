//
//  AlivcMixMediaInfo.h
//  QUSDK
//
//  Created by Vienta on 2019/5/14.
//  Copyright © 2019 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunVideoParam.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AliyunPureColorBorderInfo : NSObject
/**
 视频边框颜色
 */
/**
 The border color of the video
 */
@property (nonatomic, strong) UIColor *color;

/**
 视频边框宽度
 */
/**
 The border width of the video
 */
@property (nonatomic, assign) CGFloat width;

/**
 视频圆角半径
 */
/**
 The radius of the video's corner
 */
@property (nonatomic, assign) CGFloat cornerRadius;
@end



@interface AliyunMixMediaVideoInfo : NSObject

/**
 视图层级
 数值大的视图在上方，数值相同的合拍录制视频在文件视频上方
 */
/**
 The level of video view layer
 Bigger value above on lesser value layer
 If same value, the record video above on file video.
 */
@property (nonatomic, assign) NSInteger layerLevel;

/**
 视频边框信息
 */
/**
 The border info of the video
 */
@property (nonatomic, strong) AliyunPureColorBorderInfo *borderInfo;

/**
 视频窗口的位置大小
 */
/**
 The layout of the video in mix video
 */
@property (nonatomic, assign) CGRect frame;
@end



@interface AliyunMixMediaRecordVideoInfo: AliyunMixMediaVideoInfo
/**
 视频采集分辨率
 */
/**
 The resolution of the video
 */
@property (nonatomic, assign) CGSize resolution;
@end



@interface AliyunMixMediaFileVideoInfo : AliyunMixMediaVideoInfo
/**
 视频文件路径
 */
/**
 The file path of the video
 */
@property (nonatomic, copy) NSString *filePath;

/**
 参与合拍的视频开始时间（秒）
 */
/**
 The start time of the sample video of the duet.
 */
@property (nonatomic, assign) CGFloat streamStartTime;

/**
 参与合拍的视频结束时间
 */
@property (nonatomic, assign) CGFloat streamEndTime;
@end



@interface AliyunMixMediaInfoParam : NSObject

/**
 合拍窗口View 必须设置
 */
@property(nonatomic, strong) UIView *outputSizeView;

/**
 合拍摄像头录制的视频
 API_AVAILABLE(3.21.0)
 */
/**
 The video recorded by camera
 API_AVAILABLE(3.21.0)
 */
@property(nonatomic, strong) AliyunMixMediaRecordVideoInfo *recordVideoInfo;

/**
 参与合拍的视频
 API_AVAILABLE(3.21.0)
 */
/**
 The sample video of the duet
 API_AVAILABLE(3.21.0)
 */
@property(nonatomic, strong) AliyunMixMediaFileVideoInfo *mixVideoInfo;


/**
 合拍样本视频的窗口大小
 内部根据此frame在outputSizeView上展示样本播放窗口
 */
@property(nonatomic, assign) CGRect mixVideoViewFrame __deprecated_msg("use mixVideoInfo.frame instead");

/**
 合拍摄像头采集窗口的大小
 内部根据此frame在outputSizeView上展示采集窗口
 */
@property(nonatomic, assign) CGRect previewViewFrame __deprecated_msg("use recordVideoInfo.frame instead");

/**
 合拍摄像头录制的视频分辨率
 */
@property(nonatomic, assign) CGSize previewVideoSize __deprecated_msg("use recordVideoInfo.resolution instead");

/**
 参与合拍的视频路径
 */
@property(nonatomic, copy) NSString *mixVideoFilePath __deprecated_msg("use mixVideoInfo.filePath instead");

/**
 参与合拍的视频开始时间
 */
@property(nonatomic, assign) CGFloat streamStartTime __deprecated_msg("use mixVideoInfo.streamStartTime instead");

/**
 参与合拍的视频结束时间
 */
@property(nonatomic, assign) CGFloat streamEndTime __deprecated_msg("use mixVideoInfo.streamEndTime instead");

@end
