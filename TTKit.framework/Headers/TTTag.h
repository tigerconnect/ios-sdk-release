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

/**
 * A role tag is used to filter roles.
 */
@interface TTTag : NSManagedObject

/**
 * Color of the tag.
 */
@property (nullable, nonatomic, retain) NSString *color;

/**
 * Name of the tag.
 */
@property (nullable, nonatomic, retain) NSString *name;

/**
 * Identifying token of the tag.
 */
@property (nullable, nonatomic, retain) NSString *token;

/**
 * Identifying token of the organization to which the tag belongs.
 */
@property (nullable, nonatomic, retain) NSString *organizationToken;

/**
 * Roles that are associated with this tag.
 */
@property (nullable, nonatomic, retain) NSSet<TTRole *> *roles;

/**
 * Number of roles associated with this tag.
 */
@property (nullable, nonatomic, retain) NSNumber *roleCount;

/**
 * Identifier of the tag color.
 */
@property (nullable, nonatomic, retain) NSString *colorId;

@end
