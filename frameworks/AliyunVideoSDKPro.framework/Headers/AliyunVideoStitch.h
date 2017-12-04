//
//  AliyunVideoStitch.h
//  qurecorder
//
//  Created by Vienta on 2017/1/11.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AliyunVideoStitch : NSObject

- (BOOL)stitchVideos:(NSArray *)videoPaths output:(NSString *)output;

@end
