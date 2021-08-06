//
//  AliyunSticker.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/24.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunRenderModel.h"

/**
 贴纸类型 API_AVAILABLE(3.22.0)
 */
/**
 The type of sticker API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSUInteger, AliyunStickerType) {
    /**
     图片贴纸 API_AVAILABLE(3.22.0)
     */
    /**
     The sticker of image API_AVAILABLE(3.22.0)
     */
    AliyunStickerType_Image,
    /**
     动图贴纸 API_AVAILABLE(3.22.0)
     */
    /**
     The sticker of gif API_AVAILABLE(3.22.0)
     */
    AliyunStickerType_Gif,
    /**
     文字贴纸 API_AVAILABLE(3.22.0)
     */
    /**
     The sticker of text API_AVAILABLE(3.22.0)
     */
    AliyunStickerType_Text,
};

/**
 贴纸基类 API_AVAILABLE(3.22.0)
 */
/**
 The Sticker base class API_AVAILABLE(3.22.0)
 */
@interface AliyunSticker : AliyunRenderModel<NSCopying>
/**
 贴纸ID API_AVAILABLE(3.22.0)
 */
/**
 The id of sticker API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) int stickerId;
/**
 资源路径 API_AVAILABLE(3.22.0)
 */
/**
 the path of sticker resource API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSString *resourePath;
/**
 贴纸类型 API_AVAILABLE(3.22.0)
 */
/**
 the type of sticker API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunStickerType stickerType;
/**
 贴纸原始大小 API_AVAILABLE(3.22.0)
 */
/**
 the origin size of sticker API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) CGSize originSize;

/**
 获取所有动画action API_AVAILABLE(3.23.0)
 */
/**
 get all frame animation actions. API_AVAILABLE(3.23.0)
 */
- (NSArray *)getAllActionList;

@end
