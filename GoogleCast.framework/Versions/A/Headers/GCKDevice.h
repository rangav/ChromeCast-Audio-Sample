// Copyright 2012 Google Inc.

#import <Foundation/Foundation.h>

#import "GCKDefines.h"

/**
 * @file GCKDevice.h
 * GCKDeviceStatus enum.
 */

/**
 * @enum GCKDeviceStatus
 * Enum defining the device status at the time the device was scanned.
 */
typedef NS_ENUM(NSInteger, GCKDeviceStatus) {
  /** Unknown status. */
  GCKDeviceStatusUnknown = -1,
  /** Idle device status. */
  GCKDeviceStatusIdle = 0,
  /** Busy/join device status. */
  GCKDeviceStatusBusy = 1,
};

/** Device capability flag for video out. */
GCK_EXPORT const NSInteger kGCKDeviceCapabilityVideoOut;
/** Device capability flag for video in. */
GCK_EXPORT const NSInteger kGCKDeviceCapabilityVideoIn;
/** Device capability flag for audio out. */
GCK_EXPORT const NSInteger kGCKDeviceCapabilityAudioOut;
/** Device capability flag for audio in. */
GCK_EXPORT const NSInteger kGCKDeviceCapabilityAudioIn;

/**
 * An object representing a first-screen device.
 *
 * @ingroup Discovery
 */
GCK_EXPORT
@interface GCKDevice : NSObject <NSCopying, NSCoding>

/** The device's IPv4 address, in dot-notation. Used when making network requests. */
@property(nonatomic, copy, readonly) NSString *ipAddress;

/** The device's service port. */
@property(nonatomic, readonly) UInt32 servicePort;

/**
 * The device's unique ID. This is the USN (Unique Service Name) as reported by the SSDP protocol.
 */
@property(nonatomic, copy) NSString *deviceID;

/** The device's friendly name. This is a user-assignable name such as "Living Room". */
@property(nonatomic, copy) NSString *friendlyName;

/** The device's manufacturer name. */
@property(nonatomic, copy) NSString *manufacturer;

/** The device's model name. */
@property(nonatomic, copy) NSString *modelName;

/** An array of GCKImage objects containing icons for the device. */
@property(nonatomic, copy) NSArray *icons;

/** The device's status at the time that it was most recently scanned. */
@property(nonatomic, readonly) GCKDeviceStatus status;

/** The status text reported by the currently running receiver application, if any. */
@property(nonatomic, copy) NSString *statusText;

/** The device's version. */
@property(nonatomic, copy) NSString *deviceVersion;

/** Designated initializer. Constructs a new GCKDevice with the given IP address.
 *
 * @param ipAddress The device's IPv4 address, in dot-notation.
 * @param servicePort The device's service port.
 */
- (instancetype)initWithIPAddress:(NSString *)ipAddress servicePort:(UInt32)servicePort;

/**
 * Tests if this device refers to the same physical device as another. Returns YES if both
 * GCKDevice objects have the same IP address, service port, device ID, and version.
 */
- (BOOL)isSameDeviceAs:(const GCKDevice *)other;

/**
 * Returns YES if the device supports the given capabilities.
 *
 * @param deviceCapabilities A bitwise-OR of one or more of the kGCKDeviceCapability* constants.
 */
- (BOOL)hasCapabilities:(NSInteger)deviceCapabilities;

@end
