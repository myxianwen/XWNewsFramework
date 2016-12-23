//
//  XWNewsSDK.h
//  XWNewsSDK
//
//  Created by yj on 16/11/25.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol XWNewsSDKDelegate <NSObject>

@optional

/**
 sdk注册成功回调

 @param userId 用户id
 */
- (void)newsSDKDidRegisterSuccessUserId:(NSString*)userId;


/**
 sdk注册失败回调

 @param error 错误信息
 */
- (void)newsSDKDidRegisterFail:(NSError *)error;

@end


@interface XWNewsSDK : NSObject

/**
 注册鲜闻sdk

 @param appId  id
 @param appkey key
 */
+(void)registerSDKWithAppId:(NSString*)appId appKey:(NSString*)appkey delegate:(id<XWNewsSDKDelegate>)delegate;



/**
 设置是否显示推荐频道

 @param showRecommandChannel BOOL
 */
+ (void)setShowRecommandChannel:(BOOL)showRecommandChannel;

/**
 sdk版本号

 @return sdk 版本号
 */
+(NSString*)version;


/**
 设置用户信息

 @param userId     用户id
 @param nickName   昵称
 @param avatar_url 头像

 */
+(void)setUserInfoWithUserId:(NSString*)userId nickName:(NSString*)nickName avatar_url:(NSString*)avatar_url;


@end
