//
//  ZohoPortalAuthSFSafariViewController.h
//  Pods
//
//  Created by Kumareshwaran on 16/03/17.
//
//

#import <UIKit/UIKit.h>

#if !TARGET_OS_WATCH
@interface ZohoPortalAuthSFSafariViewController : UIViewController
-(NSString *)getURL;
- (void)oauthpost:(NSNotification *)note;
@end

#endif
