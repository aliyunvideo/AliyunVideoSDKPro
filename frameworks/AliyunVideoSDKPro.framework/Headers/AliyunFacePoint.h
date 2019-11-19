//
//  FaceModel.h
//  qupairecorder
//
//  Created by 天 王 on 2016/12/26.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AliyunFacePoint : NSObject

/**
 faceId
 */
@property (nonatomic, assign) NSInteger faceId;

/**
 左眼等比例的坐标值  例如:视频尺寸为(320, 320) 左眼位置为(100, 100) 那么leftEye为(100.0/320, 100.0/320)  下同
 */
@property (nonatomic, assign) CGPoint leftEye;

/**
 右眼等比例的坐标值
 */
@property (nonatomic, assign) CGPoint rightEye;

/**
 嘴等比例的坐标值
 */
@property (nonatomic, assign) CGPoint mouth;


-(float*) getData;
-(int) getDataLength;

@end
