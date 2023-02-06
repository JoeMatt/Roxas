//
//  RSTSilentAssertionHandler.h
//  Roxas
//
//  Created by Riley Testut on 1/13/17.
//  Copyright © 2017 Riley Testut. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RSTSilentAssertionHandler : NSAssertionHandler

+ (void)enable;
+ (void)disable;

@end
