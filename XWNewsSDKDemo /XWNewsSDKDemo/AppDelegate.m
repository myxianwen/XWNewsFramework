//
//  AppDelegate.m
//  XWNewsSDKDemo
//
//  Created by yj on 16/11/28.
//  Copyright © 2016年 yj. All rights reserved.
//

#import "AppDelegate.h"
#import <XWNewsFrameWork/XWNewsSDK.h>
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    [XWNewsSDK registerSDKWithAppId:@"xxxx" appKey:@"test" delegate:self];
    
    return YES;
}


- (void)newsSDKDidRegisterSuccessUserId:(NSString*)userId {
    
    [XWNewsSDK setUserInfoWithUserId:userId nickName:@"小明" avatar_url:@""];
}

@end
