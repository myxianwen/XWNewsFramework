//
//  XWNewsSettingsManager.h
//  XWNewsSDK
//
//  Created by yj on 16/12/5.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface XWNewsSettingsManager : NSObject

+ (instancetype)sharedSettingsManger;

/**
 顶部选中字体的颜色，R:194 G:39 B:39为默认颜色
 */
@property (strong,nonatomic) UIColor*scrollSelectedTitleColor;


/**
 顶部未选中的字体颜色，默认为黑色
 */
@property (strong,nonatomic) UIColor *scrollNormalTitleColor;


/**
 顶部导航视图的背景色，默认为[UIColor whiteColor]
 */
@property (strong,nonatomic) UIColor *navigationBackgroudColor;


/**
 顶部滑动条的颜色 R:194 G:39 B:39为默认颜色
 */
@property (strong,nonatomic) UIColor *sliderColor;


/**
 新闻列表的背景色，默认为白色
 */
@property (strong,nonatomic) UIColor *newsListBackgroundColor;


/**
 新闻标题也是，默认为黑色
 */
@property (strong,nonatomic) UIColor *newsTitleColor;


/**
 新闻来源，阅读数，时间，评论字体的颜色,默认为R:150,G:150,B:150
 */
@property (strong,nonatomic) UIColor *newsSubTextColor;

/**
 新闻类型的背景色，[UIColor colorWithRed:191/255.0 green:51/255.0 blue:48/255.0 alpha:1.0];
 */
@property (strong,nonatomic) UIColor *newsMediaTypeBackgroundColor;



@end
