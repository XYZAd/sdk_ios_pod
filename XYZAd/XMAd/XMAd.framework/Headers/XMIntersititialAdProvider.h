//
//  XMIntersititialAdProvider.h
//  XMAd
//
//  Created by C on 2020/6/29.
//  Copyright © 2020 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>

@class XMError,XMIntersititialAd;

NS_ASSUME_NONNULL_BEGIN

/// 用于请求插屏广告的Provider，新插屏，通用插屏都走该Provider
@interface XMIntersititialAdProvider : NSObject<XMAdProviderProtocol>


/// 获取intersititialAd
/// @param param 参数
/// @param completion 回调
+ (void)intersititialAdModelWithParam:(XMAdIntersititialParam *)param
                           completion:(void(^_Nonnull)(XMIntersititialAd * _Nullable model, XMError *_Nullable error))completion;


/// 预加载
/// @param param param
+ (void)preloadAds:(XMAdIntersititialParam *)param;


/// 从缓存中获取广告，不会触发广告请求，但是可能会阻塞线程，获取的广告可能为nil
/// @param param param
/// @param error 错误信息
+ (XMIntersititialAd *)fetchIntersititialAdFromCache:(XMAdParam *)param
                                               error:(XMError *_Nullable*_Nullable)error;

@end

NS_ASSUME_NONNULL_END
