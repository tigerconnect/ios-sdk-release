//
//  TTRoleGroup.h
//  TTKit
//
//  Created by Oren Zitoun on 6/10/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTGroup.h"

@class TTUser;

NS_ASSUME_NONNULL_BEGIN

@interface TTRoleGroup : TTGroup

@property (nullable, nonatomic, retain) TTUser *conversationTarget;

@end

NS_ASSUME_NONNULL_END
