//
//  RSTNibView.m
//  Roxas
//
//  Created by Riley Testut on 8/23/18.
//  Copyright © 2018 Riley Testut. All rights reserved.
//

#import "RSTNibView.h"

#import "NSLayoutConstraint+Edges.h"

#if TARGET_OS_TV
@import Roxas_tvOS;
#else
@import Roxas_iOS;
#endif

@implementation RSTNibView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self)
    {
        [self initializeFromNib];
    }
    
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder
{
    self = [super initWithCoder:aDecoder];
    if (self)
    {
        [self initializeFromNib];
    }
    
    return self;
}

- (void)initializeFromNib
{
    NSString *name = NSStringFromClass(self.class);
    
    NSArray<NSString *> *components = [name componentsSeparatedByString:@"."];
    name = [components lastObject];
    
    #if SWIFT_PACKAGE
#if TARGET_OS_TV
    NSBundle *bundle = Roxas_tvOS.resources;
#else
    NSBundle *bundle = Roxas_iOS.resources;
#endif
    #else
    NSBundle *bundle = [NSBundle bundleForClass:self.class];
    #endif
    
    UINib *nib = [UINib nibWithNibName:name bundle:bundle];
    NSArray *views = [nib instantiateWithOwner:self options:nil];
    
    UIView *nibView = [views firstObject];
    NSAssert(nibView != nil && [nibView isKindOfClass:[UIView class]], @"The nib for %@ must contain a root UIView.", name);
    
    nibView.preservesSuperviewLayoutMargins = YES;
    [self addSubview:nibView pinningEdgesWithInsets:UIEdgeInsetsZero];
}

@end
