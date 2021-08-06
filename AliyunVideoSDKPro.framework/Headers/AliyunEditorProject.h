//
//  AliyunEditorProject.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/13.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPConfig.h"
#import "AEPTimeline.h"
#import "AEPSource.h"

@interface AliyunEditorBaseProject : NSObject
/**
 当前SDK的工程版本号
 */
/**
 The Current Version of sdk
 */
@property (nonatomic, class, readonly) int CurrentVersion;

/**
 工程文件的版本号
 */
/**
 The version of this project file
 */
@property (nonatomic, assign, readonly) int version;

/**
 工程ID，由用户确定，默认为空
 */
/**
 The projectid, define by user, default is nil
 */
@property (nonatomic, copy, readonly) NSString *projectId;

/**
 标题
 */
/**
 The title
 */
@property (nonatomic, copy) NSString *title;

/**
 创建时间
 */
/**
 The Create time
 */
@property (nonatomic, copy, readonly) NSString *createTime;

/**
 修改时间
 */
/**
 The modified time
 */
@property (nonatomic, copy, readonly) NSString *modifiedTime;

/**
 工程状态（保留值，当前为空）
 */
/**
 The project status. (current not use, is nil)
 */
@property (nonatomic, copy, readonly) NSString *status;

/**
 工程描述信息
 */
/**
 The detail info of project
 */
@property (nonatomic, copy) NSString *info;

/**
 持续时间（秒）
 */
/**
 The duration (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/**
 工程资源总大小(KB)
 */
/**
 The resource size. (KB)
 */
@property (nonatomic, assign, readonly) size_t resourceSize;

/**
 工程配置
 */
/**
 The config of project
 */
@property (nonatomic, strong, readonly) AEPConfig *config;

/**
 封面资源
 */
/**
 The resource of Cover
 */
@property (nonatomic, strong, readonly) AEPSource *cover;

@end

/**
 编辑工程数据模型
 */
/**
 The model of editor project
 */
@interface AliyunEditorProject : AliyunEditorBaseProject

/**
 时间线
 */
/**
 Timeline
 */
@property (nonatomic, strong, readonly) AEPTimeline *timeline;

@end
