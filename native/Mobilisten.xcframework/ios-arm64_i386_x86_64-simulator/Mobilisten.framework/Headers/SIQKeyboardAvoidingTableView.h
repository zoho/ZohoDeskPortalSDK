//
//  SIQKeyboardAvoidingTableView.h
//  SIQKeyboardAvoiding
//
//  Created by Michael Tyson on 30/09/2013.
//  Copyright 2015 A Tasty Pixel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIScrollView+SIQKeyboardAvoidingAdditions.h"

@interface SIQKeyboardAvoidingTableView : UITableView <UITextFieldDelegate, UITextViewDelegate>
- (BOOL)focusNextTextField;
- (void)scrollToActiveTextField;
@end
