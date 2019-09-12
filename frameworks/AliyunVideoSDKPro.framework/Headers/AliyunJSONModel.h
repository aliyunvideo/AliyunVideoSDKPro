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
/****
 Deprecated.
 */
__attribute__((deprecated)) @interface AliyunJSONModel : NSObject

/**
 *  创建JSONModel
 *
 *  @param dic   数据字典
 *  @return      JSONModel
 */
/****
 *  Creates a JSONModel object.
 *
 *  @param dic   The data dictionary.
 *  @return      JSONModel
 */
- (instancetype)initWithDictionary:(NSDictionary *)dic;

/**
 *  转换字典
 *
 *  @return      数据字典
 */
/****
 *  Converts a dictionary.
 *
 *  @return      The converted data dictionary.
 */
- (NSDictionary *)toDictionary;

/**
 *  创建JSONModel
 *
 *  @param path   文件路径
 *  @return       JSONModel
 */
/****
 *  Creates a JSONModel object.
 *
 *  @param path   The file path.
 *  @return       JSONModel
 */
- (instancetype)initWithFile:(NSString *)path;

/**
 *  文件写入数据
 *
 *  @param path 路径
 */
/****
 * Writes data to a file.
 *
 *  @param path The file path.
 */
- (void)jsonToFile:(NSString *)path;

/**
 重写 防止无属性时候 setKeyValue crash

 @param value value
 @param key  key
 */
/****
 Overrides the system method.

 @param value value
 @param key  key
 */
- (void)setValue:(id)value forUndefinedKey:(NSString *)key;

@end
