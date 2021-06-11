//
//  AliyunGifStickerController.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/24.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunRenderBaseController.h"
#import "AliyunGifSticker.h"
#import "AliyunFrameAnimationProtocol.h"

/**
 动图贴纸控制器 API_AVAILABLE(3.22.0)
 */
/**
 The controller of git sticker API_AVAILABLE(3.22.0)
 */
@interface AliyunGifStickerController : AliyunRenderBaseController<AliyunFrameAnimationProtocol>
/**
 动图贴纸 API_AVAILABLE(3.22.0)
 */
/**
 The sticker of gif API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunGifSticker *gif;
@end
