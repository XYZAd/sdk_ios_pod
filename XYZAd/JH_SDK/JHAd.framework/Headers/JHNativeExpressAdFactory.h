//
//  JHNativeExpressAdFactory.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/8.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHNativeExpressAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface JHNativeExpressAdFactory : NSObject

/**通过工厂方法创建JHNativeExpressAd*/
+ (void)createNativeExpressAdWithPlacementId:(NSString *)placementId adSize:(CGSize)size listView:(UIView *)listView curVC:(UIViewController *)curVC result:(void(^)(JHNativeExpressAd * __nullable nativeExpressAd,NSError * __nullable error))result;


@end

NS_ASSUME_NONNULL_END
