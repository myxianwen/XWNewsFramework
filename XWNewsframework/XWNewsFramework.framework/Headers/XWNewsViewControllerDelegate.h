//
//  XWNewsViewControllerDelegate.h
//  XWNewsSDK
//
//  Created by yj on 16/11/30.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger,XWNetLoadType){

    XWNetLoadTypeNewsList, // 新闻列表网络结果
    XWNetLoadTypeNewsDetail, // 新闻详情
    XWNetLoadTypeSubjectList, // 专题列表
    XWNetLoadTypeImagesNews, // 图片新闻
    XWNetLoadTypeViedeoDetail, // 视频详情
    XWNetLoadTypeActivity // 活动页
    
};
@class XWNews;
@protocol XWNewsViewControllerDelegate <NSObject>


@optional

/**
 列表点击事件

 @param controller 所在控制器
 @param indexPath  indexPath
 @param news       新闻对象
 @param op_from    对应的channel_id
 */
- (void)newsViewController:(UIViewController*)controller didSeletedRowAtIndex:(NSIndexPath *)indexPath news:(XWNews*)news op_from:(NSString*)op_from;






/**
 专题的返回按钮点击

 @param subjectListController 专题控制器
 @param backItem              返回item
 */
- (void)subjectListController:(UIViewController*)subjectListController didSelecctedBackItem:(UIButton*)backItem;


/**
 底部tabbar的点击事件
 
 @param item                 item，根据item的tag值来区分  XWBottomButtonTypeBack, // 返回按钮
 XWBottomButtonTypeComment, //评论 XWBottomButtonTypeShare // 分享
 @param news                 当前显示的新闻对象
 */
- (void)newsDetailController:(UIViewController*)newsDetailController didSelectTabBarItem:(UIButton*)item news:(XWNews*)news;

/**
 活动页面点击事件

 @param activityController 活动页面控制器
 */
- (void)activityControllerDidSelectedBackItem:(UIViewController*)activityController;

/**
 
 视频页面的返回按钮点击事件
 
 */
- (void)videoDetailViewController:(UIViewController*)videoDetailViewController didSelectBackItem:(UIButton*)item news:(XWNews*)news;

/**
 
 视频页面的分享按钮点击事件
 
 */
- (void)videoDetailViewController:(UIViewController*)videoDetailViewController didSelectShareItem:(UIButton*)item news:(XWNews*)news;




/**
 网络请求结束回调

 @param netLoadType 网络请求的界面类型(暂时只开放新闻列表的网络请求结束回调结果，其他界面后续会考虑)
 @param resultCode  结果code，当为 0 时为请求成功，其他为参数错误
 @param dataCount   返回的新闻条数，只有处于新闻列表的时候才有用，，返回值为-1
 @param error       网络错误的error,正常为nil，
 */
- (void)newsNetloadType:(XWNetLoadType)netLoadType resultCode:(int)resultCode dataCount:(NSUInteger)dataCount netError:(NSError*)error;


@end
