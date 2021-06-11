//
//  AliyunRollCaptionComposer.h
//  AliyunVideoSDKPro
//
//  Created by mengyehao on 2021/2/26.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AliyunVideoSDKPro/AliyunRollCaptionItemStyle.h>

NS_ASSUME_NONNULL_BEGIN

@interface AliyunRollCaptionComposer  : NSObject

/**
* 更新字幕信息 API_AVAILABLE(3.20.0)
*
* @param captionList 单个字幕包含：@see AliyunRollCaptionItemStyle
*/
- (void)updateCaptionList:(NSArray<AliyunRollCaptionItemStyle *> *)captionList;

/**
 * 编辑单个字幕样式 API_AVAILABLE(3.20.0)
 *
 * @param index
 * @return
 */
- (AliyunRollCaptionItemStyle *)captionItemStyle:(int)index;

/**
 * 显示 API_AVAILABLE(3.20.0)
 *
 * @return bool
 */
- (BOOL)show;

/**
 * 重置 API_AVAILABLE(3.20.0)
 * 注意：会清除字幕信息
 */
- (BOOL)reset;

@end

NS_ASSUME_NONNULL_END
