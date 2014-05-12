//
//  ZYQTabBar.h
//  ZYQTabBarController
//
//  Created by Tretter Matthias on 14.02.12.
//  Copyright (c) 2012 NOUS Wissensmanagement GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    ZYQTabBarPositionTop = 0,
    ZYQTabBarPositionRight,
    ZYQTabBarPositionBottom,
    ZYQTabBarPositionLeft,
} ZYQTabBarPosition;

#define kZYQTabBarPositionDefault ZYQTabBarPositionLeft


NS_INLINE BOOL ZYQTabBarIsVertical(ZYQTabBarPosition position) {
    return position == ZYQTabBarPositionLeft || position == ZYQTabBarPositionRight;
}

NS_INLINE BOOL ZYQTabBarIsHorizontal(ZYQTabBarPosition position) {
    return position == ZYQTabBarPositionTop || position == ZYQTabBarPositionBottom;
}

typedef enum {
    ZYQTabBarLayoutStrategyStrungTogether        = 0,
    ZYQTabBarLayoutStrategyEvenlyDistributed,
    ZYQTabBarLayoutStrategyCentered
} ZYQTabBarLayoutStrategy;


@interface ZYQTabBar : UIScrollView

@property (nonatomic, strong) NSArray *items;
@property (nonatomic, assign) NSUInteger selectedItemIndex;
@property (nonatomic, assign) ZYQTabBarPosition position;
@property (nonatomic, assign) ZYQTabBarLayoutStrategy layoutStrategy;
/** the padding to apply between items, not taken into account when layoutStrategy is EvenlyDistributed */
@property (nonatomic, assign) CGFloat itemPadding;

/** defaults to black */
@property (nonatomic, strong) UIColor *tintColor;
/** defaults to nil */
@property (nonatomic, strong) UIImage *backgroundImage;
/** flag whether the semi-transparent item highlight is shown */
@property (nonatomic, assign) BOOL drawItemHighlight;
/** flag whether tabbar-gloss should be drawn */
@property (nonatomic, assign) BOOL drawGloss;
/** defaults to white */
@property (nonatomic, strong) UIColor *itemHighlightColor;

- (void)selectItemAtIndex:(NSUInteger)index;
- (void)deselectSelectedItem;

- (UIImageView *)imageViewRepresentation;

@end
