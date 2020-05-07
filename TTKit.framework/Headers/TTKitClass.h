//
//  TTKitClass.h
//  TTKit
//
//  Copyright (c) 2013, 2014 TigerText, Inc. All rights reserved.
//
////

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "TTMessage.h"
#import "TTKitConstants.h"
#import "TTKitConfiguration.h"

@class TTContact, TTBadgeData, TTDownloadData, TTGroup, TTMessageRequest, TTOrganization, TTParty, TTPresenceData, TTRole, TTRosterEntry, TTShift, TTUploadData, TTUser, TTTag;
@protocol TTAttachmentDownloadObserver;

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
extern NSString * _Nonnull const TTKitErrorDomain;


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
@property(nullable, nonatomic, readonly) NSString *ttKey;

/**
 *  The ttSecret property contains the secret used when initializing TTKit.
 */
@property(nullable, nonatomic, readonly) NSString *ttSecret;

/**
 *  The userToken property contains the logged in user’s token.
 */
@property(nullable, nonatomic, readonly) NSString *userToken;

/**
 *  The agentName property contains the agentName used when initializing TTKit.
 */
@property(nullable, nonatomic, readonly) NSString *agentName;

///-------------------------------------------------------
/// @name Application Lifecycle
///-------------------------------------------------------

/**
 *  Initializing TTKit.
 *  This method should be called in the App Delegate.
 *  @param configuration      TTKitConfiguration object
 */
- (void)initializeWithConfiguration:(TTKitConfiguration * _Nonnull)configuration;

/**
 *  Return the TTKit shared instance.
 *
 *  @return TTKit shared instance.
 */
+ (instancetype _Nonnull)sharedInstance;

/**
 Signup to TigerText.
 
 @param userId user login id (Email or username).
 @param password user's password.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)signupWithUserId:(NSString * _Nonnull)userId
                password:(NSString * _Nonnull)password
                 success:(void(^ _Nullable)(TTUser * _Nonnull newUser, NSString * _Nullable validationPhoneNumber, NSString * _Nullable validationText, BOOL inboundSmsVerification, BOOL disableSmsValidation, BOOL extAuth))success
                 failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Login to TTKit.
 
 @param userId user login id (Email or username).
 @param password user's password.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)loginWithUserId:(NSString * _Nonnull)userId
               password:(NSString * _Nonnull)password
                success:(void(^ _Nullable)(TTUser * _Nonnull newUser))success
                failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Login to TTKit.
 
 @param key user's key.
 @param secret user's secret.
 @param agent Your unique client agent (provided by TigerText).
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)loginWithKey:(NSString * _Nonnull)key
              secret:(NSString * _Nonnull)secret
               agent:(NSString * _Nullable)agent
             success:(void(^ _Nullable)(TTUser * _Nonnull newUser))success
             failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

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
+ (NSString * _Nonnull)version;

/**
 *  Should be added to the method with the same name in your AppDelegate in order to support Background fetch for push notifications.
 *
 *  @param userInfo          The remote notification payload identifier.
 *  @param completionHandler The completion handler provided by the AppDelegate.
 */

#if TARGET_OS_IOS
- (void)didReceiveRemoteNotification:(NSDictionary *_Nonnull)userInfo fetchCompletionHandler:(void (^ _Nullable)(UIBackgroundFetchResult))completionHandler;
#endif

/**
 Register the device APNs token.
 
 @param dataToken device push token.
 
 */
- (void)registerPushNotificationDataToken:(NSData *_Nonnull)dataToken;

/**
 Register the device VoIP APNs token.
 
 @param dataToken device VoIP push token.
 
 */
- (void)registerVoipPushNotificationDataToken:(NSData *_Nonnull)dataToken;

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
- (NSFetchedResultsController *_Nullable)organizationsAccountsFetchControllerForOrganizationToken:(NSString *_Nonnull)token delegate:(id<NSFetchedResultsControllerDelegate>_Nullable)delegate;

/**
 Organization fetchController will return all TTOrganization objects sorted by organization name
 Must be called on the main thread only.
 
 @param token Organization Token.
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *_Nullable)organizationsFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate>_Nullable)delegate;

/**
 Preferred email fetchController will return the selected/default TTOrganizationAccount with email object
 Must be called on the main thread only.
 
 @param token    organization Token.
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController *_Nullable)preferredEmailFetchControllerWithOrganizationToken:(NSString *_Nonnull)token delegate:(id<NSFetchedResultsControllerDelegate>_Nullable)delegate;


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
- (NSFetchedResultsController *_Nullable)preferredPhoneFetchControllerWithOrganizationToken:(NSString *_Nonnull)token delegate:(id<NSFetchedResultsControllerDelegate>_Nullable)delegate;

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
- (NSFetchedResultsController *_Nullable)organizationAccountsEmailFetchControllerWithOrganizationToken:(NSString *_Nonnull)token delegate:(id<NSFetchedResultsControllerDelegate>_Nullable)delegate;

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
- (NSFetchedResultsController *_Nullable)organizationAccountsPhoneFetchControllerWithOrganizationToken:(NSString *_Nonnull)token delegate:(id<NSFetchedResultsControllerDelegate>_Nullable)delegate;

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
- (NSFetchedResultsController *_Nullable)messageStatusFetchControllerForMessageToken:(NSString *_Nonnull)token delegate:(id<NSFetchedResultsControllerDelegate>_Nullable)delegate;
/**
 *  Returns the TTOrganization currently used.
 *
 *  @return a TTOrganization Object.
 */
- (TTOrganization * _Nullable)currentOrganization;

/**
 *  Returns a TTOrganization object for the provided token.
 *
 *  @param orgToken organization Token.
 *
 *  @return A TTOrganization Object.
 */
- (TTOrganization *_Nullable)organizationWithToken:(NSString *_Nonnull)orgToken;

/**
 *  Retrieve all Organizations.
 *
 *  @return An NSArray containing TTOrganization objects. If no TTOrganizations exists, an empty array will be returned.
 */
- (NSArray *_Nullable)getAllOrganizations;

/**
 *  Validate if a specific TTOrganization object is a personal organization.
 *
 *  @param anOrganization A TTOrganization object.
 *
 *  @return returns YES if provided TTOrganization is personal, NO otherwise.
 */
- (BOOL)organizationIsPersonal:(TTOrganization *_Nonnull)anOrganization;

/**
 *  Returns the token of the current organization.
 *
 *  @return NSString containing token of current organization.
 */
- (NSString *_Nullable)currentOrganizationToken;

/**
 *  Returns the name of the current organization.
 *
 *  @return NSString containing name of current organization.
 */
- (NSString *_Nullable)currentOrganizationName;

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
- (void)setCurrentOrganization:(TTOrganization *_Nonnull)organization;

/**
 *  Add user to current organization by providing an email address linked with that organization.
 *
 *  @param emailString Email address. Must be valid and not empty or nil.
 *  @param success     Success block, returns newly created Organization object.
 *  @param failure     Failure block, provides an NSError with a description of the issue.
 */
- (void)joinOrganizationWithEmail:(NSString *_Nonnull)emailString
                          success:(void (^ _Nullable)(TTOrganization * _Nonnull organization))success
                          failure:(void (^ _Nullable)(NSError * _Nullable error))failure;


/**
 *  Remove user from current organization by providing the organization token.
 *
 *  @param organizationToken Organization token. Must be valid and not empty or nil.
 *  @param success     Success block.
 *  @param failure     Failure block, provides an NSError with a description of the issue.
 */

- (void)leaveOrganization:(NSString *_Nonnull)organizationToken
                  success:(void (^ _Nullable)(void))success
                  failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Unlinks user email from current organization by providing an email address linked with that organization.
 *
 *  @param emailString Email address. Must be valid and not empty or nil.
 *  @param success     Success block.
 *  @param failure     Failure block, provides an NSError with a description of the issue.
 */
- (void)unlinkEmail:(NSString * _Nonnull)emailString
            success:(void (^ _Nullable)(void))success
            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

///-------------------------------------------------------
/// @name Users
///-------------------------------------------------------

/**
 Users fetchController for organization will return all TTuser objects related to the current organization
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)usersFetchControllerForCurrentOrganizationWithDelegate:(id _Nullable)delegate;

/**
 Users fetchController for group will return all TTuser objects related to the a TTGroup object
 Must be called on the main thread only.
 
 @param token TTGroup token.
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)usersFetchControllerWithGroupToken:(NSString * _Nonnull)token delegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

/**
 *  Local search for Users
 Returns an array of TTUser objects with a displayName containing the search string which are a part of the user's current organization.
 Returned objects are TTUser
 *
 *  @param search          Search string.
 *  @param completionBlock Block which should handle the returned TTUser array. If no user is found, returned array will be empty.
 */
- (void)searchUsersLocally:(NSString * _Nonnull)search
                   success:(void(^ _Nullable)(NSArray * _Nullable users))completionBlock;

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
- (void)searchUsers:(NSString * _Nonnull)search
             params:(NSDictionary * _Nullable)params
            success:(void(^ _Nullable)(NSArray * _Nullable users, NSDictionary * _Nullable resultMetadata))completionBlock; 

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
- (void)searchUsers:(NSString * _Nonnull)search
        metatadaKey:(NSString * _Nullable)metadataKey
             params:(NSDictionary * _Nullable)params
            success:(void(^ _Nullable)(NSArray * _Nullable users, NSDictionary * _Nullable resultMetadata))completionBlock;

/**
 *  get a paginated list of room members (Public group)
 Returns an array of TTUser objects.
 *
 *  @param group                      The room group object.
 *  @param continuationToken          Pass in a continuation token to paginate results.
 *  @param completionBlock Block which should handle the returned TTUser array. If no user is found, returned array will be empty. The resultMetadata will contain some extra information about the search results such as
 *  the total number of possible results and pagniation data
 */
- (void)getRoomMembersWithGroup:(TTGroup * _Nonnull)group
              continuationToken:(NSString * _Nullable)continuationToken
                        success:(void(^ _Nullable)(NSArray * _Nullable users, NSDictionary * _Nullable resultMetadata))completionBlock;

/**
 *  Change current user's password to a new one.
 *
 *  @param currentPassword The user's current password.
 *  @param newPassword     The user's new password.
 *  @param success         Success block.
 *  @param failure         Failure block, provides an NSError with a description of the issue.
 */
- (void)changePasswordFromCurrentPassword:(NSString * _Nonnull)currentPassword
                              newPassword:(NSString * _Nonnull)newPassword
                                  success:(void(^ _Nullable)(void))success
                                  failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Requests a reset password email to be sent to provided email address.
 *
 *  @param email   Email must be valid and not empty or nil.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)resetPassword:(NSString * _Nonnull)email
              success:(void (^ _Nullable)(NSString * _Nullable successReply))success
              failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Returns the avatar URL of the provided party.
 *
 *  @param aParty TTParty object. A TTUser object, which inherits TTParty, can also be provided.
 *
 *  @return NSString containing the avatar's remote URL.
 */
- (NSString * _Nullable)avatarUrlForParty:(TTParty * _Nonnull)aParty;

/**
 *  Returns the display name of the provided party.
 *
 *  @param aParty TTParty object. A TTUser object, which inherits TTParty, can also be provided.
 *
 *  @return NSString containg the party's display name.
 */
- (NSString * _Nullable)nameForParty:(TTParty * _Nonnull)aParty;

/**
 *  Returns a TTParty for the provided token
 *
 *  @param token an entity token
 *
 *  @return A TTParty for the provided token
 */
- (TTParty * _Nullable)partyWithToken:(NSString * _Nonnull)token;

/**
 *  Retrieve a TTUser by providing phone number or email address.
 *
 *  @param phoneOrEmail Phone number or email address.
 *  @param success      Success block, returns a TTUser object.
 *  @param failure      Failure block, returns an NSError.
 *
 *  @return Returns an AFHTTPRequest operation if all values were valid, nil otherwise.
 */
- (id _Nullable)downloadTigerTextUserWithPhoneNumberOrEmailAddress:(NSString * _Nonnull)phoneOrEmail
                                                           success:(void(^ _Nullable)(TTUser * _Nonnull aUser))success
                                                           failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Update local user
 *
 *  @param displayName          user's display name.
 *  @param imageData            user's avatar.
 *  @param success              Success block, returns an updated User object.
 *  @param failure              Failure block, returns an NSError.
 */
- (id _Nullable)updateLocalUserWithName:(NSString * _Nullable)displayName
                              imageData:(NSData * _Nullable)imageData
                                success:(void (^ _Nullable)(TTUser * _Nullable user))success
                                failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Update local user status
 *
 *  @param status          user's current status.
 *  @param success         Success block, returns an updated User object.
 *  @param failure         Failure block, returns an NSError.
 */
- (id _Nullable)updateLocalUserStatus:(NSString * _Nullable)status
                              success:(void (^ _Nullable)(TTUser * _Nullable user))success
                              failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Retrieve the local user.
 *
 *  @return A TTUser object.
 */
- (TTUser * _Nullable)localUser;

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
- (void)userWithAddress:(NSString * _Nullable)userAddress
            displayName:(NSString * _Nullable)displayName
              firstName:(NSString * _Nullable)firstName
               lastName:(NSString * _Nullable)lastName
                success:(void (^ _Nullable)(NSString * _Nullable userToken))success
                failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Retrieve a user for the provided token.
 *
 *  @param token A user token.
 *
 *  @return A TTUser object with the provided token.
 */
- (TTUser * _Nullable)userWithToken:(NSString * _Nonnull)token;

/**
 *  Validate if provided TTUser object is the local user.
 *
 *  @param user A TTUser object to be validated.
 *
 *  @return YES if provided TTUser is the local user, NO otherwise.
 */
- (BOOL)isUserLocalUser:(TTUser * _Nonnull)user;

/**
 *  Retrieve TTPresenceData by the user's token.
 *
 *  @param token User's token.
 *
 *  @return A TTPresenceData object.
 */
- (TTPresenceData * _Nullable)getPresenceDataForUserToken:(NSString * _Nonnull)token;

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
- (id _Nullable)downloadDetailsForUserToken:(NSString * _Nonnull)token
                                    success:(void(^ _Nullable)(TTUser * _Nullable user))success
                                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Downloads user details. Results will be persisted to the local data store.
 *
 *  @param token        TTUser object.
 *  @param success      Success block.
 *  @param failure      Failure block, returns an NSError.
 *
 */
- (id _Nullable)downloadDetailsForUser:(TTUser * _Nonnull)aUser
                               success:(void(^ _Nullable)(TTUser * _Nullable user))success
                               failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

///-------------------------------------------------------
/// @name Groups
///-------------------------------------------------------

/**
 Groups fetchController will return all TTGroup objects related to the current organization
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)groupsFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

/**
 Public Groups fetchController will return all public groups related to the current organization with
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)publicGroupsFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

/**
 Private Groups fetchController will return all private groups related to the current organization with
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)privateGroupsFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

/**
 Broadcast List Groups fetchController will return all broadcast list groups related to the current organization with
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)broadcastListGroupsFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

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
- (void)createGroupWithName:(NSString * _Nullable)groupName
              membersTokens:(NSArray * _Nullable)membersTokens
                  avatarUrl:(NSString * _Nullable)avatarUrl
                  imageData:(NSData * _Nullable)imageData
              replayHistory:(BOOL)replayHistory
                    success:(void(^ _Nullable)(TTGroup * _Nullable newGroup))success
                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure DEPRECATED_MSG_ATTRIBUTE("Use createGroupWithName:membersTokens:avatarUrl:imageData:asRole:replayHistory:success:failure:");

/**
 *  Create a new TTGroup.
 *
 *  Local user will be added as a memeber of the resulting group unless nil was passed for memberTokens array.
 *
 *  @param groupName     Name of the new group (NSString).
 *  @param membersTokens NSArray of user tokens. When nil no members will be added to the group, when empty only local user will be added.
 *  @param avatarUrl     NSString containing the group avatar's URL.
 *  @param imageData     NSData containing the group avatar's image.
 *  @param role          If you wish to create this group as a role pass in the TTRole object
 *  @param replayHistory BOOL, show group history when new users join.
 *  @param success       Success block.
 *  @param failure       Failure block, provides an NSError with a description of the issue.
 *
 *
 */
- (void)createGroupWithName:(NSString * _Nullable)groupName
              membersTokens:(NSArray * _Nullable)membersTokens
                  avatarUrl:(NSString * _Nullable)avatarUrl
                  imageData:(NSData * _Nullable)imageData
                     asRole:(TTRole * _Nullable)role
              replayHistory:(BOOL)replayHistory
                    success:(void(^ _Nullable)(TTGroup * _Nullable newGroup))success
                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Create a new TTGroup with metadata.
 *
 *  Local user will be added as a memeber of the resulting group unless nil was passed for memberTokens array.
 *
 *  @param groupName     Name of the new group (NSString).
 *  @param membersTokens NSArray of user tokens. When nil no members will be added to the group, when empty only local user will be added.
 *  @param avatarUrl     NSString containing the group avatar's URL.
 *  @param imageData     NSData containing the group avatar's image.
 *  @param metadata      NSDictionary keys and values you wish to add to the group (i.e key1 : value1, key2 : value2).
 *  @param replayHistory BOOL, show group history when new users join.
 *  @param success       Success block.
 *  @param failure       Failure block, provides an NSError with a description of the issue.
 *
 *
 */
- (void)createGroupWithName:(NSString * _Nullable)groupName
              membersTokens:(NSArray * _Nullable)membersTokens
                  avatarUrl:(NSString * _Nullable)avatarUrl
                  imageData:(NSData * _Nullable)imageData
                   metadata:(NSDictionary * _Nullable)metadata
              replayHistory:(BOOL)replayHistory
                    success:(void(^ _Nullable)(TTGroup * _Nullable newGroup))success
                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure DEPRECATED_MSG_ATTRIBUTE("Use createGroupWithName:membersTokens:avatarUrl:imageData:asRole:metadata:replayHistory:success:failure:");

/**
 *  Create a new TTGroup with metadata.
 *
 *  Local user will be added as a memeber of the resulting group unless nil was passed for memberTokens array.
 *
 *  @param groupName     Name of the new group (NSString).
 *  @param membersTokens NSArray of user tokens. When nil no members will be added to the group, when empty only local user will be added.
 *  @param avatarUrl     NSString containing the group avatar's URL.
 *  @param imageData     NSData containing the group avatar's image.
 *  @param role          If you wish to create this group as a role pass in the TTRole object
 *  @param metadata      NSDictionary keys and values you wish to add to the group (i.e key1 : value1, key2 : value2).
 *  @param replayHistory BOOL, show group history when new users join.
 *  @param success       Success block.
 *  @param failure       Failure block, provides an NSError with a description of the issue.
 *
 *
 */
- (void)createGroupWithName:(NSString * _Nullable)groupName
              membersTokens:(NSArray * _Nullable)membersTokens
                  avatarUrl:(NSString * _Nullable)avatarUrl
                  imageData:(NSData * _Nullable)imageData
                     asRole:(TTRole * _Nullable)role
                   metadata:(NSDictionary * _Nullable)metadata
              replayHistory:(BOOL)replayHistory
                    success:(void(^ _Nullable)(TTGroup * _Nullable newGroup))success
                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

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
- (void)createPublicGroupWithName:(NSString * _Nullable)groupName
                    membersTokens:(NSArray * _Nullable)membersTokens
                        avatarUrl:(NSString * _Nullable)avatarUrl
                        imageData:(NSData * _Nullable)imageData
                 groupDescription:(NSString * _Nullable)groupDescription
                    replayHistory:(BOOL)replayHistory
                          success:(void(^ _Nullable)(TTGroup * _Nullable newGroup))success
                          failure:(void (^ _Nullable)(NSError * _Nullable error))failure;
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
- (void)updateGroupWithToken:(NSString * _Nullable)token
                   groupName:(NSString * _Nullable)groupName
                      avatar:(NSData * _Nullable)imageData
                     success:(void(^ _Nullable)(TTGroup * _Nullable newGroup))success
                     failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

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
- (void)updateRoomWithToken:(NSString * _Nullable)token
                  groupName:(NSString * _Nullable)groupName
                     avatar:(NSData * _Nullable)imageData
            roomDescription:(NSString * _Nullable)roomDescription
                    success:(void(^ _Nullable)(TTGroup * _Nullable newGroup))success
                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Retrieve a TTGroup by it's token.
 *
 *  @param token A group's token.
 *
 *  @return A TTGroup object or nil if token fits no group.
 */
- (TTGroup * _Nullable)groupWithToken:(NSString * _Nonnull)token;

/**
 *  Add a TTUser to a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param users A TTUser object.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)addUserToGroup:(TTGroup * _Nonnull)group
                  user:(TTUser * _Nonnull)user
               success:(void (^ _Nullable)(void))success
               failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Add multiple TTUsers to a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param users An NSArray of TTUser objects.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 */
- (void)addUsersToGroup:(TTGroup * _Nonnull)group
                  users:(NSArray * _Nonnull)users
                success:(void (^ _Nullable)(void))success
                failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Add multiple TTUsers to a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param userTokens An NSArray of TTUser objects tokens.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 */
- (void)addUsersToGroup:(TTGroup * _Nonnull)group
             userTokens:(NSArray * _Nonnull)userTokens
                success:(void (^ _Nullable)(void))success
                failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Leave group.
 *  Removes local user from group
 *
 *  @param group A TTGroup object.
 */
- (void)leaveGroup:(TTGroup * _Nonnull)group;

/**
 *  Join group.
 *  Adds local user to a group
 *
 *  @param group A TTGroup object.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)joinGroup:(TTGroup * _Nonnull)group
          success:(void (^ _Nullable)(void))success
          failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Remove an array of TTUsers from a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param users An NSArray of TTUser objects.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)removeUsersFromGroup:(TTGroup * _Nonnull)group
                       users:(NSArray * _Nonnull)users
                     success:(void (^ _Nullable)(TTGroup * _Nonnull group))success
                     failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Remove a TTUser from a TTGroup.
 *
 *  @param group A TTGroup object.
 *  @param user A TTUser object.
 */
- (void)removeUserFromGroup:(TTGroup * _Nonnull)group user:(TTUser * _Nonnull)user;

/**
 *  Remote group search
 Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchGroups:(NSString * _Nonnull)search
             success:(void(^ _Nullable)(NSArray * _Nullable groups))completionBlock;

/**
 *  Remote group search
 Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param params          NSDictionary with additional search parameters.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchGroups:(NSString * _Nonnull)search
              params:(NSDictionary *_Nullable)params
             success:(void(^ _Nullable)(NSArray * _Nullable groups))completionBlock;

/**
 *
 Private group search
 Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 *  @param failure      Failure block, returns an NSError.
 */
- (void)searchPrivateGroups:(NSString * _Nonnull)search
                    success:(void(^ _Nullable)(NSArray * _Nullable groups))completionBlock
                    failure:(void(^ _Nullable)(NSError * _Nullable error))failure;

/**
 *
 Public group search
 Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param continuationToken     Pass in a continuation token to paginate results.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 *  @param failure      Failure block, returns an NSError.
 */
- (void)searchPublicGroups:(NSString * _Nullable)search
         continuationToken:(NSString * _Nullable)continuationToken
                   success:(void(^ _Nullable)(NSArray * _Nullable groups, NSDictionary * _Nullable resultMetadata))completionBlock
                   failure:(void(^ _Nullable)(NSError * _Nullable error))failure;

/**
 *
 Broadcast List group search
 Returns an array of TTGroup objects with a displayName containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param continuationToken     Pass in a continuation token to paginate results.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 *  @param failure      Failure block, returns an NSError.
 */
- (void)searchBroadcastListGroups:(NSString * _Nonnull)search
                continuationToken:(NSString * _Nullable)continuationToken
                          success:(void(^ _Nullable)(NSArray * _Nullable groups, NSDictionary * _Nullable resultMetadata))completionBlock
                          failure:(void(^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Remote search for Groups by the a metadata key
 Returns an array of TTGroup objects with a metadata key containing the search string which are a part of the user's current organization.
 Returned objects are TTGroup
 *
 *  @param search          Search string.
 *  @param metadataKey          metadataKey key to filter results by.
 *  @param completionBlock Block which should handle the returned TTGroup array. If no user is found, returned array will be empty.
 */
- (void)searchGroups:(NSString * _Nonnull)search
         metatadaKey:(NSString * _Nonnull)metadataKey
             success:(void(^ _Nullable)(NSArray * _Nullable groups))completionBlock;

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
- (void)searchGroups:(NSString * _Nonnull)search
         metatadaKey:(NSString * _Nonnull)metadataKey
              params:(NSDictionary * _Nullable)params
             success:(void(^ _Nullable)(NSArray * _Nullable groups))completionBlock;

/**
 *  Delete a group
 *
 *  @param group TTGroup object
 */
- (void)deleteGroup:(TTGroup * _Nonnull)group;

/**
 *  Downloads group details. Results will be persisted to the local data store.
 *
 *  @param token        TTGroup object.
 *  @param success      Success block.
 *  @param failure      Failure block, returns an NSError.
 *
 */
- (id _Nullable)downloadDetailsForGroup:(TTGroup * _Nonnull)aGroup
                                success:(void(^ _Nullable)(TTGroup *_Nullable group))success
                                failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

///-------------------------------------------------------
/// @name Roster
///-------------------------------------------------------

/**
 Roster fetchController will return all TTRosterEntry objects for current organization sorted by last message timestamp
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)rosterFetchControllerWithDelegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

/**
 Roster fetchController will return all TTRosterEntry objects for ALL organizations sorted by last message timestamp
 Must be called on the main thread only.
 
 @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)rosterFetchControllerForAllOrganizationsWithDelegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

/**
 Roster fetchController will return all TTRosterEntry objects for ALL organizations sorted by last message timestamp for a given metadata key-value pair.
 Must be called on the main thread only.
 
 *  @param key metadata key.
 *  @param value metadata value.
 *  @param delegate NSFetchedResultsControllerDelegate object.
 
 @return An 'NSFetchedResultsController' Object.
 
 */
- (NSFetchedResultsController * _Nullable)rosterFetchControllerForAllOrganizationsMetadataKey:(NSString * _Nonnull)key metadataValue:(NSString * _Nonnull)value delegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

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
- (NSFetchedResultsController * _Nullable)rosterFetchControllerdWithMetadataKey:(NSString * _Nonnull)key metadataValue:(NSString * _Nonnull)value organizationToken:(NSString * _Nonnull)organizationToken delegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

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
- (void)searchRosterEntriesWithString:(NSString * _Nonnull)search
                              success:(void(^ _Nullable)(NSArray * _Nullable rosterEntries))completionBlock;

/**
 *  Retrieve a TTRosterEntry by its conversationHash.
 *
 *  @param conversationHash An NSString with the conversationHash.
 *
 *  @return A TTRosterEntry with the conversationHash or nil if conversationHash was nil, empty or no TTRosterEntry has the conversationHash.
 */
- (TTRosterEntry * _Nullable)rosterEntryWithConversationHash:(NSString * _Nonnull)conversationHash;

/**
 *  Delete a TTRosterEntry.
 *
 *  @param entry A TTRosterEntry to be deleted.
 */
- (void)deleteRosterEntry:(TTRosterEntry * _Nonnull)entry;

/**
 *  Retrieve Roster Entry with user, this could be use to access the conversation screen from the user's contacts
 *
 *  @param user TTUser object
 *
 *  @return An 'TTRosterEntry' object
 */
- (TTRosterEntry * _Nullable)rosterEntryForUser:(TTUser * _Nonnull)user;

/**
 *  Retrieve Roster Entry with user, this could be use to access the conversation screen from the user's contacts
 *
 *  @param user TTUser object
 *  @param organizationToken An organization token
 *
 *  @return An 'TTRosterEntry' object
 */
- (TTRosterEntry * _Nullable)rosterEntryForUser:(TTUser * _Nonnull)user organizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Retrieve Roster Entry for a set of user token, this could be use to access the conversation screen from the user's groups
 *
 *  @param user TTUser object
 *
 *  @return An 'TTRosterEntry' object
 *
 */
- (TTRosterEntry * _Nullable)rosterEntryForUsersTokens:(NSArray * _Nonnull)tokenArray;

/**
 *  Retrieve Roster Entry with group, this could be use to access the conversation screen from the user's contacts
 *
 *  @param group TTGroup object
 *
 *  @return An 'TTRosterEntry' object
 */
- (TTRosterEntry * _Nullable)rosterEntryForGroup:(TTGroup * _Nonnull)group;

/**
 *  Retrieve Roster Entry for a conversation between a role and the local user.
 *
 *  @param roleRecipient The conversation role recipient.
 *
 *  @param organizationToken An organization token, will default to current organization if not provided.
 *
 *  @return An 'TTRosterEntry' object.
 */
- (TTRosterEntry * _Nullable)rosterEntryForRoleRecipient:(TTRole * _Nonnull)roleRecipient organizationToken:(NSString * _Nonnull)organizationToken;

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
- (TTRosterEntry * _Nullable)rosterEntryForRoleSender:(TTRole * _Nullable)roleSender roleRecipient:(TTRole * _Nonnull)roleRecipient organizationToken:(NSString * _Nonnull)organizationToken;

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
- (TTRosterEntry * _Nullable)rosterEntryForRoleSender:(TTRole * _Nullable)roleSender userRecipient:(TTUser * _Nonnull)userRecipient organizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Determine whether the roster entry is TigerPage
 *
 *  @param A TTRosterEntry to compare
 *
 *  @return returns YES if provided TTRosterEntry is tigerpage, NO otherwise.
 */
- (BOOL)isRosterEntryTigerPage:(TTRosterEntry * _Nonnull) entry;

/**
 *  Validate if provided token is Tigerpage.
 *
 *  @param token A token to compare
 *
 *  @return YES if provided token is Tigerpage, NO otherwise.
 */
- (BOOL)isTokenTigerPage:(NSString * _Nonnull)token;

/**
 *  Fetch all TTRosterEntry objects
 *
 *
 *  @return NSArray object with all TTRosterEntry objects
 */
- (NSArray * _Nullable)getAllRosterEntries;

/**
 * Get conversation hash for a specific peer-to-peer conversation.
 *
 * @param aSenderToken A sender token
 * @param aSenderOrgToken
 * @param aRecipientOrgToken
 *
 * @return an NSString of the conversationHash
 */
- (NSString * _Nonnull)conversationHashWithSenderToken:(NSString * _Nonnull)aSenderToken senderOrgToken:(NSString * _Nonnull)aSenderOrgToken recipientOrgToken:(NSString * _Nonnull)aRecipientOrgToken;

/**
 * Get conversation hash for a specific group conversation.
 *
 * @param aGroupToken A sender token
 *
 * @return an NSString of the conversationHash
 */
- (NSString * _Nonnull)conversationHashWithGroupToken:(NSString * _Nonnull)aGroupToken;

///-------------------------------------------------------
/// @name Shift
///-------------------------------------------------------

/**
 *  Fetch a TTUser roles schedule.
 *
 *  @param userToken user token.
 *  @param startDate Schedule start time.
 *  @param endDate Schedule end time.
 *  @param organizationToken organization token.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 *  @discussion Use this method to pull fresh data from the scheduling server. The shifts returned will contain all the roles that the user you provided is scheduled to be assigned to.
 *
 */

- (id _Nullable)userShiftsWithToken:(NSString * _Nonnull)userToken
                          startDate:(NSDate * _Nonnull)startDate
                            endDate:(NSDate * _Nonnull)endDate
                  organizationToken:(NSString * _Nonnull)organizationToken
                            success:(void (^ _Nullable)(NSArray <TTShift *>* _Nullable shifts))success
                            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Fetch a TTRole users schedule.
 *
 *  @param roleToken role token.
 *  @param startDate Schedule start time.
 *  @param endDate Schedule end time.
 *  @param organizationToken organization token.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 *  @discussion Use this method to pull fresh data from the scheduling server. The shifts returned will contain all the users that are scheduled to be assigned to the role you provided
 *
 */

- (id _Nullable)roleShiftsWithToken:(NSString * _Nonnull)roleToken
                          startDate:(NSDate * _Nonnull)startDate
                            endDate:(NSDate * _Nonnull)endDate
                  organizationToken:(NSString * _Nonnull)organizationToken
                            success:(void (^ _Nullable)(NSArray <TTShift *>* _Nullable shifts))success
                            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Use this method to check if calendar service is enabled for any Organization.
 *
 *  @param organizationToken The organization token for which to check for calendar service feature.
 */
- (BOOL)isCalendarServiceEnabledForOrganization:(NSString * _Nonnull)organizationToken;

///-------------------------------------------------------
/// @name Messages
///-------------------------------------------------------

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

- (void)forwardMessage:(NSString * _Nonnull)messageToken
                asRole:(TTRole * _Nullable)role
             recipient:(NSString * _Nonnull)recipientToken
               success:(void(^ _Nullable)(void))success
               failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

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

- (void)forwardMessage:(NSString * _Nonnull)messageToken
                asRole:(TTRole * _Nullable)role
             recipient:(NSString * _Nonnull)recipientToken
       priorityMessage:(TTMessagePriority)priorityMessage
               success:(void(^ _Nullable)(TTGroup * _Nullable group))success
               failure:(void (^ _Nullable)(NSError * _Nullable error))failure;


/**
 *  Forward messages to a user.
 *
 *  @param messageTokens message tokens.
 *  @param role The TTRole object you wish to send as
 *  @param recipientToken user or group token.
 *  @param priorityMessage priority type for this message.
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *
 */

- (void)forwardMessages:(NSArray<NSString *> *_Nonnull)messageTokens
                 asRole:(TTRole *_Nullable)roleSender
              recipient:(NSString *_Nonnull)recipient
        priorityMessage:(TTMessagePriority)priority
                success:(void(^_Nullable)(TTGroup *_Nullable group))success
                failure:(void (^_Nullable)(NSError *_Nullable error))failure;


/**
 *  Forward a message to group of users, creating a group in the process.
 *
 *  @param messageToken message token.
 *  @param users array of users to send to
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */

- (void)forwardMessage:(NSString * _Nonnull)messageToken
                asRole:(TTRole * _Nullable)role
               toUsers:(NSArray * _Nonnull)users
               success:(void(^ _Nullable)(TTGroup * _Nullable group))success
               failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Forward messages to group of users, creating a group in the process.
 *
 *  @param messageTokens message tokens.
 *  @param users array of users to send to
 *  @param success Success block.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */

- (void)forwardMessages:(NSArray<NSString *> *_Nonnull)messageTokens
                 asRole:(TTRole * _Nullable)asRole
                toUsers:(NSArray * _Nonnull)users
                success:(void(^ _Nullable)(TTGroup * _Nullable group))success
                failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Send a message using TTMessageRequest object.
 *
 *  @param messageRequest TTMessageRequest object.
 *  @param completion The completion block, will return the new created message or an NSError.
 */
- (void)sendMessageWithRequest:(TTMessageRequest * _Nonnull)messageRequest
                    completion:(void(^ _Nullable)(TTMessage * _Nullable message, NSError * _Nullable error))completion;

/**
 Retry sending message will try to send the message again (usually used for failed messages)
 
 @param message message object.
 
 */
- (void)retrySendingMessage:(TTMessage * _Nonnull)message;

/**
 Resend message will create a new duplicate message.
 
 @param message message object.
 
 */
- (void)resendMessage:(TTMessage * _Nonnull)message;

/**
 Mark all unread message for roster entry (conversation) as read.
 
 @param conversationHash Conversation Hash.
 @param isGroup is the conversation a group conversation.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)markAllUnreadMessagesAsReadForConversationHash:(NSString * _Nonnull)conversationHash
                                               isGroup:(BOOL)isGroup
                                               success:(void(^ _Nullable)(void))success
                                               failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Mark all unread message for roster entry (conversation) as read.
 
 @param rosterEntry roster entry (conversation) object.
 @param success success return block.
 @param failure failure return block.
 
 */
- (void)markAllUnreadMessagesAsRead:(TTRosterEntry * _Nonnull)rosterEntry
                            success:(void(^ _Nullable)(void))success
                            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Mark message status as Read.
 
 @param message TTMessage object.
 
 */
- (void)markMessageAsRead:(TTMessage * _Nonnull)message DEPRECATED_MSG_ATTRIBUTE("Use markMessagesAsRead:");

/**
 Mark message statuses as Read

 @param messages Array of TTMessage objects.
 */
- (void)markMessagesAsRead:(NSArray<TTMessage *> *_Nonnull)messages;

/**
 Return all the unread messages for a specific conversation using the default NSManagedObjectContext.
 
 @param conversationHash conversationHash for the conversation
 
 */
- (NSArray * _Nullable)allUnreadMessagesForConversationHash:(NSString * _Nonnull)conversationHash;

/**
 Conversation fetchController will return ALL TTMessage objects sorted by message creation date.
 
 @warning Must be called on the main thread only.
 
 @param conversationHash roster entry conversation hash.
 @param includeBangs set this flag to recieve bang event messages in the conversation (i.e 'username has left the group').
 @param delegate NSFetchedResultsControllerDelegate.
 
 @return An 'NSFetchedResultsController' Object.
 
 @warning This will return ALL the messages for that conversation, to maximize performance we suggest you use 'conversationFetchControllerWithConversationHash:fetchLimit:batchSize:offset:delegate:' to load a smaller subset and paginate through.
 
 */
- (NSFetchedResultsController * _Nullable)conversationFetchControllerWithConversationHash:(NSString * _Nonnull)conversationHash includeBangs:(BOOL)includeBangs delegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

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
- (NSFetchedResultsController * _Nullable)conversationFetchControllerWithConversationHash:(NSString * _Nonnull)conversationHash fetchLimit:(NSUInteger)fetchLimit batchSize:(NSUInteger)batchSize includeBangs:(BOOL)includeBangs offset:(NSUInteger)offset delegate:(id<NSFetchedResultsControllerDelegate> _Nullable)delegate;

/**
 *  Delete a TTMessage.
 *
 *  @param message a TTMessage object to be deleted.
 */
- (void)deleteMessage:(TTMessage * _Nonnull)message;

/**
 *  Delete multiple TTMessages.
 *
 *  @param messages an array of TTMessage objects to be deleted.
 */
- (void)deleteMessages:(NSArray<TTMessage *> *_Nonnull)messages;

/**
 Delete all messages for roster entry.
 
 @param entry roster entry object.
 
 */
- (void)deleteAllMessageForRosterEntry:(TTRosterEntry * _Nonnull)entry;

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
- (id _Nullable)addMetadataForGroup:(TTGroup * _Nonnull)group
                             params:(NSDictionary * _Nonnull)params
                            success:(void (^ _Nullable)(void))success
                            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Setting Metadata to group
 
 @param group TTGroup object.
 @param params metadata keys and values you wish to set as the group's metadata (i.e key1 : value1, key2 : value2). This will override previous values
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id _Nullable)setMetadataForGroup:(TTGroup * _Nonnull)group
                             params:(NSDictionary * _Nullable)params
                            success:(void (^ _Nullable)(void))success
                            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Adding Metadata to user
 
 @param user TTUser object.
 @param organizationToken The organization token you wish to add Metadata, Must be valid and not empty or nil.
 @param params metadata keys and values you wish to add to the user (i.e key1 : value1, key2 : value2).
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id _Nullable)addMetadataForUser:(TTUser * _Nonnull)user
                 organizationToken:(NSString * _Nonnull)organizationToken
                            params:(NSDictionary * _Nonnull)params
                           success:(void (^ _Nullable)(void))success
                           failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Setting Metadata to user
 
 @param user TTUser object.
 @param organizationToken The organization token you wish to set Metadata, Must be valid and not empty or nil.
 @param params metadata keys and values you wish to set as the user's metadata (i.e key1 : value1, key2 : value2). This will override previous values
 @param success Success block.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id _Nullable)setMetadataForUser:(TTUser * _Nonnull)user
                 organizationToken:(NSString * _Nonnull)organizationToken
                            params:(NSDictionary * _Nullable)params
                           success:(void (^ _Nullable)(void))success
                           failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Getting Metadata of user
 
 @param user TTUser object.
 @param organizationToken The organization token you wish to get Metadata, Must be valid and not empty or nil.
 @param success Success block with metadata results.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id _Nullable)getMetadataForUser:(TTUser * _Nonnull)user
                 organizationToken:(NSString * _Nonnull)organizationToken
                           success:(void (^ _Nullable)(NSArray * _Nullable results))success
                           failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Getting Metadata of group
 
 @param group TTGroup object.
 @param success Success block with metadata results.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id _Nullable)getMetadataForGroup:(TTGroup * _Nonnull)group
                            success:(void (^ _Nullable)(NSArray * _Nullable results))success
                            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 Getting Metadata of conversation
 
 @param roster TTRosterEntry object.
 @param success Success block with metadata results.
 @param failure Failure block, provides an NSError with a description of the issue.
 
 */
- (id _Nullable)getMetadataForRosterEntry:(TTRosterEntry * _Nonnull)roster
                                  success:(void (^ _Nullable)(NSArray * _Nullable results))success
                                  failure:(void (^ _Nullable)(NSError * _Nullable error))failure;


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
- (NSFetchedResultsController * _Nullable)savedRolesFetchedResultsControllerWithOrganizationToken:(NSString * _Nonnull)organizationToken tagTokens:(NSArray * _Nullable)tagTokens delegate:(id _Nullable)delegate;

/**
 *  Fetch/refresh the complete list of the user's saved roles.
 *
 *  @param organizationToken The organization token, will default to current organization token.
 *
 *  @param completion Called upon query's completion.
 */
- (id _Nullable)savedRolesForOrganizationToken:(NSString * _Nonnull)organizationToken completion:(void (^ _Nullable)(NSArray * _Nullable savedRoles, BOOL success, NSError * _Nullable error))completion;

/**
 *  Update Role saved property, use this to bookmark a role to the list of your saved (favorite) roles.
 *
 *  @param role          The TTRole objects you wish to update
 *
 *  @param completion Called upon query's completion.
 */
- (void)updateSaveForRole:(TTRole * _Nonnull)role save:(BOOL)save completion:(void (^ _Nullable)(BOOL success, NSError * _Nullable error))completion;

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
- (void)searchSavedRoles:(NSString * _Nonnull)searchString
       organizationToken:(NSString * _Nonnull)organizationToken
                 success:(void (^ _Nullable)(NSArray * _Nullable results))completionBlock;

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
- (id _Nullable)searchRoles:(NSString * _Nonnull)searchTerm
            filterTagTokens:(NSArray * _Nullable)tagTokens
          organizationToken:(NSString * _Nonnull)organizationToken
          continuationToken:(NSString * _Nullable)continuationToken
                    success:(void(^ _Nullable)(NSArray * _Nullable roles, NSDictionary * _Nullable resultMetadata))success
                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Search Tags in an organization.
 *
 *  Returns an NSArray of TTTag objects which passes one of the following string comparisons:
 *
 *  1. Its displayName property contains the search string.
 * *
 *  @param searchString          The search term (NSString).
 *  @param filterColorTokens     An Array of Color tokens (NSString) you wish to filter by.
 *  @param organizationToken     The organization token you wish to perform the search, will default to current organization if not provided.
 *  @param continuationToken     Pass in a continuation token to paginate results.
 *  @param completionBlock Block which should handle the returned TTTag array. If no tags are found, returned array will be empty. The resultMetadata will contain some extra information about the search results such as
 *  the total number of possible results and pagniation data
 */
- (id _Nullable)searchTags:(NSString * _Nullable)searchString
filterColorTokens:(NSArray * _Nullable)colorTokens
organizationToken:(NSString * _Nonnull)organizationToken
continuationToken:(NSString * _Nullable)continuationToken
         success:(void(^_Nullable)(NSArray <TTTag *>* _Nullable tags, NSDictionary * _Nullable resultMetadata))success
         failure:(void (^_Nullable)(NSError * _Nullable error))failure;

/**
 *  Retrieve a role for the provided token.
 *
 *  @param token A role token.
 *
 *  @return A TTRole object with the provided token.
 */
- (TTRole * _Nullable)roleWithToken:(NSString * _Nonnull)token;


/**
 *  Opt in local user to a role.
 *
 *  @param role The role you wish to Opt in to.
 *  @param success Success block with updated role.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *  @return A TTRole object with the provided token.
 */
- (id _Nullable)optInToRole:(TTRole * _Nonnull)role
                    success:(void (^ _Nullable)(TTRole * _Nullable role))success
                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Opt out local user to a role.
 *
 *  @param role The role you wish to Opt out of.
 *  @param newUser optional new user to opt in after the local user is remove from the role.
 *  @param success Success block with updated role.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 *  @return A TTRole object with the provided token.
 */
- (id _Nullable)optOutOfRole:(TTRole * _Nonnull)role
                   optInUser:(TTUser * _Nullable)newUser
                     success:(void (^ _Nullable)(TTRole * _Nullable role))success
                     failure:(void (^ _Nullable)(NSError * _Nullable error))failure;


/**
 *  Leave group as a role.
 *
 *  @param role The role you wish to remove from the group.
 *  @param group The group you wish to update.
 *  @param success Success block with updated role.
 *  @param failure Failure block, provides an NSError with a description of the issue.
 */
- (void)removeRoleFromGroup:(TTRole * _Nonnull)role
                      group:(TTGroup * _Nonnull)group
                    success:(void (^ _Nullable)(void))success
                    failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Fetch/refresh the complete list of tags.
 *
 *  @param organizationToken The organization token, will default to current organization token.
 *
 *  @param completion Called upon query's completion.
 */
- (void)tagsForOrganizationToken:(NSString * _Nullable)organizationToken
                         success:(void (^ _Nullable)(NSArray * _Nullable tags))success
                         failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

///-------------------------------------------------------
/// @name Handling Message Attachment
///-------------------------------------------------------

/**
 Checks if the mime type is a supported type for attachments

 @param type mime type of the attachment
 @return A BOOL indicating if type is supported.
 */
- (BOOL)isMimeTypeSupported:(NSString *_Nonnull)type;

/**
 Get file extension string for a given mime type

 @param type MIME type of attachment
 @return corresponding file extension for attachment
 */
- (NSString *_Nullable)fileExtensionForMimeType:(NSString *_Nonnull)type;

/**
 Queue a message attachment for download.
 
 If the message attachment object is empty or exists on disk the download will be aborted.
 
 @param message message with attachment object.
 */

- (void)queueMessageForAttachmentDownload:(TTMessage * _Nonnull)message DEPRECATED_MSG_ATTRIBUTE("Use queueMessageForAttachmentDownload:observer:");

/**
 Queue a message attachment for download.
 
 If the message attachment object is empty or exists on disk the download will be aborted.
 
 @param message message with attachment object.
 @param observer an TTAttachmentDownloadObserver to observe progress/state of the attachment download.
 */
- (void)queueMessageForAttachmentDownload:(TTMessage * _Nonnull)message observer:(id<TTAttachmentDownloadObserver> _Nullable)observer;

/**
 Remove an observer from the list of observers for message attachment download.
 
 @param observer an TTAttachmentDownloadObserver to observe progress/state of the attachment download.
 @param message message with attachment object.
 */
- (void)removeAttachmentObserver:(id<TTAttachmentDownloadObserver> _Nonnull)observer forMessage:(TTMessage * _Nonnull)message;

/**
 Checks if the message attachment exists on disk.
 
 If the message attachment object is nil returns false.
 
 @param message message with attachment object.
 
 @return A BOOL if the attachment exists on disk.
 
 */
- (BOOL)isMessageAttachmentCachedToDisk:(TTMessage * _Nonnull)message;

/**
 Checks if the message attachment exists on disk in the share folder (App group).
 
 If the message attachment object is nil returns false.
 
 @param message message with attachment object.
 
 @return A BOOL if the attachment exists on disk.
 
 */
- (BOOL)isMessageAttachmentCachedToSharedFolder:(TTMessage * _Nonnull)message;

/**
 File path string to the attachment on disk.
 
 If the message attachment object is nil returns nil.
 
 @param message message with attachment object.
 
 @return An 'NSString' Object.
 
 */
- (NSString * _Nullable)localPathForAttachment:(TTMessage * _Nonnull)message;

///-------------------------------------------------------
/// @name Attachments Upload and Download data
///-------------------------------------------------------

/**
 DownloadData contains progress information regarding an attachment download
 
 @param message message with attachment object.
 
 @return An 'TTDownloadData' Object.
 
 */
- (TTDownloadData * _Nullable)getDownloadDataForMessage:(TTMessage * _Nonnull)message;

/**
 UploadData contains progress information regarding an attachment upload
 
 @param message message object.
 
 @return An 'TTUploadData' Object.
 
 */
- (TTUploadData * _Nullable)getUploadDataForMessage:(TTMessage * _Nonnull)message;

/**
 *
 *  Encrypt an NSData object.
 *
 *  @param data NSData object to be encrypted.
 *
 *  @return An Encrypted NSData object if input parameters were valid and encryption was successful, nil otherwise.
 */
- (NSData * _Nullable)encryptData:(NSData * _Nonnull)data;

/**
 *  Decrypt an encrypted NSData object.
 *
 *  @param data Encrypted NSData object to be decrypted.
 *
 *  @return A Decrypted NSData object if input parameters were valid and decryption was successful, nil otherwise.
 */
- (NSData * _Nullable)decryptData:(NSData * _Nonnull)data;

/**
 *  Remove cached data using the provided key.
 *
 *  @param key  Key for the cached value (NSString).
 */
- (void)removeCacheDataForKey:(NSString * _Nonnull)key;

/**
 *  Encrypt NSData and cache to both disk and memory using the provided key.
 *
 *  @param data NSData to be encrypted.
 *  @param key  Key for the cached value (NSString).
 */
- (void)encryptDataAndCache:(NSData * _Nonnull)data key:(NSString * _Nonnull)key;

/**
 *  Retrieve message attachment file path, use the localToken for message you've sent and token for messages recieved.
 *
 *  @param token Either the message localToken or token.
 *  @param conversationHash message conversationHash.
 *
 *  @return File path to the message attachment.
 */
- (NSString *_Nullable)localPathForMessageWithToken:(NSString *_Nonnull)token conversationHash:(NSString *_Nonnull)conversationHash;

/**
 *  Retrieve decrypted cached object, which was stored using the provided key.
 *
 *  Method will first search the in-memory cache. If no object fits the provided key, Disk cache will be searched afterwards.
 *
 *  @param key Key for the cached value (NSString).
 *
 *  @return Decrypted NSData object.
 */
- (NSData * _Nullable)getDecryptedCachedDataForKey:(NSString * _Nonnull)key;

/**
 *  Encrypt NSData and cache to memory using the provided key.
 *
 *  @param data NSData to be encrypted.
 *  @param key  Key for the cached value (NSString).
 */
- (void)encryptDataAndCacheToMemory:(NSData * _Nonnull)data key:(NSString * _Nonnull)key;

/**
 *  Encrypt NSData and cache to disk using the provided key.
 *
 *  @param data NSData to be encrypted.
 *  @param key  Key for the cached value (NSString).
 */
- (void)encryptDataAndCacheToDisk:(NSData * _Nonnull)data key:(NSString * _Nonnull)key;

/**
 *  Retrieve a cached object by its key from the in-memory cache.
 *
 *  @param key Key for the cached value (NSString).
 *
 *  @return Decrypted NSData object for the provided key , nil if no object exists in in-memory cache for provided key.
 */
- (NSData * _Nullable)objectFromMemoryCache:(NSString * _Nonnull)key;

/**
 *  Retrieve a cached object by its key from the disk cache.
 *
 *  @param key Key for the cached value (NSString).
 *
 *  @return Decrypted NSData object for the provided key , nil if no object exists in disk cache for provided key.
 */
- (NSData * _Nullable)objectFromDiskCache:(NSString * _Nonnull)key;

/**
 *  Retrieve a decrypted NSData object representing the TTMessage's attachment.
 *
 *  @param message A TTMessage with an attachment.
 *
 *  @return Decrypted NSData object or nil if no attachment exists.
 */
- (NSData * _Nullable)dataForAttachment:(TTMessage * _Nonnull)message;

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
- (TTBadgeData * _Nullable)badgeDataForRosterEntry:(TTRosterEntry * _Nonnull)rosterEntry;

/**
 *  Retrieve TTBadgeData object for a provided conversation hash.
 *
 *  @param conversationHash Conversation hash (NSString).
 *
 *  @return A TTBadgeData object with the provided conversation hash.
 */
- (TTBadgeData * _Nullable)badgeDataForConversationHash:(NSString * _Nonnull)conversationHash;

/**
 *  Retrieve TTBadgeData object for all conversations of a provided TTOrganization.
 *
 *  @param organization A TTOrganization object.
 *
 *  @return A TTBadgeData object containing unread count for all conversations of a provided TTOrganization.
 */
- (TTBadgeData * _Nullable)badgeDataForOrganization:(TTOrganization * _Nonnull)organization;

/**
 *  Retrieve all TTBadgeData objects for all organizations.
 *
 *  @return An NSArray of TTBadgeData objects containing unread count for all conversations of a provided TTOrganization.
 */
- (NSArray * _Nullable)badgeDataForAllOrganizations;

/**
 *  Retrieve TTBadgeData object for all conversations of a provided organization token.
 *
 *  @param orgToken An organization's token (NSString).
 *
 *  @return A TTBadgeData object containing unread count for all conversations of the provided orgToken.
 */
- (TTBadgeData * _Nullable)badgeDataForOrganizationToken:(NSString * _Nonnull)orgToken;

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
- (TTContact * _Nullable)contactForHashId:(NSString * _Nonnull)hashId;

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
- (NSFetchedResultsController * _Nullable)localContactsFetchControllerWithDelegate:(id _Nullable)delegate;

#if TARGET_OS_IOS

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
- (void)searchLocalContactsWithString:(NSString * _Nonnull)search
                              success:(void(^ _Nullable)(NSArray * _Nullable contacts))completionBlock;

#endif

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
- (void)setIsTyping:(NSString * _Nonnull)receipentToken
            success:(void (^ _Nullable)(void))success
            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Use this method when local user finished typing a message to another user.
 *
 *  @param receipentToken User token of recepient.
 *  @param success        Success block.
 *  @param failure        Failure block.
 */
- (void)didEndTyping:(NSString * _Nonnull)receipentToken
             success:(void (^ _Nullable)(void))success
             failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Gets a phone number from the server that can be dialed to reach another user.
 *
 * @param userID The userID for the user you'd like to reach
 * @param success Called when we successfully get a proxy phone number from the server
 * @param failure Called when the server returns an error or cannot be reached.
 */
- (id _Nullable)getProxyPhoneNumberForUserWithToken:(NSString * _Nonnull)userToken
                                  organizationToken:(NSString * _Nonnull)organizationToken
                                            success:(void (^ _Nullable)(NSString * _Nullable proxyPhone))success
                                            failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Check if click-to-call is enabled for an organization
 *
 *  @param organizationToken A token corresponding to the organization you'd like to check for the click-to-call feature.
 */
- (BOOL)isClickToCallEnabledForOrganizationWithToken:(NSString * _Nonnull)organizationToken;


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
- (BOOL)isRoleServiceEnabledForOrganization:(NSString * _Nonnull)organizationToken;

/**
 *  Use this method to update your user's dnd auto reply response.
 *
 *  @param autoReplyResponse auto reply message that will be sent when the user is on dnd. If not set, the reply message will default to 'Do not disturb'
 */
- (void)setDoNotDisturbAutoReply:(NSString * _Nonnull)autoReply;


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
- (TTUser * _Nullable)autoforwardRecipientForCurrentOrganization;

/**
 *  Use this method to check if autoforwarding is enabled for the current org.
 *  @param organizationToken The organization token for which to check for auto-forward feature.
 */
- (BOOL)autoforwardEnabledForOrganizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Use this method to update your user's autoforwardRecipientToken.
 *  @param recipientToken User Token for auto-forward message recipient.
 *  @param organizationToken The organization token for which to configure auto-forward receipient.
 */
- (void)setAutoforwardRecipientToken:(NSString * _Nonnull)recipientToken organizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Use this method to turn off autoforwarding for the current user.
 *  @param organizationToken The organization token for which to unset auto-forward recipient.
 *  @param success        Success block.
 *  @param failure        Failure block.
 */

- (void)unsetAutoforwardForOrganizationToken:(NSString * _Nonnull)organizationToken
                                     success:(void (^ _Nullable)(void))success
                                     failure:(void (^ _Nullable)(NSError * _Nullable error))failure;

/**
 *  Use this method to get user's autoforward receiver Token.
 *  @param organizationToken The organization token for which to unset auto-forwarding.
 */
- (NSString * _Nullable)autoforwardReceiverTokenForOrganizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Use this method to get user's autoforwarding Setters (token).
 *  @param organizationToken The organization token for which to unset auto-forwarding.
 */
- (NSArray * _Nullable)autoforwardSetterTokensForOrganizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Use this method to get autoforwarding final recipient for a Roster Entry. The method is asynchronous,
 *  but will will fire the completion block very quickly in the event that a network request isn't needed.
 *  @param rosterEntry The roster entry from which to resolve the final recipient.
 */
- (void)downloadAutoforwardFinalRecipientForRosterEntry:(TTRosterEntry * _Nonnull)rosterEntry
                                             completion:(void (^ _Nullable)(TTUser * _Nullable user))completion;

/**
 *  Use this method to get user's autoforwarding final recipient. The method is asynchronous,
 *  but will will fire the completion block very quickly in the event that a network request isn't needed.
 *  @param organizationToken The organization token for which to unset auto-forwarding.
 */
- (void)downloadAutoforwardFinalRecipientForUser:(TTUser * _Nonnull)user
                               organizationToken:(NSString * _Nonnull)organizationToken
                                      completion:(void (^ _Nullable)(TTUser * _Nullable user))completion;

/**
 *  User's title, i.e 'Chief Operations Officer' for a given organization
 *  @param organizationToken Organization token.
 */
- (NSString * _Nullable)userTitleForOrganizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Set User's title for a given organization
 *  @param userTitle User title.
 *  @param organizationToken Organization token.
 */
- (void)setUserTitle:(NSString * _Nonnull)title organizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  User's department, i.e 'Marketing' for a given organization
 *  @param organizationToken Organization token.
 */
- (NSString * _Nullable)userDepartmentForOrganizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Set User's department for a given organization
 *  @param userTitle User title.
 *  @param organizationToken Organization token.
 */
- (void)setUserDepartment:(NSString * _Nonnull)department organizationToken:(NSString * _Nonnull)organizationToken;

/**
 *  Refresh the message TTMessageStatus set
 *  @param messageToken Message Token.
 *  @param success        Success block.
 *  @param failure        Failure block.
 */
- (id _Nullable)refreshMessageStatusWithMessageToken:(NSString * _Nonnull)messageToken
                                             success:(void(^ _Nullable)(TTMessage * _Nullable message))success
                                             failure:(void (^ _Nullable)(NSError * _Nullable error))failure;


///-------------------------------------------------------
/// @name Mute
///-------------------------------------------------------

/**
 Mutes conversation for a set amount of time.

 @param entity The target of the conversation that is being muted.
 @param organizationToken The organization token for the conversation.
 @param minutes The amount of time in minutes to mute the conversation.
 @param completionHandler Completion block invoked when muting call is complete, passing back any errors that occurred.
 */
- (id _Nullable)muteEntity:(NSManagedObject * _Nonnull)entity organizationToken:(NSString * _Nonnull)organizationToken forMinutes:(NSUInteger)minutes withCompletionHandler:(void(^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 Unmutes conversation.

 @param entity The target of the conversation that is being unmuted.
 @param organizationToken The organization token for the conversation.
 @param completionHandler Block that is invoked when the unmuting call is complete, passing back any errors that occurred.
 */
- (id _Nullable)unmuteEntity:(NSManagedObject * _Nonnull)entity organizationToken:(NSString * _Nonnull)organizationToken withCompletionHandler:(void(^ _Nullable)(NSError * _Nullable error))completionHandler;

@end
