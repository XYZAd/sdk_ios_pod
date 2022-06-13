//
//  JHVideoConfig.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/26.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JHVideoConfig : NSObject

/**
 视频自动播放CL00E9，默认 JHVideoAutoPlayPolicyWIFI,
 选择 JHVideoAutoPlayPolicyNever CL00E9时，需要开发者调用 JHMediaView 的 play\pause 方法触发视频播、暂停，
 或者开启 userControlEnable 设置，让用户点击 MediaView 控制播放状态
 */
@property (nonatomic, assign) JHVideoAutoPlayPolicy autoPlayPolicy;

/**
 是否静音播放视频广告，视频初始状态是否静音，默认 YES，
 可通过 JHMediaView muteEnable: 方法实时控制播放器j静音状态，
 */
@property (nonatomic, assign) BOOL videoMuted;


/**
 是否支持用户点击 MediaView 改变视频播放暂停状态，默认 NO
 设为 YES 时，用户点击会切换播放器播放、暂停状态
 */
@property (nonatomic, assign) BOOL userControlEnable;

/**
 是否展示播放进度条，默认 YES
 */
@property (nonatomic, assign) BOOL progressViewEnable;

/**
 是否展示播放器封面图，默认 YES
 */
@property (nonatomic, assign) BOOL coverImageEnable;

@end

NS_ASSUME_NONNULL_END
