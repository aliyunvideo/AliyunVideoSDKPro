//
//  AliyunImageCrop.h
//  QUSDK
//
//  Created by Vienta on 2017/6/27.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/**
 裁剪模式

 - AliyunImageCropModeAspectFill: 填充黑边 默认原照片居中
 - AliyunImageCropModeAspectCut: 裁剪画面
 */
typedef NS_ENUM(NSInteger, AliyunImageCropMode) {
    AliyunImageCropModeAspectFill = 0,
    AliyunImageCropModeAspectCut
};

/**
 图片裁剪类
 */
@interface AliyunImageCrop : NSObject

/**
 需要被裁剪的图片

 必选参数
 */
@property (nonatomic, strong) UIImage *originImage;

/**
 裁剪后的图片分辨率大小

 必选参数
 */
@property (nonatomic, assign) CGSize outputSize;

/**
 照片裁剪模式

 填充模式：0
 裁剪模式：1
 */
@property (nonatomic, assign) AliyunImageCropMode cropMode;

/**
 裁剪区域

 仅适用于裁剪模式
 例如一张图片（200x200像素 ，cropRect可设置为 (0,0,100,100)（单位为像素））
 */
@property (nonatomic, assign) CGRect cropRect;

/**
 背景颜色

 照片填充模式下有效
 */
@property (nonatomic, strong) UIColor *fillBackgroundColor;

/**
 裁剪生成图片
 
 裁剪失败，返回nil
 @return 裁剪后的图片
 */
- (UIImage *)generateImage;

@end
