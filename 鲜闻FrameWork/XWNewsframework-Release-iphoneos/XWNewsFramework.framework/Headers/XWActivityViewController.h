//
//  XWActivityViewController.h
//  XWNewsSDK
//
//  Created by yj on 16/11/30.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNews.h"
#import "XWNewsViewControllerDelegate.h"
@interface XWActivityViewController : UIViewController

@property (strong,nonatomic) XWNews *news;

@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;

@end
