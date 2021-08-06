//
//  AEPResourceModel.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/7/30.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AEPSource.h"

/**
 资源节点模块
 */
/**
 The module of resource
 */
typedef NS_ENUM(NSUInteger, AEPResourceModule) {
    AEPResourceModule_Unkown,
    /**
     封面
     */
    /**
     The Cover
     */
    AEPResourceModule_Cover,
    
    /**
     主视频轨道
     */
    /**
     The of main track
     */
    AEPResourceModule_MainVideo,

    /**
     主轨道的音乐
     */
    /**
     The music of main track
     */
    AEPResourceModule_Music,
    /**
     主轨道的配音
     */
    /**
     The dub of main track
     */
    AEPResourceModule_Dub,
    
    /**
     翻转字幕
     */
    /**
     The font of roll caption
     */
    AEPResourceModule_RollCaption,
    /**
     纯文字
     */
    /**
     The font of subtitle
     */
    AEPResourceModule_Subtitle,
    /**
     气泡字
     */
    /**
     The font of bubble
     */
    AEPResourceModule_Bubble,
    /**
     花字
     */
    /**
     The font of caption
     */
    AEPResourceModule_Caption,
   
    /**
     贴纸
     */
    /**
     The Sticker
     */
    AEPResourceModule_Sticker,

    /**
     The mv
     */
    AEPResourceModule_MV,
    /**
     滤镜
     */
    /**
     The filter
     */
    AEPResourceModule_Filter,
    /**
     特效
     */
    /**
     The Animation filter
     */
    AEPResourceModule_AnimationFilter,
    
    /**
     转场
     */
    /**
     The Transition between videos
     */
    AEPResourceModule_Transition,
    
    /**
     涂鸦
     */
    /**
     The paint
     */
    AEPResourceModule_Paint,
    /**
     水印
     */
    /**
     The watermark
     */
    AEPResourceModule_Watermark,
    /**
     尾部水印
     */
    /**
     The TailWatermark
     */
    AEPResourceModule_TailWatermark,
};

/**
 资源数据模型
 */
/**
 The model of resource
 */
@interface AEPResourceModel : NSObject

/**
 资源对象
 */
/**
 The soure of resource
 */
@property (nonatomic, strong, readonly) AEPSource *source;

/**
 资源节点所在的模块
 */
/**
 The module of node that using this resource
 */
@property (nonatomic, assign, readonly) AEPResourceModule module;

/**
 使用该资源的工程节点
 */
/**
 The node in project that using this resource
 */
@property (nonatomic, strong, readonly) id aepNode;

@end
