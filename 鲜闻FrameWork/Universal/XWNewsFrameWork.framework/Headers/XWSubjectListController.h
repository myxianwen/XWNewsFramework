//
//  XWSubjectListController.h
//  XWNewsSDK
//
//  Created by yj on 16/11/30.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "XWNewsViewControllerDelegate.h"
#import "XWNews.h"

@class XWSubjectListController;

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
@interface XWSubjectListController : UIViewController
@property (strong,nonatomic) XWNews *news;

/**
 点击对应的频道id，用于标识用户从哪个频道点进来的
 */
@property (copy,nonatomic) NSString *channel_id;

@property (weak,nonatomic) id<XWNewsViewControllerDelegate> delegate;

@end
