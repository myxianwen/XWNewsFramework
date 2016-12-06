//
//  XWImageNewsController.h
//  XWNewsSDK
//
//  Created by yj on 16/11/30.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNews.h"
#import "XWNewsViewControllerDelegate.h"
@interface XWImageNewsController : UIViewController


@property (strong,nonatomic) XWNews *news;

/** 从哪个对应的频道跳转过来id */
@property (nonatomic,strong) NSString *channel_id;


/**
 *  是否为活动新闻
 */
@property (assign,nonatomic,getter=isActivityNews) BOOL activityNews;
/**
 新闻详情代理
 */
@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;

@end
