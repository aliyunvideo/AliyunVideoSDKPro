//
//  AliyunMoveAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"
#import <UIKit/UIKit.h>

@interface AliyunMoveAction : AliyunAction

@property (nonatomic, assign) CGPoint fromePoint;//开始的位置 坐标参考系是原始屏幕坐标系 （0，0）为左上角  和系统view行为一致
@property (nonatomic, assign) CGPoint toPoint;   //目标移动到的位置
@property (nonatomic, assign) CGSize displaySize;//动画移动的区域范围

- (id)initWithRestore:(NSDictionary *)dict;

@end
