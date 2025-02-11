//
//  RSTPlaceholderView.h
//  RoxasUIKit
//
//  Created by Riley Testut on 11/21/15.
//  Copyright © 2015 Riley Testut. All rights reserved.
//

#import <RoxasUIKit/RSTNibView.h>

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface RSTPlaceholderView : RSTNibView

// Visible by default
@property (nonnull, nonatomic, readonly) UILabel *textLabel;
@property (nonnull, nonatomic, readonly) UILabel *detailTextLabel;

// Hidden by default
@property (nonnull, nonatomic, readonly) UIActivityIndicatorView *activityIndicatorView;
@property (nonnull, nonatomic, readonly) UIImageView *imageView;

// Layout
@property (nonnull, nonatomic, readonly) UIStackView *stackView;

@end
