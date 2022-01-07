//
//  XMCommonDef.h
//  XMCommon
//
//  Created by 大大东 on 2021/3/30.
//  Copyright © 2021 大大东. All rights reserved.
//

#ifndef XMCommonDef_h
#define XMCommonDef_h


typedef NS_ENUM(NSInteger, XMSDKRunMode) {
    XMSDKRunModeRelease = 0,     // URL使用生产环境地址
    XMSDKRunModeITest   = -999,  // URL使用测试环境地址
};

//
typedef NS_ENUM(NSInteger, XMSDKLogLevel) {
    XMSDKLogLevelError, // 只输出error
    XMSDKLogLevelAll,   // 输出全部日志
    XMSDKLogLevelNone,  // 关闭日志输出
};


//
#define XM_BLOCK_EXEC(block, ...) if (block) { block(__VA_ARGS__); };

//
#define XM_WEAK_SELF       __weak __typeof(self)weakSelf = self;
#define XM_STRONG_SELF     __strong __typeof(weakSelf)strongSelf = weakSelf;
#define XM_STRONG_SELF_AutoReturn  __strong __typeof(weakSelf)strongSelf = weakSelf; if (!strongSelf) { return ;}


#endif /* XMCommonDef_h */
