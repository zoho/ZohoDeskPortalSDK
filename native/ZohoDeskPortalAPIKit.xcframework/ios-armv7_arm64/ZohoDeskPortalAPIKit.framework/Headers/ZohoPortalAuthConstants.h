//
//  ZohoPortalAuthConstants.h
//  Pods
//
//  Created by Kumareshwaran on 24/03/17.
//
//

#ifndef ZohoPortalAuthConstants_h
#define ZohoPortalAuthConstants_h


/**
 * Unable to fetch token from server.
 */
static const int k_ZohoPortalAuthTokenFetchError = 201;
/**
 * Access token fetch:Response is nil.
 */
static const int k_ZohoPortalAuthTokenFetchNil = 202;
/**
 * Unable to fetch token. Nothing was received.
 */
static const int k_ZohoPortalAuthTokenFetchNothingReceived = 204;
/**
 * SFSafari Dismissed.
 */
static const int k_ZohoPortalAuthSFSafariDismissed = 205;
/**
 * There is no access token.
 */
static const int k_ZohoPortalAuthNoAccessToken = 302;
/**
 * Unable to revoke token.
 */
static const int k_ZohoPortalAuthRevokeTokenError = 801;
/**
 * Revoke token fetch:Response is nil.
 */
static const int k_ZohoPortalAuthRevokeTokenResultNil = 802;
/**
 * Revoke token fetch. Nothing was received.
 */
static const int k_ZohoPortalAuthRevokeTokenNothingReceived = 804;
/**
 * Network call failed with unknown error.
 */
static const int k_ZohoPortalAuthGenericError = 900;
/**
 * Unable to fetch Refresh token from server.
 */
static const int k_ZohoPortalAuthRefreshTokenFetchError = 901;
/**
 * Refresh token fetch:Response is nil.
 */
static const int k_ZohoPortalAuthRefreshTokenFetchNil = 902;
/**
 * Unable to fetch Refresh token. Nothing was received.
 */
static const int k_ZohoPortalAuthRefreshTokenFetchNothingReceived = 904;
/**
 * OAuth Server Error Occured during redirection
 */
static const int k_ZohoPortalAuthOAuthServerError = 905;
/**
 * There is no access token for the given scopes.
 */
static const int k_ZohoPortalAuthScopeNotFound = 906;
/**
 * Unable to fetch remote token from server.
 */
static const int k_ZohoPortalAuthRemoteTokenFetchError = 701;
/**
 * Remote token fetch:Response is nil.
 */
static const int k_ZohoPortalAuthRemoteTokenFetchNil = 702;
/**
 * Unable to fetch remote token. Nothing was received.
 */
static const int k_ZohoPortalAuthRemoteTokenFetchNothingReceived = 703;
/**
 * Unable to Enhance Scope.
 */
static const int k_ZohoPortalAuthEnhanceScopeError = 601;
/**
 * Fetches EnhanceScope
 * Response is nil.
 */
static const int k_ZohoPortalAuthEnhanceScopeResultNil = 602;
/**
 * Fetches EnhanceScope
 * Response is nil.
 */
static const int k_ZohoPortalAuthEnhanceScopeServerError = 603;
/**
 * Fetches EnhanceScope
 * Nothing was received.
 */
static const int k_ZohoPortalAuthEnhanceScopeNothingReceived = 604;

#endif /* ZohoPortalAuthConstants_h */
