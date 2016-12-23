//
//  XWSubjectListController.h
//  XWNewsSDK
//
//  Created by yj on 16/11/30.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNewsViewControllerDelegate.h"
#import "XWNews.h"


@interface XWSubjectListController : UIViewController

@property (strong,nonatomic) XWNews *news;

/**
 点击对应的频道id，用于标识用户从哪个频道点进来的
 */
@property (copy,nonatomic) NSString *channel_id;

@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;

@end
