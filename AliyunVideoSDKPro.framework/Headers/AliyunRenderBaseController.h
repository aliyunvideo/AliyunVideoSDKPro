//
//  AliyunRenderBaseController.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/24.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AliyunRenderModel;
@interface AliyunRenderBaseController : NSObject
/**
 是否支持实时预览，修改属性能直接预览生效 API_AVAILABLE(3.22.0)
 */
/**
 is support preivew immediate after progerty change API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL immediatePreview;
/**
 渲染数据模型 API_AVAILABLE(3.22.0)
 */
/**
 the model of render API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRenderModel *model;
/**
 开始编辑；用于合并多个属性修改； API_AVAILABLE(3.22.0)
 */
/**
 start edit; be used for merge multi modify API_AVAILABLE(3.22.0)
 */
- (void) beginEdit;
/**
 结束编辑；用于把从beginEdit到endEdit之间的修改最终生效 API_AVAILABLE(3.22.0)
 */
/**
 end edit; be used for apply all the modify between begin and end API_AVAILABLE(3.22.0)
 */
- (void) endEdit;
/**
 取消编辑：用于把状态恢复到beginEdit之前 API_AVAILABLE(3.22.0)
 */
/**
 cancel edit; be used for reback the state before call the begin edit API_AVAILABLE(3.22.0)
 */
- (void) cancelEdit;
@end
