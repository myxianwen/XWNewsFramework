//
//  XWNewsDetailController.h
//  XWNewsSDK
//
//  Created by yj on 16/11/28.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNews.h"
//#import "XWNewsViewControllerDelegate.h"
#import "XWNewsFrameWork/XWNewsDetailBottomView.h"
@class XWNewsDetailController;

@protocol XWNewsViewControllerDelegate <NSObject>


@optional
/**
 新闻列表点击事件回调
 
 @param newsViewController xw
 @param indexPath inedx
 @param news               新闻模型
 */
- (void)newsViewController:(XWNewsViewController*)newsViewController didSeletedRowAtIndex:(NSIndexPath *)indexPath news:(XWNews*)news;

@end
@interface XWNewsDetailController : UIViewController

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
