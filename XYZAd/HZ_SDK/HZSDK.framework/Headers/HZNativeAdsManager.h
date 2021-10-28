//
//  HZNativeAdsManager.h
//  HZSDK
//
//  Created by C on 2021/3/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class HZNativeAd;

@protocol HZNativeAdsManagerDelegate;

@interface HZNativeAdsManager : NSObject

/// The delegate for receiving state change messages such as requests succeeding/failing.
/// The delegate can be set to any object which conforming to <HZNativeAdsManagerDelegate>.
@property (nonatomic, weak, nullable) id<HZNativeAdsManagerDelegate> delegate;


- (instancetype)initWithAppId:(NSString *)appId placementId:(NSString *)placementId;

/**
 It is recommended to request no more than 3 ads.
 The maximum is 10.
 */
- (void)loadAdDataWithCount:(int)count;

@end

@protocol HZNativeAdsManagerDelegate <NSObject>

@optional

- (void)hz_nativeAdsManagerSuccessToLoad:(HZNativeAdsManager *)adsManager nativeAds:(NSArray<HZNativeAd *> *_Nullable)nativeAdDataArray;

- (void)hz_nativeAdsManager:(HZNativeAdsManager *)adsManager didFailWithError:(HZError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
