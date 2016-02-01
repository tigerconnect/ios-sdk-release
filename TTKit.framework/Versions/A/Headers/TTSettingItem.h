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

@property (nonatomic, retain) NSString * conversationHash;
@property (nonatomic, retain) NSNumber * ignoreApiUpdate;
@property (nonatomic, retain) NSNumber * localOnly;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * orgToken;
@property (nonatomic, retain) NSNumber * type;
@property (nonatomic, retain) NSNumber * locked;
@property (nonatomic, retain) id value;

@end
