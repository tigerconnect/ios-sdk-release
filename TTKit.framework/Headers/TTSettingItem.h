//
//  TTSettingItem.h
//  TTKit
//
//  Created by Oren Zitoun on 8/12/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface TTSettingItem : NSManagedObject

@property (nullable, nonatomic, retain) NSString * conversationHash;
@property (nullable, nonatomic, retain) NSNumber * ignoreApiUpdate;
@property (nullable, nonatomic, retain) NSNumber * localOnly;
@property (nullable, nonatomic, retain) NSString * name;
@property (nullable, nonatomic, retain) NSString * orgToken;
@property (nullable, nonatomic, retain) NSNumber * type;
@property (nullable, nonatomic, retain) NSNumber * locked;
@property (nullable, nonatomic, retain) id value;

@end
