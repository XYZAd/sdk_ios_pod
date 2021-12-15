//
//  XMExpressImgTextAdProvider.h
//  XMAd_Overseas
//
//  Created by C on 2021/3/24.
//  Copyright © 2021 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN
@class XMExpressImgTextAd;
@class XMError;

@interface XMExpressImgTextAdProvider : NSObject<XMAdProviderProtocol>



/*
 
 注意，获取的广告model，sdk内部将不在持有，需要外部持有引用，防止释放
 
 */

/// 获取模版广告
+ (void)expressImgTextAdModelWithParam:(XMAdExpressParam *)param
                            completion:(void(^_Nonnull)(XMExpressImgTextAd * _Nullable model, XMError *_Nullable error))completion;


/// 预加载
+ (void)preloadAds:(XMAdExpressParam *)param;

@end

NS_ASSUME_NONNULL_END
