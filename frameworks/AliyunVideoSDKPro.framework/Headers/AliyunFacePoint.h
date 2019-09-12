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
/****
 The face id.
 */
@property (nonatomic, assign) NSInteger faceId;

/**
 左眼等比例的坐标值  例如:视频尺寸为(320, 320) 左眼位置为(100, 100) 那么leftEye为(100.0/320, 100.0/320)  下同
 */
/****
 The coordinate of the left eye. For example, if the video resolution is (320, 320) and the position of the centroid of the left eye is (100, 100), the coordinate of the left eye is (100.0/320, 100.0/320).
 */
@property (nonatomic, assign) CGPoint leftEye;

/**
 右眼等比例的坐标值
 */
/****
 The coordinate of the right eye.
 */
@property (nonatomic, assign) CGPoint rightEye;

/**
 嘴等比例的坐标值
 */
/****
 The coordinate of the mouth.
 */
@property (nonatomic, assign) CGPoint mouth;


-(float*) getData;
-(int) getDataLength;

@end
