//
//  ZohoPortalAuthRequestBlocks.h
//  IAM_ClientUsers
//
//  Created by Kumareshwaran on 26/02/18.
//  Copyright © 2018 Dhanasekar K. All rights reserved.
//

#ifndef ZohoPortalAuthRequestBlocks_h
#define ZohoPortalAuthRequestBlocks_h

/**
The callback handler gives an access token or an error. The error occurs if an attempt to
refresh the access token is unsuccessful.

@param token This token should be sent in the Authorization Header.(Header Value should be @"Zoho-oauthtoken<space>TOKEN"  forHTTPHeaderField:@"Authorization" where TOKEN is the NSString accessToken obtained in this block)
@param error Respective error object if the attempt to refresh the access token is unsuccessful.
*/
typedef void (^ZohoPortalAuthAccessTokenHandler)(NSString *token,NSError *error);

/**
The callback handler gives an access token, millis value of the respective access token's expiry time or an error, if attempt to refresh was unsuccessful.

@param accessToken This accessToken should be sent in the Authorization Header.(Header Value should be @"Zoho-oauthtoken TOKEN"  forHTTPHeaderField:@"Authorization" where TOKEN is the NSString accessToken obtained in this block)
@param expiresMillis This value gives you the millis value for which the respective accesstoken would be alive and valid.
@param error Any error if the attempt to refresh was unsuccessful.
*/
typedef void (^ZohoPortalAuthWMSAccessTokenHandler)(NSString *token, long expiresMillis,NSError *error);

/**
The callblack handler at Sign-in that gives the access token if there is no error. Using this handler, you can redirect to your app's signed-in state and present your respective screens if the error is nil.

@param token OAuth access token of the signed-in user.
@param error Respective error object.
*/
typedef void (^ZohoPortalAuthSignInHandler)(NSString *token,NSError *error);

/**
The callback handler for revoking the access token at logout. Nil error means that the access token was revoked successfully. You can handle your apps logout logic in this handler if there is no error.

@param error Respective error object of revoke network call.
*/
typedef void (^ZohoPortalAuthRevokeAccessTokenHandler)(NSError *error);

#endif /* ZohoPortalAuthRequestBlocks_h */
