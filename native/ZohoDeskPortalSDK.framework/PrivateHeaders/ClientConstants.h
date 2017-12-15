//
//  ClientConstants.h
//  Pods
//
//  Created by Kumareshwaran on 24/03/17.
//
//

#ifndef ClientConstants_h
#define ClientConstants_h


/**
 * Unable to fetch token from server.
 */
static const int k_ClientTokenFetchError = 201;
/**
 * Access token fetch:Response is nil.
 */
static const int k_ClientTokenFetchNil = 202;
/**
 * Unable to fetch token. Nothing was received.
 */
static const int k_ClientTokenFetchNothingReceived = 204;
/**
 * SFSafari Dismissed.
 */
static const int k_ClientSFSafariDismissed = 205;
/**
 * There is no access token.
 */
static const int k_ClientNoAccessToken = 302;
/**
 * Unable to revoke token.
 */
static const int k_ClientRevokeTokenError = 801;
/**
 * Revoke token fetch:Response is nil.
 */
static const int k_ClientRevokeTokenResultNil = 802;
/**
 * Revoke token fetch. Nothing was received.
 */
static const int k_ClientRevokeTokenNothingReceived = 804;
/**
 * Network call failed with unknown error.
 */
static const int k_ClientGenericError = 900;
/**
 * Unable to fetch Refresh token from server.
 */
static const int k_ClientRefreshTokenFetchError = 901;
/**
 * Refresh token fetch:Response is nil.
 */
static const int k_ClientRefreshTokenFetchNil = 902;
/**
 * Unable to fetch Refresh token. Nothing was received.
 */
static const int k_ClientRefreshTokenFetchNothingReceived = 904;
/**
 * OAuth Server Error Occured during redirection
 */
static const int k_ClientOAuthServerError = 905;
/**
 * There is no access token for the given scopes.
 */
static const int k_ClientScopeNotFound = 906;
/**
 * Unable to fetch remote token from server.
 */
static const int k_RemoteTokenFetchError = 701;
/**
 * Remote token fetch:Response is nil.
 */
static const int k_RemoteTokenFetchNil = 702;
/**
 * Unable to fetch remote token. Nothing was received.
 */
static const int k_RemoteTokenFetchNothingReceived = 703;

#endif /* ClientConstants_h */
