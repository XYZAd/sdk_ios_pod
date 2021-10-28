//
//  BaiduMobAdWebSDK
//
//
//
#import <UIKit/UIKit.h>
#import "BaiduMobAdCommonConfig.h"

@interface BaiduMobAdSetting : NSObject
@property (nonatomic, assign) BOOL supportHttps;
@property (nonatomic, assign) BOOL trackCrash;

+ (BaiduMobAdSetting *)sharedInstance;

/**
 *  设置Landpage页面导航栏颜色
 */
+ (void)setLpStyle:(BaiduMobAdLpStyle)style;

/**
 * 设置视频缓存阀值，单位M, 取值范围15M-100M,默认30M
 */
+ (void)setMaxVideoCacheCapacityMb:(NSInteger)capacity;


/**
 关闭百度SDK 打印日志开关

 @param debugLogEnable YES开启  默认YES
 */
- (void)setDebugLogEnable:(BOOL)debugLogEnable;

/**
 打开或关闭百度CAID的开关

 @param enable YES开启  默认YES
 */
- (void)setBDPermissionEnable:(BOOL)enable;

/**
 * 获取CAID开关状态，默认开启。
 */
- (BOOL)getBDPermission;

/**
 * 限制个性化广告
 * @param limit YES限制，默认NO
 */
- (void)setLimitBaiduPersonalAds:(BOOL)limit;

/**
 * 获取个性化广告限制状态，默认不限制
 */
- (BOOL)getLimitBaiduPersonalAds;

@end

