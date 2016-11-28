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
1.添加XWNewsFrawork到工程中,说明该framework支持iOS8.0及其以上。
2.在AppDelegate中导入`#import <XWNewsFrameWork/XWNewsSDK.h>`注册`AppId`和`AppKey`


```
  - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    [XWNewsSDK registerSDKWithAppId:@"xxxx" appKey:@"xxxx"];
    
    return YES;
  }
```

记的得在general中设置

![xwnews-4.png](http://upload-images.jianshu.io/upload_images/970305-d567d9a02550fa40.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![xwnews-3.png](http://upload-images.jianshu.io/upload_images/970305-693e3639d40fb6ee.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

3、在需要的显示的controller中导入`#import <XWNewsFrameWork/XWNewsFrameWork.h>`


```
  - (void)viewDidLoad {
    [super viewDidLoad];
    
    
    XWNewsViewController *control = [[XWNewsViewController alloc] init];
    [self.view addSubview:control.view];
    control.view.frame = self.view.bounds;
    [self addChildViewController:control];
    control.delegate =self; // 可选

    
 }
```
4、如果需要自己定制详情页面的调整，遵守`XWNewsViewControllerDelegate`（可选）
并实现其方法就能监听其点击事件，可以拿到新闻（XWNews）对象。

```
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
```

##五、Releasenote
1.0.0 添加新闻初始化设置和新闻列表，开放新闻cell的点击跳转接口


[android版本地址点我](https://github.com/frendyxzc/XwView)
