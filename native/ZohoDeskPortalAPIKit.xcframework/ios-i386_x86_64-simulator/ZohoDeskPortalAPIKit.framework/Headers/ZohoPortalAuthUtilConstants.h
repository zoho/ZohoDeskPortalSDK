//
//  ZohoPortalAuthUtilConstants.h
//  ZohoSSO
//
//  Created by Kumareshwaran on 1/25/16.
//  Copyright © 2016 Dhanasekar K. All rights reserved.
//

#ifndef ZohoPortalAuthUtilConstants_h
#define ZohoPortalAuthUtilConstants_h

#ifdef DEBUG
#	define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#	define DLog(...)
#endif


#define kZohoPortalAuthVersion @"0.0.16"

#define kServiceKeychainItem @"com.zoho.client.oauth"


#endif /* ZohoPortalAuthUtilConstants_h */
