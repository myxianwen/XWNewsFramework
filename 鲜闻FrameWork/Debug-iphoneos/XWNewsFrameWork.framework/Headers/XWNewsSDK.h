//
//  XWNewsSDK.h
//  XWNewsSDK
//
//  Created by yj on 16/11/25.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XWNewsSDK : NSObject

/**
 注册鲜闻sdk

 @param appId  id
 @param appkey key
 */
+(void)registerSDKWithAppId:(NSString*)appId appKey:(NSString*)appkey;

@end
