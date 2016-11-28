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


- (void)newsViewController:(XWNewsViewController*)newsViewController didSeletedRowAtIndex:(NSIndexPath *)indexPath news:(XWNews*)news {
    
    switch (news.skipType) {
        case XWNewsSkipTypeNone:
            // 不跳转
            NSLog(@"不跳转");
            break;
        case XWNewsSkipTypeNoraml:
            // 普通新闻
              NSLog(@"普通新闻");
            break;
        case XWNewsSkipTypeImage:
            // 图片新闻
            NSLog(@"图片新闻");

            break;
        case XWNewsSkipTypeViedeo:
            // 视频
            NSLog(@"视频");

            break;
        case XWNewsSkipTypeProject:
            // 专题列表
             NSLog(@"专题列表");
            break;
        case XWNewsSkipTypeProjectDetail:
            // 专题详情
            NSLog(@"专题详情");
            break;
        case XWNewsSkipTypeActivity:
            // 活动
            NSLog(@"活动");
            break;
            
        default:
            break;
    }
}


@end
