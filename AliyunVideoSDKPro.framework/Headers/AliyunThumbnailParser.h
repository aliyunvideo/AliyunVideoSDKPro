//
//  AliyunThumbnailParser.h
//  AliyunVideoSDKPro
//
//  Created by mengyehao on 2021/3/17.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AliyunThumbnailParser;

@protocol AliyunThumbnailParserDelegate <NSObject>

/**
 获取出错，注意在子线程回调，而不是主线程 API_AVAILABLE(3.20.0)
 
 @param code 错误码.
 */
- (void)thumbnailParser:(AliyunThumbnailParser *)parser onError:(int)code;


/**
 获取某张图片出错，注意在子线程回调，而不是主线程 API_AVAILABLE(3.20.0)
 
 @param code 错误码
 @param time 时间戳，单位：秒
 */
- (void)thumbnailParser:(AliyunThumbnailParser *)parser onPicError:(int)code time:(float)time;


/**
 获取到的图片，注意在子线程回调，而不是主线程 API_AVAILABLE(3.20.0)
 
 @param image 图片，可能是nil，需要做判断
 @param time 时间戳，单位：秒
 */
- (void)thumbnailParser:(AliyunThumbnailParser *)parser onGetPicture:(UIImage *)image time:(float)time;

/**
 完成所有图片的获取，注意在子线程回调，而不是主线程 API_AVAILABLE(3.20.0)
 */
- (void)thumbnailParserOnCompleted:(AliyunThumbnailParser *)parser;


@end

@interface AliyunThumbnailParser : NSObject

/**
 初始化参数解析器 API_AVAILABLE(3.20.0)
 
 @param path 视频路径
 @param delegate 代理回调
 @return 解析器示例
 */
- (instancetype)initWithPath:(NSString *)path delegate:(id<AliyunThumbnailParserDelegate>)delegate;


/**
 设置要获取的图片对应的时间戳 API_AVAILABLE(3.20.0)
 
 @param timeList 里面包含时间戳，单位：秒
 */
- (void)addThumbnailTimeList:(NSArray<NSNumber *> *)timeList;


/**
 设置裁剪的位置/大小，同一个实例只可设置一次 API_AVAILABLE(3.20.0)
 
 @param cutFrame 裁剪的位置/大小
 */
- (void)setCutFrame:(CGRect)cutFrame;

/**
 设置获得的图片大小，同一个实例只可设置一次 API_AVAILABLE(3.20.0)
 
 @param outputSize 裁剪的位置/大小
 */
- (void)setOutputSize:(CGSize)outputSize;

/**
 开始 API_AVAILABLE(3.20.0)
 */
- (void)start;

/**
 取消获取缩略图 API_AVAILABLE(3.20.0)
 */
- (void)cancel;

@end


