//
//  AliyunEventManager.h
//  QUSDK
//
//  Created by Worthy on 2017/8/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVAsset+AliyunSDKInfo.h"
#define DefaultEventManager [AliyunEventManager sharedManager]

typedef NS_ENUM(NSInteger, AliyunEvent) {
    AliyunEventRecordInit = 2001,
    AliyunEventRecordStart,
    AliyunEventRecordStop,
    AliyunEventRecordDelete,
    AliyunEventRecordFinish,
    AliyunEventRecordError,
    AliyunEventRecordPaster,
    AliyunEventRecordMusic,
    AliyunEventRecordFilter,
    AliyunEventRecordRate,
    AliyunEventRecordBeauty,
    AliyunEventRecordPosition,
    AliyunEventEditInit = 3001,
    AliyunEventEditFilter = 3005,
    AliyunEventEditMV,
    AliyunEventEditExportStart = 3011,
    AliyunEventEditExportCancel,
    AliyunEventEditExportError = 3016,
    AliyunEventEditExportFinish,
    AliyunEventTranscodeStart = 8001,
    AliyunEventTranscodeCancel,
    AliyunEventTranscodeError,
    AliyunEventTranscodeFinish,
    AliyunEventImporterAddVideo = 9001,
    AliyunEventImporterAddImage = 9002,
    AliyunEventImporterFinish = 9003,
};

typedef struct AliyunVideoEventInfo {
    int bitrate;
    int fps;
    int vduration;
    int aduration;
    int64_t crc;
} AliyunVideoEventInfo;


@interface AliyunEventManager : NSObject

@property (nonatomic, copy) NSString *requestID;
@property (nonatomic, assign) BOOL enabled;

+ (instancetype)sharedManager;

- (void)sendEvent:(AliyunEvent)event params:(NSDictionary *)params;

- (AliyunVideoEventInfo)videoInfoWithPath:(NSString *)path;

- (int64_t)crc64WithPath:(NSString *)path;

- (void)refreshRequestID;

@end
