//
//  AliyunEffect.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunJSONModel.h"

id QUSDKObjectOrNull(id object);
@interface AliyunEffect : AliyunJSONModel

@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *icon;//icon path
@property (nonatomic, copy) NSString *name;

- (int)effectVid;

- (void)setEffectVid:(int)vid;

- (id)initWithFile:(NSString *)path;

- (id)initWithDict:(NSDictionary *)dict;

@end
