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
FOUNDATION_EXPORT NSString *const kTTKitMessagesDidDeleteNotification; // {userinfo: tokens} message token
FOUNDATION_EXPORT NSString *const kTTKitConnectionWasEstablishedNotification;
FOUNDATION_EXPORT NSString *const kTTKitConnectionWasLostNotification;
FOUNDATION_EXPORT NSString *const kTTKitConnectionIsConnectingNotification; // {userinfo: userToken} user token
FOUNDATION_EXPORT NSString *const kTTKitConnectionAuthenticationDidFailNotification;
FOUNDATION_EXPORT NSString *const kTTKitReadyNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserDetailsWereDownloadedNotification;
FOUNDATION_EXPORT NSString *const kTTKitUserDidUpdateChangeNotification;
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
FOUNDATION_EXPORT NSString *const kTTKITUserVoipAPNDeviceTokenKey;

FOUNDATION_EXPORT NSString *const kTTKitURLResponseKey;
FOUNDATION_EXPORT NSString *const kTTKitURLErrorMessageKey;
FOUNDATION_EXPORT NSString *const kTTKitTigerPageTokenProduction;
FOUNDATION_EXPORT NSString *const kTTKitTigerPageTokenQA;
FOUNDATION_EXPORT NSString *const kTTKitTigerPageTokenDev;

FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceAlertsKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceRoleKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceRoleAlertsKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServicePatientCareKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceEscalationKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServicePatientMessagingKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceTeamsKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceTeamsIntraTeamKey;
FOUNDATION_EXPORT NSString *const kTTKitFeatureServiceTeamsActivatedTeamKey;

FOUNDATION_EXPORT NSString *const kTTKitEscalationDeletedNotification;
FOUNDATION_EXPORT NSString *const kTTKitEscalationUpdatedNotification;
FOUNDATION_EXPORT NSString *const kTTKitEscalationCreatedNotification;

FOUNDATION_EXPORT NSString *const kTTKitEscalationStatusEscalated;
FOUNDATION_EXPORT NSString *const kTTKitEscalationStatusInProgress;
FOUNDATION_EXPORT NSString *const kTTKitEscalationStatusAcknowledged;
FOUNDATION_EXPORT NSString *const kTTKitEscalationStatusCancelled;
FOUNDATION_EXPORT NSString *const kTTKitEscalationStatusNoResponse;
FOUNDATION_EXPORT NSString *const kTTKitEscalationStatusConversationEscalated;

FOUNDATION_EXPORT NSString *const kTTKitTeamRequestUpdatedNotification;
FOUNDATION_EXPORT NSString *const kTTKitTeamRequestDeclinedNotification;

FOUNDATION_EXPORT NSString *const kTTKitRoleTagUpdatedNotification;

FOUNDATION_EXPORT NSString *const kTTKitMimeTypeJpeg;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypePjpeg;

FOUNDATION_EXPORT NSString *const kTTKitMimeTypePng;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeXpng;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeGif;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeBmp;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeAudioMP4;

FOUNDATION_EXPORT NSString *const kTTKitMimeTypeWav;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeXwav;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeMpeg;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeXm4a;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeMp3;

FOUNDATION_EXPORT NSString *const kTTKitMimeTypeVideoMP4;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeXa4v;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeQuicktime;

FOUNDATION_EXPORT NSString *const kTTKitMimeTypePdf;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeMsWord;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeDocx;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeExcel;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypeSheet;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypePowerpoint;
FOUNDATION_EXPORT NSString *const kTTKitMimeTypePresentation;

FOUNDATION_EXPORT NSString *const kTTKitOrganizationsClickToCallContactsUpdatedNotification;

@end
