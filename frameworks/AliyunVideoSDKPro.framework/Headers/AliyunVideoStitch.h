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
/****
 A class that splices videos.
 */
@interface AliyunVideoStitch : NSObject

/**
 将多段视频进行拼接

 @param videoPaths 视频资源路径集合
 @param output 输出路径
 @param id 上传日志的id
 @return 是否成功
 */
/****
 Splices multiple video clips.

 @param videoPaths The paths of video clips to be spliced.
 @param output The output path.
 @param id The log id.
 @return Whether the invocation is successful.
 */
- (BOOL)stitchVideos:(NSArray *)videoPaths output:(NSString *)output reportId:(int64_t)id;

@end
