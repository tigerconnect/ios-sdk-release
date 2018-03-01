//
//  TTOrganizationAccount.h
//  TTKit
//
//  Created by Oren Zitoun on 5/28/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

/**
 *  TTOrganizationAccount represents contact info for an organization with the same organization token as the TTOrganizationAccount token property.
 */
@interface TTOrganizationAccount : NSManagedObject

/**
 *  Email address.
 */
@property (nullable, nonatomic, retain) NSString * email;

/**
 *  Is pending. Boolean value.
 */
@property (nullable, nonatomic, retain) NSNumber * pending;

/**
 *  Phone number.
 */
@property (nullable, nonatomic, retain) NSString * phone;

/**
 *  Boolean value.  YES if this is the preferred TTOrganizationAccount for the specific organization. Only one TTOrganizationAccount can be prefered per organization.
 */
@property (nullable, nonatomic, retain) NSNumber * preferred;

/**
 *  Organization token to which this object is related.
 */
@property (nullable, nonatomic, retain) NSString * token;

@end
