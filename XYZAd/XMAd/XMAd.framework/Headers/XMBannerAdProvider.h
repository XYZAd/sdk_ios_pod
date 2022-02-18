//
//  XMBannerAdProvider.h
//  XMAd
//
//  Created by 大大东 on 2019/12/24.
//  Copyright © 2019 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>

@class XMError,XMBannerAd;

NS_ASSUME_NONNULL_BEGIN


/// 用于请求模版banner的Provider
@interface XMBannerAdProvider : NSObject <XMAdProviderProtocol>


/**
 
 注意，获取的广告model，sdk内部将不在持有，需要外部持有引用，防止释放
 
 */

/// 获取banner
/// @param param 参数
/// @param completion 回调
+ (void)bannerAdModelWithParam:(XMAdBannerParam *)param
                    completion:(void (^)(XMBannerAd * _Nullable, XMError * _Nullable))completion;


/// 预加载
/// @param param param
+ (void)preloadAds:(XMAdBannerParam *)param;


/// 从缓存中获取广告，不会触发广告请求，但是可能会阻塞线程，获取的广告可能为nil
/// @param param param
/// @param error 错误信息
+ (XMBannerAd *)fetchBannerAdFromCache:(XMAdParam *)param
                                 error:(XMError *_Nullable*_Nullable)error;

@end

NS_ASSUME_NONNULL_END
