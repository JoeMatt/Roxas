//
//  RSTCellContentView.h
//  RoxasUIKit
//
//  Created by Riley Testut on 2/13/17.
//  Copyright © 2017 Riley Testut. All rights reserved.
//

#import <RoxasUIKit/RSTCellContentCell.h>

#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

@class RSTCellContentChange;

NS_ASSUME_NONNULL_BEGIN

@protocol RSTCellContentView <NSObject>

@property (nonatomic, nullable) id dataSource;
@property (nonatomic, nullable) id prefetchDataSource;

@property (nonatomic, readonly) Protocol *dataSourceProtocol;

@property (nonatomic, nullable) UIView *backgroundView;

- (void)beginUpdates;
- (void)endUpdates;
- (void)reloadData;

- (void)addChange:(RSTCellContentChange *)change;

- (nullable id)indexPathForCell:(id)cell;

- (id)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;

@end



NS_ASSUME_NONNULL_END
