//
//  FirstViewController.m
//  XWNewsSDKDemo
//
//  Created by LJ on 2016/12/20.
//  Copyright © 2016年 yj. All rights reserved.
//

#import "FirstViewController.h"
#import <XWNewsFrameWork/XWNewsFrameWork.h>

@interface FirstViewController ()<XWNewsViewControllerDelegate>

@end

@implementation FirstViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
  
    
    
    XWNewsViewController *control = [[XWNewsViewController alloc] init];

    
    [self.view addSubview:control.view];
    control.view.frame = self.view.bounds;
    
    [self addChildViewController:control];
    control.delegate =self;
      self.view.backgroundColor = [UIColor whiteColor];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
//- (void)newsViewController:(UIViewController *)controller didSeletedRowAtIndex:(NSIndexPath *)indexPath news:(XWNews *)news op_from:(NSString *)op_from {
//    //news.skipType
//    //     news.news_id = @"6661731";
//    switch (news.skipType) {
//        case XWNewsSkipTypeNone:
//            // 不跳转
//            break;
//        case XWNewsSkipTypeNoraml:
//            
//            // 普通新闻
//        {
//            XWNewsDetailController *detail = [[XWNewsDetailController alloc] init];
//            
//            detail.news = news;
//            detail.channel_id = op_from;
//            detail.delegate = self;
//            [controller presentViewController:detail animated:YES completion:nil];
//        }
//            
//            break;
//        case XWNewsSkipTypeImage:
//            // 图片新闻
//        {
//            XWImageNewsController *imagesVC = [[XWImageNewsController alloc] init];
//            imagesVC.channel_id = op_from;
//            imagesVC.news = news;
//            imagesVC.delegate = self;
//            [controller presentViewController:imagesVC animated:YES completion:nil];
//        }
//            break;
//        case XWNewsSkipTypeViedeo:
//            // 视频
//        {
//            XWVideoDetailViewController *videoVC = [[XWVideoDetailViewController alloc] init];
//            videoVC.channel_id = op_from;
//            videoVC.news = news;
//            videoVC.delegate = self;
//            [controller presentViewController:videoVC animated:YES completion:nil];
//        }
//            break;
//        case XWNewsSkipTypeProject:
//            // 专题列表
//            
//        {
//            
//            XWSubjectListController *subject = [[XWSubjectListController alloc] init];
//            
//            subject.news = news;
//            subject.channel_id = op_from;
//            subject.delegate = self;
//            
//            [controller presentViewController:subject animated:YES completion:nil];
//            
//        }
//            
//            
//            break;
//        case XWNewsSkipTypeProjectDetail:
//            // 专题详情
//        {
//            
//            XWSubjectListController *subject = [[XWSubjectListController alloc] init];
//            
//            subject.news = news;
//            subject.channel_id = op_from;
//            subject.delegate = self;
//            
//            [controller presentViewController:subject animated:YES completion:nil];
//            
//            XWNewsDetailController *detail = [[XWNewsDetailController alloc] init];
//            
//            detail.news = news;
//            detail.channel_id = op_from;
//            detail.delegate = self;
//            [subject presentViewController:detail animated:YES completion:nil];
//            
//        }
//            break;
//        case XWNewsSkipTypeActivity:
//            // 活动
//        {
//            XWActivityViewController *activityVC = [[XWActivityViewController alloc] init];
//            activityVC.news = news;
//            activityVC.delegate = self;
//            
//            [controller presentViewController:activityVC animated:YES completion:nil];
//        }
//            break;
//            
//        default:
//            break;
//    }
//}



///**
// 专题列表点击事件
// 
// @param backItem 返回按钮
// */
//- (void)subjectListController:(UIViewController *)subjectListController didSelecctedBackItem:(UIButton *)backItem {
//    
//    
//    [subjectListController dismissViewControllerAnimated:YES completion:nil];
//}
//
//
//// 新闻详情或者图片新闻底部状态的的点击事件
//- (void)newsDetailController:(UIViewController *)newsDetailController didSelectTabBarItem:(UIButton *)item news:(XWNews *)news {
//    
//    switch (item.tag) {
//        case XWBottomButtonTypeBack:
//            
//            //返回
//            [newsDetailController dismissViewControllerAnimated:YES completion:nil];
//            break;
//            //评论
//        case XWBottomButtonTypeComment:
//            break;
//        case XWBottomButtonTypeShare:
//            
//            // 分享
//            
//            break;
//        default:
//            break;
//    }
//}
//
//
//// 活动页面的返回按钮点击事件
//- (void)activityControllerDidSelectedBackItem:(UIViewController *)activityController {
//    
//    [activityController dismissViewControllerAnimated:YES completion:nil];
//}
////  视频页面分享点击事件
//-(void)videoDetailViewController:(UIViewController *)videoDetailController didSelectShareItem:(UIButton *)item news:(XWNews *)news{
//    
//    NSLog(@"videoshare ---3");
//}
////视频页面返回按钮点击事件
//-(void)videoDetailViewController:(UIViewController *)videoDetailViewController didSelectBackItem:(UIButton *)item news:(XWNews *)news{
//    
//    NSLog(@"videoback ---1");
//    [videoDetailViewController dismissViewControllerAnimated:YES completion:nil];
//}
//
//
//- (BOOL)prefersStatusBarHidden {
//    
//    return NO; // xit
//}


@end
