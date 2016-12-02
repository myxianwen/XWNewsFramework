# XWNewsFramework
This is a framework of xianwen... 轻松接入鲜闻内容

##一、使用
先看下效果图

![
![xwnews-2.png](http://upload-images.jianshu.io/upload_images/970305-c0f9b4fd3728bfa8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
](http://upload-images.jianshu.io/upload_images/970305-7b9b7da36f72ddbc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
##二、功能
轻松接入接入鲜闻内容
##三、原理
封装鲜闻内容
##四、用法
1.添加目录/鲜闻FrameWork/Universal下的XWNewsFrawork.framework和XWNewsImages.bundle到工程中,说明该framework支持iOS8.0及其以上。<br>
2.在AppDelegate中导入`#import <XWNewsFrameWork/XWNewsSDK.h>`注册`AppId`和`AppKey`



```    
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    [XWNewsSDK registerSDKWithAppId:@"xxx" appKey:@"test" delegate:self];
    
    return YES;
}
```
###可选设置:在SDK注册成功的回调中注册用户昵称和头像url如果不设置有个默认的昵称和头像`- (void)newsSDKDidRegisterSuccessUserId:(NSString*)userId`

```
- (void)newsSDKDidRegisterSuccessUserId:(NSString*)userId {

[XWNewsSDK setUserInfoWithUserId:userId nickName:@"dd" avatar_url:@""];
}
```

记的得在general中设置

![xwnews-4.png](http://upload-images.jianshu.io/upload_images/970305-d567d9a02550fa40.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![xwnews-3.png](http://upload-images.jianshu.io/upload_images/970305-693e3639d40fb6ee.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

3、在Build Settings ->Linking ->Other Linker Flags添加 -all_load

![xwnews-5.png](http://images.iimedia.cn/00001e495c92698c2844081001ca71bc176051b415463b9d8ee0700287547a545a17e)

4、添加依赖库libsqlite3.tbd

5、在需要的显示的controller中导入`#import <XWNewsFrameWork/XWNewsFrameWork.h>`


- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    XWNewsViewController *control = [[XWNewsViewController alloc] init];
    [self.view addSubview:control.view];
    control.view.frame = self.view.bounds;
    [self addChildViewController:control];
    control.delegate =self; // 可选

    
}

4、如果需要自己定制详情页面的调整，遵守`XWNewsViewControllerDelegate`（可选）
并实现其方法就能监听其点击事件，可以拿到新闻（XWNews）对象。

```
- (void)newsViewController:(UIViewController *)controller didSeletedRowAtIndex:(NSIndexPath *)indexPath news:(XWNews *)news op_from:(NSString *)op_from {
//    news.skipType
news.news_id = @"6661731";
switch (2) {
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
break;
case XWBottomButtonTypeShare:

// 分享

break;
default:
break;
}
}


// 活动页面的返回按钮点击事件（可选，接入活动页面就必须实现）
- (void)activityControllerDidSelectedBackItem:(UIViewController *)activityController {

[activityController dismissViewControllerAnimated:YES completion:nil];
}
```
##五、Releasenote
1.0.0 添加新闻初始化设置和新闻列表，开放新闻cell的点击跳转接口<br>
1.0.1 添加设置昵称和头像接口，开发新闻详情，图片新闻，活动页，专题列表。

<br>
<br>
<br>
[Android版本地址点我](https://github.com/frendyxzc/XwView)
