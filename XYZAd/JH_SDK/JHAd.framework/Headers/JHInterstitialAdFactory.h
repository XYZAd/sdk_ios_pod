//
//  JHInterstitialAdFactory.h
//  JHAd
//
//  Created by Liujingjie on 2020/2/8.
//  Copyright © 2020 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHInterstitialAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface JHInterstitialAdFactory : NSObject

/**通过工厂方法创建JHInterstitialAd*/
+ (void)createInterstitialAdWithPlacementId:(NSString *)placementId  result:(nonnull void (^)(JHInterstitialAd * _Nullable interititialAd, NSError * _Nullable error))result;

@end

NS_ASSUME_NONNULL_END
