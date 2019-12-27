//
//  AliyunVideoStitch.h
//  qurecorder
//
//  Created by Vienta on 2017/1/11.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 视频拼接类
 */
@interface AliyunVideoStitch : NSObject

/**
 将多段视频进行拼接

 @param videoPaths 视频资源路径集合
 @param output 输出路径
 @param id 上传日志的id
 @return 是否成功
 */
- (BOOL)stitchVideos:(NSArray *)videoPaths output:(NSString *)output reportId:(int64_t)id;

@end
