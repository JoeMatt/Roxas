//
//  RSTFetchedResultsDataSource.h
//  RoxasUIKit
//
//  Created by Riley Testut on 8/12/16.
//  Copyright © 2016 Riley Testut. All rights reserved.
//

#import <RoxasUIKit/RSTCellContentDataSource.h>
#import <RoxasUIKit/RSTCellContentPrefetchingDataSource.h>

#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

@interface RSTFetchedResultsDataSource<ContentType: NSManagedObject *, CellType: UIView<RSTCellContentCell> *, ViewType: UIScrollView<RSTCellContentView> *, DataSourceType> : RSTCellContentDataSource<ContentType, CellType, ViewType, DataSourceType> <NSFetchedResultsControllerDelegate>

@property (nonatomic) NSInteger liveFetchLimit;

@property (nonatomic) NSFetchedResultsController<ContentType> *fetchedResultsController;

#if TARGET_OS_TV
- (instancetype)initWithFetchRequest:(NSFetchRequest<ContentType> *)fetchRequest managedObjectContext:(NSManagedObjectContext *)managedObjectContext searchResultsController:(nonnull UIViewController*)searchResultsController;
#else
- (instancetype)initWithFetchRequest:(NSFetchRequest<ContentType> *)fetchRequest managedObjectContext:(NSManagedObjectContext *)managedObjectContext;
#endif
#if TARGET_OS_TV
- (instancetype)initWithFetchedResultsController:(NSFetchedResultsController<ContentType> *)fetchedResultsController searchResultsController:(nonnull UIViewController*) searchResultsController NS_DESIGNATED_INITIALIZER;
#else
- (instancetype)initWithFetchedResultsController:(NSFetchedResultsController<ContentType> *)fetchedResultsController NS_DESIGNATED_INITIALIZER;
#endif

- (instancetype)init NS_UNAVAILABLE;

@end


@interface RSTFetchedResultsPrefetchingDataSource<ContentType: NSManagedObject *, CellType: UIView<RSTCellContentCell> *, ViewType: UIScrollView<RSTCellContentView> *, DataSourceType, PrefetchContentType> : RSTFetchedResultsDataSource<ContentType, CellType, ViewType, DataSourceType> <RSTCellContentPrefetchingDataSource>

@property (nonatomic) NSCache<ContentType, PrefetchContentType> *prefetchItemCache;

@property (nullable, copy, nonatomic) NSOperation *_Nullable (^prefetchHandler)(ContentType item, NSIndexPath *indexPath, void (^completionHandler)(_Nullable PrefetchContentType item, NSError *_Nullable error));
@property (nullable, copy, nonatomic) void (^prefetchCompletionHandler)(CellType cell, _Nullable PrefetchContentType item, NSIndexPath *indexPath, NSError *_Nullable error);

@end

NS_ASSUME_NONNULL_END


// Concrete Subclasses

NS_ASSUME_NONNULL_BEGIN

@interface RSTFetchedResultsTableViewDataSource<ContentType: NSManagedObject *> : RSTFetchedResultsDataSource<ContentType, UITableViewCell *, UITableView *, id<UITableViewDataSource>> <UITableViewDataSource>
@end

@interface RSTFetchedResultsCollectionViewDataSource<ContentType: NSManagedObject *> : RSTFetchedResultsDataSource<ContentType, UICollectionViewCell *, UICollectionView *, id<UICollectionViewDataSource>> <UICollectionViewDataSource>
@end


@interface RSTFetchedResultsTableViewPrefetchingDataSource<ContentType: NSManagedObject *, PrefetchContentType> : RSTFetchedResultsPrefetchingDataSource<ContentType, UITableViewCell *, UITableView *, id<UITableViewDataSource>, PrefetchContentType> <UITableViewDataSource, UITableViewDataSourcePrefetching>
@end

@interface RSTFetchedResultsCollectionViewPrefetchingDataSource<ContentType: NSManagedObject *, PrefetchContentType> : RSTFetchedResultsPrefetchingDataSource<ContentType, UICollectionViewCell *, UICollectionView *, id<UICollectionViewDataSource>, PrefetchContentType> <UICollectionViewDataSource, UICollectionViewDataSourcePrefetching>
@end

NS_ASSUME_NONNULL_END
