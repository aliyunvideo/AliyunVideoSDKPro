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

@interface AliyunMixMediaInfoParam : NSObject

/**
 合拍窗口View 必须设置
 */
/****
 The view of the duet. Required. 
 */
@property(nonatomic, strong) UIView *outputSizeView;

/**
 合拍样本视频的窗口大小
 内部根据此frame在outputSizeView上展示样本播放窗口
 */
/****
 The size of the view for displaying the sample video of the duet.
 This parameter is used to render the view for displaying the sample video on the view of the duet, outputSizeView.
 */
@property(nonatomic, assign) CGRect mixVideoViewFrame;

/**
 合拍摄像头采集窗口的大小
 内部根据此frame在outputSizeView上展示采集窗口
 */
/****
 The size of the view for displaying the video captured by camera.  
 This parameter is used to render the view for displaying the video captured by camera on the view of the duet, outputSizeView.
 */
@property(nonatomic, assign) CGRect previewViewFrame;

/**
 合拍摄像头录制的视频分辨率
 */
/****
 The resolution of the video recorded by camera. 
 */
@property(nonatomic, assign) CGSize previewVideoSize;

/**
 参与合拍的视频路径
 */
/****
 The path of the sample video of the duet.
 */
@property(nonatomic, copy) NSString *mixVideoFilePath;

/**
 参与合拍的视频开始时间
 */
/****
 The start time of the sample video of the duet.
 */
@property(nonatomic, assign) CGFloat streamStartTime;

/**
 参与合拍的视频结束时间
 */
/****
 The end time of the sample video of the duet.
 */
@property(nonatomic, assign) CGFloat streamEndTime;

@end
