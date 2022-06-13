//
//  JHAdApi.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/7.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JHAd/JHAdConst.h>
NS_ASSUME_NONNULL_BEGIN
@interface JHAdApi : NSObject

/**
    SDK初始化
    注意：该方法必须在didFinishLaunchingWithOptions中调用且一定要调用
 */
+ (void)initJHAd;
/**版本号*/
+ (NSString *)jh_version;
/**
    设置日志等级，默认为没有调试日志输出
 */
+ (void)jh_setLogLevel:(JHLogLevel)level;
/**
    app向SDK传递IDFA
    注意：如果app中有获取idfa的方法，获取到idfa后请传递给sdk
 */
+ (void)jh_setTransmitIDFA:(NSString*)idfaString;

/**
 关闭个性化推荐广告
 1:屏蔽个性化推荐广告
 0(所有非1):不屏蔽个性化推荐广告
 */
+ (void)jh_setPersonalizedState:(NSInteger)state;

@end

NS_ASSUME_NONNULL_END
