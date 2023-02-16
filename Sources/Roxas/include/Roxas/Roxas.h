//
//  Roxas.h
//  Roxas
//
//  Created by Riley Testut on 8/27/14.
//  Copyright (c) 2014 Riley Testut. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for Roxas.
FOUNDATION_EXPORT double RoxasVersionNumber;

//! Project version string for Roxas.
FOUNDATION_EXPORT const unsigned char RoxasVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <Roxas/PublicHeader.h>

// Generic
#import <Roxas/RSTDefines.h>
#import <Roxas/RSTError.h>

// Operations
#import <Roxas/RSTOperationQueue.h>
#import <Roxas/RSTOperation.h>
#import <Roxas/RSTOperation_Subclasses.h>

// Operations - Block Operations
#import <Roxas/RSTBlockOperation.h>

// Operations - Load Operations
#import <Roxas/RSTLoadOperation.h>

// Core Data
#import <Roxas/RSTPersistentContainer.h>
#import <Roxas/RSTRelationshipPreservingMergePolicy.h>

// Functionality
#import <Roxas/RSTHasher.h>

// Categories
#import <Roxas/NSBundle+Extensions.h>
#import <Roxas/NSFileManager+URLs.h>
#import <Roxas/NSUserDefaults+DynamicProperties.h>
#import <Roxas/NSString+Localization.h>
#import <Roxas/NSPredicate+Search.h>

// Categories - RSTActivityIndicating
#import <Roxas/RSTActivityIndicating.h>
#import <Roxas/NSConstraintConflict+Conveniences.h>
