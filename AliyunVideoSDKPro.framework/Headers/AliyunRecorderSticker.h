//
//  AliyunRecorderSticker.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/24.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunImageSticker.h"
#import "AliyunGifSticker.h"

/**
 录制模块的图片贴纸 API_AVAILABLE(3.22.0)
 */
/**
 The Image sticker of recorder API_AVAILABLE(3.22.0)
 */
@interface AliyunRecorderImageSticker : AliyunImageSticker
/**
 设置自定义的适配策略 API_AVAILABLE(3.22.0)
 */
/**
 The strategy of autoresizing API_AVAILABLE(3.22.0)
 */
- (void) setAutoresizingMask:(UIViewAutoresizing)mask;
@end

/**
 录制模块的GIF贴纸 API_AVAILABLE(3.22.0)
 */
/**
 The Gif sticker of recorder API_AVAILABLE(3.22.0)
 */
@interface AliyunRecorderGifSticker : AliyunGifSticker
/**
 设置自定义的适配策略 API_AVAILABLE(3.22.0)
 */
/**
 The strategy of autoresizing
 */
- (void) setAutoresizingMask:(UIViewAutoresizing)mask;
@end
