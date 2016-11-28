//
//  XWNews.h
//  XWNewsSDK
//
//  Created by yj on 16/11/21.
//  Copyright © 2016年 yj. All rights reserved.
//  新闻对象

#import "JKDBModel.h"
typedef NS_ENUM(NSInteger,XWNewsCellStyle){
    
    XWNewsCellStyleNoPicture, // 无图模式
    XWNewsCellStyleOnePicture, // 一张图
    XWNewsCellStyleThreePicture, // 三张图
    XWNewsCellStyleBigPicture, //大图模式
    XWNewsCellStyleAd, // 广告样式
    XWNewsCellStyleMusic // 音频样式
};


typedef NS_ENUM(NSInteger,XWNewsSkipType){

    XWNewsSkipTypeNoraml, //跳转普通新闻
    
    XWNewsSkipTypeViedeo, // 跳转视频
    XWNewsSkipTypeImage, // 跳转图片新闻
    XWNewsSkipTypeProject, //跳转专题列表
    XWNewsSkipTypeNone, // 不跳转
    XWNewsSkipTypeProjectDetail, //跳转专题详情
    XWNewsSkipTypeActivity // 跳转活动页面
    
};


@interface XWNews : JKDBModel

/**
 标签
 */
@property (nonatomic,copy) NSString *labels;

/**
 媒体名称
 */
@property (nonatomic,copy) NSString *media_name;

/**
 新闻浏览数
 */
@property (nonatomic,copy) NSNumber *browse_count;

/**
 新闻标题
 */
@property (nonatomic,copy) NSString *title;

/**
 新闻地址
 */
@property (nonatomic,copy) NSString *url;

/**
 新闻摘要
 */
@property (nonatomic,copy) NSString *summary;

/**
 图片（列表图）
 */
@property (nonatomic,copy) NSString *image;

/**
 唯一标识
 */
@property (nonatomic,copy) NSString *sn;

/**
 展示样式 0 无图，1 一张图， 3三张图，4 大图，5音频 6 活动
 */
@property (nonatomic,copy) NSString *image_type;

/**
 cell的样式
 */
@property (assign,nonatomic) XWNewsCellStyle cellStyle;

/**
 发布时间戳
 */
@property (nonatomic,copy) NSString *release_time;

/**
 描述图
 */
@property (nonatomic,copy) NSString *images_path;

/**
 喜欢数
 */
@property (nonatomic,copy) NSNumber *like_count;

/**
 原文地址
 */
@property (nonatomic,copy) NSString *src_url;

/**
 平台id
 */
@property (nonatomic,copy) NSString *platform_id;

/**
 是否需要去重 0 去重 1不去重
 */
@property (nonatomic,copy) NSString *is_duplicate;

/**
 点水数
 */
@property (nonatomic,copy) NSNumber *dislike_count;

/**
 新闻id
 */
@property (nonatomic,copy) NSString *news_id;

/**
 跳转方式 0：普通新闻 1视频 2 图片新闻 3 专题 4 不跳转 5 打开文章返回专题 6活动
 */
@property (nonatomic,copy) NSString *skip_way;

/**
 跳转对应的枚举
 */
@property (assign,nonatomic) XWNewsSkipType skipType;

/**
 新闻等级
 */
@property (nonatomic,copy) NSString *level;

/**
 新闻等级对应的名字 如置顶，热
 */
@property (nonatomic,copy) NSString *level_name;

/**
 媒体id
 */
@property (nonatomic,copy) NSString *media_id;

/**
 小图
 */
@property (nonatomic,copy) NSString *small_image;

/**
 目标地址
 */
@property (nonatomic,copy) NSString *target_url;

/**
 对应的频道id
 */
@property (nonatomic,copy) NSString *channel_id;

/**
 插入时间
 */
@property (nonatomic,copy) NSString *import_time;

/**
 用户评论数
 */
@property (nonatomic,copy) NSNumber *comment_count;

/**
 用户ugc_id 暂未开放
 */
@property (nonatomic,copy) NSString *ugc_id;

/**
 图片比例（用于活动页）
 */
@property (nonatomic,copy) NSString *image_rate;


/**
 三图样式的时候获取图片数组

 @return 图片数组
 */
-(NSArray*)imagesArray;


/**
 是否显示刷新视图
 */
@property (assign,nonatomic) BOOL isShowLastFreshView;


@end
