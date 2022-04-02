//
//  XMUniversalAdProvider.h
//  XMAd
//
//  Created by C on 2022/2/22.
//  Copyright © 2022 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class XMUniversalAd,XMSplashAdProvider;

@interface XMUniversalAdProvider : NSObject


/**
 *
 * 设置开屏的Provider，如果不设置，这里请求的广告将不会包含开屏广告，
 * 如果项目方没有接入开屏，可以忽略，如果项目方接入了开屏，可以将开屏类设置到这里
 * 设置到这里不会影响项目方单独的开屏功能
 *
 */
@property (nonatomic, class) XMSplashAdProvider *splashAdProvider;


/// 获取V5.0的广告，注意该广告类型不确定，请注意渲染方式
/// @param param 请求参数
/// @param completion 是否有广告的回调
+ (void)universalAdModelWithParam:(XMAdUniversalParam *)param
                       completion:(void(^_Nonnull)(XMUniversalAd * _Nullable model, XMError *_Nullable error))completion;


/// 预加载
/// @param param param
+ (void)preloadAds:(XMAdUniversalParam *)param;



/// 从缓存中获取广告，不会触发广告请求，获取的广告可能为nil
/// @param param param
/// @param error 错误信息
+ (XMUniversalAd *)fetchUniversalAdAdFromCache:(XMAdUniversalParam *)param
                                         error:(XMError *_Nullable*_Nullable)error;



@end

NS_ASSUME_NONNULL_END
