//
//  ZYQTabBarItem.h
//  ZYQTabBarController
//
//  Created by Tretter Matthias on 24.04.12.
//  Copyright (c) 2012 NOUS Wissensmanagement GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZYQTabBarItem : UIControl

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIImage *selectedImage;
@property (nonatomic, copy) NSString *title;

@property (nonatomic, strong) UIColor *selectedImageTintColor;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *selectedTitleColor;

+ (ZYQTabBarItem *)itemWithTitle:(NSString *)title image:(UIImage *)image;

- (void)setSize:(CGSize)size;

@end

@class ZYQTabBarController;

@interface UIViewController (ZYQTabBarItem)

@property (nonatomic, strong, setter = zyq_setTabBarItem:) ZYQTabBarItem *zyq_tabBarItem;
@property (nonatomic, readonly) ZYQTabBarController *zyq_tabBarController;

@end
