//
//  UIView+ZIAMView.h
//  IAM_SSO
//
//  Created by Abinaya Ravichandran on 05/07/22.
//  Copyright © 2022 Dhanasekar K. All rights reserved.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
#if !TARGET_OS_WATCH
@interface UIView (ZIAMView)
- (void)pinToSuperView:(CGFloat)constant;
- (void)setWidthConstraint:(CGFloat)constant;
- (void)setHeightConstraint:(CGFloat)constant;
- (void)pinTopToSuperView:(CGFloat)constant;
- (void)pinTrailingToSuperView:(CGFloat)constant;
- (void)pinLeadingToSuperView:(CGFloat)constant;
- (void)pinBottomToSuperView:(CGFloat)constant;
- (void)pinTopToSuperViewSafeArea:(CGFloat)constant API_AVAILABLE(ios(11.0));
- (void)pinTopTo:(UIView*)nextView constant:(CGFloat)constant;
-(void)pinCenterToSuperView;
@end
#endif
NS_ASSUME_NONNULL_END
