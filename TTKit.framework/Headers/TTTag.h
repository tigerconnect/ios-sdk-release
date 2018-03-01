//
//  TTTag.h
//  TTKit
//
//  Created by Oren Zitoun on 6/7/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTRole;

@interface TTTag : NSManagedObject

@property (nullable, nonatomic, retain) NSString *color;
@property (nullable, nonatomic, retain) NSString *name;
@property (nullable, nonatomic, retain) NSString *token;
@property (nullable, nonatomic, retain) NSString *organizationToken;
@property (nullable, nonatomic, retain) NSSet<TTRole *> *roles;

@end
