//
//  AliyunVideoSDKPro.h
//  AliyunVideoSDKPro
//
//  Created by Worthy Zhang on 2019/10/29.
//  Copyright © 2019 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for AliyunVideoSDKPro.
FOUNDATION_EXPORT double AliyunVideoSDKProVersionNumber;

//! Project version string for AliyunVideoSDKPro.
FOUNDATION_EXPORT const unsigned char AliyunVideoSDKProVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AliyunVideoSDKPro/PublicHeader.h>

#ifndef AliyunVideoSDKPro_h
#define AliyunVideoSDKPro_h
#import <AliyunVideoSDKPro/AliyunMixMediaInfoParam.h>
#import <AliyunVideoSDKPro/AliyunMixRecorder.h>
#import <AliyunVideoSDKPro/AliyunMixStream.h>
#import <AliyunVideoSDKPro/AliyunMixTrack.h>
#import <AliyunVideoSDKPro/AliyunMixComposer.h>
#import <AliyunVideoSDKPro/AliyunAudioRecorder.h>
#import <AliyunVideoSDKPro/AliyunClipManager.h>
#import <AliyunVideoSDKPro/AliyunFacePoint.h>
#import <AliyunVideoSDKPro/AliyunIRecorder.h>
#import <AliyunVideoSDKPro/AliyunVideoStitch.h>
#import <AliyunVideoSDKPro/AliyunXianyuFaceMap.h>
#import <AliyunVideoSDKPro/AliyunCrop.h>
#import <AliyunVideoSDKPro/AliyunImageCrop.h>
#import <AliyunVideoSDKPro/AliyunImporter.h>
#import <AliyunVideoSDKPro/AliyunIPlayer.h>
#import <AliyunVideoSDKPro/AliyunEditor.h>
#import <AliyunVideoSDKPro/AliyunIExporter.h>
#import <AliyunVideoSDKPro/AliyunIPlayerCallback.h>
#import <AliyunVideoSDKPro/AliyunIExporterCallback.h>
#import <AliyunVideoSDKPro/AliyunPasterBaseView.h>
#import <AliyunVideoSDKPro/AliyunPasterManager.h>
#import <AliyunVideoSDKPro/AliyunPasterController.h>
#import <AliyunVideoSDKPro/AliyunIPasterRender.h>
#import <AliyunVideoSDKPro/AliyunPasterUIEventProtocol.h>
#import <AliyunVideoSDKPro/AliyunIPaint.h>
#import <AliyunVideoSDKPro/AliyunICanvasView.h>
#import <AliyunVideoSDKPro/AliyunPublishManager.h>
#import <AliyunVideoSDKPro/AliyunVodPublishManager.h>
#import <AliyunVideoSDKPro/AVAsset+AliyunSDKInfo.h>
#import <AliyunVideoSDKPro/AliyunAction.h>
#import <AliyunVideoSDKPro/AliyunActionProtocol.h>
#import <AliyunVideoSDKPro/AliyunAlphaAction.h>
#import <AliyunVideoSDKPro/AliyunClip.h>
#import <AliyunVideoSDKPro/AliyunCustomAction.h>
#import <AliyunVideoSDKPro/AliyunEffect.h>
#import <AliyunVideoSDKPro/AliyunEffectBlurBackground.h>
#import <AliyunVideoSDKPro/AliyunEffectCaption.h>
#import <AliyunVideoSDKPro/AliyunEffectDub.h>
#import <AliyunVideoSDKPro/AliyunEffectFactory.h>
#import <AliyunVideoSDKPro/AliyunEffectFilter.h>
#import <AliyunVideoSDKPro/AliyunEffectImage.h>
#import <AliyunVideoSDKPro/AliyunEffectMV.h>
#import <AliyunVideoSDKPro/AliyunEffectMusic.h>
#import <AliyunVideoSDKPro/AliyunEffectPaster.h>
#import <AliyunVideoSDKPro/AliyunEffectPasterBase.h>
#import <AliyunVideoSDKPro/AliyunEffectPasterFrameItem.h>
#import <AliyunVideoSDKPro/AliyunEffectPasterTimeItem.h>
#import <AliyunVideoSDKPro/AliyunEffectRunningDisplayMode.h>
#import <AliyunVideoSDKPro/AliyunEffectStaticImage.h>
#import <AliyunVideoSDKPro/AliyunEffectSubtitle.h>
#import <AliyunVideoSDKPro/AliyunEffectTimeFilter.h>
#import <AliyunVideoSDKPro/AliyunErrorCode.h>
#import <AliyunVideoSDKPro/AliyunErrorCodeEnum.h>
#import <AliyunVideoSDKPro/AliyunErrorLogger.h>
#import <AliyunVideoSDKPro/AliyunEventManager.h>
#import <AliyunVideoSDKPro/AliyunHttpClient.h>
#import <AliyunVideoSDKPro/AliyunIClipConstructor.h>
#import <AliyunVideoSDKPro/AliyunIEffectRecovery.h>
#import <AliyunVideoSDKPro/AliyunJSONModel.h>
#import <AliyunVideoSDKPro/AliyunMediaInfo.h>
#import <AliyunVideoSDKPro/AliyunMoveAction.h>
#import <AliyunVideoSDKPro/AliyunNativeParser.h>
#import <AliyunVideoSDKPro/AliyunRotateAction.h>
#import <AliyunVideoSDKPro/AliyunRotateByAction.h>
#import <AliyunVideoSDKPro/AliyunRotateRepeatAction.h>
#import <AliyunVideoSDKPro/AliyunRotateToAction.h>
#import <AliyunVideoSDKPro/AliyunScaleAction.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffect.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectCircle.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectFade.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectPolygon.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectShuffer.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectTranslate.h>
#import <AliyunVideoSDKPro/AliyunVideoParam.h>
#import <AliyunVideoSDKPro/AliyunVideoSDKInfo.h>
#import <AliyunVideoSDKPro/AliyunEffectConfig.h>
#endif
