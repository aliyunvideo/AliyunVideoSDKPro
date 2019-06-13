//
//  AliyunIEffectRecovery.h
//  QUSDK
//
//  Created by Vienta on 2019/5/31.
//  Copyright © 2019 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AliyunIEffectRecovery <NSObject>

/**
 初始化方法 内部从json文件恢复后调用此方法

 @param dict 初始化参数
 @return 实例对象
 */
- (id)initWithRestore:(NSDictionary *)dict;

/**
 拷贝对象

 @return 拷贝后的对象
 */
- (id)copyAnother;

@end
