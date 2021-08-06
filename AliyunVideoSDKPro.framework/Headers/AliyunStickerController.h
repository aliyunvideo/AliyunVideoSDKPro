//
//  AliyunStickerController.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/6/21.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunRenderBaseController.h"
#import "AliyunSticker.h"
#import "AliyunFrameAnimationProtocol.h"

@interface AliyunStickerController : AliyunRenderBaseController<AliyunFrameAnimationProtocol>
@end

@interface AliyunStickerController(Model)
@property (nonatomic, readonly) AliyunSticker *sticker;
@end
