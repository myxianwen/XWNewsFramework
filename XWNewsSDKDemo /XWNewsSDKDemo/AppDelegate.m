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
    
    
    
    
    // 下面设置为可选类型
    /*
     // 设置顶部导航栏的颜色
     [XWNewsSettingsManager sharedSettingsManger].navigationBackgroudColor = [UIColor redColor];
     
     // 设置顶部标题未选中状态的颜色
     [XWNewsSettingsManager sharedSettingsManger].scrollNormalTitleColor = [UIColor greenColor];
     
     // 设置顶部标题选中的颜色
     [XWNewsSettingsManager sharedSettingsManger].scrollSelectedTitleColor = [UIColor yellowColor];
     
     // 设置滑动条的颜色
     [XWNewsSettingsManager sharedSettingsManger].sliderColor = [UIColor blueColor];
     
     // 设置新闻列表背景色
     [XWNewsSettingsManager sharedSettingsManger].newsListBackgroundColor = [UIColor greenColor];
     
     // 设置新闻类型的背景颜色
     [XWNewsSettingsManager sharedSettingsManger].newsMediaTypeBackgroundColor = [UIColor greenColor];
     // 设置新闻标题颜色
     [XWNewsSettingsManager sharedSettingsManger].newsTitleColor = [UIColor redColor];
     // 设置新闻来源，阅读数、评论，时间的颜色
     [XWNewsSettingsManager sharedSettingsManger].newsSubTextColor = [UIColor yellowColor];
     */
    
    return YES;
}


- (void)newsSDKDidRegisterSuccessUserId:(NSString*)userId {
    
    [XWNewsSDK setUserInfoWithUserId:userId nickName:@"小明" avatar_url:@""];
}

@end
