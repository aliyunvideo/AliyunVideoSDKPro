//
//  AEPSource.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 资源类型
 */
/**
 The type of resource
 */
typedef NS_ENUM(NSUInteger, AEPSourceType) {
    AEPSourceType_Video,
    AEPSourceType_Image,
    AEPSourceType_Gif,
    AEPSourceType_Audio,
    AEPSourceType_MV,
    AEPSourceType_Font,
    AEPSourceType_Config,
};

/**
 编辑工程资源
 */
/**
 The resource of edit project
 */
@interface AEPSource : NSObject

/**
 资源类型
 */
/**
 The type of resource
 */
@property (nonatomic, assign, readonly) AEPSourceType type;

/**
 资源ID
 */
/**
 The id of resource
 */
@property (nonatomic, copy, readonly) NSString *sourceId;

/**
 资源路径
 */
/**
 The path of resource
 */
@property (nonatomic, copy, readonly) NSString *path;

/**
 资源远端地址
 */
/**
 The url of resource
 */
@property (nonatomic, copy, readonly) NSString *URL;

/**
 资源大小(KB)
 */
/**
 The size of resource (KB)
 */
@property (nonatomic, assign, readonly) size_t size;

/**
 是否本地资源
 */
/**
 is local
 */
@property (nonatomic, assign, readonly) BOOL isLocal;
@end

/**
 资源创建方法
 */
/**
 The create factory
 */
@interface AEPSource (Creator)
/**
 创建资源对象
 
 @param type 资源类型
 @param sourceId 资源ID，可选
 @param url 资源远端地址，可选
 @param path 资源本地地址，可选
 */
/**
 Create resource
 
 @param type the type of resoruce
 @param sourceId the id of resource
 @param url the url of resource
 @param path the local path of resource
 */
+ (AEPSource *) SourceWithType:(AEPSourceType)type
                      sourceId:(NSString *)sourceId
                           url:(NSString *)url
                          path:(NSString *)path;

/**
 通过修改本地路径创建资源对象
 
 @param path 本地路径
 */
/**
 create resource obj with path
 
 @param path the local path of resource
 */
- (AEPSource *) createWithPath:(NSString *)path;

/**
 通过修改远程路径创建资源对象
 
 @param url 远端地址
 */
/**
 create resource obj with url
 
 @param url the url of resource
 */
- (AEPSource *) createWithURL:(NSString *)URL;

/**
 通过资源ID创建资源对象
 
 @param sourceId 资源ID
 */
/**
 create resource obj with sourceId
 
 @param sourceId the id of resoruce
 */
- (AEPSource *) createWithSourceId:(NSString *)sourceId;
@end
