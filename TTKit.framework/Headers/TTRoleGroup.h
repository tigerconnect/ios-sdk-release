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

@interface TTRoleGroup : TTGroup

@property (nullable, nonatomic, retain) TTUser *conversationTarget;

@end
