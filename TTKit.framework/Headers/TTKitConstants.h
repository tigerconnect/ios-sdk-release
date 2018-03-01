//
//  TTKitConstants.h
//  TTKit
//
//  Created by Oren Zitoun on 2/15/17.
//  Copyright © 2017 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TTKitConstants : NSObject


// Notifications
FOUNDATION_EXPORT NSString *const kTTKitUnreadMessagesCountChangedNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageWasReceivedNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageWasDeletedNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageWillDeleteNotification; // {userinfo: token} message token
FOUNDATION_EXPORT NSString *const kTTKitConnectionWasEstablishedNotification;
FOUNDATION_EXPORT NSString *const kTTKitConnectionWasLostNotification;
FOUNDATION_EXPORT NSString *const kTTKitConnectionIsConnectingNotification; // {userinfo: userToken} user token
FOUNDATION_EXPORT NSString *const kTTKitConnectionAuthenticationDidFailNotification;
FOUNDATION_EXPORT NSString *const kTTKitReadyNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserDetailsWereDownloadedNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserDidUpdateChangeNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageDidUpdateChangeNotification;
FOUNDATION_EXPORT NSString *const kTTKitGroupDidUpdateChangeNotification;
FOUNDATION_EXPORT NSString *const kTTKitReceivedMessageDidUpdateChangeNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageAttachmentDownloadedNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageAttachmentUploadedNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageDidExpireNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageDidFailToSendNotification; // {userinfo: localToken} message localToken
FOUNDATION_EXPORT NSString *const kTTKitMessageSentNotification; // {userinfo: token} message token
FOUNDATION_EXPORT NSString *const kTTKitRosterEntryWillDeleteNotification;
FOUNDATION_EXPORT NSString *const kTTKitCurrentOrganizationChangeNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserIsTypingChangeNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserInfoObjectKey;
FOUNDATION_EXPORT NSString *const kTTKitCurrentOrganizationTokenKey;
FOUNDATION_EXPORT NSString *const kTTKitDidLogoutNotification;
FOUNDATION_EXPORT NSString *const kTTKitCurrentOrganizationNameKey;
FOUNDATION_EXPORT NSString *const kTTKitCurrentOrganizationKey;
FOUNDATION_EXPORT NSString *const kTTKitDidReceiveRemoteLogoutNotification;
FOUNDATION_EXPORT NSString *const kTTKitSessionExpiredUpdateNotification;
FOUNDATION_EXPORT NSString *const kTTKitDidLoginNotification;
FOUNDATION_EXPORT NSString *const kTTKitWillLogoutNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserInfoErrorKey;
FOUNDATION_EXPORT NSString *const kTTKitOrganizationTokensUserInfoKey;
FOUNDATION_EXPORT NSString *const kTTKitBackgroundPushUpdateCompleteNotification;
FOUNDATION_EXPORT NSString *const kTTKitOfflineMessageProcessingDidFinishNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserValidatedPhoneNumberNotification;
FOUNDATION_EXPORT NSString *const kTTKitOrganizationsDidUpdateNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserDeviceLocalTimeIsOutOfSyncNotification;
FOUNDATION_EXPORT NSString *const kTTKitMuteStateChanged; // userInfo - @{<entity token, NSString> : <entity type, Class>}]}.
FOUNDATION_EXPORT NSString *const kTTKitRoomsFeatureDisabledNotification;
FOUNDATION_EXPORT NSString *const kTTAPIDelayedResponseNotification;
FOUNDATION_EXPORT NSString *const kTTKitAutoforwardFeatureDisabledNotification;
FOUNDATION_EXPORT NSString *const kTTKitAutoforwardRecipientTokenChangedNotification;
FOUNDATION_EXPORT NSString *const kTTKitRoleServiceSettingsChangedNotification;

FOUNDATION_EXPORT NSString *const kTTKitDidBeginDownloadingOfflineMessagesNotification; // {userinfo: count} (total count of offline messages)
FOUNDATION_EXPORT NSString *const kTTKitOfflineMessagesDownloadedUpdateNotification;    // {userinfo: totalDownloadedMessagesCount} (total count of downloaded offline messages)
FOUNDATION_EXPORT NSString *const kTTKitDidFinishDownloadingOfflineMessagesNotification;
FOUNDATION_EXPORT NSString *const kTTKitDidStartProcessingOfflineMessagesNotification; // After all offline messages are downloaded we will begin to proccess them and persist them to the local db
FOUNDATION_EXPORT NSString *const kTTKitDidFinishProcessingOfflineMessagesNotification;// Will get called after all offline messages are proccessed and persisted

// Misc
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusSending;
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusSent;
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusFailed;
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusRead;
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusToBeRead;
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusDelivered;
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusNew;
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusReceivedOnClient;
FOUNDATION_EXPORT NSString *const kTTKitMessageStatusPendingUpdate;

FOUNDATION_EXPORT NSString *const kTTKitContactsManagerLabelKey;
FOUNDATION_EXPORT NSString *const kTTkitContactsManagerValueKey;

FOUNDATION_EXPORT NSString *const kTTKitPersonalOrganizationDefaultToken;
FOUNDATION_EXPORT NSString *const kTTKITUserAPNDeviceTokenKey;

FOUNDATION_EXPORT NSString *const kTTKitURLResponseKey;
FOUNDATION_EXPORT NSString *const kTTKitTigerPageTokenProduction;
FOUNDATION_EXPORT NSString *const kTTKitTigerPageTokenQA;
FOUNDATION_EXPORT NSString *const kTTKitTigerPageTokenDev;

FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceAlertsKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceRoleKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServicePatientCareKey;

@end
