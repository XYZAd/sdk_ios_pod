//
//  JHBannerAdFactory.h
//  JHAd
//
//  Created by Liujingjie on 2020/2/8.
//  Copyright © 2020 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHBannerAdView.h"

NS_ASSUME_NONNULL_BEGIN

@interface JHBannerAdFactory : NSObject

/**通过工厂方法创建JHBannerAdView*/
+ (void)createBannerAdWithPlacementId:(NSString *)placementId frame:(CGRect)frame vc:(UIViewController *)vc  result:(nonnull void (^)(JHBannerAdView * _Nullable bannerAdView, NSError * _Nullable error))result;


@end

NS_ASSUME_NONNULL_END
