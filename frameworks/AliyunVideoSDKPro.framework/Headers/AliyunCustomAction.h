//
//  AliyunCustomAction.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/6/19.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"

@interface AliyunCustomAction : AliyunAction

@property (nonatomic, copy) NSString *fragmentShader;
@property (nonatomic, strong) NSDictionary *customUniformsMapper;

- (id)initWithRestore:(NSDictionary *)dict;

@end

