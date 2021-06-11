//
//  AliyunImageStickerController.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/24.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunRenderBaseController.h"
#import "AliyunImageSticker.h"

/**
 图片贴纸控制器 API_AVAILABLE(3.22.0)
 */
/**
 The controller of image sticker API_AVAILABLE(3.22.0)
 */
@interface AliyunImageStickerController : AliyunRenderBaseController
/**
 图片贴纸 API_AVAILABLE(3.22.0)
 */
/**
 The image sticker API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunImageSticker *image;
@end
