//
//  AliyunDraftManager.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/7/7.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunDraft.h"

@class AliyunDraftManager;
@protocol AliyunDraftManagerDelegate <NSObject>
/**
 草稿列表发生变化
 */
/**
 The event for draft list did change
 */
- (void) onAliyunDraftManager:(AliyunDraftManager *)mgr listDidChange:(NSArray<AliyunDraft *> *)list;
@end

/**
 本地草稿管理器
 */
/**
 The manager of local draft
 */
@interface AliyunDraftManager : NSObject
/**
 唯一标识
 */
/**
 The id of manager
 */
@property (nonatomic, copy, readonly) NSString *identifier;
/**
 草稿列表
 */
/**
 The list of draft
 */
@property (nonatomic, copy, readonly) NSArray<AliyunDraft *> *draftList;

/**
 事件回调
 */
/**
 The callback of manager's event
 */
@property (nonatomic, weak) id<AliyunDraftManagerDelegate> delegate;

/**
 初始化器
 
 @param identifier 唯一标识
 */
/**
 The Init of draft manager
 
 @param identifier
 */
- (instancetype) initWithId:(NSString *)identifier;

/**
 添加草稿
 
 @param draft 草稿
 */
/**
 Add the draft
 
 @param draft The draft need to be add
 */
- (void) addDraft:(AliyunDraft *)draft;

/**
 删除草稿
 
 @param draft 将要被删除的草稿
 */
/**
 delete the draft
 
 @param draft The draft will be delete from manager
 */
- (AliyunDraft *) deleteDraft:(AliyunDraft *)draft;

/**
 复制草稿
 
 @param draft 将要被复制的草稿
 @param taskPath 新草稿的路径
 @param title 新草稿的标题
 */
/**
 copy the draft
 
 @param draft The draft will be copy
 @param taskPath The path of new draft
 @param title The title of new draft
 */
- (AliyunDraft *) copyDraft:(AliyunDraft *)draft toPath:(NSString *)taskPath withTitle:(NSString *)title;
@end
