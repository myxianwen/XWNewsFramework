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
1.添加目录/鲜闻FrameWork/Universal下的XWNewsFrawork.framework和XWNewsImages.bundle到工程中,说明该framework支持iOS8.0及其以上。
<br>

2.在AppDelegate中导入`#import <XWNewsFrameWork/XWNewsSDK.h>`注册`AppId`和`AppKey` [点我立即申请](http://www.myxianwen.com/)



```    
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    [XWNewsSDK registerSDKWithAppId:@"xxx" appKey:@"test" delegate:self];
// 新增设置是否显示推荐频道
[XWNewsSDK setShowRecommandChannel:YES];
// 可选设置
     /*
// 设置顶部导航栏的颜色
[XWNewsSettingsManager sharedSettingsManger].navigationBackgroudColor = [UIColor redColor];

// 设置顶部标题未选中状态的颜色
[XWNewsSettingsManager sharedSettingsManger].scrollNormalTitleColor = [UIColor greenColor];

// 设置顶部标题选中的颜色
[XWNewsSettingsManager sharedSettingsManger].scrollSelectedTitleColor = [UIColor yellowColor];

// 设置滑动条的颜色
[XWNewsSettingsManager sharedSettingsManger].sliderColor = [UIColor blueColor];

// 设置新闻列表背景色
[XWNewsSettingsManager sharedSettingsManger].newsListBackgroundColor = [UIColor greenColor];

// 设置新闻类型的背景颜色
[XWNewsSettingsManager sharedSettingsManger].newsMediaTypeBackgroundColor = [UIColor greenColor];
// 设置新闻标题颜色
[XWNewsSettingsManager sharedSettingsManger].newsTitleColor = [UIColor redColor];
// 设置新闻来源，阅读数、评论，时间的颜色
[XWNewsSettingsManager sharedSettingsManger].newsSubTextColor = [UIColor yellowColor];
*/

    return YES;

}
```
###可选设置:在SDK注册成功的回调中注册用户昵称和头像url如果不设置有个默认的昵称和头像`- (void)newsSDKDidRegisterSuccessUserId:(NSString*)userId`

```

#pragma mark - sdk注册成功回调
- (void)newsSDKDidRegisterSuccessUserId:(NSString*)userId {

[XWNewsSDK setUserInfoWithUserId:userId nickName:@"sdk" avatar_url:@""];
}

#pragma mark - sdk注册失败回调

- (void)newsSDKDidRegisterFail:(NSError *)error {

NSLog(@"----注册失败----%@",error);
}
```

记的得在general中设置

![xwnews-4.png](http://upload-images.jianshu.io/upload_images/970305-d567d9a02550fa40.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![xwnews-3.png](http://upload-images.jianshu.io/upload_images/970305-693e3639d40fb6ee.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

<br>
3、在Build Settings ->Linking ->Other Linker Flags添加 -all_load

![xwnews-5.png](http://images.iimedia.cn/00001e495c92698c2844081001ca71bc176051b415463b9d8ee0700287547a545a17e)

<br>
4、添加依赖库libsqlite3.tbd

<br>
5、在需要的显示的controller中导入`#import <XWNewsFrameWork/XWNewsFrameWork.h>`

```
- (void)viewDidLoad {
    [super viewDidLoad];
    
    XWNewsViewController *control = [[XWNewsViewController alloc] init];
    [self.view addSubview:control.view];
    control.view.frame = self.view.bounds;
    [self addChildViewController:control];
    control.delegate =self; // 可选
#warning 自选频道 例子
NSString *nameStr = @"美食";
UIButton *chooseChannel = [UIButton buttonWithType:UIButtonTypeCustom];
chooseChannel.frame = CGRectMake([UIScreen mainScreen].bounds.size.width-80, [UIScreen mainScreen].bounds.size.height-100, 50, 50);
chooseChannel.layer.cornerRadius = 25;
[chooseChannel setTitle:nameStr forState:UIControlStateNormal];
chooseChannel.backgroundColor = [UIColor greenColor];
[chooseChannel setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
[self.view addSubview:chooseChannel];
[chooseChannel addTarget:self action:@selector(chooseButtonAction:) forControlEvents:UIControlEventTouchUpInside];
    
}
```
<br>
/*

自选单个频道sdk会根据传入的channelName来匹配频道匹配不到默认为推荐频道
用户可自行选择频道（如： 娱乐，视频，国际 等等。。。）
具体频道名参照http://www.myxianwen.com里的名字为准

*/
-(void)chooseButtonAction:(UIButton *)button{

NSString *nameStr = button.titleLabel.text;

XWOnlyNewsListViewController *newsList = [[XWOnlyNewsListViewController alloc] init];
newsList.delegate = self;
newsList.channelName = nameStr;
[self presentViewController:newsList animated:YES completion:nil];
}
6、如果需要自己定制详情页面的调整，遵守`XWNewsViewControllerDelegate`（可选）
并实现其方法就能监听其点击事件，可以拿到新闻（XWNews）对象。

```
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
// 视频（新增，为可选类型）
XWVideoDetailViewController *videoVC = [[XWVideoDetailViewController alloc] init];
videoVC.channel_id = op_from;
videoVC.news = news;
videoVC.delegate = self;
[controller presentViewController:videoVC animated:YES completion:nil];

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

/**
单频道列表的返回按钮点击

@param onlyNewsListViewController 新闻列表控制器
@param backItem              返回item
*/
- (void)onlyNewsListViewController:(UIViewController*)onlyNewsListViewController didSelecctedBackItem:(UIButton*)backItem{

[onlyNewsListViewController dismissViewControllerAnimated:YES completion:nil];
}


// 新闻详情或者图片新闻底部状态的的点击事件（可选，如果接入新闻详情或者图片新闻需要监听）
- (void)newsDetailController:(UIViewController *)newsDetailController didSelectTabBarItem:(UIButton *)item news:(XWNews *)news {

switch (item.tag) {
case XWBottomButtonTypeBack:
//返回
[newsDetailController dismissViewControllerAnimated:YES completion:nil];
break;

case XWBottomButtonTypeComment:
//评论
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

//  视频页面分享点击事件（可选）
-(void)videoDetailViewController:(UIViewController *)videoDetailController didSelectShareItem:(UIButton *)item news:(XWNews *)news{

NSLog(@"videoshare ---3");
}
//视频页面返回按钮点击事件（可选）
-(void)videoDetailViewController:(UIViewController *)videoDetailViewController didSelectBackItem:(UIButton *)item news:(XWNews *)news{

NSLog(@"videoback ---1");
[videoDetailViewController dismissViewControllerAnimated:YES completion:nil];
}
// 新闻列表的回调状态
- (void)newsNetloadType:(XWNetLoadType)netLoadType resultCode:(int)resultCode dataCount:(NSUInteger)dataCount netError:(NSError *)error {


if (netLoadType == XWNetLoadTypeNewsList) {

if (error) {

// 网络出错
NSLog(@"neterror = %@",error);
}
else{

if (resultCode == 0) {

NSLog(@"请求成功 ---新闻条数 = %lu",(unsigned long)dataCount);
}
else {


NSLog(@"参数错误");
}
}
}

}
```
7、XWNews对象属性说明
![image](https://raw.githubusercontent.com/frendyxzc/XwView/master/screenshot/20161205115129.png)

##五、Releasenote
1.0.0 添加新闻初始化设置和新闻列表，开放新闻cell的点击跳转接口<br>
1.0.1 添加设置昵称和头像接口，开发新闻详情，图片新闻，活动页，专题列表。<br>
1.0.2 新开发新闻列表的颜色设置和视频详情页面，优化交互<br>
1.0.3 修改评论和新闻详情的接口.<br>
1.0.4 新增设置是否显示推荐频道的接口<br>
1.0.5 修复二级跳转不能显示问题<br>
1.0.6 新增新闻列表网络请求结果接口和sdk注册失败回调接口<br>
1.0.7 支持bit code,之前不支持bitcode打包的时候可以build settings 中 Enable Bitcode 设为NO。`注意打包提交的话不要使用通用包，使用XWNewsframework-Release-iphoneos`
![QQ20161224-0.png](http://upload-images.jianshu.io/upload_images/970305-ad3e013f8a7c9af9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
1.0.8 新增自选单个频道
<br>
<br>
<br>
[Android版本地址点我](https://github.com/frendyxzc/XwView)
