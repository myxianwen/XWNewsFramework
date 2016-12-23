//
//  AppDelegate.m
//  XWNewsSDKDemo
//
//  Created by yj on 16/11/28.
//  Copyright © 2016年 yj. All rights reserved.
//

#import "AppDelegate.h"
#import <XWNewsFrameWork/XWNewsSDK.h>
#import "ViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    [XWNewsSDK registerSDKWithAppId:@"5100" appKey:@"731e52172f9872d6062a5c48c46ab863" delegate:self];
    
    
    
    // 新增设置是否显示推荐频道
    [XWNewsSDK setShowRecommandChannel:YES];
    
    
    self.window  = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    
    UITabBarController *tab = [[UITabBarController alloc] init];
    
    ViewController *test  = [ViewController new];
    
    [tab addChildViewController:test];
    
    test.title = @"test";
    self.window.rootViewController = tab;
    
    
    
    [self.window makeKeyAndVisible];
    
    
    
    
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


#pragma mark - sdk注册成功回调
- (void)newsSDKDidRegisterSuccessUserId:(NSString*)userId {
    
    [XWNewsSDK setUserInfoWithUserId:userId nickName:@"sdk" avatar_url:@""];
}

#pragma mark - sdk注册失败回调

- (void)newsSDKDidRegisterFail:(NSError *)error {
    
    NSLog(@"----注册失败----%@",error);
}


@end
