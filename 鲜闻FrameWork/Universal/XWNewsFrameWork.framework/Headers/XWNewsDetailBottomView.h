//
//  XWNewsDetailBottomView.h
//  XWNewsSDK
//
//  Created by yangjie on 16/11/28.
//  Copyright © 2016年 yj. All rights reserved.
//

#import <UIKit/UIKit.h>
@class XWNewsDetailBottomView;
typedef NS_ENUM(NSInteger,XWBottomButtonType){
    XWBottomButtonTypeBack, // 返回按钮
    XWBottomButtonTypeComment, //评论
    XWBottomButtonTypeShare // 分享
};

@protocol XWNewsDetailBottomViewDelegate <NSObject>


@optional
- (void)newsDeatilBottomView:(XWNewsDetailBottomView*)detailBottomView didSelectedItem:(UIButton*)item;
- (void)newsDetailBottomViewDidSelectedSendItem:(XWNewsDetailBottomView*)detailBottomView;


@end

@interface XWNewsDetailBottomView : UIView


/** 代理 */
@property (nonatomic,weak) id<XWNewsDetailBottomViewDelegate> delegate;


/** 是否隐藏其他按钮 */
@property (nonatomic,assign) BOOL isHiddeOtherButton;

/** 输入框 */
@property (nonatomic,strong) UITextField *commmentTextField;


/**
 标识是否为图片新闻
 */
@property (assign,nonatomic) BOOL isImageNews;

@end
