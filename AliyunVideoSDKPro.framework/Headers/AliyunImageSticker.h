//
//  AliyunImageSticker.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/24.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunSticker.h"

/**
 图片贴纸 API_AVAILABLE(3.22.0)
 */
/**
 the sticker of image API_AVAILABLE(3.22.0)
 */
@interface AliyunImageSticker : AliyunSticker<NSCopying>
/**
 图片路径 API_AVAILABLE(3.22.0)
 */
/**
 The path of image API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSString *imagePath;
/**
 初始化 API_AVAILABLE(3.22.0)
 @param path 图片路径
 */
/**
 Init API_AVAILABLE(3.22.0)
 @param path the path of image
 */
- (instancetype) initWithImagePath:(NSString *)path;
@end
