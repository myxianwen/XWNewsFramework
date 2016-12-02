//
//  ViewController.m
//  XWNewsSDKDemo
//
//  Created by yj on 16/11/28.
//  Copyright © 2016年 yj. All rights reserved.
//

#import "ViewController.h"
#import <XWNewsFrameWork/XWNewsFrameWork.h>

@interface ViewController ()<XWNewsViewControllerDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    XWNewsViewController *control = [[XWNewsViewController alloc] init];
    [self.view addSubview:control.view];
    control.view.frame = self.view.bounds;
    [self addChildViewController:control];
    control.delegate =self;

    
}
- (void)newsViewController:(UIViewController *)controller didSeletedRowAtIndex:(NSIndexPath *)indexPath news:(XWNews *)news op_from:(NSString *)op_from {

    switch (news.skipType) {
            
        case XWNewsSkipTypeNone:
            // 不跳转
            break;
        case XWNewsSkipTypeNoraml:
            
            // 普通新闻(可选，也可以自己实现详情)
        {
            XWNewsDetailController *detail = [[XWNewsDetailController alloc] init];
            
            detail.news = news;
            detail.channel_id = op_from;
            detail.delegate = self;  // 成为其代理就能监听其点击事件
            [controller presentViewController:detail animated:YES completion:nil];
        }
            
            break;
        case XWNewsSkipTypeImage:
            // 图片新闻(可选，也可以自己实现)
        {
            XWImageNewsController *imagesVC = [[XWImageNewsController alloc] init];
            imagesVC.channel_id = op_from;
            imagesVC.news = news;
            imagesVC.delegate = self;  // 成为其代理就能监听其点击事件
            [controller presentViewController:imagesVC animated:YES completion:nil];
         
        }
            break;
        case XWNewsSkipTypeViedeo:
            // 视频（暂未开放）
            break;
        case XWNewsSkipTypeProject:
            // 专题列表(可选，也可以自己实现)
            
        {
            
            XWSubjectListController *subject = [[XWSubjectListController alloc] init];
            
            subject.news = news;
            subject.channel_id = op_from;
            subject.delegate = self;  // 成为其代理就能监听其点击事件
            
            [controller presentViewController:subject animated:YES completion:nil];
      
            
        }
           
            break;
        case XWNewsSkipTypeProjectDetail:
            // 专题详情 (可选，也可以自己实现，注意这里需要跳转两次才能跳到新闻详情的逻辑)
        {
            
            XWSubjectListController *subject = [[XWSubjectListController alloc] init];
            
            subject.news = news;
            subject.channel_id = op_from;
            subject.delegate = self;  // 成为其代理就能监听其点击事件
            
            [controller presentViewController:subject animated:NO completion:nil];
            
            XWNewsDetailController *detail = [[XWNewsDetailController alloc] init];
            
            detail.news = news;
            detail.channel_id = op_from;
            detail.delegate = self; // 成为其代理就能监听其点击事件
            [subject presentViewController:detail animated:YES completion:nil];
            
            
        }
            break;
        case XWNewsSkipTypeActivity:
            // 活动 (可选，也可以自己实现)
        {
            XWActivityViewController *activityVC = [[XWActivityViewController alloc] init];
            activityVC.news = news;
            activityVC.delegate = self; // 成为其代理就能监听其点击事件
            
            [controller presentViewController:activityVC animated:YES completion:nil];
        }
            break;
            
        default:
            break;
    }
}
// 新闻详情或者图片新闻底部状态的的点击事件（可选，如果接入新闻详情或者图片新闻需要监听）
- (void)newsDetailController:(UIViewController *)newsDetailController didSelectTabBarItem:(UIButton *)item news:(XWNews *)news {
    
    switch (item.tag) {
        case XWBottomButtonTypeBack:
            
            //返回
            [newsDetailController dismissViewControllerAnimated:YES completion:nil];
            break;
            //评论
        case XWBottomButtonTypeComment:
            NSLog(@"comment");
            break;
        case XWBottomButtonTypeShare:
            
            // 分享
            NSLog(@"share");
            
            break;
        default:
            break;
    }
}
/**
 专题列表点击事件（可选，如果接入了专题列表必须实现该方法来销毁它）
 
 @param backItem 返回按钮
 */
- (void)subjectListController:(UIViewController *)subjectListController didSelecctedBackItem:(UIButton *)backItem {
    
    [subjectListController dismissViewControllerAnimated:YES completion:nil];
}
@end
