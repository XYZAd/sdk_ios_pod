//
//  XMAdMaterialMeta.h
//  XMAd
//
//  Created by C on 2020/9/4.
//  Copyright © 2020 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XMAdMaterialMeta : NSObject

/// 应用id
@property (nonatomic, copy, readonly) NSString *appid;

/// 广告位id
@property (nonatomic, copy, readonly) NSString *slotid;

/// 广告位置
@property (nonatomic, copy, readonly) XMAdPageType *adposition;

/// 广告类型
@property (nonatomic, assign, readonly) XMAdSourceType adsource;

/// 场景类型
@property (nonatomic, copy, readonly) NSString *gametype;

/// 广告单价信息标签，注意，这里是加密（base64）后的字符串，如需解密，请联系对接开发
@property (nonatomic, copy, readonly) NSString *ecpmLevel;

@end

NS_ASSUME_NONNULL_END
