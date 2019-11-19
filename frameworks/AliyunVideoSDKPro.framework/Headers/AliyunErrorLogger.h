//
//  AliyunErrorLogger.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2017/10/12.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 错误处理类

 */
__deprecated_msg("deprecated") @interface AliyunErrorLogger : NSObject

/**
 log回调
 */
@property (nonatomic, copy) void (^logCb)(int code, NSString *msg);

@end
