//
//  JHUnifiedNativeAdFactory.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/27.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHUnifiedNativeAd.h"
#import "JHUnifiedNativeAdView.h"

NS_ASSUME_NONNULL_BEGIN

@interface JHUnifiedNativeAdFactory : NSObject

/**创建自渲染广告*/
+ (void)createUnifiedNativeAdWithPlacementId:(NSString *)placementId result:(nonnull void (^)(JHUnifiedNativeAd * _Nullable unifiedNativeAd, NSError * _Nullable error))result;
/**绑定view
 *cusView 为素材展示视图
 *listview 如果广告没有放在 UITableView 或者 UICollectionView需要传传广告视图的父视图
 *curVC 为当前广告所在的控制器
 *delegate 代理对象
 */
+ (JHUnifiedNativeAdView *)bindUnifiedNativeAdView:(UIView *)cusView listView:(UIView *)listView curVC:(UIViewController *)curVC delegate:(id<JHUnifiedNativeAdViewDelegate>)delegate dataObject:(JHUnifiedNativeAdDataObject *)dataObject;



@end

NS_ASSUME_NONNULL_END
