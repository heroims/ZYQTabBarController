//
//  ZYQTabBarController.h
//  ZYQTabBarController
//
//  Created by Tretter Matthias on 14.02.12.
//  Copyright (c) 2012 NOUS Wissensmanagement GmbH. All rights reserved.
//

#import "ZYQTabBar.h"
#import "ZYQTabBarItem.h"

#define kZYQTabBarControllerKey      @"kZYQTabBarControllerKey"

@protocol ZYQTabBarControllerDelegate ;

/** NGTabBarController is a customized TabBar displayed on any side of the device */
@interface ZYQTabBarController : UIViewController <UINavigationControllerDelegate>

typedef enum {
    ZYQTabBarControllerAnimationNone = 0,
    ZYQTabBarControllerAnimationFade,
    ZYQTabBarControllerAnimationCurl,
    ZYQTabBarControllerAnimationMove,
    ZYQTabBarControllerAnimationMoveAndScale
} ZYQTabBarControllerAnimation;

/** An array of the view controllers displayed by the tab bar */
@property (nonatomic, copy) NSArray *viewControllers;
/** The index of the view controller associated with the currently selected tab item. */
@property (nonatomic, assign) NSUInteger selectedIndex;
/** The view controller associated with the currently selected tab item. */
@property (nonatomic, unsafe_unretained) UIViewController *selectedViewController;

/** The tab bar controller’s delegate object. */
@property (nonatomic, unsafe_unretained) id<ZYQTabBarControllerDelegate> delegate;

/** The tableView used to display all tab bar elements */
@property (nonatomic, strong, readonly) ZYQTabBar *tabBar;
/** The postion of the tabBar on screen (top/left/bottom/right) */
@property (nonatomic, assign) ZYQTabBarPosition tabBarPosition;

/** The animation used when changing selected tabBarItem, default: none */
@property (nonatomic, assign) ZYQTabBarControllerAnimation animation;
/** The duration of the used animation, only taken into account when animation is different from none */
@property (nonatomic, assign) NSTimeInterval animationDuration;

@property (nonatomic, assign) BOOL tabBarHidden;

@property (nonatomic, assign) BOOL tabBarFrant;

/** The designated initializer. */
- (id)initWithDelegate:(id<ZYQTabBarControllerDelegate>)delegate;

- (void)setTabBarHidden:(BOOL)tabBarHidden animated:(BOOL)animated;

@end

@protocol ZYQTabBarControllerDelegate <NSObject>

@optional
/** Asks the delegate for the size of the given item */
- (CGSize)tabBarController:(ZYQTabBarController *)tabBarController
sizeOfItemForViewController:(UIViewController *)viewController
                   atIndex:(NSUInteger)index
                  position:(ZYQTabBarPosition)position;

/** Asks the delegate whether the specified view controller should be made active. */
- (BOOL)tabBarController:(ZYQTabBarController *)tabBarController
shouldSelectViewController:(UIViewController *)viewController
                 atIndex:(NSUInteger)index;

/** Tells the delegate that the user selected an item in the tab bar. */
- (void)tabBarController:(ZYQTabBarController *)tabBarController
 didSelectViewController:(UIViewController *)viewController
                 atIndex:(NSUInteger)index;

@end

@interface UINavigationController (ZYQTabBarNavigationDelegate)

@property (nonatomic, assign, setter = zyq_setOriginalNavigationControllerDelegate:) id<UINavigationControllerDelegate> zyq_originalNavigationControllerDelegate;

@end

