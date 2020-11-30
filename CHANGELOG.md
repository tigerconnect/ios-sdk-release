# TigerConnect Change Log
## 1.9.1

* Video Call APIs
* Bug fixes and performance improvements

## 1.8.1

* Mute Conversations
* Search Groups
* Roles
* Bug fixes and performance improvements

## 1.7

* Bug fixes and performance improvements

## 1.5.4

* Fixed migration issue that appeared in 1.5.3

## 1.5.3

* Fixed TTKit testing environment issue
* Miscellaneous stability and performance enhancements

## 1.5.1

* Fixed TTKit bundle CFBundleSupportedPlatforms issue
* Fixed issue of outgoing messages not expiring on the local device
* Miscellaneous stability and performance enhancements

## 1.4
#### Public API Changes 

* Introduced a new way to send messages using `TTMessageRequest`, which provides validation and a representation of a message to be sent using `TTKit`, `TTMessageRequest` also supports sending message metadata.
* Introduced a new api to send a `TTMessageRequest` using `[TTKit sendMessageWithRequest:completion]`
* Introduced a new api to track `TTPresenceData` changes using `TTPresenceDataObserver`


#### Public API Deprecations 

* `[TTKit sendMessage:rosterEntry:lifetime:deleteOnRead:attachmentPath:attachmentMimeType:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessage:rosterEntry:lifetime:deleteOnRead:attachmentData:attachmentMimeType:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessageToUsers:message:lifetime:deleteOnRead:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessageToUsers:forGroupName:groupAvatar:message:lifetime:deleteOnRead:attachmentData:attachmentMimeType:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessageToUsers:message:lifetime:deleteOnRead:attachmentPath:attachmentMimeType:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessageToUsers:message:lifetime:deleteOnRead:attachmentData:attachmentMimeType:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessageToUser:message:lifetime:deleteOnRead:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessageToUser:message:lifetime:deleteOnRead:attachmentPath:attachmentMimeType:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessageToUser:message:lifetime:deleteOnRead:attachmentData:attachmentMimeType:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.
* `[TTKit sendMessageToGroup:group:lifetime:deleteOnRead:attachmentData:attachmentPath:attachmentMimeType:success:failure]` has been deprecated in favor of `[TTKit sendMessageWithRequest:completion]`.

* `[TTPresenceData typeChangedBlock]` has been deprecated in favor of `TTPresenceDataObserver`.
* `[TTPresenceData statusChangedBlock]` has been deprecated in favor of `TTPresenceDataObserver`.


## 1.3.8

#### Public API Changes 
* Introduced new Auto-Forward feature which provides a simple API to allow users to Auto-Forward all incoming messages to a different user.

#### Bug Fixes

* Fixes an issue where attempting to login with key and secret fails. 

