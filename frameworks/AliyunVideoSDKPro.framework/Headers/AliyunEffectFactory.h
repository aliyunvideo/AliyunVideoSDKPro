//
//  AliyunEffectFactory.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 effect工厂类
 */
__deprecated_msg("deprecated") @interface AliyunEffectFactory : NSObject

/**
 创建一个AliyunEffect

 @param path 路径
 @return AliyunEffect
 */
+ (id)createEffect:(NSString *)path;

@end
