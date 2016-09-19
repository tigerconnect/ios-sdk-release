//
//  TTKit.h
//  TTKit
//
//  Copyright (c) 2013, 2014 TigerText, Inc. All rights reserved.
//
////

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "TTUser.h"
#import "TTParty.h"
#import "TTGroup.h"
#import "TTRoleGroup.h"
#import "TTMessage.h"
#import "TTRosterEntry.h"
#import "TTContact.h"
#import "TTAttachmentDescriptor.h"
#import "TTBadgeData.h"
#import "TTPresenceData.h"
#import "TTAttachmentType.h"
#import "TTKitSetting.h"
#import "TTOrganizationAccount.h"
#import "TTMetadata.h"
#import "TTDownloadData.h"
#import "TTUploadData.h"
#import "TTOrganization.h"
#import "TTImageView.h"
#import "TTMessageRequest.h"
#import "TTRole.h"
#import "TTTag.h"

// Notifications
FOUNDATION_EXPORT NSString *const kTTKitUnreadMessagesCountChangedNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageWasReceivedNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageWasDeletedNotification;
FOUNDATION_EXPORT NSString *const kTTKitMessageWillDeleteNotification; // {userinfo: token} message token
FOUNDATION_EXPORT NSString *const kTTKitConnectionWasEstablishedNotification;
FOUNDATION_EXPORT NSString *const kTTKitConnectionWasLostNotification;
FOUNDATION_EXPORT NSString *const kTTKitConnectionIsConnectingNotification;
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
FOUNDATION_EXPORT NSString *const kTTAPIWaitingForResponseNotification;
FOUNDATION_EXPORT NSString *const kTTAPIDelayedResponseNotification;
FOUNDATION_EXPORT NSString *const kTTKitAutoforwardFeatureDisabledNotification;
FOUNDATION_EXPORT NSString *const kTTKitAutoforwardRecipientTokenChangedNotification;
FOUNDATION_EXPORT NSString *const kTTKitRoleServiceSettingsChangedNotification;
FOUNDATION_EXPORT NSString *const kTTAPIRequestTimeoutNotification;
FOUNDATION_EXPORT NSString *const kTTAPINoResponseErrorNotification;
FOUNDATION_EXPORT NSString *const kTTAPIRequestCancelledNotification;

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

FOUNDATION_EXPORT NSString *const kTTKitContactsManagerLabelKey;
FOUNDATION_EXPORT NSString *const kTTkitContactsManagerValueKey;

FOUNDATION_EXPORT NSString *const kTTKitPersonalOrganizationDefaultToken;
FOUNDATION_EXPORT NSString *const kTTKITUserAPNDeviceTokenKey;

FOUNDATION_EXPORT NSString *const kTTKitURLResponseKey;

/**
 *  TTKitEnvironment types
 */
typedef NS_ENUM(NSUInteger, TTKitEnvironment){
    /**
     *  Production environment
     */
    TTKitEnvironmentProduction = 0,
    /**
     *  Test environment
     */
    TTKitEnvironmentTest,
};

/**
 *  TTKitError.
 */
typedef NS_ENUM(NSUInteger, TTKitError) {
    /**
     *  No Error was generated.
     */
    TTKitErrorNoError = 0,
    /**
     *  Request is missing a parameter.
     */
    TTKitErrorMissingParamter,
    /**
     *
     */
    TTKitErrorNotInitialized,
    /**
     *
     */
    TTErrorParameterNotSupported,
    /**
     *
     */
    TTErrorExpiredSession,
    /**
     *
     */
    TTErrorExceededAllowedCapacity,
};

/**
 *  Error Domain used with TTKit's errors
 */
extern NSString *const TTKitErrorDomain;


/**
 *  TTKit is the main object used when using the TTKit iOS SDK. It contains methods that include SDK initialization and user, message and other model object controls.  In addition to creating and manipulating objects, TTKit provides encrypted in-memory and disk based caches to improve performance.
 *
 *  @warning When initializing TTKit, please wait until the isReady property is set to YES or the TTKitReadyNotification is posted before using the provided services.
 *
 */

@interface TTKit : NSObject


/**
 *  The isReady property will be TRUE when TTKit is properly initialized and ready to be used.
 */
@property(nonatomic, readonly) BOOL isReady;

/**
 *  The isConnected property will be TRUE once TTKit establishes a stream with the server.
 */
@property(nonatomic, readonly) BOOL isConnected;

/**
 *  The ttKey property contains the key used when initializing TTKit.
 */
@property(nonatomic, readonly) NSString *ttKey;

/**
 *  The ttSecret property contains the secret used when initializing TTKit.
 */
@property(nonatomic, readonly) NSString *ttSecret;

/**
 *  The userToken property contains the logged in user’s token.
 */
@property(nonatomic, readonly) NSString *userToken;

/**
 *  The agentName property contains the agentName used when initializing TTKit.
 */
@property(nonatomic, readonly) NSString *agentName;

///-------------------------------------------------------
/// @name Application Lifecycle
///-------------------------------------------------------

/**
 *   Initializing TTKit.
 *   Initializing TTKit, pointing to the production environment. This method should be called in the App Delegate.
 *   @param agent Your unique client agent (provided by TigerText).
 */

- (void)initializeWithAgent:(NSString *)agent;

/**
 *  Initializing TTKit.
 *  This method should be called in the App Delegate.
 *  @param agent       Your unique client agent (provided by TigerText).
 *  @param environment Production or Test
 */
- (void)initializeWithAgent:(NSString *)agent environment:(TTKitEnvironment)environment;

/**
 *  Return the TTKit shared instance.
 *
 *  @return TTKit shared instance.
 */
+ (instancetype)sharedInstance;

/**
 Signup to TigerText.
 
 @param userId user login id (Email or username).
 @param password user's password.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)signupWithUserId:(NSString *)userId
                password:(NSString *)password
                 success:(void(^)(TTUser *newUser, NSString *validationPhoneNumber, NSString *validationText))success
                 failure:(void (^)(NSError * error))failure;

/**
 Login to TTKit.
 
 @param userId user login id (Email or username).
 @param password user's password.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)loginWithUserId:(NSString *)userId
               password:(NSString *)password
                success:(void(^)(TTUser *newUser))success
                failure:(void (^)(NSError * error))failure;

/**
 Login to TTKit.
 
 @param key user's key.
 @param secret user's secret.
 @param agent Your unique client agent (provided by TigerText).
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)loginWithKey:(NSString *)key
              secret:(NSString *)secret
               agent:(NSString *)agent
             success:(void(^)(TTUser *newUser))success
             failure:(void (^)(NSError * error))failure;

/**
 *   Logout from TTKit.
 *   All local data, including Database and attachments, will be deleted. Session will be invalidaded and most of the API calls won't function until a new login is done.
 */
- (void)logout;

/**
 *  TTKit Version.
 *
 *  @return NSString conatining TTKit's version.
 */
+ (NSString *)version;

/**
 *  Should be added to the method with the same name in your AppDelegate in order to support Background Session usage.
 *
 *  @param application       The application object provided by the AppDelegate.
 *  @param identifier        The session identifier provided by The AppDelegate.
 *  @param completionHandler The completion handler provided by the AppDelegate.
 */
- (void)application:(UIApplication *)application
handleEventsForBackgroundURLSession:(NSString *)identifier
  completionHandler:(void (^)())completionHandler;

/**
 *  Should be added to the method with the same name in your AppDelegate in order to support Background fetch for push notifications.
 *
 *  @param application       The application object provided by the AppDelegate.
 *  @param userInfo          The remote notification payload identifier.
 *  @param completionHandler The completion handler provided by the AppDelegate.
 */

- (void)application:(UIApplication *)application
didReceiveRemoteNotification:(NSDictionary *)userInfo
fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/**
 Register the device APNs token.
 
 @param dataToken device push token.
 
 */
- (void)registerPushNotificationDataToken:(NSData *)dataToken;

///-------------------------------------------------------
/// @name Organization
///-------------------------------------------------------

/**
 Organization Account fetchController will return all TTOrganizationAccount objects sorted by email
 Must be called on the main thread only.
 
 @param token Organization Token.
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)organizationsAccountsFetchControllerForOrganizationToken:(NSString *)token delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 Organization fetchController will return all TTOrganization objects sorted by organization name
 Must be called on the main thread only.
 
 @param token Organization Token.
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)organizationsFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 Preferred email fetchController will return the selected/default TTOrganizationAccount with email object
 Must be called on the main thread only.
 
 @param token    organization Token.
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)preferredEmailFetchControllerWithOrganizationToken:(NSString *)token delegate:(id<NSFetchedResultsControllerDelegate>)delegate;


/**
 *  Preferred phone fetchController will return the selected/default TTOrganizationAccount with phone number object.
 *
 *  @warning Must be called on the main thread only.
 *
 *  @param token    organization Token.
 @param delegate NSFetchedResultsControllerDelegate.
 *
 *  @return An 'NSFetchedResultsController' Object.
 *
 */
- (NSFetchedResultsController *)preferredPhoneFetchControllerWithOrganizationToken:(NSString *)token delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 *  Returns a NSFetchedResultsController with all TTOrganizationAccounts in which email isn't nil.
 *
 *  @warning Must be called on the main thread only.
 *
 *  @param token    organization Token.
 *  @param delegate NSFetchedResultsControllerDelegate object.
 *
 *  @return NSFetchedResultsController, results are sorted by email address.
 */
- (NSFetchedResultsController *)organizationAccountsEmailFetchControllerWithOrganizationToken:(NSString *)token delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 *  Returns a NSFetchedResultsController with all TTOrganizationAccounts in which phone isn't nil.
 *
 *  @warning Must be called on the main thread only.
 *
 *  @param token    organization Token.
 *  @param delegate NSFetchedResultsControllerDelegate object.
 *
 *  @return NSFetchedResultsController, results are sorted by phone number.
 */
- (NSFetchedResultsController *)organizationAccountsPhoneFetchControllerWithOrganizationToken:(NSString *)token delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 *  Returns a NSFetchedResultsController with all TTMessageStatus related to a message, you can use this contorller to track multiple users statuses for a specific message.
 *
 *  @warning Must be called on the main thread only.
 *
 *  @param token    message Token.
 *  @param delegate NSFetchedResultsControllerDelegate object.
 *
 *  @return NSFetchedResultsController, results are sorted by phone number.
 */
- (NSFetchedResultsController *)messageStatusFetchControllerForMessageToken:(NSString *)token delegate:(id<NSFetchedResultsControllerDelegate>)delegate;
/**
 *  Returns the TTOrganization currently used.
 *
 *  @return a TTOrganization Object.
 */
- (TTOrganization *)currentOrganization;

/**
 *  Returns a TTOrganization object for the provided token.
 *
 *  @param orgToken organization Token.
 *
 *  @return A TTOrganization Object.
 */
- (TTOrganization *)organizationWithToken:(NSString *)orgToken;

/**
 *  Retrieve all Organizations.
 *
 *  @return An NSArray containing TTOrganization objects. If no TTOrganizations exists, an empty array will be returned.
 */
- (NSArray *)getAllOrganizations;

/**
 *  Validate if a specific TTOrganization object is a personal organization.
 *
 *  @param anOrganization A TTOrganization object.
 *
 *  @return returns YES if provided TTOrganization is personal, NO otherwise.
 */
- (BOOL)organizationIsPersonal:(TTOrganization *)anOrganization;

/**
 *  Returns the token of the current organization.
 *
 *  @return NSString containing token of current organization.
 */
- (NSString *)currentOrganizationToken;

/**
 *  Returns the name of the current organization.
 *
 *  @return NSString containing name of current organization.
 */
- (NSString *)currentOrganizationName;

/**
 *  Validate if current organization is a personal one.
 *
 *  @return  returns YES if current organization is personal, NO otherwise.
 */
- (BOOL)isCurrentOrganizationPersonal;

/**
 *  Set current organization.
 *
 *  @param organization A TTOrganization object.
 */
- (void)setCurrentOrganization:(TTOrganization *)organization;

/**
 *  Add user to current organization by providing an email address linked with that organization.
 *
 *  @param emailString Email address. Must be valid and not empty or nil.
 *  @param success     Success block, returns newly created Organization object.
 *  @param failure     Failure block, provides an NSError with a description of the issue.
 */
- (void)joinOrganizationWithEmail:(NSString *)emailString
                          success:(void (^)(TTOrganization *organization))success
                          failure:(void (^)(NSError * error))failure;


/**
 *  Remove user from current organization by providing the organization token.
 *
 *  @param organizationToken Organization token. Must be valid and not empty or nil.
 *  @param success     Success block.
 *  @param failure     Failure block, provides an NSError with a description of the issue.
 */

- (void)leaveOrganization:(NSString *)organizationToken
                  success:(void (^)(void))success
                  failure:(void (^)(NSError * error))failure;

/**
 *  Unlinks user email from current organization by providing an email address linked with that organization.
 *
 *  @param emailString Email address. Must be valid and not empty or nil.
 *  @param success     Success block.
 *  @param failure     Failure block, provides an NSError with a description of the issue.
 */
- (void)unlinkEmail:(NSString *)emailString
                           success:(void (^)(void))success
                           failure:(void (^)(NSError * error))failure;

///-------------------------------------------------------
/// @name Users
///-------------------------------------------------------

/**
 Users fetchController for organization will return all TTuser objects related to the current organization
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)usersFetchControllerForCurrentOrganizationWithDelegate:(id)delegate;

/**
 Users fetchController for group will return all TTuser objects related to the a TTGroup object
 Must be called on the main thread only.
 
 @param token TTGroup token.
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)usersFetchControllerWithGroupToken:(NSString *)token delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 *  Local search for Users
    Returns an array of TTUser objects with a displayName containing the search string which are a part of the user's current organization.
    Returned objects are TTUser
 *
 *  @param search          Search string.
 *  @param completionBlock Block which should handle the returned TTUser array. If no user is found, returned array will be empty.
 */
- (void)searchUsersLocally:(NSString *)search
            success:(void(^)(NSArray *users))completionBlock;

/**
 *  Remote search for Users by the user's display name
    Returns an array of TTUser objects with a displayName containing the search string which are a part of the user's current organization.
    Returned objects are TTUser
 *
 *  @param search          Search string.
 *  @param params          Extra search parameters.
 *  @param completionBlock Block which should handle the returned TTUser array. If no user is found, returned array will be empty. The resultMetadata will contain some extra information about the search results such as
 *  the total number of possible results and pagniation data
 */
- (void)searchUsers:(NSString *)search
             params:(NSDictionary *)params
            success:(void(^)(NSArray *users, NSDictionary *resultMetadata))completionBlock;

/**
 *  Remote search for Users by the a metadata key
    Returns an array of TTUser objects with a displayName containing the search string which are a part of the user's current organization.
    Returned objects are TTUser
 *
 *  @param search          Search string.
 *  @param metadataKey          metadataKey key to filter results by.
 *  @param params          Extra search parameters.
 *  @param completionBlock Block which should handle the returned TTUser array. If no user is found, returned array will be empty. The resultMetadata will contain some extra information about the search results such as
 *  the total number of possible results and pagniation data
 */
- (void)searchUsers:(NSString *)search
        metatadaKey:(NSString *)metadataKey
             params:(NSDictionary *)params
            success:(void(^)(NSArray *users, NSDictionary *resultMetadata))completionBlock;

/**
 *  get a paginated list of room members (Public group)
    Returns an array of TTUser objects.
 *
 *  @param group                      The room group object.
 *  @param continuationToken          Pass in a continuation token to paginate results.
 *  @param completionBlock Block which should handle the returned TTUser array. If no user is found, returned array will be empty. The resultMetadata will contain some extra information about the search results such as
 *  the total number of possible results and pagniation data
 */
- (void)getRoomMembersWithGroup:(TTGroup *)group
              continuationToken:(NSString *)continuationToken
                        success:(void(^)(NSArray *users, NSDictionary *resultMetadata))completionBlock;

/**
 *  Change current user's password to a new one.
 *
 *  @param currentPassword The user's current password.
 *  @param newPassword     The user's new password.
 *  @param success         Success block.
 *  @param failure         Failure block, provides an NSError with a description of the issue.
 */
- (void)changePasswordFromCurrentPassword:(NSString *)currentPassword
                              newPassword:(NSString *)newPassword
                                  success:(void(^)(void))success
                                  failure:(void (^)(NSError * error))failure;

/**
 *  Requests a reset password email to be sent to provided email address.
 *
 *  @param email   Email must be valid and not empty or nil.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)resetPassword:(NSString *)email
              success:(void (^)(NSString *successReply))success
              failure:(void (^)(NSError *))failure;

/**
 *  Returns the avatar URL of the provided party.
 *
 *  @param aParty TTParty object. A TTUser object, which inherits TTParty, can also be provided.
 *
 *  @return NSString containing the avatar's remote URL.
 */
- (NSString *)avatarUrlForParty:(TTParty *)aParty;

/**
 *  Returns the display name of the provided party.
 *
 *  @param aParty TTParty object. A TTUser object, which inherits TTParty, can also be provided.
 *
 *  @return NSString containg the party's display name.
 */
- (NSString *)nameForParty:(TTParty *)aParty;

/**
 *  Returns a TTParty for the provided token
 *
 *  @param token an entity token
 *
 *  @return A TTParty for the provided token
 */
- (TTParty *)partyWithToken:(NSString *)token;

/**
 *  Retrieve a TTUser by providing phone number or email address.
 *
 *  @param phoneOrEmail Phone number or email address.
 *  @param success      Success block, returns a TTUser object.
 *  @param failure      Failure block, returns an NSError.
 *
 *  @return Returns an AFHTTPRequest operation if all values were valid, nil otherwise.
 */
- (id)downloadTigerTextUserWithPhoneNumberOrEmailAddress:(NSString *)phoneOrEmail
                                                 success:(void(^)(TTUser *aUser))success
                                                 failure:(void (^)(NSError * error))failure;

/**
 *  Update local user
 *
 *  @param displayName          user's display name.
 *  @param imageData            user's avatar.
 *  @param success              Success block, returns an updated User object.
 *  @param failure              Failure block, returns an NSError.
 */
- (id)updateLocalUserWithName:(NSString *)displayName
                    imageData:(NSData *)imageData
                      success:(void (^)(TTUser *))success
                      failure:(void (^)(NSError *))failure;

/**
 *  Update local user status
 *
 *  @param status          user's current status.
 *  @param success         Success block, returns an updated User object.
 *  @param failure         Failure block, returns an NSError.
 */
- (id)updateLocalUserStatus:(NSString *)status
                    success:(void (^)(TTUser *))success
                    failure:(void (^)(NSError *))failure;

/**
 *  Retrieve the local user.
 *
 *  @return A TTUser object.
 */
- (TTUser *)localUser;

/**
 *  @abstract Retrieve a user from an email or phone number.
 *  @discussion If you want to send a TigerText message to an email of phone number (`Message Anyone`) use this method to retrieve a
 *  TigerText user token you would be able to message
 *
 *  @param userAddress     A valid email or phone number.
 *  @param displayName     The (possibly) new user display name.
 *  @param firstName       The (possibly) new user first name.
 *  @param lastName        The (possibly) new user last name.
 *  @param success         Success block, returns the retrieved user token.
 *  @param failure         Failure block, returns an NSError.
 */
- (void)userWithAddress:(NSString *)userAddress
            displayName:(NSString *)displayName
              firstName:(NSString *)firstName
               lastName:(NSString *)lastName
                success:(void (^)(NSString *))success
                failure:(void (^)(NSError *))failure;

/**
 *  Retrieve a user for the provided token.
 *
 *  @param token A user token.
 *
 *  @return A TTUser object with the provided token.
 */
- (TTUser *)userWithToken:(NSString *)token;

/**
 *  Validate if provided TTUser object is the local user.
 *
 *  @param user A TTUser object to be validated.
 *
 *  @return YES if provided TTUser is the local user, NO otherwise.
 */
- (BOOL)isUserLocalUser:(TTUser *)user;

/**
 *  Retrieve TTPresenceData by the user's token.
 *
 *  @param token User's token.
 *
 *  @return A TTPresenceData object.
 */
- (TTPresenceData *)getPresenceDataForUserToken:(NSString *)token;

/**
 *  Validates the presence of session credentials.
 *
 *  @return YES if session is valid, NO otherwise.
 */
- (BOOL)isUserConnected;

/**
 *  Downloads user details. Results will be persisted to the local data store.
 *
 *  @param token        TTUser token.
 *  @param success      Success block.
 *  @param failure      Failure block, returns an NSError.
 *
 */
- (id)downloadDetailsForUserToken:(NSString *)token
                          success:(void(^)(TTUser *user))success
                          failure:(void (^)(NSError * error))failure;

/**
 *  Downloads user details. Results will be persisted to the local data store.
 *
 *  @param token        TTUser object.
 *  @param success      Success block.
 *  @param failure      Failure block, returns an NSError.
 *
 */
- (id)downloadDetailsForUser:(TTUser *)aUser
                     success:(void(^)(TTUser *user))success
                     failure:(void (^)(NSError * error))failure;

///-------------------------------------------------------
/// @name Groups
///-------------------------------------------------------

/**
 Groups fetchController will return all TTGroup objects related to the current organization
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)groupsFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 *  Create a new TTGroup. 
 *
 *  Local user will be added as a memeber of the resulting group unless nil was passed for memberTokens array.
 *
 *  @param groupName     Name of the new group (NSString).
 *  @param membersTokens NSArray of user tokens. When nil no members will be added to the group, when empty only local user will be added.
 *  @param avatarUrl     NSString containing the group avatar's URL.
 *  @param imageData     NSData containing the group avatar's image.
 *  @param replayHistory BOOL, show group history when new users join.
 *  @param success       Success block.
 *  @param failure       Failure block, provides an NSError with a description of the issue.
 *
 *
 */
- (void)createGroupWithName:(NSString *)groupName
              membersTokens:(NSArray *)membersTokens
                  avatarUrl:(NSString *)avatarUrl
                  imageData:(NSData *)imageData
              replayHistory:(BOOL)replayHistory
                    success:(void(^)(TTGroup *newGroup))success
                    failure:(void (^)(NSError * error))failure;

/**
 *  Create a new TTGroup with metadata.
 *
 *  Local user will be added as a memeber of the resulting group unless nil was passed for memberTokens array.
 *
 *  @param groupName     Name of the new group (NSString).
 *  @param membersTokens NSArray of user tokens. When nil no members will be added to the group, when empty only local user will be added.
 *  @param avatarUrl     NSString containing the group avatar's URL.
 *  @param imageData     NSData containing the group avatar's image.
    @param metadata      NSDictionary keys and values you wish to add to the group (i.e key1 : value1, key2 : value2).
 *  @param replayHistory BOOL, show group history when new users join.
 *  @param success       Success block.
 *  @param failure       Failure block, provides an NSError with a description of the issue.
 *
 *
 */
- (void)createGroupWithName:(NSString *)groupName
              membersTokens:(NSArray *)membersTokens
                  avatarUrl:(NSString *)avatarUrl
                  imageData:(NSData *)imageData
                   metadata:(NSDictionary *)metadata
              replayHistory:(BOOL)replayHistory
                    success:(void(^)(TTGroup *newGroup))success
                    failure:(void (^)(NSError * error))failure;

/**
 *  Create a new Public TTGroup.
 *
 *  Local user will be added as a memeber of the resulting group unless nil was passed for memberTokens array.
 *
 *  @param groupName            Name of the new group (NSString).
 *  @param membersTokens        NSArray of user tokens. When nil no members will be added to the group, when empty only local user will be added.
 *  @param avatarUrl            NSString containing the group avatar's URL.
 *  @param imageData            NSData containing the group avatar's image.
 *  @param groupDescription     Public group description (Max 300 Characters).
 *  @param replayHistory        BOOL, show group history when new users join.
 *  @param success              Success block.
 *  @param failure              Failure block, provides an NSError with a description of the issue.
 *
 *
 */
- (void)createPublicGroupWithName:(NSString *)groupName
                    membersTokens:(NSArray *)membersTokens
                        avatarUrl:(NSString *)avatarUrl
                        imageData:(NSData *)imageData
                 groupDescription:(NSString *)groupDescription
                    replayHistory:(BOOL)replayHistory
                          success:(void(^)(TTGroup *newGroup))success
                          failure:(void (^)(NSError * error))failure;
/**
 *
 *  Update a group.
 *
 *  @param token         Group token.
 *  @param groupName     Group name.
 *  @param imageData     NSData containing the group avatar's image.
 *  @param success       Success block.
 *  @param failure       Failure block, provides an NSError with a description of the issue.
 *
 *  @return a 'TTGroup' object
 *
 */
- (void)updateGroupWithToken:(NSString *)token
                   groupName:(NSString *)groupName
                      avatar:(NSData *)imageData
                     success:(void(^)(TTGroup *newGroup))success
                     failure:(void (^)(NSError * error))failure;

/**
 *
 *  Update a public group (Room).
 *
 *  @param token               Public group token.
 *  @param groupName           Public group name.
 *  @param imageData           NSData containing the group avatar's image.
 *  @param roomDescription     Room description (Max 300 Characters).
 *  @param success             Success block.
 *  @param failure             Failure block, provides an NSError with a description of the issue.
 *
 *  @return a 'TTGroup' object
 *
 */
- (void)updateRoomWithToken:(NSString *)token
                  groupName:(NSString *)groupName
                     avatar:(NSData *)imageData
            roomDescription:(NSString *)roomDescription
                    success:(void(^)(TTGroup *newGroup))success
                    failure:(void (^)(NSError * error))failure;

/**
 *  Retrieve a TTGroup by it's token.
 *
 *  @param token A group's token.
 *
 *  @return A TTGroup object or nil if token fits no group.
 */
- (TTGroup *)groupWithToken:(NSString *)token;

/**
 *  Add a TTUser to a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param users A TTUser object.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)addUserToGroup:(TTGroup *)group
                  user:(TTUser *)user
               success:(void (^)(void))success
               failure:(void (^)(NSError * error))failure;

/**
 *  Add multiple TTUsers to a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param users An NSArray of TTUser objects.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 */
- (void)addUsersToGroup:(TTGroup *)group
                  users:(NSArray *)users
                success:(void (^)(void))success
                failure:(void (^)(NSError * error))failure;

/**
 *  Add multiple TTUsers to a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param userTokens An NSArray of TTUser objects tokens.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 */
- (void)addUsersToGroup:(TTGroup *)group
             userTokens:(NSArray *)userTokens
                success:(void (^)(void))success
                failure:(void (^)(NSError * error))failure;

/**
 *  Leave group.
 *  Removes local user from group
 *
 *  @param group A TTGroup object.
 */
- (void)leaveGroup:(TTGroup *)group;

/**
 *  Join group.
 *  Adds local user to a group
 *
 *  @param group A TTGroup object.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)joinGroup:(TTGroup *)group
          success:(void (^)(void))success
          failure:(void (^)(NSError * error))failure;

/**
 *  Remove an array of TTUsers from a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param users An NSArray of TTUser objects.
 */
- (void)removeUsersFromGroup:(TTGroup *)group users:(NSArray *)users DEPRECATED_MSG_ATTRIBUTE("Use removeUsersFromGroup:users:success:failure:");

/**
 *  Remove an array of TTUsers from a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param users An NSArray of TTUser objects.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)removeUsersFromGroup:(TTGroup *)group
                       users:(NSArray *)users
                     success:(void (^)(TTGroup *group))success
                     failure:(void (^)(NSError * error))failure;

/**
 *  Remove a TTUser from a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param user A TTUser object.
 */
- (void)removeUserFromGroup:(TTGroup *)group user:(TTUser *)user;

/**
 *  Remote group search
    Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
    Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchGroups:(NSString *)search
             success:(void(^)(NSArray *groups))completionBlock;

/**
 *  Remote group search
 Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param params          NSDictionary with additional search parameters.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchGroups:(NSString *)search
              params:(NSDictionary *)params
             success:(void(^)(NSArray *groups))completionBlock;


/**
 *
    Local group search
    Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
    Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchGroupsLocally:(NSString *)search
             success:(void(^)(NSArray *groups))completionBlock;

/**
 *
 Public group search
 Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchPublicGroups:(NSString *)search
         continuationToken:(NSString *)continuationToken
                   success:(void(^)(NSArray *users, NSDictionary *resultMetadata))completionBlock;

/**
 *  Remote search for Groups by the a metadata key
 Returns an array of TTGroup objects with a metadata key containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param metadataKey          metadataKey key to filter results by.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchGroups:(NSString *)search
         metatadaKey:(NSString *)metadataKey
             success:(void(^)(NSArray *users))completionBlock;

/**
 *  Remote search for Groups by the a metadata key
 Returns an array of TTGroup objects with a metadata key containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param metadataKey          metadataKey key to filter results by.
 *  @param params          NSDictionary with additional search parameters.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchGroups:(NSString *)search
         metatadaKey:(NSString *)metadataKey
              params:(NSDictionary *)params
             success:(void(^)(NSArray *users))completionBlock;

/**
 *  Delete a group
 *
 *  @param group TTGroup object
 */
- (void)deleteGroup:(TTGroup *)group;

/**
 *  Downloads group details. Results will be persisted to the local data store.
 *
 *  @param token        TTGroup object.
 *  @param success      Success block.
 *  @param failure      Failure block, returns an NSError.
 *
 */
- (id)downloadDetailsForGroup:(TTGroup *)aGroup
                      success:(void(^)(TTGroup *group))success
                      failure:(void (^)(NSError * error))failure;

///-------------------------------------------------------
/// @name Roster
///-------------------------------------------------------

/**
 Roster fetchController will return all TTRosterEntry objects for current organization sorted by last message timestamp
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)rosterFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 Roster fetchController will return all TTRosterEntry objects for ALL organizations sorted by last message timestamp
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)rosterFetchControllerForAllOrganizationsWithDelegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 Roster fetchController will return all TTRosterEntry objects for ALL organizations sorted by last message timestamp for a given metadata key-value pair.
 Must be called on the main thread only.
 
 *  @param key metadata key.
 *  @param value metadata value.
 *  @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)rosterFetchControllerForAllOrganizationsMetadataKey:(NSString *)key metadataValue:(NSString *)value delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 *  Roster fetchController will return TTRosterEntry objects for organization token sorted by last message timestamp for a given metadata key-value pair.
 *
 *  @warning Must be called on the main thread only.
 *
 *  @param key metadata key.
 *  @param value metadata value.
 *  @param organizationToken the relevant TTOrganization token.
 *  @param delegate NSFetchedResultsControllerDelegate object.
 *
 *  @return An 'NSFetchedResultsController' Object.
 *
 */
- (NSFetchedResultsController *)rosterFetchControllerdWithMetadataKey:(NSString *)key metadataValue:(NSString *)value organizationToken:(NSString *)organizationToken delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 *  Filter TTRosterEntries by search string.
 *
 *  Returns an NSArray of TTRosterEntry objects which passes one of the following string comparisons:
 *  
 *  1. Its displayName property contains the search string.
 *  2. Its target's displayName contains the search string.
 *  3. Its target's metadata value contains the search string.
 *
 *  Note that all of the above are case and diacritic insensitive.
 *
 *  @param search          The search term (NSString).
 *  @param completionBlock Called upon query's completion. The rosterEntries NSArray contains the resulting TTRosterEntry objects, and will be empty if query had no results.
 */
- (void)searchRosterEntriesWithString:(NSString *)search
                              success:(void(^)(NSArray *rosterEntries))completionBlock;

/**
 *  Retrieve a TTRosterEntry by its conversationHash.
 *
 *  @param conversationHash An NSString with the conversationHash.
 *
 *  @return A TTRosterEntry with the conversationHash or nil if conversationHash was nil, empty or no TTRosterEntry has the conversationHash.
 */
- (TTRosterEntry *)rosterEntryWithConversationHash:(NSString *)conversationHash;

/**
 *  Delete a TTRosterEntry.
 *
 *  @param entry A TTRosterEntry to be deleted.
 */
- (void)deleteRosterEntry:(TTRosterEntry *)entry;

/**
 *  Retrieve Roster Entry with user, this could be use to access the conversation screen from the user's contacts
 *
 *  @param user TTUser object
 *
 *  @return An 'TTRosterEntry' object
 */
- (TTRosterEntry *)rosterEntryForUser:(TTUser *)user;

/**
 *  Retrieve Roster Entry with user, this could be use to access the conversation screen from the user's contacts
 *
 *  @param user TTUser object
 *  @param organizationToken An organization token
 *
 *  @return An 'TTRosterEntry' object
 */
- (TTRosterEntry *)rosterEntryForUser:(TTUser *)user organizationToken:(NSString *)organizationToken;

/**
 *  Retrieve Roster Entry for a set of user token, this could be use to access the conversation screen from the user's groups
 *
 *  @param user TTUser object
 *
 *  @return An 'TTRosterEntry' object
 * 
 */
- (TTRosterEntry *)rosterEntryForUsersTokens:(NSArray *)tokenArray;

/**
 *  Retrieve Roster Entry with group, this could be use to access the conversation screen from the user's contacts
 *
 *  @param group TTGroup object
 *
 *  @return An 'TTRosterEntry' object
 */
- (TTRosterEntry *)rosterEntryForGroup:(TTGroup *)group;

/**
 *  Retrieve Roster Entry for a conversation between a role and the local user.
 *
 *  @param roleRecipient The conversation role recipient.
 *
 *  @param organizationToken An organization token, will default to current organization if not provided.
 *
 *  @return An 'TTRosterEntry' object.
 */
- (TTRosterEntry *)rosterEntryForRoleRecipient:(TTRole *)roleRecipient organizationToken:(NSString *)organizationToken;

/**
 *  Retrieve Roster Entry for a conversation between two roles.
 *
 *  @param roleSender The conversation role sender or the role who created this conversation.
 *
 *  @param roleRecipient The conversation role recipient.
 *
 *  @param organizationToken An organization token, will default to current organization if not provided.
 *
 *  @return An 'TTRosterEntry' object.
 */
- (TTRosterEntry *)rosterEntryForRoleSender:(TTRole *)roleSender roleRecipient:(TTRole *)roleRecipient organizationToken:(NSString *)organizationToken;

/**
 *  Retrieve Roster Entry for a conversation a role (sender) and a user.
 *
 *  @param roleSender The conversation role sender or the role who created this conversation.
 *
 *  @param userRecipient The conversation user recipient.
 *
 *  @param organizationToken An organization token, will default to current organization if not provided.
 *
 *  @return An 'TTRosterEntry' object.
 */
- (TTRosterEntry *)rosterEntryForRoleSender:(TTRole *)roleSender userRecipient:(TTUser *)userRecipient organizationToken:(NSString *)organizationToken;

/**
 *  Determine whether the roster entry is TigerPage
 *
 *  @param A TTRosterEntry to compare
 *
 *  @return returns YES if provided TTRosterEntry is tigerpage, NO otherwise.
 */
- (BOOL) isRosterEntryTigerPage: (TTRosterEntry *) entry;

/**
 *  Validate if provided token is Tigerpage.
 *
 *  @param token A token to compare
 *
 *  @return YES if provided token is Tigerpage, NO otherwise.
 */
- (BOOL)isTokenTigerPage:(NSString *)token;

/**
 *  Fetch all TTRosterEntry objects
 *
 *
 *  @return NSArray object with all TTRosterEntry objects
 */
- (NSArray *)getAllRosterEntries;

/**
 * Get conversation hash for a specific peer-to-peer conversation.
 *
 * @param aSenderToken A sender token
 * @param aSenderOrgToken
 * @param aRecipientOrgToken
 *
 * @return an NSString of the conversationHash
 */
- (NSString *)conversationHashWithSenderToken:(NSString *)aSenderToken senderOrgToken:(NSString *)aSenderOrgToken recipientOrgToken:(NSString *)aRecipientOrgToken;

/**
 * Get conversation hash for a specific group conversation.
 *
 * @param aGroupToken A sender token
 *
 * @return an NSString of the conversationHash
 */
- (NSString *)conversationHashWithGroupToken:(NSString *)aGroupToken;

///-------------------------------------------------------
/// @name Messages
///-------------------------------------------------------

/**
 *  Forward a message to a user.
 *
 *  @param messageToken message token.
 *  @param recipientToken user or group token.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 *  @discussion if a message is marked with TTMessagePriorityHigh, same priority will be conserved when forwarding. Otherwise TTMessagePriorityNormal will be used.
 *
 */

- (void)forwardMessage:(NSString *)messageToken
             recipient:(NSString *)recipientToken
               success:(void(^)(void))success
               failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use forwardMessage:asRole:recipient:success:failure:");

/**
 *  Forward a message to a user.
 *
 *  @param messageToken message token.
 *  @param role The TTRole object you wish to send as
 *  @param recipientToken user or group token.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 *  @discussion if a message is marked with TTMessagePriorityHigh, same priority will be conserved when forwarding. Otherwise TTMessagePriorityNormal will be used.
 *
 */

 - (void)forwardMessage:(NSString *)messageToken
                 asRole:(TTRole *)role
             recipient:(NSString *)recipientToken
               success:(void(^)(void))success
               failure:(void (^)(NSError * error))failure;

/**
 *  Forward a message to a user.
 *
 *  @param messageToken message token.
 *  @param recipientToken user or group token.
 *  @param priorityMessage priority type for this message.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 *  @discussion priority cannot be downgraded, meaning that if a message is marked with TTMessagePriorityHigh, same priority will be conserved even if TTMessagePriorityNormal will be used.
 *
 */

- (void)forwardMessage:(NSString *)messageToken
             recipient:(NSString *)recipientToken
       priorityMessage:(TTMessagePriority)priorityMessage
               success:(void(^)(void))success
               failure:(void (^)(NSError * error))failure
DEPRECATED_MSG_ATTRIBUTE("Use forwardMessage:asRole:recipient:priorityMessage:success:failure:");

/**
 *  Forward a message to a user.
 *
 *  @param messageToken message token.
 *  @param role The TTRole object you wish to send as
 *  @param recipientToken user or group token.
 *  @param priorityMessage priority type for this message.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 *  @discussion priority cannot be downgraded, meaning that if a message is marked with TTMessagePriorityHigh, same priority will be conserved even if TTMessagePriorityNormal will be used.
 *
 */

- (void)forwardMessage:(NSString *)messageToken
                asRole:(TTRole *)role
             recipient:(NSString *)recipientToken
       priorityMessage:(TTMessagePriority)priorityMessage
               success:(void(^)(void))success
               failure:(void (^)(NSError * error))failure;

/**
 *  Forward a message to group of users, creating a group in the process.
 *
 *  @param messageToken message token.
 *  @param role The TTRole object you wish to send as
 *  @param users array of users to send to
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */

- (void)forwardMessage:(NSString *)messageToken
               toUsers:(NSArray *)users
               success:(void(^)(TTGroup *group))success
               failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use forwardMessage:asRole:toUsers:success:failure:");

/**
 *  Forward a message to group of users, creating a group in the process.
 *
 *  @param messageToken message token.
 *  @param users array of users to send to
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */

- (void)forwardMessage:(NSString *)messageToken
                asRole:(TTRole *)role
               toUsers:(NSArray *)users
               success:(void(^)(TTGroup *group))success
               failure:(void (^)(NSError * error))failure;

/**
 *  Send a message using TTMessageRequest object.
 *
 *  @param messageRequest TTMessageRequest object.
 *  @param completion The completion block, will return the new created message or an NSError.
 */
- (void)sendMessageWithRequest:(TTMessageRequest *)messageRequest
                    completion:(void(^)(TTMessage *message, NSError *error))completion;

/**
 Send message with attachment local file path, should be used for uploading message with large attachments like videos.
 
 @param message message text.
 @param rosterEntry the relevant TTRosterObject (conversation) object.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param attachmentPath attachment local disk path.
 @param attachmentMimeType attachment mimeType.
 @param success success return block.
 @param failure failure return block.
 */
- (void)sendMessage:(NSString *)message
        rosterEntry:(TTRosterEntry *)aEntry
           lifetime:(int)aLifetime
       deleteOnRead:(BOOL)dorBool
     attachmentPath:(NSString *)attachmentPath
 attachmentMimeType:(NSString *)aMimeType
            success:(void(^)(TTMessage *newMessage))success
            failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message with attachment data.
 
 @param message message text.
 @param rosterEntry the relevant TTRosterObject (conversation) object.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param attachmentData attachment data
 @param attachmentMimeType attachment mimeType.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)sendMessage:(NSString *)message
        rosterEntry:(TTRosterEntry *)entry
           lifetime:(int)aLifetime
       deleteOnRead:(BOOL)dorBool
     attachmentData:(NSData *)attachmentData
 attachmentMimeType:(NSString *)aMimeType
            success:(void(^)(TTMessage *newMessage))success
            failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message to a collection of users to create a new conversation
 
 @param users an array of TTUser objects.
 @param message message text.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param success success return block.
 @param failure failure return block.
 */
- (void)sendMessageToUsers:(NSArray *)users
                   message:(NSString *)message
                  lifetime:(int)aLifetime
              deleteOnRead:(BOOL)dorBool
                   success:(void(^)(TTRosterEntry *rosterEntry ,TTMessage *newMessage))success
                   failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message to a collection of users to create a new conversation
 
 @param users an array of TTUser objects.
 @param message message text.
 @param groupName group name.
 @param groupAvatar group avatar image NSData.
 @param message message text.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param attachmentData attachment data
 @param attachmentMimeType attachment mimeType.
 @param success success return block.
 @param failure failure return block.
 */
- (void)sendMessageToUsers:(NSArray *)users
              forGroupName:(NSString *)groupName
               groupAvatar:(NSData *)groupAvatar
                   message:(NSString *)message
                  lifetime:(int)aLifetime
              deleteOnRead:(BOOL)dorBool
            attachmentData:(NSData *)attachmentData
        attachmentMimeType:(NSString *)mimeType
                   success:(void(^)(TTRosterEntry *rosterEntry ,TTMessage *newMessage))success
                   failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message to a collection of users to create a new conversation
 
 @param users an array of TTUser objects.
 @param message message text.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param attachmentPath attachment local disk path.
 @param attachmentMimeType attachment mimeType.
 @param success success return block.
 @param failure failure return block.
 */
- (void)sendMessageToUsers:(NSArray *)users
                   message:(NSString *)message
                  lifetime:(int)aLifetime
              deleteOnRead:(BOOL)dorBool
            attachmentPath:(NSString *)attachmentPath
        attachmentMimeType:(NSString *)mimeType
                   success:(void(^)(TTRosterEntry *rosterEntry ,TTMessage *newMessage))success
                   failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message to a collection of users to create a new conversation
 
 @param users an array of TTUser objects.
 @param message message text.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param attachmentData attachment data
 @param attachmentMimeType attachment mimeType.
 @param success success return block.
 @param failure failure return block.
 */
- (void)sendMessageToUsers:(NSArray *)users
                   message:(NSString *)message
                  lifetime:(int)aLifetime
              deleteOnRead:(BOOL)dorBool
            attachmentData:(NSData *)attachmentData
        attachmentMimeType:(NSString *)mimeType
                   success:(void(^)(TTRosterEntry *rosterEntry ,TTMessage *newMessage))success
                   failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message.
 
 @param message message text.
 @param rosterEntry the relevant TTRosterObject (conversation) object.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)sendMessage:(NSString *)message
        rosterEntry:(TTRosterEntry *)entry
           lifetime:(int)aLifetime
       deleteOnRead:(BOOL)dorBool
            success:(void(^)(TTMessage *newMessage))success
            failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message to a user to create a new converation
 
 @param user TTUser object.
 @param message message text.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)sendMessageToUser:(TTUser *)user
                  message:(NSString *)message
                 lifetime:(int)aLifetime
             deleteOnRead:(BOOL)dorBool
                  success:(void(^)(TTMessage *newMessage))success
                  failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message to a user to create a new converation
 
 @param user TTUser object.
 @param message message text.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param attachmentPath attachment local disk path.
 @param attachmentMimeType attachment mimeType.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)sendMessageToUser:(TTUser *)user
                  message:(NSString *)message
                 lifetime:(int)aLifetime
             deleteOnRead:(BOOL)dorBool
           attachmentPath:(NSString *)attachmentPath
       attachmentMimeType:(NSString *)mimeType
                  success:(void(^)(TTMessage *newMessage))success
                  failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message to a user to create a new converation
 
 @param user TTUser object.
 @param message message text.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param attachmentData attachment data.
 @param attachmentMimeType attachment mimeType.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)sendMessageToUser:(TTUser *)user
                  message:(NSString *)message
                 lifetime:(int)lifetime
             deleteOnRead:(BOOL)deleteOnRead
           attachmentData:(NSData *)attachmentData
       attachmentMimeType:(NSString *)mimeType
                  success:(void(^)(TTMessage *newMessage))success
                  failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
 Send message to a group to create a new converation
 
 @param message message text.
 @param group the group you wish to message to.
 @param lifetime message lifetime (minutes).
 @param deleteOnRead message deletes after recipient has read it.
 @param attachmentData attachment data.
 @param attachmentPath attachment local disk path.
 @param attachmentMimeType attachment mimeType.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)sendMessageToGroup:(NSString *)message
                     group:(TTGroup *)group
                  lifetime:(int)lifetime
              deleteOnRead:(BOOL)deleteOnRead
            attachmentData:(NSData *)attachmentData
            attachmentPath:(NSString *)attachmentPath
        attachmentMimeType:(NSString *)aMimeType
                   success:(void(^)(TTRosterEntry *rosterEntry, TTMessage *newMessage))success
                   failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use sendMessageWithRequest:completion: method instead.");

/**
  Retry sending message will try to send the message again (usually used for failed messages)
 
 @param message message object.
 
 */
- (void)retrySendingMessage:(TTMessage *)message;

/**
 Resend message will create a new duplicate message.
 
 @param message message object.
 
 */
- (void)resendMessage:(TTMessage *)message;

/**
 Mark all unread message for roster entry (conversation) as read.
 
 @param conversationHash Conversation Hash.
 @param isGroup is the conversation a group conversation.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)markAllUnreadMessagesAsReadForConversationHash:(NSString *)conversationHash
                                               isGroup:(BOOL)isGroup
                                               success:(void(^)(void))success
                                               failure:(void (^)(NSError * error))failure;

/**
 Mark all unread message for roster entry (conversation) as read.
 
 @param rosterEntry roster entry (conversation) object.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)markAllUnreadMessagesAsRead:(TTRosterEntry *)rosterEntry
                            success:(void(^)(void))success
                            failure:(void (^)(NSError * error))failure;

/**
 Mark message status as Read.
 
 @param message TTMessage object.
 
 */
- (void)markMessageAsRead:(TTMessage *)message;

/**
 Return all the unread messages for a specific conversation using the default NSManagedObjectContext.
 
 @param conversationHash conversationHash for the conversation
 
 */
- (NSArray *)allUnreadMessagesForConversationHash:(NSString *)conversationHash;

/**
 Return all the unread messages for a specific conversation using a specific NSManagedObjectContext.
 
 @param conversationHash conversationHash for the conversation
 @param context the NSManagedContext to use
 
 */
- (NSArray *)allUnreadMessagesForConversationHash:(NSString *)conversationHash context:(NSManagedObjectContext *)context;

/**
 Conversation fetchController will return ALL TTMessage objects sorted by message creation date.
 
 @warning Must be called on the main thread only.
 
 @param conversationHash roster entry conversation hash.
 @param includeBangs set this flag to recieve bang event messages in the conversation (i.e 'username has left the group').
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 @warning This will return ALL the messages for that conversation, to maximize performance we suggest you use 'conversationFetchControllerWithConversationHash:fetchLimit:batchSize:offset:delegate:' to load a smaller subset and paginate through.
 
 */
- (NSFetchedResultsController *)conversationFetchControllerWithConversationHash:(NSString *)conversationHash includeBangs:(BOOL)includeBangs delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 Conversation fetchController will return TTMessage objects sorted by message creation date.

 @warning Must be called on the main thread only.
 
 @param conversationHash roster entry conversation hash.
 @param fetchLimit max results to returned.
 @param batchSize max batch size.
 @param includeBangs set this flag to recieve bang event messages in the conversation (i.e 'username has left the group').
 @param offset message offset.
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)conversationFetchControllerWithConversationHash:(NSString *)conversationHash fetchLimit:(NSUInteger)fetchLimit batchSize:(NSUInteger)batchSize includeBangs:(BOOL)includeBangs offset:(NSUInteger)offset delegate:(id<NSFetchedResultsControllerDelegate>)delegate;

/**
 *  Delete a TTMessage.
 *
 *  @param message a TTMessage object to be deleted.
 */
- (void)deleteMessage:(TTMessage *)message;

/**
 Delete all messages for roster entry.
 
 @param entry roster entry object.
 
 */
- (void)deleteAllMessageForRosterEntry:(TTRosterEntry *)entry;

///-------------------------------------------------------
/// @name Metadata
///-------------------------------------------------------

/**
 Adding Metadata to group
 
 @param group TTGroup object.
 @param params metadata keys and values you wish to add to the group (i.e key1 : value1, key2 : value2).
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)addMetadataForGroup:(TTGroup *)group
                   params:(NSDictionary *)params
                  success:(void (^)(void))success
                  failure:(void (^)(NSError * error))failure;

/**
 Setting Metadata to group
 
 @param group TTGroup object.
 @param params metadata keys and values you wish to set as the group's metadata (i.e key1 : value1, key2 : value2). This will override previous values
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)setMetadataForGroup:(TTGroup *)group
                   params:(NSDictionary *)params
                  success:(void (^)(void))success
                  failure:(void (^)(NSError * error))failure;

/**
 Adding Metadata to user
 
 @param user TTUser object.
 @param params metadata keys and values you wish to add to the user (i.e key1 : value1, key2 : value2).
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)addMetadataForUser:(TTUser *)user
                  params:(NSDictionary *)params
                 success:(void (^)(void))success
                 failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use addMetadataForUser:organizationToken:params:success:failure:");

/**
 Adding Metadata to user
 
 @param user TTUser object.
 @param organizationToken The organization token you wish to add Metadata, Must be valid and not empty or nil.
 @param params metadata keys and values you wish to add to the user (i.e key1 : value1, key2 : value2).
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)addMetadataForUser:(TTUser *)user
       organizationToken:(NSString *)organizationToken
                  params:(NSDictionary *)params
                 success:(void (^)(void))success
                 failure:(void (^)(NSError * error))failure;


/**
 Setting Metadata to user
 
 @param user TTUser object.
 @param params metadata keys and values you wish to set as the user's metadata (i.e key1 : value1, key2 : value2). This will override previous values
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)setMetadataForUser:(TTUser *)user
                  params:(NSDictionary *)params
                 success:(void (^)(void))success
                 failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use setMetadataForUser:organizationToken:params:success:failure:");

/**
 Setting Metadata to user
 
 @param user TTUser object.
 @param organizationToken The organization token you wish to set Metadata, Must be valid and not empty or nil.
 @param params metadata keys and values you wish to set as the user's metadata (i.e key1 : value1, key2 : value2). This will override previous values
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)setMetadataForUser:(TTUser *)user
       organizationToken:(NSString *)organizationToken
                  params:(NSDictionary *)params
                 success:(void (^)(void))success
                 failure:(void (^)(NSError * error))failure;

/**
 Getting Metadata of user
 
 @param user TTUser object.
 @param success Success block with metadata results.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)getMetadataForUser:(TTUser *)user
                 success:(void (^)(NSArray *results))success
                 failure:(void (^)(NSError * error))failure DEPRECATED_MSG_ATTRIBUTE("Use getMetadataForUser:organizationToken:success:failure:");

/**
 Getting Metadata of user
 
 @param user TTUser object.
 @param organizationToken The organization token you wish to get Metadata, Must be valid and not empty or nil.
 @param success Success block with metadata results.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)getMetadataForUser:(TTUser *)user
       organizationToken:(NSString *)organizationToken
                 success:(void (^)(NSArray *results))success
                 failure:(void (^)(NSError * error))failure;

/**
 Getting Metadata of group
 
 @param group TTGroup object.
 @param success Success block with metadata results.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)getMetadataForGroup:(TTGroup *)group
                  success:(void (^)(NSArray *results))success
                  failure:(void (^)(NSError * error))failure;

/**
 Getting Metadata of conversation
 
 @param roster TTRosterEntry object.
 @param success Success block with metadata results.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id)getMetadataForRosterEntry:(TTRosterEntry *)roster
                        success:(void (^)(NSArray *results))success
                        failure:(void (^)(NSError * error))failure;


///-------------------------------------------------------
/// @name Roles
///-------------------------------------------------------

/**
 Saved roles fetchController will return all TTRole objects with saved = YES, sorted by name.
 
 @warning Must be called on the main thread only.
 
 @param organizationToken The organization token you wish to fetch from, will default to current organization if not provided.

 @param tagTokens Filter results with an Array of TTTag tokens.

 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)savedRolesFetchedResultsControllerWithOrganizationToken:(NSString *)organizationToken tagTokens:(NSArray *)tagTokens delegate:(id)delegate;

/**
 *  Fetch/refresh the complete list of the user's saved roles.
 *
 *  @param organizationToken The organization token, will default to current organization token.
 *
 *  @param completion Called upon query's completion.
 */
- (void)savedRolesForOrganizationToken:(NSString *)organizationToken completion:(void (^)(NSArray *savedRoles, BOOL success, NSError *error))completion;

/**
 *  Update Role saved property, use this to bookmark a role to the list of your saved (favorite) roles.
 *
 *  @param role          The TTRole objects you wish to update
 *
 *  @param completion Called upon query's completion.
 */
- (void)updateSaveForRole:(TTRole *)role save:(BOOL)save completion:(void (^)(BOOL success, NSError *error))completion;

/**
 *  Filter Saved TTRole object with search string.
 *
 *  Returns an NSArray of TTRole objects which passes one of the following string comparisons:
 *
 *  1. Its displayName property contains the search string.
 *
 *  Note that all of the above are case and diacritic insensitive.
 *
 *  @param searchString          The search term (NSString).
 *  @param organizationToken     The organization token you wish to perform the search, will default to current organization if not provided.
 *  @param completionBlock Called upon query's completion. The rosterEntries NSArray contains the resulting TTRosterEntry objects, and will be empty if query had no results.
 */
- (void)searchSavedRoles:(NSString *)searchString
       organizationToken:(NSString *)organizationToken
                 success:(void (^)(NSArray *results))completionBlock;

/**
 *  Search Roles in an organization.
 *
 *  Returns an NSArray of TTRole objects which passes one of the following string comparisons:
 *
 *  1. Its displayName property contains the search string.
 * *
 *  @param searchString          The search term (NSString).
 *  @param organizationToken     The organization token you wish to perform the search, will default to current organization if not provided.
 *  @param filterTagTokens       An Array of TTTag tokens (NSString) you wish to filter by.
 *  @param continuationToken     Pass in a continuation token to paginate results.
 *  @param completionBlock Block which should handle the returned TTRole array. If no role is found, returned array will be empty. The resultMetadata will contain some extra information about the search results such as
 *  the total number of possible results and pagniation data
 */
- (id)searchRoles:(NSString *)searchTerm
  filterTagTokens:(NSArray *)tagTokens
organizationToken:(NSString *)organizationToken
continuationToken:(NSString *)continuationToken
          success:(void(^)(NSArray *roles, NSDictionary *resultMetadata))success
          failure:(void (^)(NSError * error))failure;


/**
 *  Retrieve a role for the provided token.
 *
 *  @param token A role token.
 *
 *  @return A TTRole object with the provided token.
 */
- (TTRole *)roleWithToken:(NSString *)token;


/**
 *  Opt in local user to a role.
 *
 *  @param role The role you wish to Opt in to.
 *  @param success Success block with updated role.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *  @return A TTRole object with the provided token.
 */
- (id)optInToRole:(TTRole *)role
          success:(void (^)(TTRole *))success
          failure:(void (^)(NSError *))failure;

/**
 *  Opt out local user to a role.
 *
 *  @param role The role you wish to Opt out of.
 *  @param newUser optional new user to opt in after the local user is remove from the role.
 *  @param success Success block with updated role.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *  @return A TTRole object with the provided token.
 */
- (id)optOutOfRole:(TTRole *)role
         optInUser:(TTUser *)newUser
          success:(void (^)(TTRole *))success
          failure:(void (^)(NSError *))failure;


/**
 *  Leave group as a role.
 *
 *  @param role The role you wish to remove from the group.
 *  @param group The group you wish to update.
 *  @param success Success block with updated role.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)removeRoleFromGroup:(TTRole *)role
                      group:(TTGroup *)group
                    success:(void (^)(void))success
                    failure:(void (^)(NSError *))failure;

/**
 *  Fetch/refresh the complete list of tags.
 *
 *  @param organizationToken The organization token, will default to current organization token.
 *
 *  @param completion Called upon query's completion.
 */
- (void)tagsForOrganizationToken:(NSString *)organizationToken
                         success:(void (^)(NSArray *tags))success
                         failure:(void (^)(NSError *))failure;

///-------------------------------------------------------
/// @name Handling Message Attachment
///-------------------------------------------------------

/**
 Queue a message attachment for download.
 
 If the message attachment object is empty or exists on disk the download will be aborted.
 
 @param message message with attachment object.
 */

- (void)queueMessageForAttachmentDownload:(TTMessage *)message;

/**
 Checks if the message attachment exists on disk.
 
 If the message attachment object is nil returns false.
 
 @param message message with attachment object.
 
 @return A BOOL if the attachment exists on disk.
 
 */
- (BOOL)isMessageAttachmentCachedToDisk:(TTMessage *)message;

/**
 Checks if the message attachment exists on disk in the share folder (App group).
 
 If the message attachment object is nil returns false.
 
 @param message message with attachment object.
 
 @return A BOOL if the attachment exists on disk.
 
 */
- (BOOL)isMessageAttachmentCachedToSharedFolder:(TTMessage *)message;

/**
 File path string to the attachment on disk.
 
 If the message attachment object is nil returns nil.
 
 @param message message with attachment object.
 
 @return An 'NSString' Object.
 
 */
- (NSString *)localPathForAttachment:(TTMessage *)message;

///-------------------------------------------------------
/// @name Attachments Upload and Download data
///-------------------------------------------------------

/**
 DownloadData contains progress information regarding an attachment download
 
 @param message message with attachment object.
 
 @return An 'TTDownloadData' Object.
 
 */
- (TTDownloadData *)getDownloadDataForMessage:(TTMessage *)message;

/**
 UploadData contains progress information regarding an attachment upload
 
 @param message message object.
 
 @return An 'TTUploadData' Object.
 
 */
- (TTUploadData *)getUploadDataForMessage:(TTMessage *)message;

/**
 *
 *  Encrypt an NSData object.
 *
 *  @param data NSData object to be encrypted.
 *
 *  @return An Encrypted NSData object if input parameters were valid and encryption was successful, nil otherwise.
 */
- (NSData *)encryptData:(NSData *)data;

/**
 *  Decrypt an encrypted NSData object.
 *
 *  @param data Encrypted NSData object to be decrypted.
 *
 *  @return A Decrypted NSData object if input parameters were valid and decryption was successful, nil otherwise.
 */
- (NSData *)decryptData:(NSData *)data;

/**
 *  Remove cached data using the provided key.
 *
 *  @param key  Key for the cached value (NSString).
 */
- (void)removeCacheDataForKey:(NSString *)key;

/**
 *  Encrypt NSData and cache to both disk and memory using the provided key.
 *
 *  @param data NSData to be encrypted.
 *  @param key  Key for the cached value (NSString).
 */
- (void)encryptDataAndCache:(NSData *)data key:(NSString *)key;

/**
 *  Retrieve decrypted cached object, which was stored using the provided key.
 *
 *  Method will first search the in-memory cache. If no object fits the provided key, Disk cache will be searched afterwards.
 *
 *  @param key Key for the cached value (NSString).
 *
 *  @return Decrypted NSData object.
 */
- (NSData *)getDecryptedCachedDataForKey:(NSString *)key;

/**
 *  Encrypt NSData and cache to memory using the provided key.
 *
 *  @param data NSData to be encrypted.
 *  @param key  Key for the cached value (NSString).
 */
- (void)encryptDataAndCacheToMemory:(NSData *)data key:(NSString *)key;

/**
 *  Encrypt NSData and cache to disk using the provided key.
 *
 *  @param data NSData to be encrypted.
 *  @param key  Key for the cached value (NSString).
 */
- (void)encryptDataAndCacheToDisk:(NSData *)data key:(NSString *)key;

/**
 *  Encrypt and cache a UIImage to in-memory cache using the provided key.
 *
 *  @param image UIImage to be encrypted.
 *  @param key   Key for the cached value (NSString).
 */
- (void)setImageToMemoryCache:(UIImage *)image key:(NSString *)key;

/**
 *  Retrieve a cached object by its key from the in-memory cache.
 *
 *  @param key Key for the cached value (NSString).
 *
 *  @return Decrypted NSData object for the provided key , nil if no object exists in in-memory cache for provided key.
 */
- (NSData *)objectFromMemoryCache:(NSString *)key;

/**
 *  Retrieve a cached object by its key from the disk cache.
 *
 *  @param key Key for the cached value (NSString).
 *
 *  @return Decrypted NSData object for the provided key , nil if no object exists in disk cache for provided key.
 */
- (NSData *)objectFromDiskCache:(NSString *)key;

/**
 *  Retrieve a decrypted NSData object representing the TTMessage's attachment.
 *
 *  @param message A TTMessage with an attachment.
 *
 *  @return Decrypted NSData object or nil if no attachment exists.
 */
- (NSData *)dataForAttachment:(TTMessage *)message;

///-------------------------------------------------------
/// @name Unread Counts
///-------------------------------------------------------

/**
 *  Retrieve TTBadgeData object for a provided TTRosterEntry.
 *
 *  @param rosterEntry A TTRosterEntry object.
 *
 *  @return A TTBadgeData object with the same conversation hash as the provided TTRosterEntry.
 */
- (TTBadgeData *)badgeDataForRosterEntry:(TTRosterEntry *)rosterEntry;

/**
 *  Retrieve TTBadgeData object for a provided conversation hash.
 *
 *  @param conversationHash Conversation hash (NSString).
 *
 *  @return A TTBadgeData object with the provided conversation hash.
 */
- (TTBadgeData *)badgeDataForConversationHash:(NSString *)conversationHash;

/**
 *  Retrieve TTBadgeData object for all conversations of a provided TTOrganization.
 *
 *  @param organization A TTOrganization object.
 *
 *  @return A TTBadgeData object containing unread count for all conversations of a provided TTOrganization.
 */
- (TTBadgeData *)badgeDataForOrganization:(TTOrganization *)organization;

/**
 *  Retrieve all TTBadgeData objects for all organizations.
 *
 *  @return An NSArray of TTBadgeData objects containing unread count for all conversations of a provided TTOrganization.
 */
- (NSArray *)badgeDataForAllOrganizations;

/**
 *  Retrieve TTBadgeData object for all conversations of a provided organization token.
 *
 *  @param orgToken An organization's token (NSString).
 *
 *  @return A TTBadgeData object containing unread count for all conversations of the provided orgToken.
 */
- (TTBadgeData *)badgeDataForOrganizationToken:(NSString *)orgToken;

/**
 *  Total unread messages count for the local user across organizations.
 *
 *  @return Count of all unread messages (NSUInteger).
 */
- (NSUInteger)getTotalUnreadMessageCount;

/**
 *  Total number of conversations with at least one unread message across all organizations.
 *
 *  @return Count of conversations with unread messages (NSUInteger).
 */
- (NSUInteger)totalNumberOfConversationsWithUnreadMessages;

///-------------------------------------------------------
/// @name Local Address Book
///-------------------------------------------------------

/**
 * Retrieve TTContact with contact hashId
 *
 *   @return A 'TTContact' object
 */
- (TTContact *)contactForHashId:(NSString *)hashId;

/**
 Local contacts from device AddressBook.

 All contacts are saved and fetched from TTKit dedicated Contacts Database,
 this method will fetch the address book contacts from the device and update TTKit local contacts database.
 
 */
- (void)loadLocalContacts;

/**
 Local address book Contacts fetchController will return all TTcontact objects sorted by name.

 @warning Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *)localContactsFetchControllerWithDelegate:(id)delegate;

/**
 *  Search the device's local contacts using the provided value.
 *
 *  Returns an NSArray of TTContact objects which passes one of the following string comparisons:
 *
 *  1. Its full names contains the search string. Case and diacritic insensitive.
 *  2. Its email contains the search string. Case and diacritic insensitive.
 *  3. Its phone number contains the search string. Case and diacritic insensitive.
 *  4. Its initials contains the search string. Case insensitive and diacritic sensitive.
 *
 *  @param search          Search string to be used (NSString).
 *  @param completionBlock Called upon query's completion. The contacts NSArray contains the resulting TTContact objects, and will be empty if query had no results.
 */
- (void)searchLocalContactsWithString:(NSString *)search
                              success:(void(^)(NSArray *contacts))completionBlock;

/**
 *  Search the device's local contacts which are members of the current organization.
 *
 *  Searches the device's local contacts using the provided value, while also filtering out all TTContact objects with emails not containing the name of the current organization. TTContact search is done using the following string comparisons:
 *
 *  1. Its full names contains the search string. Case and diacritic insensitive.
 *  2. Its email contains the search string. Case and diacritic insensitive.
 *  3. Its phone number contains the search string. Case and diacritic insensitive.
 *  4. Its initials contains the search string. Case insensitive and diacritic sensitive.
 *
 *  @param search          Search string to be used (NSString).
 *  @param completionBlock Called upon query's completion. The contacts NSArray contains the resulting TTContact objects, and will be empty if query had no results.
 */
- (void)searchLocalContactsForCurrentOrganization:(NSString *)search
                                          success:(void(^)(NSArray *contacts))completionBlock;

///-------------------------------------------------------
/// @name Misc
///-------------------------------------------------------

/**
 *  Use this method when local user starts typing a message to another user.
 *
 *  @param receipentToken User token of recepient.
 *  @param success        Success block.
 *  @param failure        Failure block.
 */
- (void)setIsTyping:(NSString *)receipentToken
            success:(void (^)(void))success
            failure:(void (^)(NSError * error))failure;

/**
 *  Use this method when local user finished typing a message to another user.
 *
 *  @param receipentToken User token of recepient.
 *  @param success        Success block.
 *  @param failure        Failure block.
 */
- (void)didEndTyping:(NSString *)receipentToken
             success:(void (^)(void))success
             failure:(void (^)(NSError * error))failure;


///-------------------------------------------------------
/// @name Do Not Disturb Settings
///-------------------------------------------------------

/**
 *  Use this method to update your user's dnd setting.
 *
 *  @param dnd do not disturb value, set to YES to turn dnd on.
 */
- (void)setDoNotDisturb:(BOOL)dnd;

/**
 *  Use this method to get user's dnd value.
 *
 */
- (BOOL)doNotDisturb;

/**
 *  Use this method to check if role service is enabled for any Organization.
 *
 *  @param organizationToken The organization token for which to check for role service feature.
 */
- (BOOL)isRoleServiceEnabledForOrganization:(NSString *)organizationToken;

/**
 *  Use this method to update your user's dnd auto reply response.
 *
 *  @param autoReplyResponse auto reply message that will be sent when the user is on dnd. If not set, the reply message will default to 'Do not disturb'
 */
- (void)setDoNotDisturbAutoReply:(NSString *)autoReply;


///-------------------------------------------------------
/// @name Auto-Forwrard Settings
///-------------------------------------------------------

/**
 *  Use this method to get user's autoforward value for Organization currently used.
 *
 */
- (BOOL)isAutoforwardOnforCurrentOrganization;

/**
 *  Use this method to get user's autoforward recipient setting for current Organization.
 *
 */
- (TTUser *)autoforwardRecipientForCurrentOrganization;

/**
 *  Use this method to check if autoforwarding is enabled for the current org.
 *  @param organizationToken The organization token for which to check for auto-forward feature.
 */
- (BOOL)autoforwardEnabledForOrganizationToken:(NSString *)organizationToken;

/**
 *  Use this method to update your user's autoforwardRecipientToken.
 *  @param recipientToken User Token for auto-forward message recipient.
 *  @param organizationToken The organization token for which to configure auto-forward receipient.
 */
- (void)setAutoforwardRecipientToken:(NSString *)recipientToken organizationToken:(NSString *)organizationToken;

/**
 *  Use this method to turn off autoforwarding for the current user.
 *  @param organizationToken The organization token for which to unset auto-forward recipient.
 */
- (void)unsetAutoforwardForOrganizationToken:(NSString *)organizationToken DEPRECATED_MSG_ATTRIBUTE("Use unsetAutoforwardForOrganizationToken:success:failure method instead.");

/**
 *  Use this method to turn off autoforwarding for the current user.
 *  @param organizationToken The organization token for which to unset auto-forward recipient.
 *  @param success        Success block.
 *  @param failure        Failure block.
 */

- (void)unsetAutoforwardForOrganizationToken:(NSString *)organizationToken
                                     success:(void (^)(void))success
                                     failure:(void (^)(NSError *error))failure;

/**
 *  Use this method to get user's autoforward receiver Token.
 *  @param organizationToken The organization token for which to unset auto-forwarding.
 */
- (NSString *)autoforwardReceiverTokenForOrganizationToken:(NSString *)organizationToken;

/**
 *  Use this method to get user's autoforwarding Setters (token).
 *  @param organizationToken The organization token for which to unset auto-forwarding.
 */
- (NSArray *)autoforwardSetterTokensForOrganizationToken:(NSString *)organizationToken;

/**
 *  Use this method to get autoforwarding final recipient for a Roster Entry. The method is asynchronous,
 *  but will will fire the completion block very quickly in the event that a network request isn't needed.
 *  @param rosterEntry The roster entry from which to resolve the final recipient.
 */
- (void)downloadAutoforwardFinalRecipientForRosterEntry:(TTRosterEntry *)rosterEntry
                                             completion:(void (^)(TTUser *user))completion;

/**
 *  Use this method to get user's autoforwarding final recipient. The method is asynchronous,
 *  but will will fire the completion block very quickly in the event that a network request isn't needed.
 *  @param organizationToken The organization token for which to unset auto-forwarding.
 */
- (void)downloadAutoforwardFinalRecipientForUser:(TTUser *)user
                               organizationToken:(NSString *)organizationToken
                                      completion:(void (^)(TTUser *user))completion;

/**
 *  User's title, i.e 'Chief Operations Officer' for a given organization
 *  @param organizationToken Organization token.
 */
- (NSString *)userTitleForOrganizationToken:(NSString *)organizationToken;

/**
 *  Set User's title for a given organization
 *  @param userTitle User title.
 *  @param organizationToken Organization token.
 */
- (void)setUserTitle:(NSString *)title organizationToken:(NSString *)organizationToken;

/**
 *  User's department, i.e 'Marketing' for a given organization
 *  @param organizationToken Organization token.
 */
- (NSString *)userDepartmentForOrganizationToken:(NSString *)organizationToken;

/**
 *  Set User's department for a given organization
 *  @param userTitle User title.
 *  @param organizationToken Organization token.
 */
- (void)setUserDepartment:(NSString *)department organizationToken:(NSString *)organizationToken;

/**
 *  Refresh the message TTMessageStatus set
 *  @param messageToken Message Token.
 *  @param success        Success block.
 *  @param failure        Failure block.
 */
- (id)refreshMessageStatusWithMessageToken:(NSString *)messageToken
                                   success:(void(^)(TTMessage * message))success
                                   failure:(void (^)(NSError * error))failure;
@end
