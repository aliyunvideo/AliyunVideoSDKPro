//
//  AliyunDraft.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/7/7.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPResourceModel.h"

/**
 本地草稿对象
 */
/**
 The local draft
 */
@interface AliyunDraft : NSObject
/**
 工程ID
 */
/**
 The id of project
 */
@property (nonatomic, copy, readonly) NSString *projectId;
/**
 草稿标题
 */
/**
 The title of draft
 */
@property (nonatomic, copy, readonly) NSString *title;
/**
 创建时间
 */
/**
 The create time of draft
 */
@property (nonatomic, copy, readonly) NSString *createTime;
/**
 修改时间
 */
/**
 The modified time of draft
 */
@property (nonatomic, copy, readonly) NSString *modifiedTime;
/**
 剪辑持续时间
 */
/**
 The duration of project
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;
/**
 剪辑所有资源大小总和
 */
/**
 The size of project
 */
@property (nonatomic, assign, readonly) size_t size;
/**
 封面图路径
 */
/**
 The path of cover image
 */
@property (nonatomic, strong, readonly) AEPSource *cover;

/**
 修改工程ID
 
 @param projectId 工程ID
 */
/**
 Change the project id
 
 @param projectId The id of project
 */
- (void) changeProjectId:(NSString *)projectId;

/**
 重命名标题
 
 @param title 新的标题
 */
/**
 rename the title of draft
 
 @param title the new title of draft
 */
- (void) renameTitle:(NSString *)title;
@end

// MARK: - Load
/**
 加载任务
 */
/**
 The task of load
 */
@interface AliyunDraftLoadTask : NSObject
/**
 任务是否完成
 */
/**
 Whether the task is finished
 */
@property (nonatomic, assign, readonly) BOOL isFinish;
/**
 任务原始资源
 */
/**
 The resource for this task
 */
@property (nonatomic, strong, readonly) AEPResourceModel *resource;

/**
 加载成功
 
 @param result 加载结果
 */
/**
 Load success
 
 @param result The result of load
 */
- (void) onSuccess:(AEPSource *)result;
/**
 忽略这次加载任务
 */
/**
 Ignore this load task
 */
- (void) onIgnore;
/**
 加载失败并删除对应的节点
 */
/**
 Mark this task load fail and remove the node of resource
 */
- (void) onFailToRemove;
/**
 加载这个任务失败并停止整个加载过程
 */
/**
 Mark this task load fail And stop the whole load tasks
 */
- (void) onFailToStopWithError:(NSError *)error;
@end

/**
 加载器
 
 @param tasks 加载的任务列表
 */
/**
 The loader
 
 @param tasks The list of load task
 */
typedef void(^DraftTaskLoader)(NSArray<AliyunDraftLoadTask *> *tasks);

@class AliyunEditorBaseProject;
/**
 本地草稿加载完成回调
 
 @param taskPath 工程路径（如果加载失败则为空）
 @param project 工程对象（如果加载失败则为空）
 @param error 加载错误信息（如果加载成功则为空）
 */
/**
 The callback of local draft load
 
 @param taskPath The path of project. (it will be nil if load fail)
 @param project The obj of project. (it will be nil if load fail)
 @param error The errof obj of load. (it will be nil if load success)
 */
typedef void(^LocalDraftLoadCallback)(NSString *taskPath, AliyunEditorBaseProject *project, NSError *error);

/**
 草稿加载扩展
 */
/**
 The extension of load for draft
 */
@interface AliyunDraft (Load)
/**
 加载草稿
 
 @param loader 加载器，需要调用方实现；实现草稿资源的加载
 @param completion 完成回到
 */
- (void) load:(DraftTaskLoader)loader completion:(LocalDraftLoadCallback)completion;
@end
