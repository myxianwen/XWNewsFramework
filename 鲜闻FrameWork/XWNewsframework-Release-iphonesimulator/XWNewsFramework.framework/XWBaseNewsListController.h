//
//  XWBaseNewsListController.h
//  XWNewsSDK
//
//  Created by yj on 16/11/19.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNewsViewControllerDelegate.h"
#import "XWNews.h"
@class VTMagicView;
@class XWNewsChannel;




@interface XWBaseNewsListController : UITableViewController


/**
 频道模型数据
 */
@property (strong,nonatomic) XWNewsChannel *channel;



+(XWBaseNewsListController*)baseNewsListControllerWithMagicView:(VTMagicView*)magicView;

@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;

@end
