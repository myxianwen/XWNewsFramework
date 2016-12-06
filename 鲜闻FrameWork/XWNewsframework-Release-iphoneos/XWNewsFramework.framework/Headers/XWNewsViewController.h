//
//  XWNewsViewController.h
//  XWNewsSDK
//
//  Created by yj on 16/11/19.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNews.h"
#import "XWNewsViewControllerDelegate.h"
@interface XWNewsViewController : UIViewController


@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;

@end
