//
//  AliyunTextStickerViewController.h
//  AliyunVideoSDKPro
//
//  Created by mengyehao on 2021/5/25.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunRenderBaseController.h"
#import "AliyunCaptionSticker.h"
#import "AliyunFrameAnimationProtocol.h"




@interface AliyunCaptionStickerController : AliyunRenderBaseController<AliyunFrameAnimationProtocol>
@property (nonatomic, strong) AliyunCaptionSticker *model;
@end



