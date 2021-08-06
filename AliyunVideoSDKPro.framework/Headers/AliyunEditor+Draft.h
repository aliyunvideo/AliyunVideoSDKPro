//
//  AliyunEditor+Draft.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/7/9.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunEditor.h"
#import "AliyunDraftManager.h"

@interface AliyunEditor (Draft)
/**
 保存到草稿
 
 @param draftMgr 草稿管理
 */
/**
 save to draft
 
 @param draftMgr The manager of draft
 */
- (AliyunDraft *) saveToDraft:(AliyunDraftManager *)draftMgr;

/**
 保存到草稿
 
 @param draftMgr 草稿管理
 @param title 草稿标题
 */
/**
 save to draft
 
 @param draftMgr The manager of draft
 @param title The Title of draft
 */
- (AliyunDraft *) saveToDraft:(AliyunDraftManager *)draftMgr withTitle:(NSString *)title;
@end
