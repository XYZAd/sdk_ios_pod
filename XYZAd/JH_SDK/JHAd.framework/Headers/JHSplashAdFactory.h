//
//  JHSplashAdFactory.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/7.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHSplashAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface JHSplashAdFactory : NSObject

/**通过工厂方法创建JHSplashAd*/
+ (JHSplashAd *)createSplashAdWithPlacementId:(NSString *)placementId;


@end

NS_ASSUME_NONNULL_END
