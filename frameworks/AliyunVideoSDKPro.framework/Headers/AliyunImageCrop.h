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
/****
 Crop modes.
 
 - AliyunImageCropModeAspectFill: Fill mode. The image is centered by default.
 - AliyunImageCropModeAspectCut: Cut mode.
 */
typedef NS_ENUM(NSInteger, AliyunImageCropMode) {
    AliyunImageCropModeAspectFill = 0,
    AliyunImageCropModeAspectCut
};

/**
 图片裁剪类
 */
/****
 A class that defines image croppers.
 */
@interface AliyunImageCrop : NSObject

/**
 需要被裁剪的图片

 必选参数
 */
/****
 The image to be cropped.
 
 Required.
 */
@property (nonatomic, strong) UIImage *originImage;

/**
 裁剪后的图片分辨率大小

 必选参数
 */
/****
 The image size after cropping.
 
 Required.
 */
@property (nonatomic, assign) CGSize outputSize;

/**
 照片裁剪模式

 填充模式：0
 裁剪模式：1
 */
/****
 The crop mode.
 
 0 indicates fill mode.
 1 indicates cut mode.
 */
@property (nonatomic, assign) AliyunImageCropMode cropMode;

/**
 裁剪区域

 仅适用于裁剪模式
 例如一张图片（200x200像素 ，cropRect可设置为 (0,0,100,100)（单位为像素））
 */
/****
 The crop rectangle.
 
 This property only takes effect when cut mode is selected.
 For example, if an image has a size of 200 x 200 pixels, the crop rectangle can be set to (0,0,100,100).
 */
@property (nonatomic, assign) CGRect cropRect;

/**
 背景颜色

 照片填充模式下有效
 */
/****
 The background color.
 
 This property only takes effect when fill mode is selected.
 */
@property (nonatomic, strong) UIColor *fillBackgroundColor;

/**
 裁剪生成图片
 
 裁剪失败，返回nil
 @return 裁剪后的图片
 */
/****
 Gets the cropped image. 
 
 If an error occurred during cropping, nil is returned. 
 @return The cropped image.
 */
- (UIImage *)generateImage;

@end
