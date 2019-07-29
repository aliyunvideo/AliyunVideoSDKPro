//
//  JSONModel.h
//  QupaiSDK
//
//  Created by yly on 15/6/26.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 已废弃，请勿使用
 */
__attribute__((deprecated)) @interface AliyunJSONModel : NSObject

/**
 *  创建JSONModel
 *
 *  @param dic   数据字典
 *  @return      JSONModel
 */
- (instancetype)initWithDictionary:(NSDictionary *)dic;

/**
 *  转换字典
 *
 *  @return      数据字典
 */
- (NSDictionary *)toDictionary;

/**
 *  创建JSONModel
 *
 *  @param path   文件路径
 *  @return       JSONModel
 */
- (instancetype)initWithFile:(NSString *)path;

/**
 *  文件写入数据
 *
 *  @param path 路径
 */
- (void)jsonToFile:(NSString *)path;

/**
 重写 防止无属性时候 setKeyValue crash

 @param value value
 @param key  key
 */
- (void)setValue:(id)value forUndefinedKey:(NSString *)key;

@end
