//
//  XMImgTextAdProvider.h
//  XMAd
//
//  Created by 大大东 on 2019/12/12.
//  Copyright © 2019 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>


@class XMImgTextAd;
@class XMError;
NS_ASSUME_NONNULL_BEGIN


/// 用于请求图文（包含自渲染和模版）的Provider
@interface XMImgTextAdProvider : NSObject <XMAdProviderProtocol>


/**
 
 注意，获取的广告model，sdk内部将不在持有，需要外部持有引用，防止释放
 
 */

/// 请求图文广告
/// @param param 请求信息，具体参见XMAdImgTextParam的api介绍
/// @param completion 回调
+ (void)imgTextAdModelWithParam:(XMAdImgTextParam *)param
                     completion:(void(^_Nonnull)(XMImgTextAd * _Nullable model, XMError *_Nullable error))completion;


/// 预加载
/// @param param param
+ (void)preloadAds:(XMAdImgTextParam *)param;


/// 从缓存中获取广告，不会触发广告请求，获取的广告可能为nil
/// @param param param
/// @param error 错误信息
+ (XMImgTextAd *)fetchImgTextAdFromCache:(XMAdParam *)param
                                   error:(XMError *_Nullable*_Nullable)error;


@end

NS_ASSUME_NONNULL_END
