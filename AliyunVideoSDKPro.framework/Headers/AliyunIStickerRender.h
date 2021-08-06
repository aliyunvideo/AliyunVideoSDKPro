//
//  AliyunIStickerRender.h
//  AliyunVideoSDKPro
//
//  Created by mengyehao on 2021/5/25.
//  Copyright © 2021 aliyun. All rights reserved.
//

@class AliyunSticker;

@protocol AliyunIStickerRender <NSObject>


/**
 添加动图 API_AVAILABLE(3.22.0)
 
 @param sticker 动图数据对象，AliyunGifSticker/AliyunCaptionSticker
 @return 返回状态码
 */
- (int)addSticker:(AliyunSticker *)sticker;


/**
 移除动图 API_AVAILABLE(3.22.0)
 
 @param sticker 动图数据对象，AliyunGifSticker/AliyunCaptionSticker
 @return 返回状态码
 */
- (int)removeSticker:(AliyunSticker *)sticker;


/**
 更新动图 API_AVAILABLE(3.22.0)
 
 @param sticker 动图数据对象，AliyunGifSticker/AliyunCaptionSticker
 @return 返回状态码
 */
- (int)updateSticker:(AliyunSticker *)sticker;

@end
