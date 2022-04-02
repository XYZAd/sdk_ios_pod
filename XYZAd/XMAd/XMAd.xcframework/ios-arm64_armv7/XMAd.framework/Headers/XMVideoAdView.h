//
//  XMVideoAdView.h
//  XMAd
//
//  Created by C on 2022/2/7.
//  Copyright © 2022 XMAd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class XMVideoConfig;

NS_ASSUME_NONNULL_BEGIN

@interface XMVideoAdView : UIView

/**
 * 视频配置（default is null）
 */
@property (nonatomic, strong) XMVideoConfig *videoConfig;


/**
 * 视频广告时长，单位 ms，可能为0
 */
- (CGFloat)videoDuration;

/**
 * 视频广告已播放时长，单位 ms，可能为0
 */
- (CGFloat)videoPlayTime;

/**
 播放视频
 */
- (void)play;

/**
 暂停视频，调用 pause 后，需要被暂停的视频广告对象，不会再自动播放，需要调用 play 才能恢复播放。
 */
- (void)pause;

/**
 停止播放，并展示第一帧
 */
- (void)stop;

/**
 播放静音开关
 @param flag 是否静音
 */
- (void)muteEnable:(BOOL)flag;

/**
 自定义播放按钮(目前只能设置穿山甲、广点通、万裕）

 @param image 自定义播放按钮图片，不设置为默认图
 @param size 自定义播放按钮大小，不设置为默认大小 44 * 44
 */
- (void)setPlayButtonImage:(UIImage *)image size:(CGSize)size;

@end



NS_ASSUME_NONNULL_END
