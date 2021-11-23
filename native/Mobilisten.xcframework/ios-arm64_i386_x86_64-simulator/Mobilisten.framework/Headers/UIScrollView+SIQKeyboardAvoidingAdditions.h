//
//  UIScrollView+SIQKeyboardAvoidingAdditions.h
//  SIQKeyboardAvoiding
//
//  Created by Michael Tyson on 30/09/2013.
//  Copyright 2015 A Tasty Pixel. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIScrollView (SIQKeyboardAvoidingAdditions)
- (BOOL)SIQKeyboardAvoiding_focusNextTextField;
- (void)SIQKeyboardAvoiding_scrollToActiveTextField;

- (void)SIQKeyboardAvoiding_keyboardWillShow:(NSNotification*)notification;
- (void)SIQKeyboardAvoiding_keyboardWillHide:(NSNotification*)notification;
- (void)SIQKeyboardAvoiding_updateContentInset;
- (void)SIQKeyboardAvoiding_updateFromContentSizeChange;
- (void)SIQKeyboardAvoiding_assignTextDelegateForViewsBeneathView:(UIView*)view;
- (UIView*)SIQKeyboardAvoiding_findFirstResponderBeneathView:(UIView*)view;
-(CGSize)SIQKeyboardAvoiding_calculatedContentSizeFromSubviewFrames;
@end
