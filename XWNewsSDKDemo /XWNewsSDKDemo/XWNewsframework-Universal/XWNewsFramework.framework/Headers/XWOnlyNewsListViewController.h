//
//  XWOnlyNewsListViewController.h
//  XWNewsSDK
//
//  Created by yzl on 16/12/28.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNews.h"
#import "XWNewsViewControllerDelegate.h"


@class XWNewsChannel;
@class XWOnlyNewsListViewController;

@interface XWOnlyNewsListViewController : UIViewController

@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;

@property (strong, nonatomic) NSString *channelName;//频道名字


///**
// 频道模型数据
// */
@property (strong, nonatomic) XWNewsChannel *channel;

@end
