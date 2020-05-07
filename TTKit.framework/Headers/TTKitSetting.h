
/**
 *  Enumeration for different user / organization settings.
 */
typedef NS_ENUM(NSInteger, TTKitSetting)
{
    /**
     *  The setting `TTKitSettingUnknown` indicates an invalid or unsupported setting.
     */
    TTKitSettingUnknown,
    
    /**
     *  Delete on read setting. The key for this setting type is "dor", and the value is a boolean. There is no default for this setting (default is `nil`).
     */
    TTKitSettingDeleteOnRead,
    
    /**
     *  Setting for how long a message is available. The key for this setting type is "ttl", and the value is a NSNumber with an integer value in minutes. There is no default for this setting (default is `nil`).
     */
    TTKitSettingTimeToLive,
    
    /**
     *  Setting for whether the user is on do not disturb. The key for this setting type is "dnd", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingDoNotDisturb,
    
    /**
     *  Setting for do not disturb text. The key for this setting type is "dnd_text", and the value is a string. The default for this setting is "Do not disturb".
     */
    TTKitSettingDoNotDisturbText,
    
    /**
     *  Setting for whether to play notification sounds. The key for this setting type is "notification_sounds", and the value is a boolean. The default for this setting is `@YES`.
     */
    TTKitSettingNotificationSounds,
    
    /**
     *  Setting for whether to display notification alerts. The key for this setting type is "notification_alerts", and the value is a boolean. The default for this setting is `@YES`.
     */
    TTKitSettingNotificationAlerts,
    
    /**
     *  Setting for whether to display notification badges. The key for this setting type is "notification_badges", and the value is a boolean. The default for this setting is `@YES`.
     */
    TTKitSettingNotificationBadges,
    
    /**
     *  Setting for which sound to play when there is a push notification. The key for this setting type is "push_sound", and the value is a string, indicating the title of a sound file. The default for this setting is "purr.caf".
     */
    TTKitSettingPushSound,
    
    /**
     * Setting for whether pin lock is enabled. The key for this setting type is "pin_lock", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPINLock,
    
    /**
     * Setting for the status string. The key for this setting type is "status", and the value is a string. The default for this setting is an empty string.
     */
    TTKitSettingStatus,
    
    /**
     *  Setting for amount of time before user is required to enter pin. The key for this setting type is "pin_duration", and the value is a NSNumber with integer value in minutes. The default for this setting is 0.
     */
    TTKitSettingPINDuration,
    
    /**
     *  Setting for user's department. The key for this setting type is "department", and the value is a string. The default for this setting is an empty string.
     */
    TTKitSettingDepartment,
    
    /**
     *  Setting for user's title. The key for this setting type is "title", and the value is a string. The default for this setting is an empty string.
     */
    TTKitSettingTitle,
    
    /**
     *  Setting for user's preferred email. The key for this setting type is "preferred_email", and the value is a string. The default for this setting is an empty string.
     */
    TTKitSettingPreferredEmail,
    
    /**
     *  Setting for user's preferred phone number. The key for this setting type is "preferred_phone", and the value is a string. The default for this setting is an empty string.
     */
    TTKitSettingPreferredPhone,
    
    /**
     *  Setting for whether the message forwarding function is enabled. The key for this setting type is "forward", and the value is a boolean. The default for this setting is `@YES`.
     */
    TTKitSettingForward,
    
    /**
     *  Setting for whether the app plays a sound when user receives a message while the user has the app open. The key for this setting type is "in_app_alert_sounds", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingInAppAlertSounds,
    
    /**
     *  Setting for whether the user has been approved by admin. The key for this setting type is "pending_admin_approval", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPendingAdminApproval,
    
    /**
     *  Setting for whether an organization has public groups (forums). The key for this setting type is "allow_public_groups", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingAllowPublicGroups,
    
    /**
     *  Setting for whether autoforward is allowed when user is on do not disturb. The key for this setting type is "dnd_auto_forward", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingAllowDNDAutoforward,
    
    /**
     *  Setting that indicates the receiver of the do not disturb autoforward messages. The key for this setting type is "dnd_auto_forward_receiver", and the value is a string that is the receiver's user token. The default for this setting is an empty string.
     * @note This setting is only valid when `TTKitSettingAllowDNDAutoforward` is `@YES`.
     */
    TTKitSettingDNDAutoforwardReceiver,
    
    /**
     *  Setting for do not disturb autoforward setters. The key for this setting type is "dnd_auto_forward_setters", and the value is a string array. The default for this setting is an empty array.
     */
    TTKitSettingDNDAutoforwardSetters,
    
    /**
     *  Setting for whether priority messaging is enabled. The key for this setting type is "priority_messaging", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPriorityMessaging,
    
    /**
     *  Setting indicating if the current session is expired. The key for this setting type is "session_expired", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingSessionExpired,
    
    /**
     *  Setting for whether change password is disabled. The key for this setting type is "disabled_change_password", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingDisableChangePassword,
    
    /**
     *  Setting for whether roles are enabled in the organization. The key for this setting type is "role_service", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingRoleService,
    
    /**
     *  Setting for whether click to call is enabled in the organization. The key for this setting type is "click_to_call", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingClickToCall,
    
    /**
     *  Setting for whether calendar for role shifts is enabled in the organization. The key for this setting type is "calendar", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingCalendarService,
    
    /**
     *  Setting for the predefined list of quick replies. The key for this setting type is "quick_replies", and the value is an array of strings. The default for this setting is an empty array.
     */
    TTKitSettingQuickReplies,
    
    /**
     *  Setting for whether missed call notifications are enabled. The key for this setting type is "enable_c2c_notifications", and the value is a boolean. The default for this setting is `@YES`.
     */
    TTKitSettingEnableMissedCallNotifications,
    
    /**
     *  Setting for the proxy phone number for the organization. The key for this setting type is "proxy_number", and the value is a string. There is no default for this setting (default is `nil`).
     */
    TTKitSettingOrganizationClickToCallNumber,
    
    /**
     *  Setting for name that is displayed for the organization during a call. The key for this setting type is "phone_label", and the value is a string. There is no default for this setting (default is `nil`).
     */
    TTKitSettingOrganizationClickToCallLabel,
    
    /**
     *  Setting that indicates the name that is displayed for the contact during a call. The key for this setting type is "proxy_number_identifier", and the value is a string. There is no default for this setting (default is `nil`).
     */
    TTKitSettingOrganizationClickToCallContactCurrentName,
    
    /**
     *  Setting for whether to show end user license agreement. The key for this setting type is "eula", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingOrganizationEULA,
    
    /**
     *  Setting for the url of the end user license agreement. The key for this setting type is "eula_content", and the value is a string. There is no default for this setting (default is `nil`).
     */
    TTKitSettingOrganizationEULAURL,
    
    /**
     *  Setting for the name used when the current user calls someone. The key for this setting type is "outgoing_call_contact_name", and the value is a string. There is no default for this setting (default is `nil`).
     */
    TTKitSettingClickToCallOutGoingContactName,
    
    /**
     *  Setting for the token of the current user for outgoing calls. The key for this setting type is "outgoing_call_contact_token", and the value is a string. There is no default for this setting (default is `nil`).
     */
    TTKitSettingClickToCallOutGoingContactToken,
    
    /**
     *  Setting for whether the alerts service is enabled. The key for this setting type is "feature_alerts", and the value is a a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingAlertsService,
    
    /**
     *  Setting for whether the patient care service is enabled. The key for this setting type is "patient_care", and the value is a a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPatientCare,
    
    /**
     *  Setting for whether VoIP is enabled. The key for this setting type is "voip", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingVoipService,
    
    /**
     *  Setting for whether video call feature is enabled. The key for this setting type is "video_call", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingVideoCallService,
    
    /**
     *  Setting for whether attachments are allowed. If the value is `@YES`, then attachments are not allowed. The key for this setting type is "no_attachment", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingNoAttachments,
    
    /**
     *  Setting for whether sending photos is allowed. If the value is `@YES`, then photos are not allowed. The key for this setting type is "no_photo", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingNoPhotos,
    
    /**
     *  Setting for whether escalations feature is enabled. The key for this setting type is "roles_escalation", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingEscalations,
    
    /**
     *  Setting for whether group audio call feature is enabled. The key for this setting type is "group_audio_call", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingGroupAudioCallService,
    
    /**
     *  Setting for whether group video call feature is enabled. The key for this setting type is "group_video_call", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingGroupVideoCallService,
    
    /**
     *  Setting for whether the patient network is enabled. The key for this setting type is "patient_network", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPatientNetwork,
    
    /**
     *  Setting for whether the user has turned "away" status on. The key for this setting type is "patient_network_away", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPatientNetworkAway,

    /**
     *  Setting the user's patient network away message text.  The key for this setting type is "patient_network_away_message", and the value is a string. The default for this setting is nil`.
     */
    TTKitSettingPatientNetworkAwayMessage,

    /**
    *  Setting for patient network's group expiration. The key for this setting type is "patient_network_group_expire_at", and the value is a string representing a date which the group expires at. The default for this setting is nil.
    */
    TTKitSettingPatientNetworkGroupExpireAt,
    
    /**
    *  Setting for whether the teams service is enabled. The key for this setting type is "teams", and the value is a a boolean. The default for this setting is `@NO`.
    */
    TTKitSettingTeamsService,
    
    /**
    *  Setting for user roles in the organization. The key for this setting type is "organization_user_roles", and the value is an array. The default for this setting is `nil`. Note that this enum type has nothing to do with the roles feature. This type is used to determine whether a user is a team admin in an organization.
    */
    TTKitSettingUserRoles,
    
    /**
     *  Setting for whether group audio call feature is enabled. The key for this setting type is "group_audio_call", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPatientGroupAudioCallService,
    
    /**
     *  Setting for whether group video call feature is enabled. The key for this setting type is "group_video_call", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPatientGroupVideoCallService,
    
    /**
     *  Setting for whether VoIP is enabled. The key for this setting type is "voip", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPatientVoipService,
    
    /**
     *  Setting for whether video call feature is enabled. The key for this setting type is "video_call", and the value is a boolean. The default for this setting is `@NO`.
     */
    TTKitSettingPatientVideoCallService,


};
