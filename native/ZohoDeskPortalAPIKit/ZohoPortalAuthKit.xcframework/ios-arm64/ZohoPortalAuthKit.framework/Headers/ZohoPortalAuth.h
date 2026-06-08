//
//  ZohoPortalAuth.h
//  ZohoPortalAuth
//
//  Created by Kumareshwaran on 26/02/18.
//  Copyright © 2018 Dhanasekar K. All rights reserved.
//

#import <Foundation/Foundation.h>
#if !TARGET_OS_WATCH
#import <UIKit/UIKit.h>
#endif
#import <ZohoPortalAuthKit/ZohoPortalAuthRequestBlocks.h>
#import <ZohoPortalAuthKit/ZohoPortalAuthConstants.h>



/**
ZohoPortalAuth is a hollistic SDK which provides easy to use methods. Using these methods you can achieve Zoho Client Portal model sign-in integration with your iOS Mobile Application.
*/
@interface ZohoPortalAuth : NSObject

#if !TARGET_OS_WATCH

///  This method will initialize the parameters which are required by the ZohoPortalAuth. Call this method at App Launch.
/// @param clientID It is a unique identifier you receive when you register your application with Zoho
/// @param clientSecret  A unique key generated when you register your application with Zoho. This must be kept confidential.
/// @param portalID A unique identifier for your Portal.
/// @param scopearray The API scopes requested by the app, represented in an array of |NSString|s. The default value is |@[aaaserver.profile.READ,zohocontacts.userphoto.READ]|.(Get the list of scopes required for your app from the respective service teams. Each Scope String should follow the proper syntax. -> 'servicename'.'scopename'.'operation type' Example: AaaServer.profile.READ.
/// @param urlScheme Your App's URL Scheme.
/// @param ServiceName Your App's Service name.
/// @param mainWindow A UIWindow instance is required for presenting SFSafariViewController/AccountChooserViewController.
/// @param accountsPortalURL accounts portal url endpoint for your app.
+(void) initWithClientID: (NSString*)clientID
             ClientSecret: (NSString*)clientSecret
                 PortalID:(NSString *)portalID
                    Scope:(NSArray*)scopearray
                URLScheme:(NSString*)urlScheme
             ServiceName:(NSString*)servicename
               MainWindow:(UIWindow*)mainWindow
        AccountsPortalURL:(NSString*)accountsPortalURL;
#endif


/// This method will initialize the parameters which are required by the ZohoPortalAuth. Call this method at App Launch in Extensions and iWatch. (Note: Add your main app's bundle id in your extensions info.plist for "CLIENTUSERKIT_MAIN_APP_BUNDLE_ID" key)
/// @param clientID It is a unique identifier you receive when you register your application with Zoho
/// @param clientSecret A unique key generated when you register your application with Zoho. This must be kept confidential.
/// @param portalID A unique identifier for your Portal.
/// @param scopearray The API scopes requested by the app, represented in an array of |NSString|s. The default value is |@[aaaserver.profile.READ,zohocontacts.userphoto.READ]|.(Get the list of scopes required for your app from the respective service teams. Each Scope String should follow the proper syntax. -> 'servicename'.'scopename'.'operation type' Example: AaaServer.profile.READ.
/// @param urlScheme Your App's URL Scheme.
/// @param accountsPortalURL accounts portal url endpoint for your respective Portal.
+(void) initExtensionWithClientID:(NSString*)clientID
                      ClientSecret: (NSString*)clientSecret
                          PortalID:(NSString *)portalID
                             Scope:(NSArray*)scopearray
                         URLScheme:(NSString*)urlScheme
                      ServiceName:(NSString*)servicename
                 AccountsPortalURL:(NSString*)accountsPortalURL;


/// Method to clear the keychain items stored by ZohoPortalAuth which would be persistant even after uninstalling the app. (Call this method if it is going to be your apps firt time launch.
+(void)clearZohoAuthPortalDetailsForFirstLaunch;

/// Method to handle default scoped clients. Call this method if you have enabled default scopes for your client ID
+(void)setDefaultScopesEnabled:(BOOL)isEnabled;


/// Method to handle OAuth redirection via URL Scheme. This method should be called from your |UIApplicationDelegate|'s |application:openURL:sourceApplication:annotation|.  Returns |YES| if |ZohoPortalAuth handled this URL.
/// @param url url opened.
/// @param sourceApplication The application which opened this app.
/// @param annotation annotation object.
+(BOOL)handleURL:url sourceApplication:sourceApplication annotation:annotation;


///  Method to get the Signed-in status of user in your app. YES if there is already a user signed-in to your app or NO if there is no user signed in to your app.
+(BOOL)isUserSignedIn;


/// For MULTI-PORTAL Supported Apps:Method to get the Signed-in status of user in your app for the respective Portal ID. YES if there is already a user signed-in to your app or NO if there is no user signed in to your app.
/// @param portalID A unique identifier for your Portal.
+(BOOL)isUserSignedInForPortalID:(NSString *)portalID;


/// Method for letting us know that your app has an App Extension, so that we will place the respective data in the keychain within the specified app group. Call this method in App Delegate launch after the above initializeWithClientID method. This should be called before you call clearZohoAuthPortalDetailsForFirstLaunch method.
/// @param appGroup appgroup string in which you want the keychain data to be available.
+(void)setHavingAppExtensionWithAppGroup:(NSString *)appGroup;


/// Gets the access token. In case the access token has expired or is about to expire, this method get a new token.
/// @param tokenBlock callback in which you will get the required access token.
+(void)getOauth2Token:(ZohoPortalAuthAccessTokenHandler)tokenBlock;


/// For MULTI-PORTAL Supported Apps:Gets the access token for the respective Portal. In case the access token has expired or is about to expire, this method get a new token.
/// @param portalID A unique identifier for your Portal.
/// @param accountsPortalURL accounts portal url endpoint for your respective Portal.
/// @param tokenBlock callback in which you will get the required access token.
+(void)getOauth2TokenForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL tokenHandler:(ZohoPortalAuthAccessTokenHandler)tokenBlock;


/// Gets the access token along with its expiry time for WMS Special case handling of web sockets. In case the access token has expired or is about to expire(Reduced from 60mins to 53mins), this method get a new token.
/// @param tokenBlock callback in which you will get the required access token.
+(void)getOauth2TokenForWMS:(ZohoPortalAuthWMSAccessTokenHandler)tokenBlock;

/// Method to get the OAuth details which will be required by the Watch App to refresh the expired access token. returns dictionary containing all the details which is required to fetch a new access token.
+(NSDictionary *)giveOAuthDetailsForWatchApp;


/// Method to set the OAuth details obtained from iPhone to the keychain of watch app.
/// @param OAuthDetails dictionary containing the details required to fetch new access token.
+(void)setOAuthDeteailsInKeychainForWatchApp:(NSDictionary *)OAuthDetails;


/// This method presents the Zoho Portal Sign in page on SFSafariViewController.
/// @param signinBlock handler block.
+(void) presentZohoPortalSignIn:(ZohoPortalAuthSignInHandler)signinBlock;


/// This method presents the Zoho Portal Sign in page with custom parameters on SFSafariViewController.
/// @param urlParams custom urlparams to be passed to the portal sign-in page.
/// @param signinBlock handler block.
+ (void) presentZohoPortalSignInWithCustomParams:(NSDictionary *)urlParams
                                        signinHandler:(ZohoPortalAuthSignInHandler)signinBlock;

/// This method presents the Zoho Portal Custom Sign Up page on SFSafariViewController.
/// @param signupUrl your custom signup page url.
/// @param signinBlock handler block.
+ (void) presentZohoPortalSignUpHavingURL:(NSString *)signupUrl
                                        signinHandler:(ZohoPortalAuthSignInHandler)signinBlock;


/// This method presents the Zoho Portal Sign in page with custom URL on SFSafariViewController.
/// @param url custom urlparams to be passed to the portal sign-in page.
/// @param signinBlock handler block.
+ (void) presentZohoPortalSignInWithCustomURL:(NSString *)url
                                signinHandler:(ZohoPortalAuthSignInHandler)signinBlock;


/// For MULTI-PORTAL Supported Apps:This method presents the Zoho Portal Sign in page on SFSafariViewController for the respective Portal ID having the respective accounts portal URL.
/// @param portalID A unique identifier for your Portal.
/// @param accountsPortalURL accounts portal url endpoint for your respective Portal.
/// @param signinBlock handler block.
+(void) presentZohoPortalSignInForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL signinHanlder:(ZohoPortalAuthSignInHandler)signinBlock;


/// Method used to silently login a user into the portal app using a usertoken. (For Special JWT Handlings)
/// @param token A unique token obtained from your server to identify the user.
/// @param tokenType JWT or usertoken . Refer ZohoPortalAuthRemoteLoginType
/// @param tokenBlock handler block.
+(void) getOAuthTokenForRemoteUser:(NSString *)token
                      tokenType:(ZohoPortalAuthRemoteLoginType)tokenType
                      tokenHandler:(ZohoPortalAuthAccessTokenHandler)tokenBlock ;
/// Method used to silently login a user into the portal app using a usertoken. (For Special JWT Handlings)
/// @param token A unique token obtained from your server to identify the user.
/// @param tokenType JWT or usertoken . Refer ZohoPortalAuthRemoteLoginType
/// @param tokenBlock handler block.
+(void) getOAuthTokenForRemoteUser:(NSString *)token
                         tokenType:(ZohoPortalAuthRemoteLoginType)tokenType
                           baseURL:(NSURL*)baseURL
                      tokenHandler:(ZohoPortalAuthAccessTokenHandler)tokenBlock ;


/// Call this method at Logout. This will revoke the access token from the server and clears the keychain items stored by ZohoPortalAuth.
/// @param revokeBlock handler block.
+(void)revokeAccessToken:(ZohoPortalAuthRevokeAccessTokenHandler)revokeBlock;


/// For MULTI-PORTAL Supported Apps:Call this method at Logout. This will revoke the access token from the server and clears the keychain items stored by ZohoPortalAuth for the respective Portal..
/// @param portalID A unique identifier for your Portal.
/// @param accountsPortalURL accounts portal url endpoint for your respective Portal.
/// @param revokeBlock handler block.
+(void)revokeAccessTokenForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL revokeHandler:(ZohoPortalAuthRevokeAccessTokenHandler)revokeBlock;


/// Special method to get the sign in page URL to load on a webivew by your app.
+(NSString *)getIAMSignInURLForLoadingInWebView;


/// Method to continue the user login flow for sign in presented via webview using the sign in page URL obtained.
/// @param url url obtained during webview login
/// @param signinBlock handler block.
+(void)continueLoginFromWebviewHavingURL:(NSURL *)url signinhandler:(ZohoPortalAuthSignInHandler)signinBlock;


/// Method used for Scope Enhancements. Call this method once if you are introducing new scopes in your app update.
/// @param tokenBlock callback in which you will get the required access token.
+(void)enhanceScopes:(ZohoPortalAuthAccessTokenHandler)tokenBlock NS_EXTENSION_UNAVAILABLE_IOS("");

/// For MULTI-PORTAL Supported Apps:Method used for Scope Enhancements for respective Portal ID. Call this method once if you are introducing new scopes in your app update.
/// @param portalID A unique identifier for your Portal.
/// @param accountsPortalURL accounts portal url endpoint for your respective Portal.
/// @param tokenBlock handler block.
+(void)enhanceScopesForPortalID:(NSString *)portalID 
        havingAccountsPortalURL:(NSString *)accountsPortalURL tokenHandler:(ZohoPortalAuthAccessTokenHandler)tokenBlock;


/// Method used for Scope Enhancements for respective Portal ID. Call this method once if you are introducing new scopes in your app update.
/// @param portalID A unique identifier for your Portal.
/// @param accountsPortalURL accounts portal url endpoint for your respective Portal.
/// @param query custom params to be passed.
/// @param tokenBlock handler block.
+(void)enhanceScopesForPortalID:(NSString *)portalID
        havingAccountsPortalURL:(NSString *)accountsPortalURL
             havingCustomParams:( NSDictionary<NSString*,NSString*>* )query
                   tokenHandler:(ZohoPortalAuthAccessTokenHandler)tokenBlock;

/// Method to use new Sign in page which supports OTP Sign in.
/// @param shouldUseNewSignIn preferred bool value.
+(void)setShouldUseNewSignIn:(BOOL)shouldUseNewSignIn;

/// Call this method to fetch the User Information from server using the User Info API
/// Do not call this method frequently. But only when it is actually required. 
/// @param userinfoBlock handler block.
+(void)fetchUserInfo:(ZohoPortalAuthUserInfoHandler)userinfoBlock;


/// For MULTI-PORTAL Supported Apps:Call this method to fetch the User Information from server using the User Info API for the respective Portal..
/// @param portalID A unique identifier for your Portal.
/// @param accountsPortalURL accounts portal url endpoint for your respective Portal.
/// @param userinfoBlock handler block.
+(void)fetchUserInfoForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL revokeHandler:(ZohoPortalAuthUserInfoHandler)userinfoBlock;

///  Call this method everytime when your server gives you the invalid token error to check if it is a valid error case and to determine if you should logout the  respective user and take them to your onboarding screen.
+(void)checkAndLogout:(ZohoPortalAuthRevokeAccessTokenHandler)completion;

/// Method to set Network Delegate for On-Premise
/// @param delegate NSURLSessionDataDelegate
+(void)setNetworkDelegate:(id<NSURLSessionDataDelegate> _Nonnull )delegate;


/**
 ASWebAuthenticationSession will be used to present sign in page.
 
 @param shouldUseASWebAuth preferred bool value.
 */
+(void)shoulduseASWebAuthenticationSession:(BOOL)shouldUseASWebAuth;

+(void)shoulduseWKWebView:(BOOL)shoulduseWebView;

@end
