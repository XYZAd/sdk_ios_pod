//
//  JHRewardVideoAdFactory.h
//  JHAd
//
//  Created by L66J99E33 on 2019/11/27.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHRewardVideoAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface JHRewardVideoAdFactory : NSObject

+ (void)createRewardVideoAdWithPlacementId:(NSString *)placementId  result:(nonnull void (^)(JHRewardVideoAd * _Nullable rewardVideoAd, NSError * _Nullable error))result;

@end

NS_ASSUME_NONNULL_END
