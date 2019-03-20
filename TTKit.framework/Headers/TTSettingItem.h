//
//  TTSettingItem.h
//  TTKit
//
//  Created by Oren Zitoun on 8/12/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

/**
 * A TTSettingItem represents a setting attribute related to the user account or the user's organization.
 */
@interface TTSettingItem : NSManagedObject

/**
 * The conversation identifier related to this setting item.
 */
@property (nullable, nonatomic, retain) NSString * conversationHash;

/**
 * A BOOL value indicating whether the TTSettingItem should ignore API updates.
 */
@property (nullable, nonatomic, retain) NSNumber * ignoreApiUpdate;

/**
 * A BOOL value indicating when the value of this TTSettingItem changes (via user interaction), whether an API call should be made.
 * @discussion Amongst the types in `TTKitSetting`, the following are considered local only types: TTKitSettingPINLock, TTKitSettingPINDuration, TTKitSettingInAppAlertSounds, TTKitSettingSessionExpired, TTKitSettingQuickReplies, TTKitSettingOrganizationEULAURL, TTKitSettingClickToCallOutGoingContactName, TTKitSettingClickToCallOutGoingContactToken.
 */
@property (nullable, nonatomic, retain) NSNumber * localOnly;

/**
 * Name of the setting that is used when communicating that there has been a change in this particular setting item.
 */
@property (nullable, nonatomic, retain) NSString * name;

/**
 * The token of the organization to which this TTSettingItem belongs.
 */
@property (nullable, nonatomic, retain) NSString * orgToken;

/**
 * Type of the TTSettingItem - corresponds to members of the enum, TTKitSetting.
 * @discussion For possible values, see `TTKitSetting`
 */
@property (nullable, nonatomic, retain) NSNumber * type;

/**
 * A BOOL value indicating whether the user can change the value of the setting or if the setting is controlled by the organization.
 * @discussion The value of locked is YES or true if the setting is controlled by the organization.
 */
@property (nullable, nonatomic, retain) NSNumber * locked;

/**
 * Value of the TTSettingItem.
 * @discussion The class of `value` is dependent on the the `type` property.
 * The following types have BOOL values: TTKitSettingDeleteOnRead, TTKitSettingDoNotDisturb, TTKitSettingNotificationAlerts, TTKitSettingNotificationBadges, TTKitSettingNotificationSounds, TTKitSettingPINLock, TTKitSettingForward, TTKitSettingInAppAlertSounds, TTKitSettingPendingAdminApproval, TTKitSettingAllowPublicGroups, TTKitSettingAllowDNDAutoforward, TTKitSettingPriorityMessaging, TTKitSettingSessionExpired, TTKitSettingDisableChangePassword, TTKitSettingRoleService, TTKitSettingDisableAddInbox, TTKitSettingClickToCall, TTKitSettingCalendarService, TTKitSettingEnableMissedCallNotifications, TTKitSettingOrganizationEULA, TTKitSettingAlertsService, TTKitSettingPatientCare, TTKitSettingVoipService, TTKitSettingVideoCallService, TTKitSettingNoPhotos, TTKitSettingNoAttachments, TTKitSettingEscalations, TTKitSettingGroupAudioCallService, TTKitSettingGroupVideoCallService
 *
 * The following types have NSString values: TTKitSettingDoNotDisturbText, TTKitSettingPushSound, TTKitSettingStatus, TTKitSettingDepartment, TTKitSettingTitle, TTKitSettingPreferredEmail, TTKitSettingPreferredPhone, TTKitSettingDNDAutoforwardReceiver, TTKitSettingOrganizationClickToCallNumber, TTKitSettingOrganizationClickToCallLabel, TTKitSettingOrganizationClickToCallContactCurrentName, TTKitSettingClickToCallOutGoingContactName, TTKitSettingClickToCallOutGoingContactToken, TTKitSettingOrganizationEULAURL.
 *
 * The following types have integer values: TTKitSettingTimeToLive, TTKitSettingPINDuration.
 *
 * The following types have array values: TTKitSettingDNDAutoforwardSetters, TTKitSettingQuickReplies.
 */
@property (nullable, nonatomic, retain) id value;

@end
