//
//  AliyunDraft+Cloud.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/7/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunDraft.h"
#import "AliyunDraftManager.h"

/**
 草稿工程文件上传任务
 */
/**
 The task of draft project file
 */
@interface AliyunDraftProjectUploadTask : NSObject
/**
 任务是否完成
 */
/**
 Whether the task is finished
 */
@property (nonatomic, assign, readonly) BOOL isFinish;

/**
 草稿工程文件
 */
/**
 The file of draft project
 */
@property (nonatomic, copy, readonly) NSString *projectFilePath;

/**
 封面资源
 */
/**
 The cover resource
 */
@property (nonatomic, strong, readonly) AEPSource *cover;

/**
 草稿对象
 */
/**
 The draft object
 */
@property (nonatomic, strong, readonly) AliyunDraft *draft;

/**
 上传成功
 */
/**
 upload success
 */
- (void) onSuccess;

/**
 上传失败
 */
/**
 Upload fail
 */
- (void) onFailWithError:(NSError *)error;
@end

@interface AliyunDraft (Cloud)
/**
 上传草稿
 
 @param resourceUploader 资源上传器
 @param projectUploader 工程上传器
 @param completion 上传完成回调
 */
/**
 Upload draft

 @param resourceUploader The uploader of resource
 @param projectUploader The uploader of project
 @param completion The callback of upload finish
 */
- (void) uploadWithResourceUploader:(DraftTaskLoader)resourceUploader
                    projectUploader:(void(^)(AliyunDraftProjectUploadTask *projTask))projectUploader
                         completion:(void(^)(NSError *error))completion;
@end


@interface AliyunDraftManager (Cloud)
/**
 下载草稿
 
 @param projectFilePath 工程描述文件的文件路径
 @param downloader 资源下载器
 @param completion 下载完成的回调
 */
/**
 Download draft
 
 @param projectFilePath The path of project description file
 @param downloader The loader for draft's resources
 @param completion The callback of loader after resoruce download finish
 */
- (void) downloadDraftWithProjectFile:(NSString *)projectFilePath
                   resourceDownloader:(DraftTaskLoader)downloader
                           completion:(void(^)(AliyunDraft *draft, NSError *error))completion;
@end
