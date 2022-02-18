//
//  XMAdExpressView.h
//  XMAd
//
//  Created by C on 2022/1/25.
//  Copyright © 2022 XMAd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class XMVideoConfig;

NS_ASSUME_NONNULL_BEGIN

@interface XMAdExpressView : UIView


/**
 * 视频配置（default is null）
 */
@property (nonatomic, strong) XMVideoConfig *videoConfig;


/*
 required.
 Root view controller for handling ad actions.
 */
@property (nonatomic, weak) UIViewController * rootViewController;

/**
 是否是视频广告（MTG不返回类型，无法判别，默认false）

 */
@property (nonatomic, assign, readonly) BOOL isVideo;


/**
 当前播放时长（注意，只有穿山甲、广点通、百度贴片、万裕有该参数，其他获取为0）

 @return 视频播放时长
 */
- (NSTimeInterval)currentTime;


/**
 视频总时长（注意，只有穿山甲、广点通、百度、万裕有该参数，其他获取为0）

 @return 视频总时长
 */
- (NSTimeInterval)duration;


/**
 开始渲染广告
 
 */
- (void)renderAdIfNeed;

/**
 移除广告渲染
 
 */
- (void)unRender;


/**
 * @brief 重新布局.动画式变化,例如根据触发时目前新尺寸，用于横竖屏切换（主要是百度广告用）
 *
 * @param duration 动画时长
 * @param frame 目标的尺寸
 */
- (void)reSizeInAnimateDuration:(double)duration
                    targetFrame:(CGRect)frame;


@end

NS_ASSUME_NONNULL_END
