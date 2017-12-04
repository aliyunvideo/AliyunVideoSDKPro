//
//  AliyunVideoParam.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/21.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AliyunVideoQuality) {
    AliyunVideoQualityVeryHight,
    AliyunVideoQualityHight,
    AliyunVideoQualityMedium,
    AliyunVideoQualityLow,
    AliyunVideoQualityPoor,
    AliyunVideoQualityExtraPoor
};


typedef NS_ENUM(NSInteger, AliyunScaleMode) {
    AliyunScaleModeFit,          // 填充
    AliyunScaleModeFill          // 裁剪
};

@interface AliyunVideoParam : NSObject
@property (nonatomic, assign) int fps;
@property (nonatomic, assign) int gop;
@property (nonatomic, assign) int bitrate;
@property (nonatomic, assign) AliyunVideoQuality videoQuality;
@property (nonatomic, assign) AliyunScaleMode scaleMode;

+ (instancetype)defaultVideoParam;

@end
