//
//  KSUSDKInfo.h
//  KSUSDKInfo
//
//  Created by Dylan Sun on 2021/6/9.
//

#import <Foundation/Foundation.h>
#import "KSAdUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, KSAdSDKType) {
    KSAdSDKTypeAD = 1, // 广告联盟 SDK
    KSAdSDKTypeCU = 2, // 内容联盟 SDK
    KSAdSDKTypeEU = 3, // 直播电商 SDK
    KSAdSDKTypePureCU = 4,// 纯内容联盟SDK,广告逻辑不执行不加载
};

@interface KSUSDKInfo : NSObject

// 用户兴趣标签
@property (nonatomic, copy) NSString *appTag;
@property (nonatomic, copy, getter=appId) NSString *appId;
@property (nonatomic, copy, getter=getAppName) NSString *appName;
@property (nonatomic, assign) BOOL personalizedRecommendation;
@property (nonatomic, assign) BOOL programmaticRecommendation;
@property (nonatomic, copy) void (^userInfoBlock)(KSAdUserInfo *);
@property (nonatomic, readonly) KSAdUserInfo *userInfo;
@property (nonatomic, copy) NSString *tkVersion;
@property (nonatomic, copy) NSString *jsVersion;
@property (nonatomic, copy) NSString *currentApiHost;
@property (nonatomic, copy) NSString *currentEUApiHost;
@property (nonatomic, copy) NSString *currentLiveHost;

+ (instancetype)sharedInstance;

+ (NSString *)SDKVersion;

+ (NSString *)protocolVersion;

+ (KSAdSDKType)sdkType;

+ (int64_t)sdkVersionCode;

@end

NS_ASSUME_NONNULL_END
