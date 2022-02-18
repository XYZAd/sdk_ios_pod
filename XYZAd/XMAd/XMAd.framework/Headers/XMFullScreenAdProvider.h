//
//  XMFullScreenAdProvider.h
//  XMAd
//
//  Created by C on 2021/8/16.
//  Copyright © 2021 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class XMFullScreenAd;


/// 用于请求全屏广告的Provider
@interface XMFullScreenAdProvider : NSObject <XMAdProviderProtocol>

/// 获取全屏广告
/// @param param 参数
/// @param completion 回调
+ (void)fullScreenAdWithParam:(XMAdParam *)param
                   completion:(void(^_Nonnull)(XMFullScreenAd * _Nullable model, XMError * _Nullable error))completion;


/// 预加载
/// @param param param
+ (void)preloadAds:(XMAdParam *)param;



/// 从缓存中获取广告，不会触发广告请求，但是可能会阻塞线程，获取的广告可能为nil
/// @param param param
/// @param error 错误信息
+ (XMFullScreenAd *)fetchFullAdFromCache:(XMAdParam *)param
                                   error:(XMError *_Nullable*_Nullable)error;

@end

NS_ASSUME_NONNULL_END
