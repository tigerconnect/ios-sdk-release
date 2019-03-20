//
//  TTBadgeData.h
//  TTKit
//
//  Created by Oren Zitoun on 4/7/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TTBadgeDataObserver;

/**
 *  TTBadgeData contains the unread count for a specific conversation (on which token property will be nil) or for all conversations related to a specific organization.
 */
@interface TTBadgeData : NSObject 

/**
 *  An organization's token. Will be nil if this instance relates to a specific conversation.
 */
@property (nonatomic, strong) NSString *token;

/**
 *  Total unread messages count.
 */
@property (nonatomic, assign) NSUInteger unreadCount;

/**
 *  Priority messages only unread count.
 */
@property (nonatomic, assign) NSUInteger priorityMessagesUnreadCount;

/**
 *  General alerts unread count.
 */
@property (nonatomic, assign) NSUInteger unreadAlertsCount;

/**
 *  Patient care messages unread count.
 */
@property (nonatomic, assign) NSUInteger unreadPatientCareCount;

/**
 *  Active Escalations messages count.
 */
@property (nonatomic, assign) NSUInteger activeEscalationsCount;


/**
 *  A conversation hash to which this instance relates. Will be nil if instance relates to an organization.
 */
@property (nonatomic, strong) NSString *conversationHash;

/**
 *  Add an observer to changes.
 */
- (void)addObserver:(id<TTBadgeDataObserver>)observer;

/**
 *  Remove an observer.
 */
- (void)removeObserver:(id<TTBadgeDataObserver>)observer;

@end

/**
 @abstract The `TTBadgeDataObserver` notifies its receiver when there's a change in badge count.
 */
@protocol TTBadgeDataObserver <NSObject>

@optional
/**
 * Optional delegate function that gets called anytime there is a change in any one of the counts.

 @param unreadCount Unread message count.
 @param unreadAlertsCount Unread nurse call alerts count.
 @param unreadPatientCareCount Unread patient care count.
 @param activeEscalationCount Unread active escalation count.
 */
- (void)badgeDataChanged:(NSUInteger)unreadCount unreadAlertsCount:(NSUInteger)unreadAlertsCount unreadPatientCareCount:(NSUInteger)unreadPatientCareCount activeEscalationCount:(NSUInteger)activeEscalationCount;

@end
