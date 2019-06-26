//
//  AlivcMixTrack.h
//  AliyunVideoSDK
//
//  Created by Vienta on 2019/5/13.
//  Copyright © 2019 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunMixStream.h"
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@interface AliyunMixTrack : NSObject

/**
 向该轨道加入视频

 @param stream 视频
 */
- (void)addStream:(AliyunMixStream *)stream;

@end
