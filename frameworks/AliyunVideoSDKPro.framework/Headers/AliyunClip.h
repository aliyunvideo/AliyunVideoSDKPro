//
//  AliyunClip.h
//  qurecorder
//
//  Created by dangshuai on 17/1/4.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunJSONModel.h"


@protocol AliyunClip;

@interface AliyunClip : AliyunJSONModel
/*
 mediaType  :  类型，视频或图片image，类型改为0,1 0标示视频，1标示图片  
 mediaHeight:  图片/视频／图片的分辨率
 mediaWidth :
 src        :  
 startTime  :  图片/视频、配音 开始时间
 endTime    :  图片/视频、配音 结束时间
 rotation   :  图片/视频角度
 duration   :  图片
 */
@property (nonatomic, assign) int mediaType;
@property (nonatomic, assign) int mediaHeight;
@property (nonatomic, assign) int mediaWidth;
@property (nonatomic, copy) NSString *src;
@property (nonatomic, assign) CGFloat startTime;
@property (nonatomic, assign) CGFloat endTime;
@property (nonatomic, assign) CGFloat fadeDuration;
@property (nonatomic, assign) int displayMode;
@property (nonatomic, assign) int rotation;
@property (nonatomic, assign) CGFloat duration;
@end


@protocol AliyunClip;

@interface AliyunTrack : AliyunJSONModel

@property (nonatomic, assign) int idTrack;
@property (nonatomic, assign) float volume;
@property (nonatomic, strong) NSMutableArray<AliyunClip> *clipList;

@end
