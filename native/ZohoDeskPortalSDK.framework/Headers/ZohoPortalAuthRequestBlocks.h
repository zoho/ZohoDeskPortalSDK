//
//  ZohoPortalAuthRequestBlocks.h
//  IAM_ClientUsers
//
//  Created by Kumareshwaran on 26/02/18.
//  Copyright © 2018 Dhanasekar K. All rights reserved.
//

#ifndef ZohoPortalAuthRequestBlocks_h
#define ZohoPortalAuthRequestBlocks_h

typedef void (^ZohoPortalAuthAccessTokenHandler)(NSString *token,NSError *error);

typedef void (^ZohoPortalAuthWMSAccessTokenHandler)(NSString *token, long expiresMillis,NSError *error);

typedef void (^ZohoPortalAuthSignInHandler)(NSString *token,NSError *error);

typedef void (^ZohoPortalAuthRevokeAccessTokenHandler)(NSError *error);

#endif /* ZohoPortalAuthRequestBlocks_h */
