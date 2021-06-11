//
//  AliyunMicRecordSource.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/4/22.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunAudioRecordController.h"

/**
 机器声音采集类型 API_AVAILABLE(3.22.0)
 */
/**
 The type of audio capture API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSInteger, AliyunAudioUnitType) {
    /**
     参考kAudioUnitSubType_VoiceProcessingIO API_AVAILABLE(3.22.0)
     */
    /**
     Check the kAudioUnitSubType_VoiceProcessingIO API_AVAILABLE(3.22.0)
     */
    AliyunAudioUnitType_RemoteIO,
    /**
     参考kAudioUnitSubType_RemoteIO API_AVAILABLE(3.22.0)
     */
    /**
     Check the kAudioUnitSubType_RemoteIO API_AVAILABLE(3.22.0)
     */
    AliyunAudioUnitType_VoiceProcessingIO,
};

/**
 麦克风/机器声音源 API_AVAILABLE(3.22.0)
 */
/**
 The source of mic and source of device API_AVAILABLE(3.22.0)
 */
@interface AliyunMicRecordSource : NSObject<AliyunRecordDataSource>
@property (nonatomic, readonly) AliyunAudioUnitType unitType;
- (instancetype) initWithUnitType:(AliyunAudioUnitType)unitType;
@end

/**
 麦克风控制器 API_AVAILABLE(3.22.0)
 */
/**
 The Controller of mic API_AVAILABLE(3.22.0)
 */
@protocol AliyunMicRecordController <AliyunRecordController>
/**
 是否静音 API_AVAILABLE(3.22.0)
 */
/**
 mute API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) BOOL isMute; // 相当于weight = 0
@end
