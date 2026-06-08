//
//  NSURLProtocol+WKWebViewSupport.h
//  Pods
//
//  Created by Dylan on 2016/11/14.
//
//
//[NSURLProtocol wk_registerScheme:@"http"];
//[NSURLProtocol wk_registerScheme:@"https"];
#import <Foundation/Foundation.h>
//#import "desk-manager-Briding-Header.h"
@interface NSURLProtocol (WKWebViewSupport)

+ (void)wk_registerScheme:(NSString *)scheme;
+ (void)wk_unregisterScheme:(NSString *)scheme;

@end
