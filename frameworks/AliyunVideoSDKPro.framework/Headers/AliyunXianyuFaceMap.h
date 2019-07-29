//
//  AliyunXianyuFaceMap.h
//  QUSDK
//
//  Created by Vienta on 2017/8/14.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

__deprecated_msg("deprecated") @interface AliyunXianyuFaceMap : NSObject

/**
 输出宽高
 * @param width 输出宽
 * @param height 输出高
 */
- (id)initWithOutputWidth:(int)width height:(int)height;

/**
 * 设置TransformMatrix
 * @param fm float[16]
 * @param texture_asp 输入的纹理的宽高比
 */
- (void)setTransforamMatrix:(float*) fm texture_asp:(float)texture_asp;

/**
 * 添加动图
 * important: vid由调用者维护，在FaceMapInterface生命周期内
 * 不允许重复，且必须大于1000
 * @param vid 动图的id
 * @param dongtu_dir 动图的绝对目录
 * @param duration 持续时间微秒
 */

- (int)addGif:(int)vid path:(char const *)dongtu_dir duration:(int64_t)duration;

/**
 * 删除动图
 * @param vid 动图的id
 */
- (void)deleteGif:(int)vid;

/**
 * 设置人脸数据
 * @param vid 动图的id
 * @param face [left_eye_x, left_eye_y, right_eye_x, right_eye_y,
 *              mouth_x, mouth_y]
 * @param size 
 */
- (void)setFace:(int)vid face:(float *)face size:(int)size;

/**
 * 渲染
 * @param texture_id 输入纹理id
 * @return 输出纹理id
 */
- (int)render:(int)texture_id;

/**
 销毁
 */
- (void)destory;

@end
