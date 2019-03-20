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

/**
 * A group that represents a one on one conversation with a role.
 * @discussion This is a way to mask a group with role(s) and owner(s) as a P2P conversation, so a "P2P" between a user and a role (and its owner) makes a TTRoleGroup.
 */
@interface TTRoleGroup : TTGroup

/**
 * The other member of the conversation.
 * @discussion If a role (Doctor) is in a conversation with a user (Patient), to the doctor, the `conversationTarget` is the patient. To the patient, the `conversationTarget` is the doctor (TTRole is a subclass of TTUser).
 * @note This is mainly used on the inbox to determine which avatar to show, and in conversation to determine the recipient of the messages/calls.
 */
@property (nullable, nonatomic, retain) TTUser *conversationTarget;

@end
