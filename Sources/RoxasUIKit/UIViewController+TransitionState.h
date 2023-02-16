//
//  UIViewController+TransitionState.h
//  RoxasUIKit
//
//  Created by Riley Testut on 3/14/16.
//  Copyright © 2016 Riley Testut. All rights reserved.
//

#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

@interface UIViewController (TransitionState)

// Unlike isBeingPresented and isBeingDismissed, these actually work ಠ_ಠ
@property (nonatomic, readonly, getter=isAppearing) BOOL appearing;
@property (nonatomic, readonly, getter=isDisappearing) BOOL disappearing;

@end
