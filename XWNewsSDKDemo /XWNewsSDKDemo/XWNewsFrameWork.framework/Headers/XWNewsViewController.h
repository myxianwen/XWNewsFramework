//
//  XWNewsViewController.h
//  XWNewsSDK
//
//  Created by yj on 16/11/19.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XWNews.h"
@class XWNewsViewController;

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

@interface XWNewsViewController : UIViewController


@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;

@end
