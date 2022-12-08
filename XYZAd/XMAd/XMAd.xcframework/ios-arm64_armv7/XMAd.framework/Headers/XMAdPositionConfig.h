//
//  XMAdPositionConfig.h
//  XMAd
//
//  Created by C on 2020/7/28.
//  Copyright © 2020 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface XMAdPositionConfig : NSObject
/// 广告类型，具体看XMAdKey下面定义的key类型
@property (nonatomic, copy) XMAdKey adtype;

/// 广告位id，具体是三方平台申请的posid
@property (nonatomic, copy) NSString *tagid;

/// 三方广告的应用id
@property (nonatomic, copy) NSString *appid;

/// 请求数量，如果设置大于1的话，只对图文有效，其他当做默认值是1来处理
@property (nonatomic, assign) NSUInteger numbers;

/// 如果是权重（为0时无效），如果是竞价（为0时无效）
@property (nonatomic, assign) NSInteger weights;

/// 是否是模版
@property (nonatomic, assign) BOOL istemplate;

///  展示间隔（秒) 本次展示到下一次广告请求之间的时间间隔，云控下发。未下发或参数值为空，则表示无限制、走原逻辑
@property (nonatomic, assign) NSUInteger showinterval;


/// 展示上限（天）：单个用户的每自然天广告展示次数上限，云控下发。未下发或参数值为空，则表示无限制、走原逻辑
@property (nonatomic, assign) NSUInteger showupperlimit_day;


/// 展示上限（小时） ：单个用户的每自然小时广告展示次数上限，云控下发。未下发或参数值为空，则表示无限制、走原逻辑
@property (nonatomic, assign) NSUInteger showupperlimit_hour;

@end

NS_ASSUME_NONNULL_END
