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
#import <AliyunVideoSDKPro/AliyunICanvasLineData.h>
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
#import <AliyunVideoSDKPro/AliyunWipeAction.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffect.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectCircle.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectFade.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectPolygon.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectShuffer.h>
#import <AliyunVideoSDKPro/AliyunTransitionEffectTranslate.h>
#import <AliyunVideoSDKPro/AliyunVideoParam.h>
#import <AliyunVideoSDKPro/AliyunVideoSDKInfo.h>
#import <AliyunVideoSDKPro/AliyunEffectConfig.h>
#import <AliyunVideoSDKPro/AliyunRollCaptionComposer.h>
#import <AliyunVideoSDKPro/AliyunThumbnailParser.h>
#import <AliyunVideoSDKPro/AliyunCaptionSticker.h>

#import <AliyunVideoSDKPro/AliyunStickerManager.h>

#import <AliyunVideoSDKPro/AliyunSticker.h>
#import <AliyunVideoSDKPro/AliyunGifSticker.h>
#import <AliyunVideoSDKPro/AliyunGifStickerController.h>

#import <AliyunVideoSDKPro/AliyunRenderModel.h>
#import <AliyunVideoSDKPro/AliyunRenderBaseController.h>
#import <AliyunVideoSDKPro/AliyunCaptionStickerController.h>

#import <AliyunVideoSDKPro/AliyunImageSticker.h>
#import <AliyunVideoSDKPro/AliyunRecorderSticker.h>

#import <AliyunVideoSDKPro/AliyunRecordSource.h>
#import <AliyunVideoSDKPro/AliyunMicRecordSource.h>
#import <AliyunVideoSDKPro/AliyunCameraRecordSource.h>
#import <AliyunVideoSDKPro/AliyunViewRecordSource.h>
#import <AliyunVideoSDKPro/AliyunPlayerRecordSource.h>

#import <AliyunVideoSDKPro/AliyunRecordController.h>
#import <AliyunVideoSDKPro/AliyunAudioRecordController.h>
#import <AliyunVideoSDKPro/AliyunVideoRecordController.h>

#import <AliyunVideoSDKPro/AliyunRecorderConfig.h>
#import <AliyunVideoSDKPro/AliyunRecorder.h>

#import <AliyunVideoSDKPro/AliyunEditorProject.h>
#import <AliyunVideoSDKPro/AEPConfig.h>
#import <AliyunVideoSDKPro/AEPTimeline.h>
#import <AliyunVideoSDKPro/AEPSource.h>
#import <AliyunVideoSDKPro/AEPTrack.h>
#import <AliyunVideoSDKPro/AEPVideoTrackClip.h>
#import <AliyunVideoSDKPro/AEPAudioTrackClip.h>
#import <AliyunVideoSDKPro/AEPStickerTrack.h>
#import <AliyunVideoSDKPro/AEPEffectTrack.h>
#import <AliyunVideoSDKPro/AEPGlobalTrack.h>
#import <AliyunVideoSDKPro/AEPEffect.h>
#import <AliyunVideoSDKPro/AEPTransitionEffect.h>
#import <AliyunVideoSDKPro/AEPAction.h>

#import <AliyunVideoSDKPro/AliyunEditor+Draft.h>
#import <AliyunVideoSDKPro/AliyunDraft.h>
#import <AliyunVideoSDKPro/AliyunDraft+Cloud.h>
#import <AliyunVideoSDKPro/AliyunDraftManager.h>
#import <AliyunVideoSDKPro/AEPResourceModel.h>

#endif
