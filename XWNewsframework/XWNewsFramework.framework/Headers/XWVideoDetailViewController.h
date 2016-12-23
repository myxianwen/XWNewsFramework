//
//  XWVideoDetailViewController.h
//  XWNewsSDK
//
//  Created by yzl on 16/11/30.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNews.h"
#import "XWNewsDetailBottomView.h"
#import "XWNewsViewControllerDelegate.h"

@class XWVideoDetailViewController;

@interface XWVideoDetailViewController : UIViewController

@property (strong,nonatomic) XWNews *news;

/** 
 从哪个对应的频道跳转过来id
 */
@property (nonatomic,strong) NSString *channel_id;

/**
 新闻详情代理
 */
@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;


@end
