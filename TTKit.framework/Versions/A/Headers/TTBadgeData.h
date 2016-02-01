//
//  TTBadgeData.h
//  TTKit
//
//  Created by Oren Zitoun on 4/7/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  TTBadgeData contains the unread count for a specific conversation (on which token property will be nil) or for all conversations related to a specific organization.
 */
@interface TTBadgeData : NSObject 

/**
 *  An organization's token. Will be nil if this instance relates to a specific conversation.
 */
@property (nonatomic, strong) NSString *token;

/**
 *  Unread messages count.
 */
@property (nonatomic, assign) NSUInteger unreadCount;

/**
 *  A conversation hash to which this instance relates. Will be nil if instance relates to an organization.
 */
@property (nonatomic, strong) NSString *conversationHash;

/**
 * Block that is called when the unread count is updated
 */
@property (nonatomic, copy) void (^updateUnreadCountBlock)(NSUInteger);

/**
 * Nilifies updated unread count block
 */
- (void)prepareForReuse;

@end