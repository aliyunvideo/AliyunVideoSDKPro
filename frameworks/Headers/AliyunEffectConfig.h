//
//  AliyunEffectConfig.h
//
//  Created by lileilei on 2020/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 数值类型枚举
 - AliyunValueINT : 数值类型int
 - AliyunValueFLOAT : 数值类型float
 - AliyunValueVEC1I : 数值类型VEC1I
 - AliyunValueVEC2I : 数值类型 VEC2I
 - AliyunValueVEC3I : 数值类型VEC3I
 - AliyunValueVEC4I : 数值类型VEC4I
 - AliyunValueVEC1F : 数值类型VEC1F
 - AliyunValueVEC2F : 数值类型VEC2F
 - AliyunValueVEC3F : 数值类型VEC3F
 - AliyunValueVEC4F : 数值类型VEC4F
 - AliyunValueSCA1I :  数值类型SCA1I
 - AliyunValueSCA2I :  数值类型SCA2I
 - AliyunValueSCA3I : 数值类型SCA3I
 - AliyunValueSCA4I :  数值类型SCA4I
 - AliyunValueSCA1F :  数值类型SCA1F
 - AliyunValueSCA2F :  数值类型SCA2F
 - AliyunValueSCA3F :  数值类型SCA3F
 - AliyunValueSCA4F :  数值类型SCA4F
 - AliyunValueMAT3F :  数值类型MAT3F
 - AliyunValueMAT4F :  数值类型MAT4F
 */
typedef NS_ENUM(NSInteger, AliyunValueType){
    AliyunValueINT = 0,
    AliyunValueFLOAT,
    AliyunValueVEC1I,
    AliyunValueVEC2I,
    AliyunValueVEC3I,
    AliyunValueVEC4I,
    AliyunValueVEC1F,
    AliyunValueVEC2F,
    AliyunValueVEC3F,
    AliyunValueVEC4F,
    AliyunValueSCA1I,
    AliyunValueSCA2I,
    AliyunValueSCA3I,
    AliyunValueSCA4I,
    AliyunValueSCA1F,
    AliyunValueSCA2F,
    AliyunValueSCA3F,
    AliyunValueSCA4F,
    AliyunValueMAT3F,
    AliyunValueMAT4F,
};

/**
 参数数值封装类
 */
@interface AliyunValue : NSObject<NSCopying>

/**
 数值类型
 */
@property(nonatomic,assign) AliyunValueType type;
/**
 数值数组
 */
@property(nonatomic,strong) NSArray<NSNumber*>* values;

/**
根据字典初始化化实例对象
 */
+ (instancetype)initWithDictionary:(NSArray *)arr type:(NSString*)type;

/**
 AliyunValueType为AliyunValueINT时，获取参数值
 */
-(int)getINT;

/**
AliyunValueType为AliyunValueFLOAT时，获取参数值
*/
-(float)getFLOAT;

#pragma --mark 设值方法
/**
* 更新INT类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateINT:(int)i;

/**
* 更新FLOAT类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateFLOAT:(float)f;

/**
* 更新VEC1I类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateVEC1I:(NSInteger)i;

/**
* 更新VEC2I类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateVEC2I:(int)i0 i1:(int)i1;

/**
* 更新VEC3I类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateVEC3I:(int)i0 i1:(int)i1 i2:(int)i2;

/**
* 更新VEC4I类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateVEC4I:(int)i0 i1:(int)i1 i2:(int)i2 i3:(int)i3;

/**
* 更新SCA1I类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateSCA1I:(int)i;

/**
* 更新SCA2I类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateSCA2I:(int)i0 i1:(int)i1;

/**
* 更新SCA3I类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateSCA3I:(int)i0 i1:(int)i1 i2:(int)i2;

/**
* 更新SCA4I类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateSCA4I:(int)i0 i1:(int)i1 i2:(int)i2 i3:(int)i3;

/**
* 更新VEC1F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateVEC1F:(float)f;

/**
* 更新VEC2F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateVEC2F:(float)f0 f1:(float)f1;

/**
* 更新VEC3F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateVEC3F:(float)f0 f1:(float)f1 f2:(float)f2;

/**
* 更新VEC4F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateVEC4F:(float)f0 f1:(float)f1 f2:(float)f2 f3:(int)f3;

/**
* 更新SCA1F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateSCA1F:(float)f;

/**
* 更新SCA2F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateSCA2F:(float)f0 f1:(float)f1;

/**
* 更新SCA3F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateSCA3F:(float)f0 f1:(float)f1 f2:(float)f2;

/**
* 更新SCA4F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateSCA4F:(float)f0 f1:(float)f1 f2:(float)f2 f3:(int)f3;

/**
* 更新MAT3F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateMAT3F:(float)f0 f1:(float)f1 f2:(float)f2;

/**
* 更新MAT4F类型的值，在传入的参数与类型一致时此方法有效
*/
-(void)updateMAT4F:(float)f0 f1:(float)f1 f2:(float)f2 f3:(int)f3;

@end

/**
 参数封装类
 */
@interface AliyunParam : NSObject<NSCopying>

/**
 节点ID
 */
@property(nonatomic,assign) NSInteger nodeId;
/**
 参数名称
 */
@property(nonatomic,copy) NSString *name;
/**
 参数类型
 */
@property(nonatomic,copy) NSString *type;
/**
 参数值
 */
@property(nonatomic,strong) AliyunValue *value;
/**
 参数最大值
 */
@property(nonatomic,strong) AliyunValue *maxValue;
/**
 参数最小值
 */
@property(nonatomic,strong) AliyunValue *minValue;

/**
根据字典初始化化实例对象
 */
+ (instancetype)initWithDictionary:(NSDictionary *)dic;

/**
 模型转字典
 */
-(NSDictionary*)toDictionary;

@end

/**
 纹理类
 */
@interface AliyunTexture : NSObject<NSCopying>

/**
 节点ID
 */
@property(nonatomic,assign) NSInteger nodeId;
/**
 纹理名称
 */
@property(nonatomic,copy) NSString *name;
/**
 类型
 */
@property(nonatomic,copy) NSString *srcType;

/**
根据字典初始化化实例对象
 */
+ (instancetype)initWithDictionary:(NSDictionary *)dic;

@end

/**
 节点类
 */
@interface AliyunNode : NSObject<NSCopying>

/**
 节点ID
 */
@property(nonatomic,assign) NSInteger nodeId;
/**
 节点名称
 */
@property(nonatomic,copy) NSString *name;
/**
 片元字符串
 */
@property(nonatomic,copy) NSString *fragment;
/**
 纹理数组
 */
@property(nonatomic,strong) NSArray<AliyunTexture*> *textures;
/**
 自定义参数数组
 */
@property(nonatomic,strong) NSArray<AliyunParam*> *params;

/**
根据字典初始化化实例对象
 */
+ (instancetype)initWithDictionary:(NSDictionary *)dic;

@end

/**
 自定义特效配置类
 */
@interface AliyunEffectConfig : NSObject<NSCopying>
/**
 特效名称
 */
@property(nonatomic,copy) NSString *name;
/**
 模块
 */
@property(nonatomic,copy) NSString *module;
/**
 版本
 */
@property(nonatomic,assign) NSInteger version;
/**
 类型
 */
@property(nonatomic,assign) NSInteger type;
/**
 节点数组
 */
@property(nonatomic,strong) NSArray<AliyunNode*> *nodeTree;

/**
 根据资源本地路径初始化配置对象
 */
+ (instancetype)initWithPath:(NSString *)path;

/**
根据字典初始化化实例对象
 */
+ (instancetype)initWithDictionary:(NSDictionary *)dic;

/**
 获取调节参数
 */
-(NSString*)getParamsJsonString;

@end

NS_ASSUME_NONNULL_END
