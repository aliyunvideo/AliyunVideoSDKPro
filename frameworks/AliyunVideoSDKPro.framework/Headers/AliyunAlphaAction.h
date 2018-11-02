//
//  AliyunAlphaAction.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/6/4.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

//!!!!!注意：主流不支持添加alpha动画

#import "AliyunAction.h"

@interface AliyunAlphaAction : AliyunAction

@property (nonatomic, assign) float fromAlpha;
@property (nonatomic, assign) float toAlpha;

- (id)initWithRestore:(NSDictionary *)dict;

@end
