//
//  RSTCellContentDataSource.h
//  RoxasUIKit
//
//  Created by Riley Testut on 2/7/17.
//  Copyright © 2017 Riley Testut. All rights reserved.
//

#import <RoxasUIKit/RSTCellContentChange.h>

#import <RoxasUIKit/UITableView+CellContent.h>
#import <RoxasUIKit/UITableViewCell+CellContent.h>

#import <RoxasUIKit/UICollectionView+CellContent.h>
#import <RoxasUIKit/UICollectionViewCell+CellContent.h>

#import <UIKit/UIKit.h>

@class RSTSearchController;
@class RSTCellContentChange;

NS_ASSUME_NONNULL_BEGIN

RST_EXTERN NSString *RSTCellContentGenericCellIdentifier;

@interface RSTCellContentDataSource<ContentType, CellType: UIView<RSTCellContentCell> *, ViewType: UIScrollView<RSTCellContentView> *, DataSourceType> : NSObject

#if TARGET_OS_TV
- (instancetype)initWithSearchResultsController:(nonnull UIViewController *)searchResultsController NS_DESIGNATED_INITIALIZER;

@property (nullable, nonatomic, weak) UIViewController* searchResultsController;
#endif

// The view containing the content cells.
@property (nullable, weak, nonatomic, readonly) ViewType contentView;

// RSTSearchController for easily adding support for searching through content.
// Lazily initialized upon first access.
@property (nonatomic, readonly) RSTSearchController *searchController;

// Object to forward optional contentView.dataSource methods to.
@property (nullable, weak, nonatomic) DataSourceType proxy;

// Block to determine the cell reuse identifier to use for a given index path.
// Defaults to using RSTCellContentGenericCellIdentifier for all index paths.
@property (copy, nonatomic) NSString * (^cellIdentifierHandler)(NSIndexPath *indexPath);

// Block to configure a cell before it is displayed.
// Defaults to setting textLabel.text to item.description if CellType is UITableViewCell.
@property (copy, nonatomic) void (^cellConfigurationHandler)(CellType cell, ContentType item, NSIndexPath *indexPath);

// Optional predicate to filter content, and refreshes content immediately.
// To set predicate without refreshing content, call -[RSTCellContentDataSource setPredicate:refreshContent:] and pass NO to refreshContent:.
@property (nullable, copy, nonatomic) NSPredicate *predicate;

// A view to display when there is no content available.
// RSTBackgroundView preferred, but any UIView is valid.
// Defaults to nil.
@property (nullable, nonatomic) __kindof UIView *placeholderView;

// Animation to use when animating changes in a UITableView.
@property (nonatomic) UITableViewRowAnimation rowAnimation;

// Total number of items to be displayed in contentView.
@property (nonatomic, readonly) NSInteger itemCount;



// Returns content item at indexPath. Performs no bounds-checking.
- (ContentType)itemAtIndexPath:(NSIndexPath *)indexPath;

// Sets an optional predicate to filter content.
// Refreshes content immediately if passed YES for refreshContent:, otherwise refreshes at some later point (such as when calling [contentView reloadData]).
- (void)setPredicate:(NSPredicate * _Nullable)predicate refreshContent:(BOOL)refreshContent;

@end

NS_ASSUME_NONNULL_END
