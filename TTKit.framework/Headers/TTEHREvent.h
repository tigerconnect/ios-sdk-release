//
//  TTEHREvent.h
//  TTKit
//
//  Created by Oren Zitoun on 6/29/17.
//  Copyright © 2017 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class NSObject, TTMessage, TTEHRMeasurement;

/**
 * An Electronic Health Record message used by Care Teams to communicate patient's current condition (such as location, admit reason, admit time, etc).
 */
@interface TTEHREvent : NSManagedObject

/**
 * NSDictionary containing information about what to display in the EHR event message.
 * @discussion
 * `data[@"components"]` is a NSArray of NSDictionaries that contain components of the EHR event message.
 * Each component dictionary should have "type" as a key to indicate what type of content to display.
 * Possible values for `componentDictionary["type"]`: "nurse_header", "text_view", "bold_text_view", "completed_item", "ehr_action_item", "ehr_bold_text_view", "ehr_header_generic", "ehr_text_view", "table_item", "escalate_header", "two_button_view", "role_info", "button_view"
 *
 * Component dictionary will also contain information about the configuration of the views.
 */
@property (nullable, nonatomic, retain) NSObject *data;

/**
 * Token of the organization in which the EHR event exists.
 */
@property (nullable, nonatomic, copy) NSString *organizationToken;

/**
 * If type is equal to `kTTKitFeatureServicePatientCareKey`, then the associated message's type is set to `TTMessageTypePatientCare`
 */
@property (nullable, nonatomic, copy) NSString *type;

/**
 * The message that contains this EHR event.
 */
@property (nullable, nonatomic, retain) TTMessage *message;

/**
 * A set of lab result measurements.
 */
@property (nullable, nonatomic, retain) NSSet<TTEHRMeasurement *> *ehrMeasurements;

@end


