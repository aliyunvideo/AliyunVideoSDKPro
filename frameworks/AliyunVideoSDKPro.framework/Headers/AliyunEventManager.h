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
    AliyunEventRecordSuccess,
    AliyunEventRecordDelete,
    AliyunEventRecordFinish,
    AliyunEventRecordError,
    AliyunEventRecordPaster,
    AliyunEventRecordMusic,
    AliyunEventRecordFilter,
    AliyunEventRecordRate,
    AliyunEventRecordBeauty,
    AliyunEventRecordPosition,
    AliyunEventRecordStop,
    AliyunEventEditInit = 3001,
    AliyunEventEditFilter = 3005,
    AliyunEventEditMV,
    AliyunEventEditExportStart = 3011,
    AliyunEventEditExportCancel,
    AliyunEventEditExportError = 3016,
    AliyunEventEditExportFinish = 3017,
    AliyunEventTranscodeStart = 8001,
    AliyunEventTranscodeCancel,
    AliyunEventTranscodeError,
    AliyunEventTranscodeFinish,
    AliyunEventImporterAddVideo = 9001,
    AliyunEventImporterAddImage = 9002,
    AliyunEventImporterFinish = 9003,
};

typedef NS_ENUM(NSInteger, AliyunSubmoduleType) {
    AliyunSubmoduleTypeNull,
    AliyunSubmoduleTypeRecord,
    AliyunSubmoduleTypeCut,
    AliyunSubmoduleTypeEdit,
    AliyunSubmoduleTypeImport
};

typedef struct AliyunVideoEventInfo {
    int bitrate;
    int fps;
    int vduration;
    int aduration;
    uint64_t crc;
} AliyunVideoEventInfo;


@interface AliyunEventManager : NSObject

@property (nonatomic, copy) NSString *requestID;
@property (nonatomic, assign) BOOL enabled;

+ (instancetype)sharedManager;

- (void)sendEvent:(AliyunEvent)event params:(NSDictionary *)params;

- (void)sendEvent:(AliyunEvent)event params:(NSDictionary *)params type:(AliyunSubmoduleType)type;

- (AliyunVideoEventInfo)videoInfoWithPath:(NSString *)path;

- (int64_t)crc64WithPath:(NSString *)path;

- (void)refreshRequestID;

@end
