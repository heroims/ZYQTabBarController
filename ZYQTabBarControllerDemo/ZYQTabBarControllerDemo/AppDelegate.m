//
//  AppDelegate.m
//  ZYQTabBarControllerDemo
//
//  Created by apple on 14-5-12.
//  Copyright (c) 2014年 ZYQ. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor whiteColor];
    
    ViewController *vc1 = [[ViewController alloc] init];
    ViewController *vc2 = [[ViewController alloc] init];
    ViewController *vc3 = [[ViewController alloc] init];
    ViewController *vc4 = [[ViewController alloc] init];
    
    vc1.zyq_tabBarItem = [ZYQTabBarItem itemWithTitle:@"1" image:nil];
    vc2.zyq_tabBarItem = [ZYQTabBarItem itemWithTitle:@"2" image:nil];
    vc3.zyq_tabBarItem = [ZYQTabBarItem itemWithTitle:@"3" image:nil];
    vc4.zyq_tabBarItem = [ZYQTabBarItem itemWithTitle:@"4" image:nil];
    
    vc1.zyq_tabBarItem.selectedImageTintColor = [UIColor yellowColor];
    vc1.zyq_tabBarItem.selectedTitleColor = [UIColor yellowColor];
    
    NSArray *viewController = [NSArray arrayWithObjects:vc1,vc2,vc3,vc4,nil];
    
    ZYQTabBarController *tabBarController = [[ZYQTabBarController alloc] init];
    tabBarController.tabBar.backgroundImage=[UIImage imageNamed:@"tabbarbg"];
    tabBarController.tabBar.backgroundColor=[UIColor clearColor];
    tabBarController.animation = ZYQTabBarControllerAnimationMove;
    tabBarController.tabBar.itemPadding = 10.f;
    tabBarController.tabBarPosition = ZYQTabBarPositionBottom;
    tabBarController.tabBar.drawItemHighlight = NO;
    tabBarController.tabBar.layoutStrategy = ZYQTabBarLayoutStrategyCentered;
    tabBarController.tabBar.drawGloss = YES;
    tabBarController.viewControllers = viewController;
    
    self.window.rootViewController = tabBarController;
    
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
