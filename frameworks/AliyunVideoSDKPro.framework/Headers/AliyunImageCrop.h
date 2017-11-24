//
//  AliyunImageCrop.h
//  QUSDK
//
//  Created by Vienta on 2017/6/27.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, AliyunImageCropMode) {
    AliyunImageCropModeAspectFill = 0,  //填充黑边 默认原照片居中
    AliyunImageCropModeAspectCut        //裁剪画面
};

@interface AliyunImageCrop : NSObject

/**
 需要被裁剪的图片
 */
@property (nonatomic, strong) UIImage *originImage;

/**
 裁剪后的图片大小
 */
@property (nonatomic, assign) CGSize outputSize;

/**
 照片裁剪模式， 0：填充模式  1:裁剪模式
 */
@property (nonatomic, assign) AliyunImageCropMode cropMode;

/**
 裁剪区域，仅适用于裁剪模式，例如一张图片（200x200像素 ，cropRect可设置为 (0,0,100,100)（单位为像素））
 */
@property (nonatomic, assign) CGRect cropRect;

/**
 照片填充模式下，填充的背景颜色
 */
@property (nonatomic, strong) UIColor *fillBackgroundColor;


/**
 裁剪生成图片

 @return 裁剪后的图片  如果裁剪失败 然后nil
 */
- (UIImage *)generateImage;

@end
