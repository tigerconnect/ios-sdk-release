//
//  TTAlertEvent.h
//  TTKit
//
//  Created by Oren Zitoun on 10/27/17.
//  Copyright © 2017 TigerText, Inc. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class NSObject, TTMessage;

/**
 * An alert message used in Nurse Calls
 */
@interface TTAlertEvent : NSManagedObject

/**
 * NSDictionary that contains information about what to display in the alert event message.
 * @note `data["components"]` is a NSArray of NSDictionaries that contain components of the alert event message.
 * Each component dictionary should have "type" as key to indicate what type of content to display.
 * Possible values for `componentDictionary["type"]`: `nurse_header`, `text_view`, `bold_text_view`, `completed_item`, `ehr_action_item`, `ehr_bold_text_view`, `ehr_header_generic`, `ehr_text_view`, `table_item`, `escalate_header`, `two_button_view`, `role_info`, `button_view`
 *
 * Component dictionary will also contain information about the configuration of the views.
 */
@property (nullable, nonatomic, retain) NSObject *data;

/**
 * Token of the organization in which the alert event exists.
 */
@property (nullable, nonatomic, copy) NSString *organizationToken;

/**
 * If type is equal to `kTTKitFeatureServiceAlertsKey`, then the attached message type is set to `TTMessageTypeAlert`.
 */
@property (nullable, nonatomic, copy) NSString *type;

/**
 * Integer value denoting the priority of the alert.
 */
@property (nullable, nonatomic, copy) NSNumber *priority;

/**
 * The message that contains this alert event.
 */
@property (nullable, nonatomic, retain) TTMessage *message;

@end
