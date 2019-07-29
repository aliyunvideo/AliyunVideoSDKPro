//
//  AliyunErrorCodeEnum.h
//  QUSDK
//
//  Created by Vienta on 2017/6/14.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//  上层的errorCode

#ifndef AliyunErrorCodeEnum_h
#define AliyunErrorCodeEnum_h

/**
 错误类型
 已废弃

 - AliyunErrorMediaThreshold: AliyunErrorMediaThreshold
 - AliyunErrorMediaVideoNotSupport: AliyunErrorMediaVideoNotSupport
 - AliyunErrorMediaAudioNotSupport: AliyunErrorMediaAudioNotSupport
 - AliyunErrorMediaImageFormatNotSupport: AliyunErrorMediaImageFormatNotSupport
 - AliyunErrorMediaVideoEncoderInternal: AliyunErrorMediaVideoEncoderInternal
 */
__deprecated_msg("deprecated") typedef NS_ENUM(int, AliyunErrorMedia) {
    AliyunErrorMediaThreshold = 100001,
    AliyunErrorMediaVideoNotSupport,
    AliyunErrorMediaAudioNotSupport,
    AliyunErrorMediaImageFormatNotSupport,
    AliyunErrorMediaVideoEncoderInternal
};


#endif /* AliyunErrorCodeEnum_h */
