//
//  AliyunActionProtocol.h
//  QUSDK
//
//  Created by Vienta on 2018/5/29.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#ifndef AliyunActionProtocol_h
#define AliyunActionProtocol_h

#import "AliyunAction.h"

@protocol AliyunActionProtocol <NSObject>

- (void)addAction:(AliyunAction *)action;

- (void)removeAction:(AliyunAction *)action;

- (int)getNodeID;

- (BOOL)isVideoStream;//是否是视频流

@end


#endif /* AliyunActionProtocol_h */
