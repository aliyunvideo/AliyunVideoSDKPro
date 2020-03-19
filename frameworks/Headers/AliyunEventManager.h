//
//  AliyunEventManager.h
//  QUSDK
//
//  Created by Worthy on 2017/8/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AVAsset+AliyunSDKInfo.h"
#import <Foundation/Foundation.h>
#define DefaultEventManager [AliyunEventManager sharedManager]

__deprecated_msg("deprecated") typedef NS_ENUM(NSInteger, AliyunEvent) {
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
    AliyunEventRecordMV = 2014,
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

__deprecated_msg("deprecated") typedef NS_ENUM(NSInteger, AliyunSubmoduleType) { AliyunSubmoduleTypeNull, AliyunSubmoduleTypeRecord, AliyunSubmoduleTypeCut, AliyunSubmoduleTypeEdit, AliyunSubmoduleTypeImport };

__deprecated_msg("deprecated") typedef struct AliyunVideoEventInfo {
    int bitrate;
    int fps;
    int vduration;
    int aduration;
    uint64_t crc;
} AliyunVideoEventInfo;

__deprecated_msg("deprecated") @interface AliyunEventManager : NSObject

@property(nonatomic, copy) NSString *requestID;
@property(nonatomic, assign) BOOL enabled;

+ (instancetype)sharedManager;

- (void)sendEvent:(AliyunEvent)event params:(NSDictionary *)params;

- (void)sendEvent:(AliyunEvent)event params:(NSDictionary *)params type:(AliyunSubmoduleType)type;

+ (AliyunVideoEventInfo)videoInfoWithPath:(NSString *)path;

- (uint64_t)crc64WithPath:(NSString *)path;

- (void)refreshRequestID;

@end
